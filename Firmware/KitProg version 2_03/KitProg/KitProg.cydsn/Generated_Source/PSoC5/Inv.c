/*******************************************************************************
* File Name: Inv.c  
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
#include "Inv.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Inv__PORT == 15 && ((Inv__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Inv_Write
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
void Inv_Write(uint8 value) 
{
    uint8 staticBits = (Inv_DR & (uint8)(~Inv_MASK));
    Inv_DR = staticBits | ((uint8)(value << Inv_SHIFT) & Inv_MASK);
}


/*******************************************************************************
* Function Name: Inv_SetDriveMode
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
void Inv_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Inv_0, mode);
}


/*******************************************************************************
* Function Name: Inv_Read
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
*  Macro Inv_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Inv_Read(void) 
{
    return (Inv_PS & Inv_MASK) >> Inv_SHIFT;
}


/*******************************************************************************
* Function Name: Inv_ReadDataReg
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
uint8 Inv_ReadDataReg(void) 
{
    return (Inv_DR & Inv_MASK) >> Inv_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Inv_INTSTAT) 

    /*******************************************************************************
    * Function Name: Inv_ClearInterrupt
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
    uint8 Inv_ClearInterrupt(void) 
    {
        return (Inv_INTSTAT & Inv_MASK) >> Inv_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
