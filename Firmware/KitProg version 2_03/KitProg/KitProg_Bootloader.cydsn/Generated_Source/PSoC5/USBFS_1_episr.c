/*******************************************************************************
* File Name: USBFS_1_episr.c
* Version 2.50
*
* Description:
*  Data endpoint Interrupt Service Routines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBFS_1.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
* External function references
***************************************/

void USBFS_1_InitComponent(uint8 device, uint8 mode) ;
void USBFS_1_ReInitComponent(void) ;
#if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u)
    void USBFS_1_MIDI_OUT_EP_Service(void) ;
#endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/


/***************************************
* External references
***************************************/

extern volatile T_USBFS_1_EP_CTL_BLOCK USBFS_1_EP[];
extern volatile uint8 USBFS_1_device;
#if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u)
    extern volatile uint8 USBFS_1_midi_out_ep;
    extern volatile uint8 USBFS_1_midi_in_ep;
    #if USBFS_1_MIDI_IN_BUFF_SIZE >= 256
        extern volatile uint16 USBFS_1_midiInPointer;     /* Input endpoint buffer pointer */
    #else
        extern volatile uint8 USBFS_1_midiInPointer;      /* Input endpoint buffer pointer */
    #endif /* End USBFS_1_MIDI_IN_BUFF_SIZE >=256 */    
#endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

#if(USBFS_1_EP1_ISR_REMOVE == 0u)


    /******************************************************************************
    * Function Name: USBFS_1_EP_1_ISR
    *******************************************************************************
    *
    * Summary:
    *  Endpoint 1 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    ******************************************************************************/
    CY_ISR(USBFS_1_EP_1_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP1_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP1_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP1].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP1].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP1].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                            & ~USBFS_1_SIE_EP_INT_EP1_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP1)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP1_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP1_ISR_REMOVE */


#if(USBFS_1_EP2_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_2_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 2 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_2_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP2_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP2_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP2].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP2].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP2].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP2_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO)
            if(USBFS_1_midi_out_ep == USBFS_1_EP2)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP2_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP2_ISR_REMOVE */


#if(USBFS_1_EP3_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_3_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 3 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_3_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP3_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP3_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP3].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP3].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP3].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP3_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP3)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP3_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP3_ISR_REMOVE */


#if(USBFS_1_EP4_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_4_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 4 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_4_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP4_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP4_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP4].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP4].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP4].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP4_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP4)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP4_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP4_ISR_REMOVE */


#if(USBFS_1_EP5_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_5_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 5 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_5_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP5_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP5_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP5].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP5].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP5].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP5_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP5)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP5_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }
#endif   /* End USBFS_1_EP5_ISR_REMOVE */


#if(USBFS_1_EP6_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_6_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 6 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_6_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP6_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP6_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP6].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP6].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP6].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP6_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP6)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP6_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP6_ISR_REMOVE */


#if(USBFS_1_EP7_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_7_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 7 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_7_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP7_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP7_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP7].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP7].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP7].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP7_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP7)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP7_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP7_ISR_REMOVE */


#if(USBFS_1_EP8_ISR_REMOVE == 0u)

    /*******************************************************************************
    * Function Name: USBFS_1_EP_8_ISR
    ********************************************************************************
    *
    * Summary:
    *  Endpoint 8 Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_8_ISR)
    {
        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    
        /* `#START EP8_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            int_en = EA;
            CyGlobalIntEnable;  /* Make sure nested interrupt is enabled */
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */

        CY_GET_REG8(USBFS_1_SIE_EP8_CR0_PTR); /* Must read the mode reg */
        /* Do not toggle ISOC endpoint */
        if((USBFS_1_EP[USBFS_1_EP8].attrib & USBFS_1_EP_TYPE_MASK) !=
                                                                                    USBFS_1_EP_TYPE_ISOC)
        {
            USBFS_1_EP[USBFS_1_EP8].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
        }
        USBFS_1_EP[USBFS_1_EP8].apiEpState = USBFS_1_EVENT_PENDING;
        CY_SET_REG8(USBFS_1_SIE_EP_INT_SR_PTR, CY_GET_REG8(USBFS_1_SIE_EP_INT_SR_PTR)
                                                                        & ~USBFS_1_SIE_EP_INT_EP8_MASK);

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) 
            if(USBFS_1_midi_out_ep == USBFS_1_EP8)
            {
                USBFS_1_MIDI_OUT_EP_Service();
            }   
        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/

        /* `#START EP8_END_USER_CODE` Place your code here */

        /* `#END` */

        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u) && \
            (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO) && (CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 & ENABLE_MIDI_STREAMING */
    }

#endif   /* End USBFS_1_EP8_ISR_REMOVE */


/*******************************************************************************
* Function Name: USBFS_1_SOF_ISR
********************************************************************************
*
* Summary:
*  Start of Frame Interrupt Service Routine
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(USBFS_1_SOF_ISR)
{
    /* `#START SOF_USER_CODE` Place your code here */

    /* `#END` */
}


/*******************************************************************************
* Function Name: USBFS_1_BUS_RESET_ISR
********************************************************************************
*
* Summary:
*  USB Bus Reset Interrupt Service Routine.  Calls _Start with the same
*  parameters as the last USER call to _Start
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(USBFS_1_BUS_RESET_ISR)
{
    /* `#START BUS_RESET_USER_CODE` Place your code here */

    /* `#END` */

    USBFS_1_ReInitComponent();
}


#if((USBFS_1_EP_MM != USBFS_1__EP_MANUAL) && (USBFS_1_ARB_ISR_REMOVE == 0u))


    /*******************************************************************************
    * Function Name: USBFS_1_ARB_ISR
    ********************************************************************************
    *
    * Summary:
    *  Arbiter Interrupt Service Routine
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side effect:
    *  Search for EP8 int_status will be much slower than search for EP1 int_status.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_ARB_ISR)
    {
        uint8 int_status;
        uint8 ep_status;
        uint8 ep = USBFS_1_EP1;
        uint8 ptr = 0u;

        /* `#START ARB_BEGIN_USER_CODE` Place your code here */

        /* `#END` */

        int_status = USBFS_1_ARB_INT_SR_REG;                   /* read Arbiter Status Register */
        USBFS_1_ARB_INT_SR_REG = int_status;                   /* Clear Serviced Interrupts */

        while(int_status != 0u)
        {
            if(int_status & 1u)  /* If EpX interrupt present */
            {
                ep_status  = USBFS_1_ARB_EP1_SR_PTR[ptr];       /* read Endpoint Status Register */
                /* If In Buffer Full */
                if(ep_status & USBFS_1_ARB_EPX_SR_IN_BUF_FULL)
                {
                   if(USBFS_1_EP[ep].addr & USBFS_1_DIR_IN)
                    {
                        /* Write the Mode register */
                        USBFS_1_SIE_EP1_CR0_PTR[ptr] = USBFS_1_EP[ep].epMode;
                        /* Clear Data ready status*/
                        USBFS_1_ARB_EP1_CFG_PTR[ptr] &= ~USBFS_1_ARB_EPX_CFG_IN_DATA_RDY;
                        #if defined(USBFS_1_ENABLE_MIDI_STREAMING) && (USBFS_1_ENABLE_MIDI_API != 0u)
                            if(ep == USBFS_1_midi_in_ep)
                            {   /* Clear MIDI input pointer*/
                                USBFS_1_midiInPointer = 0u;
                            }
                        #endif /* End USBFS_1_ENABLE_MIDI_STREAMING*/
                    }
                }
                /* (re)arm Out EP only for mode2 */
                #if(USBFS_1_EP_MM != USBFS_1__EP_DMAAUTO)
                    /* If DMA Grant */
                    if(ep_status & USBFS_1_ARB_EPX_SR_DMA_GNT)
                    {
                        if((USBFS_1_EP[ep].addr & USBFS_1_DIR_IN) == 0u)
                        {
                                USBFS_1_EP[ep].apiEpState = USBFS_1_NO_EVENT_PENDING;
                                /* Write the Mode register */
                                USBFS_1_SIE_EP1_CR0_PTR[ptr] = USBFS_1_EP[ep].epMode;
                        }
                    }
                #endif /* End USBFS_1_EP_MM */

                /* `#START ARB_USER_CODE` Place your code here for handle Buffer Underflow/Overflow */

                /* `#END` */

                USBFS_1_ARB_EP1_SR_PTR[ptr] = ep_status;       /* Clear Serviced events */
            }
            ptr += USBFS_1_EPX_CNTX_ADDR_OFFSET;               /* prepare pointer for next EP */
            ep++;
            int_status >>= 1;
        }

        /* `#START ARB_END_USER_CODE` Place your code here */

        /* `#END` */
    }

#endif /* End USBFS_1_EP_MM */


/* [] END OF FILE */
