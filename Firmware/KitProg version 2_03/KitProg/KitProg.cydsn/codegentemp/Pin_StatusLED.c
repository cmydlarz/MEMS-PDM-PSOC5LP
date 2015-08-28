/*******************************************************************************
* File Name: Pin_StatusLED.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Pin_StatusLED.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Pin_StatusLED__PORT == 15 && ((Pin_StatusLED__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Pin_StatusLED_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Pin_StatusLED_Write(uint8 value) 
{
    uint8 staticBits = (Pin_StatusLED_DR & (uint8)(~Pin_StatusLED_MASK));
    Pin_StatusLED_DR = staticBits | ((uint8)(value << Pin_StatusLED_SHIFT) & Pin_StatusLED_MASK);
}


/*******************************************************************************
* Function Name: Pin_StatusLED_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Pin_StatusLED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pin_StatusLED_0, mode);
}


/*******************************************************************************
* Function Name: Pin_StatusLED_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Pin_StatusLED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_StatusLED_Read(void) 
{
    return (Pin_StatusLED_PS & Pin_StatusLED_MASK) >> Pin_StatusLED_SHIFT;
}


/*******************************************************************************
* Function Name: Pin_StatusLED_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Pin_StatusLED_ReadDataReg(void) 
{
    return (Pin_StatusLED_DR & Pin_StatusLED_MASK) >> Pin_StatusLED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_StatusLED_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_StatusLED_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Pin_StatusLED_ClearInterrupt(void) 
    {
        return (Pin_StatusLED_INTSTAT & Pin_StatusLED_MASK) >> Pin_StatusLED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
