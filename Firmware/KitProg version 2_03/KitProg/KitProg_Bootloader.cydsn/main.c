/*****************************************************************************
* File Name: main.c
* Version 2.02
*
* Description:
*  This file provides the source code to handle bootloader for PSoC 5LP.
*
* Owner:
*	Anu MD, Applications Engineer Senior (anmd@cypress.com)
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
#include <device.h>
#include "Bootloader.h"

/* Defines for Bootloader checksum validation */
#define Bootloader_BL_LAST_ROW            (*Bootloader_MD_PTR_LAST_BLDR_ROW    )
#define Bootloader_FLASH_NUMBER_SECTORS   (CY_FLASH_NUMBER_ARRAYS)
#define Bootloader_CHECKSUM_START         0    /* The bootloader always starts at 0 in flash */
#define Bootloader_FROW_SIZE          ((CYDEV_FLS_ROW_SIZE) + (CYDEV_ECC_ROW_SIZE))

/* Function Delaration */
void ValidateBootloader(void);
uint8   Bootloader_Calc8BitFlashSum(uint32 start, uint32 size) CYSMALL ;

void main()
{
	uint16 counter = 0;

	/* Check the validity of bootloader by verifying the Bootloader checksum */
	ValidateBootloader();
	
	/* Initialize PWM component for LED status control*/
    PWM_Init();

	/* If the there is a valid application, check if PSoC 4 reset switch is pressed for more than 100ms
	 * If yes, blink the LED slowly(ON Time = 1.5s, OFF Time = 1.5s) to indicate that the device is in bootloader */
	if(Bootloader_ValidateApplication() == CYRET_SUCCESS)
	{
		/* If PSoC 4A XRES pin is pulled low during reset */
		if(Pin_PSoC4A_XRES_Read() == 0)
		{
			for(counter = 0; counter <= 100; counter++)
			{
				CyDelay(1);
				
				/* If the swicth is released before specified time, do not enter bootloader */
				if(Pin_PSoC4A_XRES_Read() != 0)
					break;
			}
						 
			/* If the reset switch was pressed for more than 100 millisecond counter value will be 100 
			 * If so, set the flash run type as bootloader to wait for a bootload operation */
			if(counter >= 100)
			{
				/* Set the reset SR0 switch to indicate the */
				Bootloader_SET_RUN_TYPE (Bootloader_START_BTLDR);
				
				/*Indicate that you have entered the bootloader mode.*/
				PWM_WritePeriod(30000);
				PWM_WriteCompare(15000);
			}
		}
	}
	else
	{
		/* If the application is not valid 
		 * Blink the LED very fast (ON Time = 0.25s, OFF Time = 0.25s)*/
		PWM_WritePeriod(5000);
		PWM_WriteCompare(2500);
	}
	/* Enable the PWM */
	PWM_Enable();

	/* Start Bootloader */
	Bootloader_Start();
    for(;;)
    {
        
    }
}

/*******************************************************************************
* Function Name: ValidateBootloader
********************************************************************************
*
* Summary:
*  Function to validate the bootloader bye verifying the bootloader checksum. 
*  The CPU execution is halted if Bootloader is not valid.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ValidateBootloader(void)
{
    extern uint8  *Bootloader_ChecksumAccess;
	extern uint32 *Bootloader_SizeBytesAccess;
	uint8 CYDATA calcedChecksum;
	calcedChecksum = Bootloader_Calc8BitFlashSum(Bootloader_CHECKSUM_START,
                	*Bootloader_SizeBytesAccess - Bootloader_CHECKSUM_START);

	/* we actually included the checksum, so remove it */
	calcedChecksum -= *Bootloader_ChecksumAccess;
	calcedChecksum = 1 + ~calcedChecksum;

	/* Halt device if bootloader application is invalid */
	if((calcedChecksum != *Bootloader_ChecksumAccess))
	{
	    CyHalt(0x00u);
	}
}


/* [] END OF FILE */
