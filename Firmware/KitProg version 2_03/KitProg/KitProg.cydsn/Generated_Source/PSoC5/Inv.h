/*******************************************************************************
* File Name: Inv.h  
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

#if !defined(CY_PINS_Inv_H) /* Pins Inv_H */
#define CY_PINS_Inv_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Inv_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Inv__PORT == 15 && ((Inv__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Inv_Write(uint8 value) ;
void    Inv_SetDriveMode(uint8 mode) ;
uint8   Inv_ReadDataReg(void) ;
uint8   Inv_Read(void) ;
uint8   Inv_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Inv_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Inv_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Inv_DM_RES_UP          PIN_DM_RES_UP
#define Inv_DM_RES_DWN         PIN_DM_RES_DWN
#define Inv_DM_OD_LO           PIN_DM_OD_LO
#define Inv_DM_OD_HI           PIN_DM_OD_HI
#define Inv_DM_STRONG          PIN_DM_STRONG
#define Inv_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Inv_MASK               Inv__MASK
#define Inv_SHIFT              Inv__SHIFT
#define Inv_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Inv_PS                     (* (reg8 *) Inv__PS)
/* Data Register */
#define Inv_DR                     (* (reg8 *) Inv__DR)
/* Port Number */
#define Inv_PRT_NUM                (* (reg8 *) Inv__PRT) 
/* Connect to Analog Globals */                                                  
#define Inv_AG                     (* (reg8 *) Inv__AG)                       
/* Analog MUX bux enable */
#define Inv_AMUX                   (* (reg8 *) Inv__AMUX) 
/* Bidirectional Enable */                                                        
#define Inv_BIE                    (* (reg8 *) Inv__BIE)
/* Bit-mask for Aliased Register Access */
#define Inv_BIT_MASK               (* (reg8 *) Inv__BIT_MASK)
/* Bypass Enable */
#define Inv_BYP                    (* (reg8 *) Inv__BYP)
/* Port wide control signals */                                                   
#define Inv_CTL                    (* (reg8 *) Inv__CTL)
/* Drive Modes */
#define Inv_DM0                    (* (reg8 *) Inv__DM0) 
#define Inv_DM1                    (* (reg8 *) Inv__DM1)
#define Inv_DM2                    (* (reg8 *) Inv__DM2) 
/* Input Buffer Disable Override */
#define Inv_INP_DIS                (* (reg8 *) Inv__INP_DIS)
/* LCD Common or Segment Drive */
#define Inv_LCD_COM_SEG            (* (reg8 *) Inv__LCD_COM_SEG)
/* Enable Segment LCD */
#define Inv_LCD_EN                 (* (reg8 *) Inv__LCD_EN)
/* Slew Rate Control */
#define Inv_SLW                    (* (reg8 *) Inv__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Inv_PRTDSI__CAPS_SEL       (* (reg8 *) Inv__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Inv_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Inv__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Inv_PRTDSI__OE_SEL0        (* (reg8 *) Inv__PRTDSI__OE_SEL0) 
#define Inv_PRTDSI__OE_SEL1        (* (reg8 *) Inv__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Inv_PRTDSI__OUT_SEL0       (* (reg8 *) Inv__PRTDSI__OUT_SEL0) 
#define Inv_PRTDSI__OUT_SEL1       (* (reg8 *) Inv__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Inv_PRTDSI__SYNC_OUT       (* (reg8 *) Inv__PRTDSI__SYNC_OUT) 


#if defined(Inv__INTSTAT)  /* Interrupt Registers */

    #define Inv_INTSTAT                (* (reg8 *) Inv__INTSTAT)
    #define Inv_SNAP                   (* (reg8 *) Inv__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Inv_H */


/* [] END OF FILE */
