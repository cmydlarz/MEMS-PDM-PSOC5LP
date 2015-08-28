/*******************************************************************************
* File Name: HwVerPinD.h  
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

#if !defined(CY_PINS_HwVerPinD_H) /* Pins HwVerPinD_H */
#define CY_PINS_HwVerPinD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HwVerPinD_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HwVerPinD__PORT == 15 && ((HwVerPinD__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HwVerPinD_Write(uint8 value) ;
void    HwVerPinD_SetDriveMode(uint8 mode) ;
uint8   HwVerPinD_ReadDataReg(void) ;
uint8   HwVerPinD_Read(void) ;
uint8   HwVerPinD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HwVerPinD_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HwVerPinD_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HwVerPinD_DM_RES_UP          PIN_DM_RES_UP
#define HwVerPinD_DM_RES_DWN         PIN_DM_RES_DWN
#define HwVerPinD_DM_OD_LO           PIN_DM_OD_LO
#define HwVerPinD_DM_OD_HI           PIN_DM_OD_HI
#define HwVerPinD_DM_STRONG          PIN_DM_STRONG
#define HwVerPinD_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HwVerPinD_MASK               HwVerPinD__MASK
#define HwVerPinD_SHIFT              HwVerPinD__SHIFT
#define HwVerPinD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HwVerPinD_PS                     (* (reg8 *) HwVerPinD__PS)
/* Data Register */
#define HwVerPinD_DR                     (* (reg8 *) HwVerPinD__DR)
/* Port Number */
#define HwVerPinD_PRT_NUM                (* (reg8 *) HwVerPinD__PRT) 
/* Connect to Analog Globals */                                                  
#define HwVerPinD_AG                     (* (reg8 *) HwVerPinD__AG)                       
/* Analog MUX bux enable */
#define HwVerPinD_AMUX                   (* (reg8 *) HwVerPinD__AMUX) 
/* Bidirectional Enable */                                                        
#define HwVerPinD_BIE                    (* (reg8 *) HwVerPinD__BIE)
/* Bit-mask for Aliased Register Access */
#define HwVerPinD_BIT_MASK               (* (reg8 *) HwVerPinD__BIT_MASK)
/* Bypass Enable */
#define HwVerPinD_BYP                    (* (reg8 *) HwVerPinD__BYP)
/* Port wide control signals */                                                   
#define HwVerPinD_CTL                    (* (reg8 *) HwVerPinD__CTL)
/* Drive Modes */
#define HwVerPinD_DM0                    (* (reg8 *) HwVerPinD__DM0) 
#define HwVerPinD_DM1                    (* (reg8 *) HwVerPinD__DM1)
#define HwVerPinD_DM2                    (* (reg8 *) HwVerPinD__DM2) 
/* Input Buffer Disable Override */
#define HwVerPinD_INP_DIS                (* (reg8 *) HwVerPinD__INP_DIS)
/* LCD Common or Segment Drive */
#define HwVerPinD_LCD_COM_SEG            (* (reg8 *) HwVerPinD__LCD_COM_SEG)
/* Enable Segment LCD */
#define HwVerPinD_LCD_EN                 (* (reg8 *) HwVerPinD__LCD_EN)
/* Slew Rate Control */
#define HwVerPinD_SLW                    (* (reg8 *) HwVerPinD__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HwVerPinD_PRTDSI__CAPS_SEL       (* (reg8 *) HwVerPinD__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HwVerPinD_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HwVerPinD__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HwVerPinD_PRTDSI__OE_SEL0        (* (reg8 *) HwVerPinD__PRTDSI__OE_SEL0) 
#define HwVerPinD_PRTDSI__OE_SEL1        (* (reg8 *) HwVerPinD__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HwVerPinD_PRTDSI__OUT_SEL0       (* (reg8 *) HwVerPinD__PRTDSI__OUT_SEL0) 
#define HwVerPinD_PRTDSI__OUT_SEL1       (* (reg8 *) HwVerPinD__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HwVerPinD_PRTDSI__SYNC_OUT       (* (reg8 *) HwVerPinD__PRTDSI__SYNC_OUT) 


#if defined(HwVerPinD__INTSTAT)  /* Interrupt Registers */

    #define HwVerPinD_INTSTAT                (* (reg8 *) HwVerPinD__INTSTAT)
    #define HwVerPinD_SNAP                   (* (reg8 *) HwVerPinD__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HwVerPinD_H */


/* [] END OF FILE */
