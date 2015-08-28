/*******************************************************************************
* File Name: HwVerPinD.c  
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
#include "HwVerPinD.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HwVerPinD__PORT == 15 && ((HwVerPinD__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HwVerPinD_Write
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
void HwVerPinD_Write(uint8 value) 
{
    uint8 staticBits = (HwVerPinD_DR & (uint8)(~HwVerPinD_MASK));
    HwVerPinD_DR = staticBits | ((uint8)(value << HwVerPinD_SHIFT) & HwVerPinD_MASK);
}


/*******************************************************************************
* Function Name: HwVerPinD_SetDriveMode
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
void HwVerPinD_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HwVerPinD_0, mode);
}


/*******************************************************************************
* Function Name: HwVerPinD_Read
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
*  Macro HwVerPinD_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HwVerPinD_Read(void) 
{
    return (HwVerPinD_PS & HwVerPinD_MASK) >> HwVerPinD_SHIFT;
}


/*******************************************************************************
* Function Name: HwVerPinD_ReadDataReg
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
uint8 HwVerPinD_ReadDataReg(void) 
{
    return (HwVerPinD_DR & HwVerPinD_MASK) >> HwVerPinD_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HwVerPinD_INTSTAT) 

    /*******************************************************************************
    * Function Name: HwVerPinD_ClearInterrupt
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
    uint8 HwVerPinD_ClearInterrupt(void) 
    {
        return (HwVerPinD_INTSTAT & HwVerPinD_MASK) >> HwVerPinD_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
