/*******************************************************************************
* File Name: Outv.h  
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

#if !defined(CY_PINS_Outv_H) /* Pins Outv_H */
#define CY_PINS_Outv_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Outv_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Outv__PORT == 15 && ((Outv__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Outv_Write(uint8 value) ;
void    Outv_SetDriveMode(uint8 mode) ;
uint8   Outv_ReadDataReg(void) ;
uint8   Outv_Read(void) ;
uint8   Outv_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Outv_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Outv_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Outv_DM_RES_UP          PIN_DM_RES_UP
#define Outv_DM_RES_DWN         PIN_DM_RES_DWN
#define Outv_DM_OD_LO           PIN_DM_OD_LO
#define Outv_DM_OD_HI           PIN_DM_OD_HI
#define Outv_DM_STRONG          PIN_DM_STRONG
#define Outv_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Outv_MASK               Outv__MASK
#define Outv_SHIFT              Outv__SHIFT
#define Outv_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Outv_PS                     (* (reg8 *) Outv__PS)
/* Data Register */
#define Outv_DR                     (* (reg8 *) Outv__DR)
/* Port Number */
#define Outv_PRT_NUM                (* (reg8 *) Outv__PRT) 
/* Connect to Analog Globals */                                                  
#define Outv_AG                     (* (reg8 *) Outv__AG)                       
/* Analog MUX bux enable */
#define Outv_AMUX                   (* (reg8 *) Outv__AMUX) 
/* Bidirectional Enable */                                                        
#define Outv_BIE                    (* (reg8 *) Outv__BIE)
/* Bit-mask for Aliased Register Access */
#define Outv_BIT_MASK               (* (reg8 *) Outv__BIT_MASK)
/* Bypass Enable */
#define Outv_BYP                    (* (reg8 *) Outv__BYP)
/* Port wide control signals */                                                   
#define Outv_CTL                    (* (reg8 *) Outv__CTL)
/* Drive Modes */
#define Outv_DM0                    (* (reg8 *) Outv__DM0) 
#define Outv_DM1                    (* (reg8 *) Outv__DM1)
#define Outv_DM2                    (* (reg8 *) Outv__DM2) 
/* Input Buffer Disable Override */
#define Outv_INP_DIS                (* (reg8 *) Outv__INP_DIS)
/* LCD Common or Segment Drive */
#define Outv_LCD_COM_SEG            (* (reg8 *) Outv__LCD_COM_SEG)
/* Enable Segment LCD */
#define Outv_LCD_EN                 (* (reg8 *) Outv__LCD_EN)
/* Slew Rate Control */
#define Outv_SLW                    (* (reg8 *) Outv__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Outv_PRTDSI__CAPS_SEL       (* (reg8 *) Outv__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Outv_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Outv__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Outv_PRTDSI__OE_SEL0        (* (reg8 *) Outv__PRTDSI__OE_SEL0) 
#define Outv_PRTDSI__OE_SEL1        (* (reg8 *) Outv__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Outv_PRTDSI__OUT_SEL0       (* (reg8 *) Outv__PRTDSI__OUT_SEL0) 
#define Outv_PRTDSI__OUT_SEL1       (* (reg8 *) Outv__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Outv_PRTDSI__SYNC_OUT       (* (reg8 *) Outv__PRTDSI__SYNC_OUT) 


#if defined(Outv__INTSTAT)  /* Interrupt Registers */

    #define Outv_INTSTAT                (* (reg8 *) Outv__INTSTAT)
    #define Outv_SNAP                   (* (reg8 *) Outv__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Outv_H */


/* [] END OF FILE */
