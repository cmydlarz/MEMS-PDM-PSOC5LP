/*******************************************************************************
* File Name: HwVerPinA.h  
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

#if !defined(CY_PINS_HwVerPinA_H) /* Pins HwVerPinA_H */
#define CY_PINS_HwVerPinA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HwVerPinA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HwVerPinA__PORT == 15 && ((HwVerPinA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HwVerPinA_Write(uint8 value) ;
void    HwVerPinA_SetDriveMode(uint8 mode) ;
uint8   HwVerPinA_ReadDataReg(void) ;
uint8   HwVerPinA_Read(void) ;
uint8   HwVerPinA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HwVerPinA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HwVerPinA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HwVerPinA_DM_RES_UP          PIN_DM_RES_UP
#define HwVerPinA_DM_RES_DWN         PIN_DM_RES_DWN
#define HwVerPinA_DM_OD_LO           PIN_DM_OD_LO
#define HwVerPinA_DM_OD_HI           PIN_DM_OD_HI
#define HwVerPinA_DM_STRONG          PIN_DM_STRONG
#define HwVerPinA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HwVerPinA_MASK               HwVerPinA__MASK
#define HwVerPinA_SHIFT              HwVerPinA__SHIFT
#define HwVerPinA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HwVerPinA_PS                     (* (reg8 *) HwVerPinA__PS)
/* Data Register */
#define HwVerPinA_DR                     (* (reg8 *) HwVerPinA__DR)
/* Port Number */
#define HwVerPinA_PRT_NUM                (* (reg8 *) HwVerPinA__PRT) 
/* Connect to Analog Globals */                                                  
#define HwVerPinA_AG                     (* (reg8 *) HwVerPinA__AG)                       
/* Analog MUX bux enable */
#define HwVerPinA_AMUX                   (* (reg8 *) HwVerPinA__AMUX) 
/* Bidirectional Enable */                                                        
#define HwVerPinA_BIE                    (* (reg8 *) HwVerPinA__BIE)
/* Bit-mask for Aliased Register Access */
#define HwVerPinA_BIT_MASK               (* (reg8 *) HwVerPinA__BIT_MASK)
/* Bypass Enable */
#define HwVerPinA_BYP                    (* (reg8 *) HwVerPinA__BYP)
/* Port wide control signals */                                                   
#define HwVerPinA_CTL                    (* (reg8 *) HwVerPinA__CTL)
/* Drive Modes */
#define HwVerPinA_DM0                    (* (reg8 *) HwVerPinA__DM0) 
#define HwVerPinA_DM1                    (* (reg8 *) HwVerPinA__DM1)
#define HwVerPinA_DM2                    (* (reg8 *) HwVerPinA__DM2) 
/* Input Buffer Disable Override */
#define HwVerPinA_INP_DIS                (* (reg8 *) HwVerPinA__INP_DIS)
/* LCD Common or Segment Drive */
#define HwVerPinA_LCD_COM_SEG            (* (reg8 *) HwVerPinA__LCD_COM_SEG)
/* Enable Segment LCD */
#define HwVerPinA_LCD_EN                 (* (reg8 *) HwVerPinA__LCD_EN)
/* Slew Rate Control */
#define HwVerPinA_SLW                    (* (reg8 *) HwVerPinA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HwVerPinA_PRTDSI__CAPS_SEL       (* (reg8 *) HwVerPinA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HwVerPinA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HwVerPinA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HwVerPinA_PRTDSI__OE_SEL0        (* (reg8 *) HwVerPinA__PRTDSI__OE_SEL0) 
#define HwVerPinA_PRTDSI__OE_SEL1        (* (reg8 *) HwVerPinA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HwVerPinA_PRTDSI__OUT_SEL0       (* (reg8 *) HwVerPinA__PRTDSI__OUT_SEL0) 
#define HwVerPinA_PRTDSI__OUT_SEL1       (* (reg8 *) HwVerPinA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HwVerPinA_PRTDSI__SYNC_OUT       (* (reg8 *) HwVerPinA__PRTDSI__SYNC_OUT) 


#if defined(HwVerPinA__INTSTAT)  /* Interrupt Registers */

    #define HwVerPinA_INTSTAT                (* (reg8 *) HwVerPinA__INTSTAT)
    #define HwVerPinA_SNAP                   (* (reg8 *) HwVerPinA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HwVerPinA_H */


/* [] END OF FILE */
