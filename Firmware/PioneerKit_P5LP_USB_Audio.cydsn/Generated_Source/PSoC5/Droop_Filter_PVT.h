/*******************************************************************************
* File Name: Droop_Filter_PVT.h
* Version 2.10
*
* Description:
*  This header file contains internal definitions for the FILT component.
*  It must be included after Droop_Filter.h.
*
* Note:
* 
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_FILTER_Droop_Filter_PVT_H) /* FILT Header File */
#define Droop_Filter_PVT_H

#include "Droop_Filter.H"


/*******************************************************************************
* FILT component internal function prototypes.
*******************************************************************************/

extern void Droop_Filter_SetInterruptMode(uint8 events) ;
extern void Droop_Filter_SetDMAMode(uint8 events) ;


/*******************************************************************************
* FILT component internal variables.
*******************************************************************************/

extern const uint8 CYCODE Droop_Filter_control[]; 
extern const uint8 CYCODE Droop_Filter_data_a[];
extern const uint8 CYCODE Droop_Filter_data_b[];
extern const uint8 CYCODE Droop_Filter_cfsm[];
extern const uint8 CYCODE Droop_Filter_acu[];


/*******************************************************************************
* FILT component internal constants.
*******************************************************************************/

/* Parameters */
#define Droop_Filter_INIT_INTERRUPT_MODE    (0u)
#define Droop_Filter_INIT_DMA_MODE          (1u)
#define Droop_Filter_INIT_COHER             (0x00u)
#define Droop_Filter_INIT_DALIGN            (0x0Fu)

/* RAM memory map offsets */
#define Droop_Filter_DA_RAM                 (void XDATA *) (Droop_Filter_DFB__DPA_SRAM_DATA)
#define Droop_Filter_DB_RAM                 (void XDATA *) (Droop_Filter_DFB__DPB_SRAM_DATA)
#define Droop_Filter_CSA_RAM                (void XDATA *) (Droop_Filter_DFB__CSA_SRAM_DATA)
#define Droop_Filter_CSB_RAM                (void XDATA *) (Droop_Filter_DFB__CSB_SRAM_DATA)
#define Droop_Filter_CFSM_RAM               (void XDATA *) (Droop_Filter_DFB__FSM_SRAM_DATA)
#define Droop_Filter_ACU_RAM                (void XDATA *) (Droop_Filter_DFB__ACU_SRAM_DATA)

/* RAM register space sizes in bytes. */
#define Droop_Filter_DA_RAM_SIZE            (0x200u)
#define Droop_Filter_DB_RAM_SIZE            (0x200u)
#define Droop_Filter_CSA_RAM_SIZE           (0x100u)
#define Droop_Filter_CSB_RAM_SIZE           (0x100u)
#define Droop_Filter_CFSM_RAM_SIZE          (0x100u)
#define Droop_Filter_ACU_RAM_SIZE           (0x040u)


/*******************************************************************************
* FILT component internal register contents.
*******************************************************************************/

#define Droop_Filter_PM_ACT_MSK             Droop_Filter_DFB__PM_ACT_MSK 
#define Droop_Filter_PM_STBY_MSK            Droop_Filter_DFB__PM_STBY_MSK 

#define Droop_Filter_RUN_MASK               (0x01u)
#define Droop_Filter_EVENT_MASK             (0x1Fu)
#define Droop_Filter_SR_EVENT_SHIFT         (0x03u)
#define Droop_Filter_DMA_CTRL_MASK          (0x0Fu)
#define Droop_Filter_RAM_DIR_BUS            (0x3Fu)
#define Droop_Filter_RAM_DIR_DFB            (0x00u)


/*******************************************************************************
* FILT component internal DFB registers.
*******************************************************************************/

/* DFB interrupt control register */
#define Droop_Filter_INT_CTRL_REG           (* (reg8 *) Droop_Filter_DFB__INT_CTRL)
#define Droop_Filter_INT_CTRL_PTR           (  (reg8 *) Droop_Filter_DFB__INT_CTRL)

/* DFB DMA control register */
#define Droop_Filter_DMA_CTRL_REG           (* (reg8 *) Droop_Filter_DFB__DMA_CTRL)
#define Droop_Filter_DMA_CTRL_PTR           (  (reg8 *) Droop_Filter_DFB__DMA_CTRL)

/* DFB ram direction register */
#define Droop_Filter_RAM_DIR_REG            (* (reg8 *) Droop_Filter_DFB__RAM_DIR)
#define Droop_Filter_RAM_DIR_PTR            (  (reg8 *) Droop_Filter_DFB__RAM_DIR)

/* DFB DSI control register */
#define Droop_Filter_DSI_CTRL_REG           (* (reg8 *) Droop_Filter_DFB__DSI_CTRL)
#define Droop_Filter_DSI_CTRL_PTR           (  (reg8 *) Droop_Filter_DFB__DSI_CTRL)

/* DFB HOLDA(Output LSB) register */
#define Droop_Filter_HOLDA_REG              (* (reg8 *) Droop_Filter_DFB__HOLDA)
#define Droop_Filter_HOLDA_PTR              (  (reg8 *) Droop_Filter_DFB__HOLDA)

/* DFB HOLDAH(Output MSB) register */
#define Droop_Filter_HOLDAH_REG             (* (reg8 *) Droop_Filter_DFB__HOLDAH)
#define Droop_Filter_HOLDAH_PTR             (  (reg8 *) Droop_Filter_DFB__HOLDAH)

/* DFB HOLDAM(Output middle) register */
#define Droop_Filter_HOLDAM_REG             (* (reg8 *) Droop_Filter_DFB__HOLDAM)
#define Droop_Filter_HOLDAM_PTR             (  (reg8 *) Droop_Filter_DFB__HOLDAM)

/* DFB HOLDB(Output LSB) register */
#define Droop_Filter_HOLDB_REG              (* (reg8 *) Droop_Filter_DFB__HOLDB)
#define Droop_Filter_HOLDB_PTR              (  (reg8 *) Droop_Filter_DFB__HOLDB)

/* DFB HOLDBH(Output MSB) register */
#define Droop_Filter_HOLDBH_REG             (* (reg8 *) Droop_Filter_DFB__HOLDBH)
#define Droop_Filter_HOLDBH_PTR             (  (reg8 *) Droop_Filter_DFB__HOLDBH)

/* DFB HOLDBM(Output middle) register */
#define Droop_Filter_HOLDBM_REG             (* (reg8 *) Droop_Filter_DFB__HOLDBM)
#define Droop_Filter_HOLDBM_PTR             (  (reg8 *) Droop_Filter_DFB__HOLDBM)

/* Active mode power control register */
#define Droop_Filter_PM_ACT_CFG_REG         (* (reg8 *) Droop_Filter_DFB__PM_ACT_CFG)
#define Droop_Filter_PM_ACT_CFG_PTR         (  (reg8 *) Droop_Filter_DFB__PM_ACT_CFG)

/* Alternative active mode power control register */
#define Droop_Filter_PM_STBY_CFG_REG        (* (reg8 *) Droop_Filter_DFB__PM_STBY_CFG)
#define Droop_Filter_PM_STBY_CFG_PTR        (  (reg8 *) Droop_Filter_DFB__PM_STBY_CFG)

/* DFB ram enable register */
#define Droop_Filter_RAM_EN_REG             (* (reg8 *) Droop_Filter_DFB__RAM_EN)
#define Droop_Filter_RAM_EN_PTR             (  (reg8 *) Droop_Filter_DFB__RAM_EN)

/* DFB STAGEA(Input LSB) register */
#define Droop_Filter_STAGEA_REG             (* (reg8 *) Droop_Filter_DFB__STAGEA)
#define Droop_Filter_STAGEA_PTR             (  (reg8 *) Droop_Filter_DFB__STAGEA)

/* DFB STAGEAH(Input MSB) register */
#define Droop_Filter_STAGEAH_REG            (* (reg8 *) Droop_Filter_DFB__STAGEAH)
#define Droop_Filter_STAGEAH_PTR            (  (reg8 *) Droop_Filter_DFB__STAGEAH)

/* DFB STAGEAM(Input middle) register */
#define Droop_Filter_STAGEAM_REG            (* (reg8 *) Droop_Filter_DFB__STAGEAM)
#define Droop_Filter_STAGEAM_PTR            (  (reg8 *) Droop_Filter_DFB__STAGEAM)

/* DFB STAGEB(Input LSB) register */
#define Droop_Filter_STAGEB_REG             (* (reg8 *) Droop_Filter_DFB__STAGEB )
#define Droop_Filter_STAGEB_PTR             (  (reg8 *) Droop_Filter_DFB__STAGEB )

/* DFB STAGEBH(Input MSB) register */
#define Droop_Filter_STAGEBH_REG            (* (reg8 *) Droop_Filter_DFB__STAGEBH)
#define Droop_Filter_STAGEBH_PTR            (  (reg8 *) Droop_Filter_DFB__STAGEBH)

/* DFB STAGEBM(Input middle) register */
#define Droop_Filter_STAGEBM_REG            (* (reg8 *) Droop_Filter_DFB__STAGEBM)
#define Droop_Filter_STAGEBM_PTR            (  (reg8 *) Droop_Filter_DFB__STAGEBM)

/* DFB coherence register */
#define Droop_Filter_COHER_REG              (* (reg8 *) Droop_Filter_DFB__COHER)
#define Droop_Filter_COHER_PTR              (  (reg8 *) Droop_Filter_DFB__COHER)

/* DFB data align register */
#define Droop_Filter_DALIGN_REG             (* (reg8 *) Droop_Filter_DFB__DALIGN)
#define Droop_Filter_DALIGN_PTR             (  (reg8 *) Droop_Filter_DFB__DALIGN)

/* DFB semaphore register */
#define Droop_Filter_SEMA_REG               (* (reg8 *) Droop_Filter_DFB__SEMA)
#define Droop_Filter_SEMA_PTR               (  (reg8 *) Droop_Filter_DFB__SEMA)

/* DFB output register which are 16 bit aligned */
#define Droop_Filter_HOLDA16_REG            (* (reg16 *) Droop_Filter_DFB__HOLDAM)
#define Droop_Filter_HOLDA16_PTR            (  (reg16 *) Droop_Filter_DFB__HOLDAM)

#define Droop_Filter_HOLDB16_REG            (* (reg16 *) Droop_Filter_DFB__HOLDBM)
#define Droop_Filter_HOLDB16_PTR            (  (reg16 *) Droop_Filter_DFB__HOLDBM)

/* DFB input register which are 16 bit aligned */
#define Droop_Filter_STAGEA16_REG           (* (reg16 *) Droop_Filter_DFB__STAGEAM)
#define Droop_Filter_STAGEA16_PTR           (  (reg16 *) Droop_Filter_DFB__STAGEAM)

#define Droop_Filter_STAGEB16_REG           (* (reg16 *) Droop_Filter_DFB__STAGEBM)
#define Droop_Filter_STAGEB16_PTR           (  (reg16 *) Droop_Filter_DFB__STAGEBM)

/* DFB output registers which are 24 bit aligned */
#define Droop_Filter_HOLDA24_REG            (* (reg32 *) Droop_Filter_DFB__HOLDA)
#define Droop_Filter_HOLDA24_PTR            (  (reg32 *) Droop_Filter_DFB__HOLDA)

#define Droop_Filter_HOLDB24_REG            (* (reg32 *) Droop_Filter_DFB__HOLDB)
#define Droop_Filter_HOLDB24_PTR            (  (reg32 *) Droop_Filter_DFB__HOLDB)

/* DFB input registers which are 24 bit aligned */
#define Droop_Filter_STAGEA24_REG           (* (reg32 *) Droop_Filter_DFB__STAGEA)
#define Droop_Filter_STAGEA24_PTR           (  (reg32 *) Droop_Filter_DFB__STAGEA)

#define Droop_Filter_STAGEB24_REG           (* (reg32 *) Droop_Filter_DFB__STAGEB)
#define Droop_Filter_STAGEB24_PTR           (  (reg32 *) Droop_Filter_DFB__STAGEB)

#endif /* End FILT_PVT Header File */


/* [] END OF FILE */
