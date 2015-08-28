/*******************************************************************************
* File Name: Pin_HWVersion.h  
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

#if !defined(CY_PINS_Pin_HWVersion_H) /* Pins Pin_HWVersion_H */
#define CY_PINS_Pin_HWVersion_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_HWVersion_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_HWVersion__PORT == 15 && ((Pin_HWVersion__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_HWVersion_Write(uint8 value) ;
void    Pin_HWVersion_SetDriveMode(uint8 mode) ;
uint8   Pin_HWVersion_ReadDataReg(void) ;
uint8   Pin_HWVersion_Read(void) ;
uint8   Pin_HWVersion_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_HWVersion_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_HWVersion_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_HWVersion_DM_RES_UP          PIN_DM_RES_UP
#define Pin_HWVersion_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_HWVersion_DM_OD_LO           PIN_DM_OD_LO
#define Pin_HWVersion_DM_OD_HI           PIN_DM_OD_HI
#define Pin_HWVersion_DM_STRONG          PIN_DM_STRONG
#define Pin_HWVersion_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_HWVersion_MASK               Pin_HWVersion__MASK
#define Pin_HWVersion_SHIFT              Pin_HWVersion__SHIFT
#define Pin_HWVersion_WIDTH              6u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_HWVersion_PS                     (* (reg8 *) Pin_HWVersion__PS)
/* Data Register */
#define Pin_HWVersion_DR                     (* (reg8 *) Pin_HWVersion__DR)
/* Port Number */
#define Pin_HWVersion_PRT_NUM                (* (reg8 *) Pin_HWVersion__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_HWVersion_AG                     (* (reg8 *) Pin_HWVersion__AG)                       
/* Analog MUX bux enable */
#define Pin_HWVersion_AMUX                   (* (reg8 *) Pin_HWVersion__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_HWVersion_BIE                    (* (reg8 *) Pin_HWVersion__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_HWVersion_BIT_MASK               (* (reg8 *) Pin_HWVersion__BIT_MASK)
/* Bypass Enable */
#define Pin_HWVersion_BYP                    (* (reg8 *) Pin_HWVersion__BYP)
/* Port wide control signals */                                                   
#define Pin_HWVersion_CTL                    (* (reg8 *) Pin_HWVersion__CTL)
/* Drive Modes */
#define Pin_HWVersion_DM0                    (* (reg8 *) Pin_HWVersion__DM0) 
#define Pin_HWVersion_DM1                    (* (reg8 *) Pin_HWVersion__DM1)
#define Pin_HWVersion_DM2                    (* (reg8 *) Pin_HWVersion__DM2) 
/* Input Buffer Disable Override */
#define Pin_HWVersion_INP_DIS                (* (reg8 *) Pin_HWVersion__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_HWVersion_LCD_COM_SEG            (* (reg8 *) Pin_HWVersion__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_HWVersion_LCD_EN                 (* (reg8 *) Pin_HWVersion__LCD_EN)
/* Slew Rate Control */
#define Pin_HWVersion_SLW                    (* (reg8 *) Pin_HWVersion__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_HWVersion_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_HWVersion__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_HWVersion_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_HWVersion__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_HWVersion_PRTDSI__OE_SEL0        (* (reg8 *) Pin_HWVersion__PRTDSI__OE_SEL0) 
#define Pin_HWVersion_PRTDSI__OE_SEL1        (* (reg8 *) Pin_HWVersion__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_HWVersion_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_HWVersion__PRTDSI__OUT_SEL0) 
#define Pin_HWVersion_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_HWVersion__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_HWVersion_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_HWVersion__PRTDSI__SYNC_OUT) 


#if defined(Pin_HWVersion__INTSTAT)  /* Interrupt Registers */

    #define Pin_HWVersion_INTSTAT                (* (reg8 *) Pin_HWVersion__INTSTAT)
    #define Pin_HWVersion_SNAP                   (* (reg8 *) Pin_HWVersion__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_HWVersion_H */


/* [] END OF FILE */
