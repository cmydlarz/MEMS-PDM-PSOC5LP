/*****************************************************************************
* File Name: commandProcessor.c
*
* Version 2.03
*
* Description: This files provides source code to handle communication between 
* PSoC Programmer GUI and the KitProg.
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
#include "kitprog.h"

/*****************************************************************************
* Local Function Prototypes
*****************************************************************************/
void CmdReset(void);
void CmdStatus(void);
void SWDComm(void);

/*****************************************************************************
* Local Global Variable Declarations
*****************************************************************************/
uint8 SWDFlag = SET;

/*******************************************************************************
* Function Name: cmdReset()
********************************************************************************
* Summary:
*  Polls the status of the programmer 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void CmdStatus(void)
{
	/* Power is detected by the programmer */
	if(GetVoltage() > ONE_VOLT)
	{
       	pifBuf[3] = ACK_POWER_DETECTED;
	}
	else
	{
		pifBuf[3] = ACK_POWER_NOT_DETECTED;
	}
	
	/* Power is supplied by the programmer. Works on inverse logic. 0x00 for power supplied and 0x01 for not supplied. */
    pifBuf[4] = POWER_SUPPLIED_INVERSE;
}
/*******************************************************************************
* Function Name: cmdReset()
********************************************************************************
* Summary:
*  Resets the PSoC 4 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void CmdReset(void)
{
	/* Set the pins to Strong drive state */
	SWD_SET_XRES_OUT;
	
//	/* Ensure that current state is high */
//    SWD_SET_XRES_HI;	
//    CyDelayUs(50);
	
	/* Set low to reset */
    SWD_SET_XRES_LO; 
    CyDelayUs(400);
	
//	/* Return to high to release */
//    SWD_SET_XRES_HI;
//    CyDelayUs(50);
	
	/* Set the pins to High-Z state */
	SWD_SET_XRES_IN;
	
	SWDHalt();
	return;
}
/*******************************************************************************
* Function Name: SWDComm()
********************************************************************************
* Summary:
* Checks the command received through the USB control endpoint and invokes 
* apporpriate functions.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDComm(void)
{
    uint8 progProtocol = 0u;
	/* Global variable pendingOp is set inside the function VendorCmd() defined in USBFS_commandInterface.c */
	if(pendingOp)
    {
        switch(pendingOp)
        {
			/* Command = 0x01, programmer polls the status (connected, powered) of the KitProg */
			case CMD_STATUS:
					CmdStatus();
					break;
			
			/* Command = 0x04, to reset the PSoC 4 */
            case CMD_RESET:
					CmdReset();
                    break;	
			
			/* Command = 0x40, sets the protocol to be SWD */		
			case CMD_SET_PROTOCOL: 
                    progProtocol = pifData[0];
                    /* If protocol is SWD set the flag. Otherwise ignore the command. */
                    if (progProtocol == 1)
                    {
                        SWDFlag = SET;
					} 
					else 
					{
                        SWDFlag = NOT_SET;
					}
					break;
					
            /* Command = 0x41, synchronise data transfer of the data endpoints with control endpoint */
            case CMD_SWD_SYNC: 
                    bufOutOffset = 0;
                    bufInOffset = 0;
                    bufOutLen = 0;
                    break;
					
            /* Command = 0x42, Acquires PSoC 3/4/5. CmdSWDAcquire() defined in swd.c  */
            case CMD_SWD_ACQUIRE: 
                    CmdSWDAcquire();
                    break;
					
            /* Command = 0x43, to reset the SWD bus. SWDResetBus() defined in swd.c */
            case CMD_SWD_SPECIAL: 
                    if(pifData[0] == 0)
					{
                        SWDResetBus();
                    } 
                    break;

            default:
			/* Ignore other commands for now */
					break;
        }		

        pendingOp = CLEAR_OP;
        fTcBusy = CLEAR_BUSY;
    }
	/* If a packet is received in the OUT endpoint */
    if(USBFS_bGetEPAckState(SWD_OUT_EP))
    {
		/* If protocol is SWD, then use FSM algorithm for 64-bytes packets on SWD-commands */
        if(SWDFlag == SET) 
        {
            /* Handles the swd commands. Defined in swd.c */
			HandleSWDRequest();
        }
        
    }
	
	return;
}

/* [] END OF FILE */
