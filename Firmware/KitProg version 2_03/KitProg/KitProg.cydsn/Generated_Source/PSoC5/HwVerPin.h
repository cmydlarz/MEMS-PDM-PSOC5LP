/*******************************************************************************
* File Name: HwVerPin.h  
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

#if !defined(CY_PINS_HwVerPin_H) /* Pins HwVerPin_H */
#define CY_PINS_HwVerPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HwVerPin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HwVerPin__PORT == 15 && ((HwVerPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HwVerPin_Write(uint8 value) ;
void    HwVerPin_SetDriveMode(uint8 mode) ;
uint8   HwVerPin_ReadDataReg(void) ;
uint8   HwVerPin_Read(void) ;
uint8   HwVerPin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HwVerPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HwVerPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HwVerPin_DM_RES_UP          PIN_DM_RES_UP
#define HwVerPin_DM_RES_DWN         PIN_DM_RES_DWN
#define HwVerPin_DM_OD_LO           PIN_DM_OD_LO
#define HwVerPin_DM_OD_HI           PIN_DM_OD_HI
#define HwVerPin_DM_STRONG          PIN_DM_STRONG
#define HwVerPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HwVerPin_MASK               HwVerPin__MASK
#define HwVerPin_SHIFT              HwVerPin__SHIFT
#define HwVerPin_WIDTH              6u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HwVerPin_PS                     (* (reg8 *) HwVerPin__PS)
/* Data Register */
#define HwVerPin_DR                     (* (reg8 *) HwVerPin__DR)
/* Port Number */
#define HwVerPin_PRT_NUM                (* (reg8 *) HwVerPin__PRT) 
/* Connect to Analog Globals */                                                  
#define HwVerPin_AG                     (* (reg8 *) HwVerPin__AG)                       
/* Analog MUX bux enable */
#define HwVerPin_AMUX                   (* (reg8 *) HwVerPin__AMUX) 
/* Bidirectional Enable */                                                        
#define HwVerPin_BIE                    (* (reg8 *) HwVerPin__BIE)
/* Bit-mask for Aliased Register Access */
#define HwVerPin_BIT_MASK               (* (reg8 *) HwVerPin__BIT_MASK)
/* Bypass Enable */
#define HwVerPin_BYP                    (* (reg8 *) HwVerPin__BYP)
/* Port wide control signals */                                                   
#define HwVerPin_CTL                    (* (reg8 *) HwVerPin__CTL)
/* Drive Modes */
#define HwVerPin_DM0                    (* (reg8 *) HwVerPin__DM0) 
#define HwVerPin_DM1                    (* (reg8 *) HwVerPin__DM1)
#define HwVerPin_DM2                    (* (reg8 *) HwVerPin__DM2) 
/* Input Buffer Disable Override */
#define HwVerPin_INP_DIS                (* (reg8 *) HwVerPin__INP_DIS)
/* LCD Common or Segment Drive */
#define HwVerPin_LCD_COM_SEG            (* (reg8 *) HwVerPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define HwVerPin_LCD_EN                 (* (reg8 *) HwVerPin__LCD_EN)
/* Slew Rate Control */
#define HwVerPin_SLW                    (* (reg8 *) HwVerPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HwVerPin_PRTDSI__CAPS_SEL       (* (reg8 *) HwVerPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HwVerPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HwVerPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HwVerPin_PRTDSI__OE_SEL0        (* (reg8 *) HwVerPin__PRTDSI__OE_SEL0) 
#define HwVerPin_PRTDSI__OE_SEL1        (* (reg8 *) HwVerPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HwVerPin_PRTDSI__OUT_SEL0       (* (reg8 *) HwVerPin__PRTDSI__OUT_SEL0) 
#define HwVerPin_PRTDSI__OUT_SEL1       (* (reg8 *) HwVerPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HwVerPin_PRTDSI__SYNC_OUT       (* (reg8 *) HwVerPin__PRTDSI__SYNC_OUT) 


#if defined(HwVerPin__INTSTAT)  /* Interrupt Registers */

    #define HwVerPin_INTSTAT                (* (reg8 *) HwVerPin__INTSTAT)
    #define HwVerPin_SNAP                   (* (reg8 *) HwVerPin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HwVerPin_H */


/* [] END OF FILE */
