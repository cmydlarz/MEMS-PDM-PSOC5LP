/*****************************************************************************
* File Name: main.c
*
* Version 2.03
*
* Description:
*  This file provides the source code to handle the programmer and bridge
*  for PSoC 5LP.
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

volatile uint8 bUSBResetDetected = FALSE;

void main()
{
	/* Enable global Interrupts */
    CyGlobalIntEnable;   
	
	/* Retrieves the Hardware version. Defined in version.c. */
	GetHWVersion();
	
	/* Initializes the variables for the programming operation. */
    ProgramInit();
	
	/* Initializes the variables for the Bridge operation. */
	HostCommInit();
	
	/* Initializes SWD interface */
    SWDInit();

	/* Intialize the ADC for voltage monitoring. */
	VoltageMonitorInit();
	
	/* Initializes USB-UART interface */
    USBUARTInit();
	
	/* flag to determine if the USB is reset */
	bUSBResetDetected = FALSE;

	while(1)
    {
        /* Turn off Green LED. LED is switched on after successful enumeration
		 * The LED has inverse logic. Writing 1 to the pin turns off the LED. */
		Pin_StatusLED_Write(1);		
        
		while(!USBFS_VBusPresent())
		{
			/* Wait till powered via USB */
		}
		
		/* If the USB is not reset. */
        if(bUSBResetDetected == FALSE)
        {
           /* Start USB operation at VDDD specified in the DWR */
			USBFS_Start(0, USBFS_DWR_VDDD_OPERATION);
			
			/* Initializes the timer for handling the USBFS Suspend Activity */
			Timer_UsbSuspend_Start();
		
			isr_UsbSuspend_Start();
		}
		
		while(!USBFS_GetConfiguration())
		{
			/* Handles USB Suspend event */
			HandleUSBSuspend();	
			
			/* Wait for Device to enumerate */	
		}
		
		/* Indicate successful enumeration. */
        Pin_StatusLED_Write(0);
		
		/* Enable USB out end points */
		USBFS_EnableOutEP(SWD_OUT_EP);
		USBFS_EnableOutEP(HOST_OUT_EP);

		/* Start the USBUART Interface */
		USBUARTStart();
		
		/* 'bbUSBResetDetected' flag is set to false to indicate that the USB is 
		 * connected and configured. This flag will be set inside USBFS_episr.c if 
		 * the USB Bus Reset is detected */
		bUSBResetDetected = FALSE;	
		
		/* Loop is executed as long as USB is not reset or the Vbus is not removed */
		while(USBFS_VBusPresent() && bUSBResetDetected == FALSE)
        {	
			/* Handles the communication between PSoC Programmer GUI and the PSoC 5LP
			 * via USB HID interface. Also handles the USB-I2C bridge functionality. */
            HostComm();
			
			/* Decides the commands-to-be-sent-to-the-SWD lines/configuration based on
			 * variables set by VendorCmd(). Defined in commandProcessor.c */
			SWDComm(); 

			/* Handles USB-UART Bridge interface */
			UARTBridgeComm();
			
			/* Handles the USB Suspend Event */
			HandleUSBSuspend();		
			
			if(USBFS_IsConfigurationChanged())
			{
				bUSBResetDetected = TRUE;
			}
        }
		
		SWDHalt();
		
		if(bUSBResetDetected == FALSE)
        {
            /* If the Vbus is removed, stop the component and try to re-enumerate. 
			* Set to true inside USBFS_episr.c [CY_ISR(USBFS_BUS_RESET_ISR)] */
			USBFS_Stop();
			
			/* Disables the timer for handling the USBFS Suspend Activity */
			Timer_UsbSuspend_Stop();
		
			isr_UsbSuspend_Stop();
        }
    }	
}
