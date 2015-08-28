/*******************************************************************************
* File Name: ISSP_SDATA.h  
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

#if !defined(CY_PINS_ISSP_SDATA_H) /* Pins ISSP_SDATA_H */
#define CY_PINS_ISSP_SDATA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ISSP_SDATA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ISSP_SDATA__PORT == 15 && ((ISSP_SDATA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ISSP_SDATA_Write(uint8 value) ;
void    ISSP_SDATA_SetDriveMode(uint8 mode) ;
uint8   ISSP_SDATA_ReadDataReg(void) ;
uint8   ISSP_SDATA_Read(void) ;
uint8   ISSP_SDATA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ISSP_SDATA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ISSP_SDATA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ISSP_SDATA_DM_RES_UP          PIN_DM_RES_UP
#define ISSP_SDATA_DM_RES_DWN         PIN_DM_RES_DWN
#define ISSP_SDATA_DM_OD_LO           PIN_DM_OD_LO
#define ISSP_SDATA_DM_OD_HI           PIN_DM_OD_HI
#define ISSP_SDATA_DM_STRONG          PIN_DM_STRONG
#define ISSP_SDATA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ISSP_SDATA_MASK               ISSP_SDATA__MASK
#define ISSP_SDATA_SHIFT              ISSP_SDATA__SHIFT
#define ISSP_SDATA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ISSP_SDATA_PS                     (* (reg8 *) ISSP_SDATA__PS)
/* Data Register */
#define ISSP_SDATA_DR                     (* (reg8 *) ISSP_SDATA__DR)
/* Port Number */
#define ISSP_SDATA_PRT_NUM                (* (reg8 *) ISSP_SDATA__PRT) 
/* Connect to Analog Globals */                                                  
#define ISSP_SDATA_AG                     (* (reg8 *) ISSP_SDATA__AG)                       
/* Analog MUX bux enable */
#define ISSP_SDATA_AMUX                   (* (reg8 *) ISSP_SDATA__AMUX) 
/* Bidirectional Enable */                                                        
#define ISSP_SDATA_BIE                    (* (reg8 *) ISSP_SDATA__BIE)
/* Bit-mask for Aliased Register Access */
#define ISSP_SDATA_BIT_MASK               (* (reg8 *) ISSP_SDATA__BIT_MASK)
/* Bypass Enable */
#define ISSP_SDATA_BYP                    (* (reg8 *) ISSP_SDATA__BYP)
/* Port wide control signals */                                                   
#define ISSP_SDATA_CTL                    (* (reg8 *) ISSP_SDATA__CTL)
/* Drive Modes */
#define ISSP_SDATA_DM0                    (* (reg8 *) ISSP_SDATA__DM0) 
#define ISSP_SDATA_DM1                    (* (reg8 *) ISSP_SDATA__DM1)
#define ISSP_SDATA_DM2                    (* (reg8 *) ISSP_SDATA__DM2) 
/* Input Buffer Disable Override */
#define ISSP_SDATA_INP_DIS                (* (reg8 *) ISSP_SDATA__INP_DIS)
/* LCD Common or Segment Drive */
#define ISSP_SDATA_LCD_COM_SEG            (* (reg8 *) ISSP_SDATA__LCD_COM_SEG)
/* Enable Segment LCD */
#define ISSP_SDATA_LCD_EN                 (* (reg8 *) ISSP_SDATA__LCD_EN)
/* Slew Rate Control */
#define ISSP_SDATA_SLW                    (* (reg8 *) ISSP_SDATA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ISSP_SDATA_PRTDSI__CAPS_SEL       (* (reg8 *) ISSP_SDATA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ISSP_SDATA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ISSP_SDATA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ISSP_SDATA_PRTDSI__OE_SEL0        (* (reg8 *) ISSP_SDATA__PRTDSI__OE_SEL0) 
#define ISSP_SDATA_PRTDSI__OE_SEL1        (* (reg8 *) ISSP_SDATA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ISSP_SDATA_PRTDSI__OUT_SEL0       (* (reg8 *) ISSP_SDATA__PRTDSI__OUT_SEL0) 
#define ISSP_SDATA_PRTDSI__OUT_SEL1       (* (reg8 *) ISSP_SDATA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ISSP_SDATA_PRTDSI__SYNC_OUT       (* (reg8 *) ISSP_SDATA__PRTDSI__SYNC_OUT) 


#if defined(ISSP_SDATA__INTSTAT)  /* Interrupt Registers */

    #define ISSP_SDATA_INTSTAT                (* (reg8 *) ISSP_SDATA__INTSTAT)
    #define ISSP_SDATA_SNAP                   (* (reg8 *) ISSP_SDATA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ISSP_SDATA_H */


/* [] END OF FILE */
