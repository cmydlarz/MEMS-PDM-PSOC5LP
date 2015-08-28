/*****************************************************************************
* File Name: version.c
* Version 2.03
*
* Description:
*  This file provides the source code to handle version information.
*
* Owner:
*	Ranjith M, Applications Engineer (rnjt@cypress.com)
*
* Related Document:
* 	001-85925 - CY8CKIT-042 PSoC 4 Pioneer Kit IROS
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
static uint8 CheckHWVerPerPin(uint8 bValuePullup, uint8 bValuePullDwn);

/*****************************************************************************
* Global Variable Declarations
*****************************************************************************/
uint8 kitProgHWVersion = 0;
/*****************************************************************************
* Local Global Variable Declarations
*****************************************************************************/

volatile struct{
    uint8 signature[16]; 
    uint8 verMajor;
    uint8 verMinor;
}version = 
{
	/* Signature retained due to compatibility requirements with the programmer. */
    "Cypress-TTBridge", 
    VER_MAJOR, 
    VER_MINOR,
};


/*******************************************************************************
* The Hardware verison pins are either connected to the ground or left floating.
* There are 6 hardware revision pins, P2[6:1]. A floating pin is equivalent to a 0
* and a grounded pin equivalent to 1 in version calculcation. So, if all pins 
* are floating, hardware revision is 000000b (=0x00). The number of versions can
* thus go upto 111111b (=0x3F).
* ------------------------------------------------------------------------------

********************************************************************************/

/*******************************************************************************
* Function Name: CheckHWVerPerPin()
********************************************************************************
* Summary:
* Checks whether the pins are floating or grounded.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
uint8 CheckHWVerPerPin(uint8 bValuePullup, uint8 bValuePullDwn)
{
    uint8 bHwVer = NOT_CONNECTED;
    
    if(bValuePullup != 0 && bValuePullDwn == 0)
    {
        /* Follows pull up/down, so it is floating */
        bHwVer = NOT_CONNECTED;
    }
    else if(bValuePullup == 0 && bValuePullDwn == 0) 
    {
        /* Always LOW, so it is GND */
        bHwVer = GROUND;
    }
    else
    {
        /* Shall not be here because these lines are never pulled up in the hardware */
    }
    
    return bHwVer;
}

/*******************************************************************************
* Function Name: GetHWVersion()
********************************************************************************
* Summary:
* Calculates the hardware version of the KitProg board.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void GetHWVersion(void)
{
    uint8 bValuePullUp[6];
    uint8 bValuePullDwn[6];
	uint8 sigCheck[16];
	uint8 verCheck;
	uint8 index = 0;
	uint8 ver = 0;
    
	/* To avoid the signature value being optimized out by the compiler. */
	sigCheck[0] = version.signature[0];
	verCheck = version.verMajor + version.verMinor;

	
    /* Drive pins resistive pull up and down */
    CyPins_SetPinDriveMode(Pin_HWVersionA_0, Pin_HWVersionA_DM_RES_UPDWN);
	CyPins_SetPinDriveMode(Pin_HWVersionB_0, Pin_HWVersionB_DM_RES_UPDWN);
	CyPins_SetPinDriveMode(Pin_HWVersionC_0, Pin_HWVersionC_DM_RES_UPDWN);
	CyPins_SetPinDriveMode(Pin_HWVersionD_0, Pin_HWVersionD_DM_RES_UPDWN);
	CyPins_SetPinDriveMode(Pin_HWVersionE_0, Pin_HWVersionE_DM_RES_UPDWN);
	CyPins_SetPinDriveMode(Pin_HWVersionF_0, Pin_HWVersionF_DM_RES_UPDWN);

	/* Set and Clear the pin to check whether the pins are floating or grounded. */
	/* Set the pins */
    CyPins_SetPin(Pin_HWVersionA_0);
	CyPins_SetPin(Pin_HWVersionB_0);
	CyPins_SetPin(Pin_HWVersionC_0);
	CyPins_SetPin(Pin_HWVersionD_0);
	CyPins_SetPin(Pin_HWVersionE_0);
	CyPins_SetPin(Pin_HWVersionF_0);
	
    CyDelay(10);
	/* Read back the pins */
	bValuePullUp[0] = CyPins_ReadPin(Pin_HWVersionA_0);
	bValuePullUp[1] = CyPins_ReadPin(Pin_HWVersionB_0);
	bValuePullUp[2] = CyPins_ReadPin(Pin_HWVersionC_0);
	bValuePullUp[3] = CyPins_ReadPin(Pin_HWVersionD_0);
	bValuePullUp[4] = CyPins_ReadPin(Pin_HWVersionE_0);
	bValuePullUp[5] = CyPins_ReadPin(Pin_HWVersionF_0);
	
	/* Clear the pins */
    CyPins_ClearPin(Pin_HWVersionA_0);
	CyPins_ClearPin(Pin_HWVersionB_0);
	CyPins_ClearPin(Pin_HWVersionC_0);
	CyPins_ClearPin(Pin_HWVersionD_0);
	CyPins_ClearPin(Pin_HWVersionE_0);
	CyPins_ClearPin(Pin_HWVersionF_0);
    
	CyDelay(10);
	/* Read back the pins */
	bValuePullDwn[0] = CyPins_ReadPin(Pin_HWVersionA_0);
	bValuePullDwn[1] = CyPins_ReadPin(Pin_HWVersionB_0);
	bValuePullDwn[2] = CyPins_ReadPin(Pin_HWVersionC_0);
	bValuePullDwn[3] = CyPins_ReadPin(Pin_HWVersionD_0);
	bValuePullDwn[4] = CyPins_ReadPin(Pin_HWVersionE_0);
	bValuePullDwn[5] = CyPins_ReadPin(Pin_HWVersionF_0);
    
    /* Drive to Hi-Z to save power */
    CyPins_SetPinDriveMode(Pin_HWVersionA_0, Pin_HWVersionA_DM_DIG_HIZ);
	CyPins_SetPinDriveMode(Pin_HWVersionB_0, Pin_HWVersionB_DM_DIG_HIZ);
	CyPins_SetPinDriveMode(Pin_HWVersionC_0, Pin_HWVersionC_DM_DIG_HIZ);
	CyPins_SetPinDriveMode(Pin_HWVersionD_0, Pin_HWVersionD_DM_DIG_HIZ);
	CyPins_SetPinDriveMode(Pin_HWVersionE_0, Pin_HWVersionE_DM_DIG_HIZ);
	CyPins_SetPinDriveMode(Pin_HWVersionF_0, Pin_HWVersionF_DM_DIG_HIZ);
    
    
	/* Calculate the HW version */
	for(index = 0; index < 6; index++)
	{
    	ver = ver + ((CheckHWVerPerPin(bValuePullUp[index], bValuePullDwn[index]) - 1) * (0x01 << index));
	}
					 
	kitProgHWVersion = ver - 1;
	return;
}

/* [] END OF FILE */
