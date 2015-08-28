/*******************************************************************************
* File Name: Pin_VTarget.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_VTarget_H) /* Pins Pin_VTarget_H */
#define CY_PINS_Pin_VTarget_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_VTarget_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_VTarget__PORT == 15 && ((Pin_VTarget__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_VTarget_Write(uint8 value) ;
void    Pin_VTarget_SetDriveMode(uint8 mode) ;
uint8   Pin_VTarget_ReadDataReg(void) ;
uint8   Pin_VTarget_Read(void) ;
uint8   Pin_VTarget_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_VTarget_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_VTarget_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_VTarget_DM_RES_UP          PIN_DM_RES_UP
#define Pin_VTarget_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_VTarget_DM_OD_LO           PIN_DM_OD_LO
#define Pin_VTarget_DM_OD_HI           PIN_DM_OD_HI
#define Pin_VTarget_DM_STRONG          PIN_DM_STRONG
#define Pin_VTarget_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_VTarget_MASK               Pin_VTarget__MASK
#define Pin_VTarget_SHIFT              Pin_VTarget__SHIFT
#define Pin_VTarget_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_VTarget_PS                     (* (reg8 *) Pin_VTarget__PS)
/* Data Register */
#define Pin_VTarget_DR                     (* (reg8 *) Pin_VTarget__DR)
/* Port Number */
#define Pin_VTarget_PRT_NUM                (* (reg8 *) Pin_VTarget__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_VTarget_AG                     (* (reg8 *) Pin_VTarget__AG)                       
/* Analog MUX bux enable */
#define Pin_VTarget_AMUX                   (* (reg8 *) Pin_VTarget__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_VTarget_BIE                    (* (reg8 *) Pin_VTarget__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_VTarget_BIT_MASK               (* (reg8 *) Pin_VTarget__BIT_MASK)
/* Bypass Enable */
#define Pin_VTarget_BYP                    (* (reg8 *) Pin_VTarget__BYP)
/* Port wide control signals */                                                   
#define Pin_VTarget_CTL                    (* (reg8 *) Pin_VTarget__CTL)
/* Drive Modes */
#define Pin_VTarget_DM0                    (* (reg8 *) Pin_VTarget__DM0) 
#define Pin_VTarget_DM1                    (* (reg8 *) Pin_VTarget__DM1)
#define Pin_VTarget_DM2                    (* (reg8 *) Pin_VTarget__DM2) 
/* Input Buffer Disable Override */
#define Pin_VTarget_INP_DIS                (* (reg8 *) Pin_VTarget__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_VTarget_LCD_COM_SEG            (* (reg8 *) Pin_VTarget__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_VTarget_LCD_EN                 (* (reg8 *) Pin_VTarget__LCD_EN)
/* Slew Rate Control */
#define Pin_VTarget_SLW                    (* (reg8 *) Pin_VTarget__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_VTarget_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_VTarget__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_VTarget_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_VTarget__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_VTarget_PRTDSI__OE_SEL0        (* (reg8 *) Pin_VTarget__PRTDSI__OE_SEL0) 
#define Pin_VTarget_PRTDSI__OE_SEL1        (* (reg8 *) Pin_VTarget__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_VTarget_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_VTarget__PRTDSI__OUT_SEL0) 
#define Pin_VTarget_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_VTarget__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_VTarget_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_VTarget__PRTDSI__SYNC_OUT) 


#if defined(Pin_VTarget__INTSTAT)  /* Interrupt Registers */

    #define Pin_VTarget_INTSTAT                (* (reg8 *) Pin_VTarget__INTSTAT)
    #define Pin_VTarget_SNAP                   (* (reg8 *) Pin_VTarget__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_VTarget_H */


/* [] END OF FILE */
