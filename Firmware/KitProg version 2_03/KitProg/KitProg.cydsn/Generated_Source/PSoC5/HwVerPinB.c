/*******************************************************************************
* File Name: HwVerPinB.c  
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
#include "HwVerPinB.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HwVerPinB__PORT == 15 && ((HwVerPinB__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HwVerPinB_Write
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
void HwVerPinB_Write(uint8 value) 
{
    uint8 staticBits = (HwVerPinB_DR & (uint8)(~HwVerPinB_MASK));
    HwVerPinB_DR = staticBits | ((uint8)(value << HwVerPinB_SHIFT) & HwVerPinB_MASK);
}


/*******************************************************************************
* Function Name: HwVerPinB_SetDriveMode
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
void HwVerPinB_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HwVerPinB_0, mode);
}


/*******************************************************************************
* Function Name: HwVerPinB_Read
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
*  Macro HwVerPinB_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HwVerPinB_Read(void) 
{
    return (HwVerPinB_PS & HwVerPinB_MASK) >> HwVerPinB_SHIFT;
}


/*******************************************************************************
* Function Name: HwVerPinB_ReadDataReg
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
uint8 HwVerPinB_ReadDataReg(void) 
{
    return (HwVerPinB_DR & HwVerPinB_MASK) >> HwVerPinB_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HwVerPinB_INTSTAT) 

    /*******************************************************************************
    * Function Name: HwVerPinB_ClearInterrupt
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
    uint8 HwVerPinB_ClearInterrupt(void) 
    {
        return (HwVerPinB_INTSTAT & HwVerPinB_MASK) >> HwVerPinB_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
