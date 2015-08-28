/*******************************************************************************
* File Name: VTarget.h  
* Version 1.80
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

#if !defined(CY_PINS_VTarget_H) /* Pins VTarget_H */
#define CY_PINS_VTarget_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VTarget_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VTarget__PORT == 15 && ((VTarget__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VTarget_Write(uint8 value) ;
void    VTarget_SetDriveMode(uint8 mode) ;
uint8   VTarget_ReadDataReg(void) ;
uint8   VTarget_Read(void) ;
uint8   VTarget_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VTarget_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VTarget_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VTarget_DM_RES_UP          PIN_DM_RES_UP
#define VTarget_DM_RES_DWN         PIN_DM_RES_DWN
#define VTarget_DM_OD_LO           PIN_DM_OD_LO
#define VTarget_DM_OD_HI           PIN_DM_OD_HI
#define VTarget_DM_STRONG          PIN_DM_STRONG
#define VTarget_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VTarget_MASK               VTarget__MASK
#define VTarget_SHIFT              VTarget__SHIFT
#define VTarget_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VTarget_PS                     (* (reg8 *) VTarget__PS)
/* Data Register */
#define VTarget_DR                     (* (reg8 *) VTarget__DR)
/* Port Number */
#define VTarget_PRT_NUM                (* (reg8 *) VTarget__PRT) 
/* Connect to Analog Globals */                                                  
#define VTarget_AG                     (* (reg8 *) VTarget__AG)                       
/* Analog MUX bux enable */
#define VTarget_AMUX                   (* (reg8 *) VTarget__AMUX) 
/* Bidirectional Enable */                                                        
#define VTarget_BIE                    (* (reg8 *) VTarget__BIE)
/* Bit-mask for Aliased Register Access */
#define VTarget_BIT_MASK               (* (reg8 *) VTarget__BIT_MASK)
/* Bypass Enable */
#define VTarget_BYP                    (* (reg8 *) VTarget__BYP)
/* Port wide control signals */                                                   
#define VTarget_CTL                    (* (reg8 *) VTarget__CTL)
/* Drive Modes */
#define VTarget_DM0                    (* (reg8 *) VTarget__DM0) 
#define VTarget_DM1                    (* (reg8 *) VTarget__DM1)
#define VTarget_DM2                    (* (reg8 *) VTarget__DM2) 
/* Input Buffer Disable Override */
#define VTarget_INP_DIS                (* (reg8 *) VTarget__INP_DIS)
/* LCD Common or Segment Drive */
#define VTarget_LCD_COM_SEG            (* (reg8 *) VTarget__LCD_COM_SEG)
/* Enable Segment LCD */
#define VTarget_LCD_EN                 (* (reg8 *) VTarget__LCD_EN)
/* Slew Rate Control */
#define VTarget_SLW                    (* (reg8 *) VTarget__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VTarget_PRTDSI__CAPS_SEL       (* (reg8 *) VTarget__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VTarget_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VTarget__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VTarget_PRTDSI__OE_SEL0        (* (reg8 *) VTarget__PRTDSI__OE_SEL0) 
#define VTarget_PRTDSI__OE_SEL1        (* (reg8 *) VTarget__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VTarget_PRTDSI__OUT_SEL0       (* (reg8 *) VTarget__PRTDSI__OUT_SEL0) 
#define VTarget_PRTDSI__OUT_SEL1       (* (reg8 *) VTarget__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VTarget_PRTDSI__SYNC_OUT       (* (reg8 *) VTarget__PRTDSI__SYNC_OUT) 


#if defined(VTarget__INTSTAT)  /* Interrupt Registers */

    #define VTarget_INTSTAT                (* (reg8 *) VTarget__INTSTAT)
    #define VTarget_SNAP                   (* (reg8 *) VTarget__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VTarget_H */


/* [] END OF FILE */
