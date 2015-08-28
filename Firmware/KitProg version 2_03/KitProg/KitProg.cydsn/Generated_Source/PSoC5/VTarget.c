/*******************************************************************************
* File Name: VTarget.c  
* Version 1.80
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
#include "VTarget.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 VTarget__PORT == 15 && ((VTarget__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: VTarget_Write
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
void VTarget_Write(uint8 value) 
{
    uint8 staticBits = (VTarget_DR & (uint8)(~VTarget_MASK));
    VTarget_DR = staticBits | ((uint8)(value << VTarget_SHIFT) & VTarget_MASK);
}


/*******************************************************************************
* Function Name: VTarget_SetDriveMode
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
void VTarget_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VTarget_0, mode);
}


/*******************************************************************************
* Function Name: VTarget_Read
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
*  Macro VTarget_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VTarget_Read(void) 
{
    return (VTarget_PS & VTarget_MASK) >> VTarget_SHIFT;
}


/*******************************************************************************
* Function Name: VTarget_ReadDataReg
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
uint8 VTarget_ReadDataReg(void) 
{
    return (VTarget_DR & VTarget_MASK) >> VTarget_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VTarget_INTSTAT) 

    /*******************************************************************************
    * Function Name: VTarget_ClearInterrupt
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
    uint8 VTarget_ClearInterrupt(void) 
    {
        return (VTarget_INTSTAT & VTarget_MASK) >> VTarget_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
