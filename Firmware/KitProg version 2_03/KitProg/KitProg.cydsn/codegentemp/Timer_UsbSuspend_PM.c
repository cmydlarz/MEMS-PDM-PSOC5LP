/*******************************************************************************
* File Name: Timer_UsbSuspend_PM.c
* Version 2.50
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_UsbSuspend.h"
static Timer_UsbSuspend_backupStruct Timer_UsbSuspend_backup;


/*******************************************************************************
* Function Name: Timer_UsbSuspend_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_UsbSuspend_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_UsbSuspend_SaveConfig(void) 
{
    #if (!Timer_UsbSuspend_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            Timer_UsbSuspend_backup.TimerUdb = Timer_UsbSuspend_ReadCounter();
            Timer_UsbSuspend_backup.TimerPeriod = Timer_UsbSuspend_ReadPeriod();
            Timer_UsbSuspend_backup.InterruptMaskValue = Timer_UsbSuspend_STATUS_MASK;
            #if (Timer_UsbSuspend_UsingHWCaptureCounter)
                Timer_UsbSuspend_backup.TimerCaptureCounter = Timer_UsbSuspend_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            Timer_UsbSuspend_backup.TimerUdb = Timer_UsbSuspend_ReadCounter();
            Timer_UsbSuspend_backup.InterruptMaskValue = Timer_UsbSuspend_STATUS_MASK;
            #if (Timer_UsbSuspend_UsingHWCaptureCounter)
                Timer_UsbSuspend_backup.TimerCaptureCounter = Timer_UsbSuspend_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!Timer_UsbSuspend_ControlRegRemoved)
            Timer_UsbSuspend_backup.TimerControlRegister = Timer_UsbSuspend_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_UsbSuspend_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_UsbSuspend_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_UsbSuspend_RestoreConfig(void) 
{   
    #if (!Timer_UsbSuspend_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 Timer_UsbSuspend_interruptState;

            Timer_UsbSuspend_WriteCounter(Timer_UsbSuspend_backup.TimerUdb);
            Timer_UsbSuspend_WritePeriod(Timer_UsbSuspend_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Timer_UsbSuspend_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Timer_UsbSuspend_STATUS_AUX_CTRL |= Timer_UsbSuspend_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Timer_UsbSuspend_interruptState);
            Timer_UsbSuspend_STATUS_MASK =Timer_UsbSuspend_backup.InterruptMaskValue;
            #if (Timer_UsbSuspend_UsingHWCaptureCounter)
                Timer_UsbSuspend_SetCaptureCount(Timer_UsbSuspend_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            Timer_UsbSuspend_WriteCounter(Timer_UsbSuspend_backup.TimerUdb);
            Timer_UsbSuspend_STATUS_MASK =Timer_UsbSuspend_backup.InterruptMaskValue;
            #if (Timer_UsbSuspend_UsingHWCaptureCounter)
                Timer_UsbSuspend_SetCaptureCount(Timer_UsbSuspend_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!Timer_UsbSuspend_ControlRegRemoved)
            Timer_UsbSuspend_WriteControlRegister(Timer_UsbSuspend_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_UsbSuspend_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_UsbSuspend_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_UsbSuspend_Sleep(void) 
{
    #if(!Timer_UsbSuspend_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Timer_UsbSuspend_CTRL_ENABLE == (Timer_UsbSuspend_CONTROL & Timer_UsbSuspend_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_UsbSuspend_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_UsbSuspend_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_UsbSuspend_Stop();
    Timer_UsbSuspend_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_UsbSuspend_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_UsbSuspend_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_UsbSuspend_Wakeup(void) 
{
    Timer_UsbSuspend_RestoreConfig();
    #if(!Timer_UsbSuspend_ControlRegRemoved)
        if(Timer_UsbSuspend_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_UsbSuspend_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
