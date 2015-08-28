/*****************************************************************************
* File Name: USBFS_commandInterface.c
*
* Version 2.03
*
* Description: Handles the USB control endpoint comands.
*
* Owner:
*	Ranjith M, Applications Engineer (rnjt@cypress.com)
*
* Related Document:
* 	001-85925 - CY8CKIT-042 PSoC 4 Pioneer Kit IROS
*	RNJT#18
*
* Hardware Dependency:
* 	CY8CKIT-042 (KitProg) 
*
* Code Tested With:
* 	Creator 2.2
*	GCC1 4.4.1
*	CY8CKIT-042 Rev 1
*
******************************************************************************
* Copyright (2013), Cypress Semiconductor Corporation.
******************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*****************************************************************************/
/* This module contains code that attempts to combine the functionality of the 2 
* chip solution employed in the PSoC MiniProgrammer.  That device uses a 66113 
* for the USB interface and a 27543 to program the target device.  Communication
* between the 66113 and 27543 is generally via a parallel bus although there is 
* also an ISSP connection so that the 27543 can be field reprogrammed via the 
* 66113.  Note that the 66113 is an OTP part.
*
* Communication between the PSoC Programmer GUI and the 66113 is mainly via 
* "no data" control transfers.  So, an example control transfer's data may 
* look like the following (in hex) C0 02 07 01 00 01 00 01	
* the C0 is the "Device to Host Vendor Request", 02 is bRequest - in our case, 
* a write.  the 07 01 will show up on the CATC as a Big Endian wValue - we only
* care about the raw bytes.  So, the 07 is the command and the 01 is the mode.
* The 66113 code takes care of commands 1 thru 6 internally. Command 7 is passed
* on to the 27543 via the parallel interface.  Since we are emulating the 27543, 
* we will need to add code to handle command #7 here.
*****************************************************************************/

#include "kitprog.h"

/*****************************************************************************
* Local Function Prototypes
*****************************************************************************/
void ProgramInit(void);
void VendorCmd(void);
/*****************************************************************************
* Local Global Variable Declarations
******************************************************************************/
uint8 pendingOp;
uint8 fTcBusy;
uint8 pifData[2];
uint8 pifBuf[64];
uint8 progMode;
/*******************************************************************************/
extern volatile T_USBFS_TD USBFS_currentTD;
/*******************************************************************************
* Function Name: ProgramInit()
********************************************************************************
* Summary: Initializes the variables for the programming operation.
*   
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global Variables:
* pendingOp	: Clears the flag which indicattes any pending programming operation
*
* fTcBust	: Clears the busy flag which indicates the PC that the PSoC 5LP is 
* currently busy in a programming operation
*
*******************************************************************************/
void ProgramInit(void)
{
    pendingOp = CLEAR_OP;
    fTcBusy = CLEAR_BUSY;
}
/*******************************************************************************
* Function Name: VendorCmd()
********************************************************************************
* Summary:
* Entry point from the USBFS user module. Called inside the function 
* USBFS_HandleVendorRqst() defined inside USBFS_vnd.c
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global Variables: 
* pifBuf	: Bufer to send data to through the USB control endpoint
* pifData	: Buffer to store commands received through the USB control endpoint
* progMode	: Next programming operation to be performed
* 
******************************************************************************/
void VendorCmd(void)
{
	/* Varaible to store ACK to be send to the USB packet */
    uint8 progRes;
	/* Varaible to store the data which indicates whether the received command is a programming command */
	uint8 progCmd;
	progRes = USB_OK_ACK;
    
	/* If executing a previous instruction, initiate a zero length USB transfer */
	if(fTcBusy == SET_BUSY)
	{
		USBFS_currentTD.count = 0;
	} 
    else 
    {
		/* Extract the count of bytes received. */
		USBFS_currentTD.count = ((uint16)CY_GET_REG8(USBFS_EP0_DR6_PTR)) + 
                                  ((uint16)CY_GET_REG8(USBFS_EP0_DR7_PTR)<<8);

		/* If a read operation, set the data pointer to the databuffer address. */
        if(CY_GET_REG8(USBFS_EP0_DR1_PTR) == READ_CMD)
        {
            USBFS_currentTD.pData = &pifBuf[0];
        } 
		/* If a write operation, extract the commands from the USB control endpoint registers */
        else if(CY_GET_REG8(USBFS_EP0_DR1_PTR) == WRITE_CMD)
        {
            /* Acknowledge the command */
			USBFS_currentTD.pData = &progRes;
			
			/* progCmd checks if the command is a programing command. */
            progCmd  = CY_GET_REG8(USBFS_EP0_DR2_PTR);
			
			/* progMode stores the programming operation type */
            progMode = CY_GET_REG8(USBFS_EP0_DR3_PTR);
			
			/* Array pifData stores the values such as the aquire mode (Reset/Powercycle), device to be acquired (PSoC 3/4/5LP), 
			* number of retries before declaring the programming operation to have failed, and the protocol type (SWD). The values
			* depend on the current value of the variable progMode */
            pifData[0] = CY_GET_REG8(USBFS_EP0_DR4_PTR);
            pifData[1]  = CY_GET_REG8(USBFS_EP0_DR5_PTR);
            
			/* If the command is a programming command */
            if(progCmd == PROGRAM_CMD)
            {	
                if(progMode != CMD_BUFFER)
                {
                    /* Pass the command to pending operation */
					pendingOp = progMode;
					
                    /* Set the busy flag */
                    fTcBusy = SET_BUSY;				
                }
            }
        } 
        else 
        {
			/* do nothing */
        }
	
    }
	return;
}

/* [] END OF FILE */
