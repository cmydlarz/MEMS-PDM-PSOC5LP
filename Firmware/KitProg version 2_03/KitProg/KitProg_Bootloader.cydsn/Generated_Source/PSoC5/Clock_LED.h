/*******************************************************************************
* File Name: Clock_LED.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_LED_H)
#define CY_CLOCK_Clock_LED_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_LED_Start(void) ;
void Clock_LED_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_LED_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_LED_StandbyPower(uint8 state) ;
void Clock_LED_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_LED_GetDividerRegister(void) ;
void Clock_LED_SetModeRegister(uint8 modeBitMask) ;
void Clock_LED_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_LED_GetModeRegister(void) ;
void Clock_LED_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_LED_GetSourceRegister(void) ;
#if defined(Clock_LED__CFG3)
void Clock_LED_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_LED_GetPhaseRegister(void) ;
#endif /* defined(Clock_LED__CFG3) */

#define Clock_LED_Enable()                       Clock_LED_Start()
#define Clock_LED_Disable()                      Clock_LED_Stop()
#define Clock_LED_SetDivider(clkDivider)         Clock_LED_SetDividerRegister(clkDivider, 1)
#define Clock_LED_SetDividerValue(clkDivider)    Clock_LED_SetDividerRegister((clkDivider) - 1, 1)
#define Clock_LED_SetMode(clkMode)               Clock_LED_SetModeRegister(clkMode)
#define Clock_LED_SetSource(clkSource)           Clock_LED_SetSourceRegister(clkSource)
#if defined(Clock_LED__CFG3)
#define Clock_LED_SetPhase(clkPhase)             Clock_LED_SetPhaseRegister(clkPhase)
#define Clock_LED_SetPhaseValue(clkPhase)        Clock_LED_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(Clock_LED__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_LED_CLKEN              (* (reg8 *) Clock_LED__PM_ACT_CFG)
#define Clock_LED_CLKEN_PTR          ((reg8 *) Clock_LED__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_LED_CLKSTBY            (* (reg8 *) Clock_LED__PM_STBY_CFG)
#define Clock_LED_CLKSTBY_PTR        ((reg8 *) Clock_LED__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_LED_DIV_LSB            (* (reg8 *) Clock_LED__CFG0)
#define Clock_LED_DIV_LSB_PTR        ((reg8 *) Clock_LED__CFG0)
#define Clock_LED_DIV_PTR            ((reg16 *) Clock_LED__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_LED_DIV_MSB            (* (reg8 *) Clock_LED__CFG1)
#define Clock_LED_DIV_MSB_PTR        ((reg8 *) Clock_LED__CFG1)

/* Mode and source configuration register */
#define Clock_LED_MOD_SRC            (* (reg8 *) Clock_LED__CFG2)
#define Clock_LED_MOD_SRC_PTR        ((reg8 *) Clock_LED__CFG2)

#if defined(Clock_LED__CFG3)
/* Analog clock phase configuration register */
#define Clock_LED_PHASE              (* (reg8 *) Clock_LED__CFG3)
#define Clock_LED_PHASE_PTR          ((reg8 *) Clock_LED__CFG3)
#endif /* defined(Clock_LED__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_LED_CLKEN_MASK         Clock_LED__PM_ACT_MSK
#define Clock_LED_CLKSTBY_MASK       Clock_LED__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_LED_SRC_SEL_MSK        Clock_LED__CFG2_SRC_SEL_MASK
#define Clock_LED_MODE_MASK          (~(Clock_LED_SRC_SEL_MSK))

#if defined(Clock_LED__CFG3)
/* CFG3 phase mask */
#define Clock_LED_PHASE_MASK         Clock_LED__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_LED__CFG3) */

#endif /* CY_CLOCK_Clock_LED_H */


/* [] END OF FILE */
