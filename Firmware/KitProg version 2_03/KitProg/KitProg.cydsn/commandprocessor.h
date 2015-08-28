/*****************************************************************************
* File Name: commandProcessor.h
* Version 2.03
*
* Description:
*  This file contains the function prototypes and constants used in
*  the commandProcessor.c.
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
#if !defined(COMMAND_PROCESSOR_H) 
#define COMMAND_PROCESSOR_H 

/*****************************************************************************
* MACRO Definition
*****************************************************************************/
#define SET 					0x01
#define NOT_SET 				0x00

/* SWD Commands */
#define CMD_BUFFER				0x00
#define CMD_STATUS 				0x01
#define CMD_RESET				0x04
#define CMD_SET_PROTOCOL		0x40
#define CMD_SWD_SYNC    		0x41
#define CMD_SWD_ACQUIRE 		0x42
#define CMD_SWD_SPECIAL 		0x43

/* Power Status Commands */
#define POWER_SUPPLIED_INVERSE	0x00
#define POWER_SUPPLIED			0x01
#define POWER_DETECTED			0x02
#define ACK_POWER_NOT_DETECTED	0x00
#define ACK_POWER_DETECTED		0x40

#define ONE_VOLT				1000
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


/*****************************************************************************
* Function Prototypes
*****************************************************************************/
void SWDComm(void);
void CmdReset(void);
void CmdStatus(void);
/*****************************************************************************
* External Function Prototypes
*****************************************************************************/

#endif /* COMMAND_PROCESSOR_H */
