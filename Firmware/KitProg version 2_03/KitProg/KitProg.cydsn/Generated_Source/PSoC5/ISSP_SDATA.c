/*******************************************************************************
* File Name: ISSP_SDATA.c  
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
#include "ISSP_SDATA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ISSP_SDATA__PORT == 15 && ((ISSP_SDATA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ISSP_SDATA_Write
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
void ISSP_SDATA_Write(uint8 value) 
{
    uint8 staticBits = (ISSP_SDATA_DR & (uint8)(~ISSP_SDATA_MASK));
    ISSP_SDATA_DR = staticBits | ((uint8)(value << ISSP_SDATA_SHIFT) & ISSP_SDATA_MASK);
}


/*******************************************************************************
* Function Name: ISSP_SDATA_SetDriveMode
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
void ISSP_SDATA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ISSP_SDATA_0, mode);
}


/*******************************************************************************
* Function Name: ISSP_SDATA_Read
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
*  Macro ISSP_SDATA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ISSP_SDATA_Read(void) 
{
    return (ISSP_SDATA_PS & ISSP_SDATA_MASK) >> ISSP_SDATA_SHIFT;
}


/*******************************************************************************
* Function Name: ISSP_SDATA_ReadDataReg
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
uint8 ISSP_SDATA_ReadDataReg(void) 
{
    return (ISSP_SDATA_DR & ISSP_SDATA_MASK) >> ISSP_SDATA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ISSP_SDATA_INTSTAT) 

    /*******************************************************************************
    * Function Name: ISSP_SDATA_ClearInterrupt
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
    uint8 ISSP_SDATA_ClearInterrupt(void) 
    {
        return (ISSP_SDATA_INTSTAT & ISSP_SDATA_MASK) >> ISSP_SDATA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
