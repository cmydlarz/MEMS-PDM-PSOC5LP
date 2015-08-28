/*****************************************************************************
* File Name: USBFS_commandInterface.h
* Version 2.03
*
* Description:
*  This file contains the function prototypes and constants used in
*  the USBFS_commandInterface.c.
*
* Note:
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
#if !defined(USBFS_COMMANDINTERFACE_H) 
#define USBFS_COMMANDINTERFACE_H 

/*****************************************************************************
* MACRO Definition
*****************************************************************************/
#define CLEAR_OP			0x00
#define CLEAR_BUSY			0x00
#define SET_BUSY			0x01
#define USB_OK_ACK			0x01
#define READ_CMD			0x01
#define WRITE_CMD			0x02
#define PROGRAM_CMD			0x07

/*****************************************************************************
* Data Type Definition
*****************************************************************************/


/*****************************************************************************
* Enumerated Data Definition
*****************************************************************************/


/*****************************************************************************
* Data Struct Definition
*****************************************************************************/


/*****************************************************************************
* Global Variable Declaration
*****************************************************************************/
extern uint8 pendingOp; 
extern uint8 fTcBusy; 
extern uint8 pifData[2];
extern uint8 pifBuf[64];
/*****************************************************************************
* Function Prototypes
*****************************************************************************/


/*****************************************************************************
* External Function Prototypes
*****************************************************************************/
extern void ProgramInit(void);
extern void VendorCmd(void);


#endif  /* USBFS_COMMANDINTERFACE_H */