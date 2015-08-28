/*******************************************************************************
* File Name: SWDXRES.c  
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
#include "SWDXRES.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SWDXRES__PORT == 15 && ((SWDXRES__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SWDXRES_Write
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
void SWDXRES_Write(uint8 value) 
{
    uint8 staticBits = (SWDXRES_DR & (uint8)(~SWDXRES_MASK));
    SWDXRES_DR = staticBits | ((uint8)(value << SWDXRES_SHIFT) & SWDXRES_MASK);
}


/*******************************************************************************
* Function Name: SWDXRES_SetDriveMode
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
void SWDXRES_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SWDXRES_0, mode);
}


/*******************************************************************************
* Function Name: SWDXRES_Read
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
*  Macro SWDXRES_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SWDXRES_Read(void) 
{
    return (SWDXRES_PS & SWDXRES_MASK) >> SWDXRES_SHIFT;
}


/*******************************************************************************
* Function Name: SWDXRES_ReadDataReg
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
uint8 SWDXRES_ReadDataReg(void) 
{
    return (SWDXRES_DR & SWDXRES_MASK) >> SWDXRES_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SWDXRES_INTSTAT) 

    /*******************************************************************************
    * Function Name: SWDXRES_ClearInterrupt
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
    uint8 SWDXRES_ClearInterrupt(void) 
    {
        return (SWDXRES_INTSTAT & SWDXRES_MASK) >> SWDXRES_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
