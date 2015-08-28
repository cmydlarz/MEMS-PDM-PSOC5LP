/*******************************************************************************
* File Name: HwVerPin.c  
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
#include "HwVerPin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HwVerPin__PORT == 15 && ((HwVerPin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HwVerPin_Write
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
void HwVerPin_Write(uint8 value) 
{
    uint8 staticBits = (HwVerPin_DR & (uint8)(~HwVerPin_MASK));
    HwVerPin_DR = staticBits | ((uint8)(value << HwVerPin_SHIFT) & HwVerPin_MASK);
}


/*******************************************************************************
* Function Name: HwVerPin_SetDriveMode
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
void HwVerPin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HwVerPin_0, mode);
	CyPins_SetPinDriveMode(HwVerPin_1, mode);
	CyPins_SetPinDriveMode(HwVerPin_2, mode);
	CyPins_SetPinDriveMode(HwVerPin_3, mode);
	CyPins_SetPinDriveMode(HwVerPin_4, mode);
	CyPins_SetPinDriveMode(HwVerPin_5, mode);
}


/*******************************************************************************
* Function Name: HwVerPin_Read
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
*  Macro HwVerPin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HwVerPin_Read(void) 
{
    return (HwVerPin_PS & HwVerPin_MASK) >> HwVerPin_SHIFT;
}


/*******************************************************************************
* Function Name: HwVerPin_ReadDataReg
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
uint8 HwVerPin_ReadDataReg(void) 
{
    return (HwVerPin_DR & HwVerPin_MASK) >> HwVerPin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HwVerPin_INTSTAT) 

    /*******************************************************************************
    * Function Name: HwVerPin_ClearInterrupt
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
    uint8 HwVerPin_ClearInterrupt(void) 
    {
        return (HwVerPin_INTSTAT & HwVerPin_MASK) >> HwVerPin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
