/*******************************************************************************
* File Name: USBFS_1_pm.c
* Version 2.50
*
* Description:
*  This file provides Suspend/Resume APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <device.h>
#include "USBFS_1.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START PM_CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
* Local data allocation
***************************************/

static USBFS_1_BACKUP_STRUCT  USBFS_1_backup;


/***************************************
* External data references
***************************************/

extern volatile uint8 USBFS_1_configuration;


/***************************************
* External function references
***************************************/

extern void USBFS_1_ConfigReg(void) ;
#if(USBFS_1_EP_MM != USBFS_1__EP_MANUAL)
    extern void USBFS_1_Stop_DMA(uint8 epNumber) ;
#endif   /* End USBFS_1_EP_MM != USBFS_1__EP_MANUAL */

#if((USBFS_1_DP_ISR_REMOVE == 0u) && (!CY_PSOC5A))


    /*******************************************************************************
    * Function Name: USBFS_1_DP_Interrupt
    ********************************************************************************
    *
    * Summary:
    *  This Interrupt Service Routine handles DP pin changes for wake-up from
    *  the sleep mode.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_DP_ISR)
    {
        /* `#START DP_USER_CODE` Place your code here */

        /* `#END` */

        /* Clears active interrupt */
        CY_GET_REG8(USBFS_1_DP_INTSTAT_PTR);
    }

#endif /* (USBFS_1_DP_ISR_REMOVE == 0u) && (!CY_PSOC5A) */


/*******************************************************************************
* Function Name: USBFS_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: USBFS_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_RestoreConfig(void) 
{
    if(USBFS_1_configuration != 0)
    {
        USBFS_1_ConfigReg();    
    }
}


/*******************************************************************************
* Function Name: USBFS_1_Suspend
********************************************************************************
*
* Summary:
*  This function disables the USBFS block and prepares for power donwn mode.
*
* Parameters:
*  None.
*
* Return:
*   None.
*
* Global variables:
*  USBFS_1_backup.enable:  modified.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_Suspend(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    if((CY_GET_REG8(USBFS_1_CR0_PTR) & USBFS_1_CR0_ENABLE) != 0u)
    {   /* USB block is enabled */
        USBFS_1_backup.enableState = 1u;

        #if(USBFS_1_EP_MM != USBFS_1__EP_MANUAL)
            USBFS_1_Stop_DMA(USBFS_1_MAX_EP);     /* Stop all DMAs */
        #endif   /* End USBFS_1_EP_MM != USBFS_1__EP_MANUAL */

        #if(CY_PSOC5A)
            /* Disable USBIO block */
            USBFS_1_PM_AVAIL_CR_REG &= ~USBFS_1_PM_AVAIL_EN_FSUSBIO;
        #endif /* End CY_PSOC5A */

        /* Power Down Sequencing for USBIO for TO4*/
        #if(!CY_PSOC5A)
            /* Ensure USB transmit enable is low (USB_USBIO_CR0.ten). - Manual Transmission - Disabled */
            USBFS_1_USBIO_CR0_REG &= ~USBFS_1_USBIO_CR0_TEN;
            CyDelayUs(0);  /*~50ns delay */

            /* Disable the USBIO by asserting PM.USB_CR0.fsusbio_pd_n(Inverted) and pd_pullup_hv(Inverted) high. */
            USBFS_1_PM_USB_CR0_REG &= \
                                    ~(USBFS_1_PM_USB_CR0_PD_N | USBFS_1_PM_USB_CR0_PD_PULLUP_N);
         #endif /* End !CY_PSOC5A */

        /* Disable the SIE */
        USBFS_1_CR0_REG &= ~USBFS_1_CR0_ENABLE;

        #if(!CY_PSOC5A)
            CyDelayUs(0);  /*~50ns delay */
            /* Store mode and Disable VRegulator*/
            USBFS_1_backup.mode = USBFS_1_CR1_REG & USBFS_1_CR1_REG_ENABLE;
            USBFS_1_CR1_REG &= ~USBFS_1_CR1_REG_ENABLE;

            CyDelayUs(1);  /* 0.5 us min delay */
            /* Disable the USBIO reference by setting PM.USB_CR0.fsusbio_ref_en.*/
            USBFS_1_PM_USB_CR0_REG &= ~USBFS_1_PM_USB_CR0_REF_EN;

            /* Switch DP and DM terminals to GPIO mode and disconnect 1.5k pullup*/
            USBFS_1_USBIO_CR1_REG |= USBFS_1_USBIO_CR1_IOMODE;

        #endif /* End !CY_PSOC5A*/

        /* Disable USB in ACT PM */
        USBFS_1_PM_ACT_CFG_REG &= ~USBFS_1_PM_ACT_EN_FSUSB;
        /* Disable USB block for Standby Power Mode */
        USBFS_1_PM_STBY_CFG_REG &= ~USBFS_1_PM_STBY_EN_FSUSB;
        CyDelayUs(1); /* min  0.5us delay required */

    }
    else
    {
        USBFS_1_backup.enableState = 0u;
    }
    CyExitCriticalSection(enableInterrupts);

    /* Set the DP Interrupt for wake-up from sleep mode. */
    #if((USBFS_1_DP_ISR_REMOVE == 0u) && (!CY_PSOC5A))
        CyIntSetVector(USBFS_1_DP_INTC_VECT_NUM,   USBFS_1_DP_ISR);
        CyIntSetPriority(USBFS_1_DP_INTC_VECT_NUM, USBFS_1_DP_INTC_PRIOR);
        CyIntClearPending(USBFS_1_DP_INTC_VECT_NUM);
        CyIntEnable(USBFS_1_DP_INTC_VECT_NUM);
    #endif /* (USBFS_1_DP_ISR_REMOVE == 0u) && (!CY_PSOC5A) */

}


/*******************************************************************************
* Function Name: USBFS_1_Resume
********************************************************************************
*
* Summary:
*  This function enables the USBFS block after power down mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  USBFS_1_backup - checked.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_Resume(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    if(USBFS_1_backup.enableState != 0u)
    {
        #if((USBFS_1_DP_ISR_REMOVE == 0u) && (!CY_PSOC5A))
            CyIntDisable(USBFS_1_DP_INTC_VECT_NUM);
        #endif /* End USBFS_1_DP_ISR_REMOVE */

        #if(CY_PSOC5A)
            /* Enable USBIO block */
            USBFS_1_PM_AVAIL_CR_REG |= USBFS_1_PM_AVAIL_EN_FSUSBIO;

            /* Bus Reset Length, It has correct default value in ES3 */
            USBFS_1_BUS_RST_CNT_REG = USBFS_1_BUS_RST_COUNT;
        #endif /* End CY_PSOC5A */

        /* Enable USB block */
        USBFS_1_PM_ACT_CFG_REG |= USBFS_1_PM_ACT_EN_FSUSB;
        /* Enable USB block for Standby Power Mode */
        USBFS_1_PM_STBY_CFG_REG |= USBFS_1_PM_STBY_EN_FSUSB;
        /* Enable core clock */
        USBFS_1_USB_CLK_EN_REG |= USBFS_1_USB_CLK_ENABLE;

        /* USBIO Wakeup Sequencing for TO4 */
        #if (!CY_PSOC5A)
            /* Enable the USBIO reference by setting PM.USB_CR0.fsusbio_ref_en.*/
            USBFS_1_PM_USB_CR0_REG |= USBFS_1_PM_USB_CR0_REF_EN;
            /* The reference will be available ~40us after power restored */
            CyDelayUs(40);
            /* Return VRegulator*/
            USBFS_1_CR1_REG |= USBFS_1_backup.mode;
            CyDelayUs(0);  /*~50ns delay */
            /* Enable USBIO */
            USBFS_1_PM_USB_CR0_REG |= USBFS_1_PM_USB_CR0_PD_N;
            CyDelayUs(2);
            /* Set the USBIO pull-up enable */
            USBFS_1_PM_USB_CR0_REG |= USBFS_1_PM_USB_CR0_PD_PULLUP_N;
        #endif /* End !CY_PSOC5A */

        /* Reinit Arbiter congiguration for DMA transfers */
        #if(USBFS_1_EP_MM != USBFS_1__EP_MANUAL)
            /* usb arb interrupt enable */
            USBFS_1_ARB_INT_EN_REG = USBFS_1_ARB_INT_MASK;
            #if(USBFS_1_EP_MM == USBFS_1__EP_DMAMANUAL)
                USBFS_1_ARB_CFG_REG = USBFS_1_ARB_CFG_MANUAL_DMA;
            #endif   /* End USBFS_1_EP_MM == USBFS_1__EP_DMAMANUAL */
            #if(USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO)
                /*Set cfg cmplt this rises DMA request when the full configuration is done */
                USBFS_1_ARB_CFG_REG = USBFS_1_ARB_CFG_AUTO_DMA | USBFS_1_ARB_CFG_AUTO_MEM;
            #endif   /* End USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO */
        #endif   /* End USBFS_1_EP_MM != USBFS_1__EP_MANUAL */

        /* STALL_IN_OUT */
        CY_SET_REG8(USBFS_1_EP0_CR_PTR, USBFS_1_MODE_STALL_IN_OUT);
        /* Enable the SIE with a last address */
        USBFS_1_CR0_REG |= USBFS_1_CR0_ENABLE;
        CyDelayCycles(1);
        /* Finally, Enable d+ pullup and select iomode to USB mode*/
        CY_SET_REG8(USBFS_1_USBIO_CR1_PTR, USBFS_1_USBIO_CR1_USBPUEN);

        /* Restore USB register settings */
        USBFS_1_RestoreConfig();
    
    }
    CyExitCriticalSection(enableInterrupts);
}

#if(CY_PSOC5A)


/*******************************************************************************
* Function Name: USBFS_1_Resume_Condition
********************************************************************************
* Summary:
*  This function enables the USBIO block after power down mode, reads the 
*  current state of the DP pin and disables the USBIO block backward when DP 
*  pin is not in low state.
 
*
* Parameters:  
*  void 
*
* Return: 
*  Zero for low level DP pin state and not zero for high level.
*  
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 USBFS_1_Resume_Condition(void) 
{
    uint8 pinVal;
    
    /* Enable USBIO block */
    USBFS_1_PM_AVAIL_CR_REG &= ~USBFS_1_PM_AVAIL_EN_FSUSBIO;
    
    /* Check DP pin for low level */
    pinVal = USBFS_1_USBIO_CR1_REG & USBFS_1_USBIO_CR1_DP0;
    
    if( pinVal != 0u)
    {
        /* Disable USBIO block */
        USBFS_1_PM_AVAIL_CR_REG &= ~USBFS_1_PM_AVAIL_EN_FSUSBIO;
    }    
    
    return (pinVal);
}

#endif /* End CY_PSOC5A */


/* [] END OF FILE */
