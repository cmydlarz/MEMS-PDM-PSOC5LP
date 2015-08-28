/*******************************************************************************
* File Name: Pin_HWType.h  
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

#if !defined(CY_PINS_Pin_HWType_H) /* Pins Pin_HWType_H */
#define CY_PINS_Pin_HWType_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_HWType_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_HWType__PORT == 15 && ((Pin_HWType__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_HWType_Write(uint8 value) ;
void    Pin_HWType_SetDriveMode(uint8 mode) ;
uint8   Pin_HWType_ReadDataReg(void) ;
uint8   Pin_HWType_Read(void) ;
uint8   Pin_HWType_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_HWType_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_HWType_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_HWType_DM_RES_UP          PIN_DM_RES_UP
#define Pin_HWType_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_HWType_DM_OD_LO           PIN_DM_OD_LO
#define Pin_HWType_DM_OD_HI           PIN_DM_OD_HI
#define Pin_HWType_DM_STRONG          PIN_DM_STRONG
#define Pin_HWType_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_HWType_MASK               Pin_HWType__MASK
#define Pin_HWType_SHIFT              Pin_HWType__SHIFT
#define Pin_HWType_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_HWType_PS                     (* (reg8 *) Pin_HWType__PS)
/* Data Register */
#define Pin_HWType_DR                     (* (reg8 *) Pin_HWType__DR)
/* Port Number */
#define Pin_HWType_PRT_NUM                (* (reg8 *) Pin_HWType__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_HWType_AG                     (* (reg8 *) Pin_HWType__AG)                       
/* Analog MUX bux enable */
#define Pin_HWType_AMUX                   (* (reg8 *) Pin_HWType__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_HWType_BIE                    (* (reg8 *) Pin_HWType__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_HWType_BIT_MASK               (* (reg8 *) Pin_HWType__BIT_MASK)
/* Bypass Enable */
#define Pin_HWType_BYP                    (* (reg8 *) Pin_HWType__BYP)
/* Port wide control signals */                                                   
#define Pin_HWType_CTL                    (* (reg8 *) Pin_HWType__CTL)
/* Drive Modes */
#define Pin_HWType_DM0                    (* (reg8 *) Pin_HWType__DM0) 
#define Pin_HWType_DM1                    (* (reg8 *) Pin_HWType__DM1)
#define Pin_HWType_DM2                    (* (reg8 *) Pin_HWType__DM2) 
/* Input Buffer Disable Override */
#define Pin_HWType_INP_DIS                (* (reg8 *) Pin_HWType__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_HWType_LCD_COM_SEG            (* (reg8 *) Pin_HWType__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_HWType_LCD_EN                 (* (reg8 *) Pin_HWType__LCD_EN)
/* Slew Rate Control */
#define Pin_HWType_SLW                    (* (reg8 *) Pin_HWType__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_HWType_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_HWType__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_HWType_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_HWType__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_HWType_PRTDSI__OE_SEL0        (* (reg8 *) Pin_HWType__PRTDSI__OE_SEL0) 
#define Pin_HWType_PRTDSI__OE_SEL1        (* (reg8 *) Pin_HWType__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_HWType_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_HWType__PRTDSI__OUT_SEL0) 
#define Pin_HWType_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_HWType__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_HWType_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_HWType__PRTDSI__SYNC_OUT) 


#if defined(Pin_HWType__INTSTAT)  /* Interrupt Registers */

    #define Pin_HWType_INTSTAT                (* (reg8 *) Pin_HWType__INTSTAT)
    #define Pin_HWType_SNAP                   (* (reg8 *) Pin_HWType__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_HWType_H */


/* [] END OF FILE */
