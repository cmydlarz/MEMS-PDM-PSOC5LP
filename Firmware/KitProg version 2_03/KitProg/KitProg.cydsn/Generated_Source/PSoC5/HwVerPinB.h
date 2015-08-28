/*******************************************************************************
* File Name: HwVerPinB.h  
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

#if !defined(CY_PINS_HwVerPinB_H) /* Pins HwVerPinB_H */
#define CY_PINS_HwVerPinB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HwVerPinB_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HwVerPinB__PORT == 15 && ((HwVerPinB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HwVerPinB_Write(uint8 value) ;
void    HwVerPinB_SetDriveMode(uint8 mode) ;
uint8   HwVerPinB_ReadDataReg(void) ;
uint8   HwVerPinB_Read(void) ;
uint8   HwVerPinB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HwVerPinB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HwVerPinB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HwVerPinB_DM_RES_UP          PIN_DM_RES_UP
#define HwVerPinB_DM_RES_DWN         PIN_DM_RES_DWN
#define HwVerPinB_DM_OD_LO           PIN_DM_OD_LO
#define HwVerPinB_DM_OD_HI           PIN_DM_OD_HI
#define HwVerPinB_DM_STRONG          PIN_DM_STRONG
#define HwVerPinB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HwVerPinB_MASK               HwVerPinB__MASK
#define HwVerPinB_SHIFT              HwVerPinB__SHIFT
#define HwVerPinB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HwVerPinB_PS                     (* (reg8 *) HwVerPinB__PS)
/* Data Register */
#define HwVerPinB_DR                     (* (reg8 *) HwVerPinB__DR)
/* Port Number */
#define HwVerPinB_PRT_NUM                (* (reg8 *) HwVerPinB__PRT) 
/* Connect to Analog Globals */                                                  
#define HwVerPinB_AG                     (* (reg8 *) HwVerPinB__AG)                       
/* Analog MUX bux enable */
#define HwVerPinB_AMUX                   (* (reg8 *) HwVerPinB__AMUX) 
/* Bidirectional Enable */                                                        
#define HwVerPinB_BIE                    (* (reg8 *) HwVerPinB__BIE)
/* Bit-mask for Aliased Register Access */
#define HwVerPinB_BIT_MASK               (* (reg8 *) HwVerPinB__BIT_MASK)
/* Bypass Enable */
#define HwVerPinB_BYP                    (* (reg8 *) HwVerPinB__BYP)
/* Port wide control signals */                                                   
#define HwVerPinB_CTL                    (* (reg8 *) HwVerPinB__CTL)
/* Drive Modes */
#define HwVerPinB_DM0                    (* (reg8 *) HwVerPinB__DM0) 
#define HwVerPinB_DM1                    (* (reg8 *) HwVerPinB__DM1)
#define HwVerPinB_DM2                    (* (reg8 *) HwVerPinB__DM2) 
/* Input Buffer Disable Override */
#define HwVerPinB_INP_DIS                (* (reg8 *) HwVerPinB__INP_DIS)
/* LCD Common or Segment Drive */
#define HwVerPinB_LCD_COM_SEG            (* (reg8 *) HwVerPinB__LCD_COM_SEG)
/* Enable Segment LCD */
#define HwVerPinB_LCD_EN                 (* (reg8 *) HwVerPinB__LCD_EN)
/* Slew Rate Control */
#define HwVerPinB_SLW                    (* (reg8 *) HwVerPinB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HwVerPinB_PRTDSI__CAPS_SEL       (* (reg8 *) HwVerPinB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HwVerPinB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HwVerPinB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HwVerPinB_PRTDSI__OE_SEL0        (* (reg8 *) HwVerPinB__PRTDSI__OE_SEL0) 
#define HwVerPinB_PRTDSI__OE_SEL1        (* (reg8 *) HwVerPinB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HwVerPinB_PRTDSI__OUT_SEL0       (* (reg8 *) HwVerPinB__PRTDSI__OUT_SEL0) 
#define HwVerPinB_PRTDSI__OUT_SEL1       (* (reg8 *) HwVerPinB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HwVerPinB_PRTDSI__SYNC_OUT       (* (reg8 *) HwVerPinB__PRTDSI__SYNC_OUT) 


#if defined(HwVerPinB__INTSTAT)  /* Interrupt Registers */

    #define HwVerPinB_INTSTAT                (* (reg8 *) HwVerPinB__INTSTAT)
    #define HwVerPinB_SNAP                   (* (reg8 *) HwVerPinB__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HwVerPinB_H */


/* [] END OF FILE */
