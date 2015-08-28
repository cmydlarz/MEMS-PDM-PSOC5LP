/*****************************************************************************
* File Name: power.c
* 
* Version 2.03
*
* Description:
*  This file provides the source code to handle the power routines for PSoC 5LP.
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

#include "KitProg.h"

/*****************************************************************************
* Local Function Prototypes
*****************************************************************************/
void VoltageMonitorInit(void);
uint16 GetVoltage(void);
void GetRange(void);
uint16 Convert_To_milliVolts(uint16 counts);
void SendPSoCToSleep(void);
void ResumeFromSleep(void);
void HandleUSBSuspend(void);

/*****************************************************************************
* Global Variable Declarations
*****************************************************************************/
uint8 checkActivityFlag = FALSE;

/*****************************************************************************
* Local Global Variable Declarations
*****************************************************************************/
uint8 range = RANGE_5V0;
uint16 result = 0;
/*******************************************************************************
* Function Name: VoltageMonitorInit()
********************************************************************************
* Summary:
* Initialize the ADC for voltage monitoring.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void VoltageMonitorInit(void)
{
	//ADC_Voltage_Target_Start();
	//ADC_Voltage_Target_StartConvert();
	GetRange();
}

/*******************************************************************************
* Function Name: CalADC()
********************************************************************************
* Summary:
* Get the VDD Range.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void GetRange(void)
{
	/* Select the known voltage source VRef for the ADC */
	//AMux_Select(0);
	
	/* Calculate the counts for the known voltage source */
	//ADC_Voltage_Target_IsEndConversion(ADC_Voltage_Target_WAIT_FOR_RESULT);
	//result = ADC_Voltage_Target_GetResult16();
	
	/* Determine the VDD range based on the count value for known input source */
	if(result < THRESHOLD)
	{
		range = RANGE_5V0;
	}
	else
	{
		range = RANGE_3V3;
	}
}
/*******************************************************************************
* Function Name: GetVoltage()
********************************************************************************
* Summary:
* Calculates the VDD of the PSoC 4
*
* Parameters:
*  void
*
* Return:
*  Voltage in millivolts.
*
*******************************************************************************/
uint16 GetVoltage(void)
{
	uint16 targetVoltage = ZERO;
	uint16 targetValue = ZERO;	
	
	/* Seelct the Vtarget input */
	//AMux_Select(1);
	
	/* Calculate the ADC input value */
	//ADC_Voltage_Target_IsEndConversion(ADC_Voltage_Target_WAIT_FOR_RESULT);
	//targetValue = ADC_Voltage_Target_GetResult16();
	
	/* Convert to milliVolts */
	targetVoltage = Convert_To_milliVolts(targetValue);
	
	/* Account for the resistive divider in the hardware used to sample 
	* the input voltage (1.5K + 3K) */
	targetVoltage = targetVoltage * 3;
	targetVoltage = targetVoltage/2;
	
	return(targetVoltage);
}
/*******************************************************************************
* Function Name: Convert_To_milliVolts()
********************************************************************************
* Summary:
* Converts the ADC output counts to millivolts. Calcultaion is: 
* mV = (counts*5000)/(2^12) or (counts*3300)/(2^12) depending on the voltage range.
*
* Parameters:
*  counts: ADC 12-bit count value
*
* Return:
*  Voltage in millivolts.
*
*******************************************************************************/
uint16 Convert_To_milliVolts(uint16 counts)
{
	uint16 voltage = ZERO;
	uint32 intermediate = ZERO;
	
	/*Convert to millivolts based on the input voltage range */
	if(range == RANGE_5V0)
	{
		intermediate = counts * FIVE_VOLT_MULTIPLIER;
	}
	else
	{
		intermediate = counts * THREE_VOLT_MULTIPLIER;
	}
	intermediate = intermediate/TWELVE_BIT_DIVIDER;
	
	/* Convert to 16-bit value */
	voltage = (uint16)intermediate;	
	
	return(voltage);
}
/*******************************************************************************
* Function Name: VoltageMonitorStop()
********************************************************************************
* Summary:
*  Stops the ADC component used for target voltage monitoring.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void VoltageMonitorStop(void)
{
	//ADC_Voltage_Target_Sleep();
}
/*******************************************************************************
* Function Name: SendPSoCToSleep()
********************************************************************************
* Summary:
*  Prepares the PSoC 5LP device for sleep and puts the device in low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SendPSoCToSleep(void)
{
	Pin_StatusLED_Write(1);
	Timer_UsbSuspend_Stop();	
	UART_Bridge_Stop();
    VoltageMonitorStop();
	SWDHalt();
	HostCommStop();
	I2CPullUpDisable();		
	CyPmSaveClocks();
	CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_PICU);	
}
/*******************************************************************************
* Function Name: ResumeFromSleep()
********************************************************************************
* Summary:
*  Restores the configurations of PSoC 5LP after resuming from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResumeFromSleep(void)
{
	CyPmRestoreClocks();
	ProgramInit();
	HostCommInit();
	SWDInit();
	//ADC_Voltage_Target_Wakeup();
	//ADC_Voltage_Target_StartConvert();
	
	/* Initializes USB-UART interface */
    USBUARTInit();
	
	/* Initializes the timer for handling the USBFS Suspend Activity */
	Timer_UsbSuspend_Start();
	bUSBResetDetected = TRUE;
	Pin_StatusLED_Write(0);
}
/*******************************************************************************
* Function Name: HandleUSBSuspend()
********************************************************************************
* Summary:
* 	Handles the USB suspend Event
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void HandleUSBSuspend(void)
{
	if(checkActivityFlag == TRUE)
	{	
		if(USBFS_CheckActivity() == 0)
		{

			USBFS_Suspend();
			SendPSoCToSleep();
			ResumeFromSleep();
			USBFS_Resume();
		}
		else
		{
			/* Do nothing */
		}
		checkActivityFlag = FALSE;
	}
}


/* [] END OF FILE */
