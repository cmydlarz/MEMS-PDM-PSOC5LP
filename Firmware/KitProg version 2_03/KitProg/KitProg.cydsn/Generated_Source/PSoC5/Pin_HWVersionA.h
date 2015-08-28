/*******************************************************************************
* File Name: Pin_HWVersionA.h  
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

#if !defined(CY_PINS_Pin_HWVersionA_H) /* Pins Pin_HWVersionA_H */
#define CY_PINS_Pin_HWVersionA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_HWVersionA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_HWVersionA__PORT == 15 && ((Pin_HWVersionA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_HWVersionA_Write(uint8 value) ;
void    Pin_HWVersionA_SetDriveMode(uint8 mode) ;
uint8   Pin_HWVersionA_ReadDataReg(void) ;
uint8   Pin_HWVersionA_Read(void) ;
uint8   Pin_HWVersionA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_HWVersionA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_HWVersionA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_HWVersionA_DM_RES_UP          PIN_DM_RES_UP
#define Pin_HWVersionA_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_HWVersionA_DM_OD_LO           PIN_DM_OD_LO
#define Pin_HWVersionA_DM_OD_HI           PIN_DM_OD_HI
#define Pin_HWVersionA_DM_STRONG          PIN_DM_STRONG
#define Pin_HWVersionA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_HWVersionA_MASK               Pin_HWVersionA__MASK
#define Pin_HWVersionA_SHIFT              Pin_HWVersionA__SHIFT
#define Pin_HWVersionA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_HWVersionA_PS                     (* (reg8 *) Pin_HWVersionA__PS)
/* Data Register */
#define Pin_HWVersionA_DR                     (* (reg8 *) Pin_HWVersionA__DR)
/* Port Number */
#define Pin_HWVersionA_PRT_NUM                (* (reg8 *) Pin_HWVersionA__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_HWVersionA_AG                     (* (reg8 *) Pin_HWVersionA__AG)                       
/* Analog MUX bux enable */
#define Pin_HWVersionA_AMUX                   (* (reg8 *) Pin_HWVersionA__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_HWVersionA_BIE                    (* (reg8 *) Pin_HWVersionA__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_HWVersionA_BIT_MASK               (* (reg8 *) Pin_HWVersionA__BIT_MASK)
/* Bypass Enable */
#define Pin_HWVersionA_BYP                    (* (reg8 *) Pin_HWVersionA__BYP)
/* Port wide control signals */                                                   
#define Pin_HWVersionA_CTL                    (* (reg8 *) Pin_HWVersionA__CTL)
/* Drive Modes */
#define Pin_HWVersionA_DM0                    (* (reg8 *) Pin_HWVersionA__DM0) 
#define Pin_HWVersionA_DM1                    (* (reg8 *) Pin_HWVersionA__DM1)
#define Pin_HWVersionA_DM2                    (* (reg8 *) Pin_HWVersionA__DM2) 
/* Input Buffer Disable Override */
#define Pin_HWVersionA_INP_DIS                (* (reg8 *) Pin_HWVersionA__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_HWVersionA_LCD_COM_SEG            (* (reg8 *) Pin_HWVersionA__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_HWVersionA_LCD_EN                 (* (reg8 *) Pin_HWVersionA__LCD_EN)
/* Slew Rate Control */
#define Pin_HWVersionA_SLW                    (* (reg8 *) Pin_HWVersionA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_HWVersionA_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_HWVersionA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_HWVersionA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_HWVersionA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_HWVersionA_PRTDSI__OE_SEL0        (* (reg8 *) Pin_HWVersionA__PRTDSI__OE_SEL0) 
#define Pin_HWVersionA_PRTDSI__OE_SEL1        (* (reg8 *) Pin_HWVersionA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_HWVersionA_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_HWVersionA__PRTDSI__OUT_SEL0) 
#define Pin_HWVersionA_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_HWVersionA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_HWVersionA_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_HWVersionA__PRTDSI__SYNC_OUT) 


#if defined(Pin_HWVersionA__INTSTAT)  /* Interrupt Registers */

    #define Pin_HWVersionA_INTSTAT                (* (reg8 *) Pin_HWVersionA__INTSTAT)
    #define Pin_HWVersionA_SNAP                   (* (reg8 *) Pin_HWVersionA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_HWVersionA_H */


/* [] END OF FILE */
