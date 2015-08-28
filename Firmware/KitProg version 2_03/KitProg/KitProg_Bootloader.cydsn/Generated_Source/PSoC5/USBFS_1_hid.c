/*******************************************************************************
* File Name: USBFS_1_hid.c
* Version 2.50
*
* Description:
*  USB HID Class request handler.
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

#if defined(USBFS_1_ENABLE_HID_CLASS)

#include "USBFS_1_hid.h"


/***************************************
*    HID Variables
***************************************/

volatile uint8 USBFS_1_hidProtocol[USBFS_1_MAX_INTERFACES_NUMBER];  /* HID device protocol status */
volatile uint8 USBFS_1_hidIdleRate[USBFS_1_MAX_INTERFACES_NUMBER];  /* HID device idle reload value */
volatile uint8 USBFS_1_hidIdleTimer[USBFS_1_MAX_INTERFACES_NUMBER]; /* HID device idle rate value */


/***************************************
* Custom Declarations
***************************************/

/* `#START HID_CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
*    External references
***************************************/

uint8 USBFS_1_InitControlRead(void) ;
uint8 USBFS_1_InitControlWrite(void) ;
uint8 USBFS_1_InitNoDataControlTransfer(void) ;
T_USBFS_1_LUT *USBFS_1_GetConfigTablePtr(uint8 c)
                                                            ;
T_USBFS_1_LUT *USBFS_1_GetDeviceTablePtr(void)
                                                            ;

extern volatile T_USBFS_1_TD USBFS_1_currentTD;
extern uint8 CYCODE USBFS_1_HIDREPORT_DESCRIPTORS[];
extern volatile uint8 USBFS_1_configuration;
extern volatile uint8 USBFS_1_interfaceSetting[];


/***************************************
*    Internal references
***************************************/

void USBFS_1_FindReport(void) ;
void USBFS_1_FindReportDescriptor(void) ;
void USBFS_1_FindHidClassDecriptor(void) ;


/*******************************************************************************
* Function Name: USBFS_1_UpdateHIDTimer
********************************************************************************
*
* Summary:
*  Updates the HID report timer and reloads it if expired
*
* Parameters:
*  interface:  Interface Number.
*
* Return:
*  status.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 USBFS_1_UpdateHIDTimer(uint8 interface) 
{
    uint8 status = USBFS_1_IDLE_TIMER_INDEFINITE;

    if(USBFS_1_hidIdleRate[interface] != 0u)
    {
        if(USBFS_1_hidIdleTimer[interface] > 0u)
        {
            USBFS_1_hidIdleTimer[interface]--;
            status = USBFS_1_IDLE_TIMER_RUNNING;
        }
        else
        {
            USBFS_1_hidIdleTimer[interface] = USBFS_1_hidIdleRate[interface];
            status = USBFS_1_IDLE_TIMER_EXPIRED;
        }
    }

    return(status);
}


/*******************************************************************************
* Function Name: USBFS_1_GetProtocol
********************************************************************************
*
* Summary:
*  Returns the selected protocol value to the application
*
* Parameters:
*  interface:  Interface Number.
*
* Return:
*  Interface protocol.
*
*******************************************************************************/
uint8 USBFS_1_GetProtocol(uint8 interface) 
{
    return(USBFS_1_hidProtocol[interface]);
}


/*******************************************************************************
* Function Name: USBFS_1_DispatchHIDClassRqst
********************************************************************************
*
* Summary:
*  This routine dispatches class requests
*
* Parameters:
*  None.
*
* Return:
*  requestHandled
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 USBFS_1_DispatchHIDClassRqst() 
{
    uint8 requestHandled = USBFS_1_FALSE;
    uint8 interfaceNumber;

    interfaceNumber = CY_GET_REG8(USBFS_1_wIndexLo);
    if ((CY_GET_REG8(USBFS_1_bmRequestType) & USBFS_1_RQST_DIR_MASK) == USBFS_1_RQST_DIR_D2H)
    {   /* Control Read */
        switch (CY_GET_REG8(USBFS_1_bRequest))
        {
            case USBFS_1_GET_DESCRIPTOR:
                if (CY_GET_REG8(USBFS_1_wValueHi) == USBFS_1_DESCR_HID_CLASS)
                {
                    USBFS_1_FindHidClassDecriptor();
                    if (USBFS_1_currentTD.count != 0u)
                    {
                        requestHandled = USBFS_1_InitControlRead();
                    }
                }
                else if (CY_GET_REG8(USBFS_1_wValueHi) == USBFS_1_DESCR_HID_REPORT)
                {
                    USBFS_1_FindReportDescriptor();
                    if (USBFS_1_currentTD.count != 0u)
                    {
                        requestHandled = USBFS_1_InitControlRead();
                    }
                }
                else
                {   /* requestHandled is initialezed as FALSE by default */
                }
                break;
            case USBFS_1_HID_GET_REPORT:
                USBFS_1_FindReport();
                if (USBFS_1_currentTD.count != 0u)
                {
                    requestHandled = USBFS_1_InitControlRead();
                }
                break;

            case USBFS_1_HID_GET_IDLE:
                /* This function does not support multiple reports per interface*/
                /* Validate interfaceNumber and Report ID (should be 0) */
                if( (interfaceNumber < USBFS_1_MAX_INTERFACES_NUMBER) &&
                    (CY_GET_REG8(USBFS_1_wValueLo) == 0u ) ) /* do not support Idle per Report ID */
                {
                    USBFS_1_currentTD.count = 1u;
                    USBFS_1_currentTD.pData = &USBFS_1_hidIdleRate[interfaceNumber];
                    requestHandled  = USBFS_1_InitControlRead();
                }
                break;
            case USBFS_1_HID_GET_PROTOCOL:
                /* Validate interfaceNumber */
                if( interfaceNumber < USBFS_1_MAX_INTERFACES_NUMBER)
                {
                    USBFS_1_currentTD.count = 1u;
                    USBFS_1_currentTD.pData = &USBFS_1_hidProtocol[interfaceNumber];
                    requestHandled  = USBFS_1_InitControlRead();
                }
                break;
            default:    /* requestHandled is initialezed as FALSE by default */
                break;
        }
    }
    else if ((CY_GET_REG8(USBFS_1_bmRequestType) & USBFS_1_RQST_DIR_MASK) ==
                                                                            USBFS_1_RQST_DIR_H2D)
    {   /* Control Write */
        switch (CY_GET_REG8(USBFS_1_bRequest))
        {
            case USBFS_1_HID_SET_REPORT:
                USBFS_1_FindReport();
                if (USBFS_1_currentTD.count != 0u)
                {
                    requestHandled = USBFS_1_InitControlWrite();
                }
                break;
            case USBFS_1_HID_SET_IDLE:
                /* This function does not support multiple reports per interface */
                /* Validate interfaceNumber and Report ID (should be 0) */
                if( (interfaceNumber < USBFS_1_MAX_INTERFACES_NUMBER) &&
                    (CY_GET_REG8(USBFS_1_wValueLo) == 0u ) ) /* do not support Idle per Report ID */
                {
                    USBFS_1_hidIdleRate[interfaceNumber] = CY_GET_REG8(USBFS_1_wValueHi);
                    /* With regards to HID spec: "7.2.4 Set_Idle Request"
                    *  Latency. If the current period has gone past the
                    *  newly proscribed time duration, then a report
                    *  will be generated immediately.
                    */
                    if(USBFS_1_hidIdleRate[interfaceNumber] <
                       USBFS_1_hidIdleTimer[interfaceNumber])
                    {
                        /* Set the timer to zero and let the UpdateHIDTimer() API return IDLE_TIMER_EXPIRED status*/
                        USBFS_1_hidIdleTimer[interfaceNumber] = 0u;
                    }
                    /* If the new request is received within 4 milliseconds
                    *  (1 count) of the end of the current period, then the
                    *  new request will have no effect until after the report.
                    */
                    else if(USBFS_1_hidIdleTimer[interfaceNumber] <= 1u)
                    {
                        /* Do nothing.
                        * Let the UpdateHIDTimer() API continue to work and
                        * return IDLE_TIMER_EXPIRED status
                        */
                    }
                    else
                    {   /* Reload the timer*/
                        USBFS_1_hidIdleTimer[interfaceNumber] =
                        USBFS_1_hidIdleRate[interfaceNumber];
                    }
                    requestHandled = USBFS_1_InitNoDataControlTransfer();
                }
                break;

            case USBFS_1_HID_SET_PROTOCOL:
                /* Validate interfaceNumber and protocol (must be 0 or 1) */
                if( (interfaceNumber < USBFS_1_MAX_INTERFACES_NUMBER) &&
                    (CY_GET_REG8(USBFS_1_wValueLo) <= 1u) )
                {
                    USBFS_1_hidProtocol[interfaceNumber] = CY_GET_REG8(USBFS_1_wValueLo);
                    requestHandled = USBFS_1_InitNoDataControlTransfer();
                }
                break;
            default:    /* requestHandled is initialezed as FALSE by default */
                break;
        }
    }
    else
    {   /* requestHandled is initialezed as FALSE by default */
    }

    return(requestHandled);
}


/*******************************************************************************
* Function Name: USB_FindHidClassDescriptor
********************************************************************************
*
* Summary:
*  This routine find Hid Class Descriptor pointer based on the Interface number
*  and Alternate setting then loads the currentTD structure with the address of
*  the buffer and the size.
*  The HID Class Descriptor resides inside the config descriptor.
*
* Parameters:
*  None.
*
* Return:
*  currentTD
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_FindHidClassDecriptor() 
{
    T_USBFS_1_LUT *pTmp;
    volatile uint8 *pDescr;
    uint8 interfaceN;

    pTmp = USBFS_1_GetConfigTablePtr(USBFS_1_configuration - 1u);
    interfaceN = CY_GET_REG8(USBFS_1_wIndexLo);
    /* Third entry in the LUT starts the Interface Table pointers */
    pTmp += 2;
    /* Now use the request interface number*/
    pTmp = &pTmp[interfaceN];
    /*USB_DEVICEx_CONFIGURATIONy_INTERFACEz_TABLE*/
    pTmp = (T_USBFS_1_LUT *) pTmp->p_list;
    /* Now use Alternate setting number */
    pTmp = &pTmp[USBFS_1_interfaceSetting[interfaceN]];
    /*USB_DEVICEx_CONFIGURATIONy_INTERFACEz_ALTERNATEi_HID_TABLE*/
    pTmp = (T_USBFS_1_LUT *) pTmp->p_list;
    /* Fifth entry in the LUT points to Hid Class Descriptor in Configuration Descriptor*/
    pTmp += 4;
    pDescr = (volatile uint8 *)pTmp->p_list;
    USBFS_1_currentTD.count = pDescr[0u];
    USBFS_1_currentTD.pData = pDescr;
}


/*******************************************************************************
* Function Name: USB_FindReportDescriptor
********************************************************************************
*
* Summary:
*  This routine find Hid Report Descriptor pointer based on the Interface
*  number, then loads the currentTD structure with the address of the buffer
*  and the size.
*  Hid Report Descriptor is located after IN/OUT/FEATURE reports.
*
* Parameters:
*   void
*
* Return:
*  currentTD
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_FindReportDescriptor() 
{
    T_USBFS_1_LUT *pTmp;
    volatile uint8 *pDescr;
    uint8 interfaceN;

    pTmp = USBFS_1_GetConfigTablePtr(USBFS_1_configuration - 1u);
    interfaceN = CY_GET_REG8(USBFS_1_wIndexLo);
    /* Third entry in the LUT starts the Interface Table pointers */
    pTmp += 2u;
    /* Now use the request interface number*/
    pTmp = &pTmp[interfaceN];
    /*USB_DEVICEx_CONFIGURATIONy_INTERFACEz_TABLE*/
    pTmp = (T_USBFS_1_LUT *) pTmp->p_list;
    /* Now use Alternate setting number */
    pTmp = &pTmp[USBFS_1_interfaceSetting[interfaceN]];
    /*USB_DEVICEx_CONFIGURATIONy_INTERFACEz_ALTERNATEi_HID_TABLE*/
    pTmp = (T_USBFS_1_LUT *) pTmp->p_list;
    /* Fourth entry in the LUT starts the Hid Report Descriptor */
    pTmp += 3;
    pDescr = (volatile uint8 *)pTmp->p_list;
    USBFS_1_currentTD.count =  (((uint16)pDescr[1] << 8u) | pDescr[0u]);
    USBFS_1_currentTD.pData = &pDescr[2u];
}


/*******************************************************************************
* Function Name: USBFS_1_FindReport
********************************************************************************
*
* Summary:
*  This routine sets up a transfer based on the Interface number, Report Type
*  and Report ID, then loads the currentTD structure with the address of the
*  buffer and the size.  The caller has to decide if it is a control read or
*  control write.
*
* Parameters:
*  None.
*
* Return:
*  currentTD
*
* Reentrant:
*  No.
*
*******************************************************************************/
void USBFS_1_FindReport() 
{
    T_USBFS_1_LUT *pTmp;
    T_USBFS_1_TD *pTD;
    uint8 interfaceN;
    uint8 reportType;

    /* `#START HID_FINDREPORT` Place custom handling here */

    /* `#END` */
    USBFS_1_currentTD.count = 0u;   /* Init not supported condition */
    pTmp = USBFS_1_GetConfigTablePtr(USBFS_1_configuration - 1u);
    reportType = CY_GET_REG8(USBFS_1_wValueHi);
    interfaceN = CY_GET_REG8(USBFS_1_wIndexLo);
    /* Third entry in the LUT COnfiguration Table starts the Interface Table pointers */
    pTmp += 2;
    /* Now use the request interface number */
    pTmp = &pTmp[interfaceN];
    /*USB_DEVICEx_CONFIGURATIONy_INTERFACEz_TABLE*/
    pTmp = (T_USBFS_1_LUT *) pTmp->p_list;
    if(interfaceN < USBFS_1_MAX_INTERFACES_NUMBER)
    {
        /* Now use Alternate setting number */
        pTmp = &pTmp[USBFS_1_interfaceSetting[interfaceN]];
        /*USB_DEVICEx_CONFIGURATIONy_INTERFACEz_ALTERNATEi_HID_TABLE*/
        pTmp = (T_USBFS_1_LUT *) pTmp->p_list;
        /* Validate reportType to comply with "7.2.1 Get_Report Request" */
        if((reportType >= USBFS_1_HID_GET_REPORT_INPUT) &&
           (reportType <= USBFS_1_HID_GET_REPORT_FEATURE))
        {
            /* Get the entry proper TD (IN, OUT or Feature Report Table)*/
            pTmp = &pTmp[reportType - 1u];
            reportType = CY_GET_REG8(USBFS_1_wValueLo);    /* Get reportID */
            /* Validate table support by the HID descriptor, compare table count with reportID */
            if(pTmp->c >= reportType)
            {
                pTD = (T_USBFS_1_TD *) pTmp->p_list;
                pTD = &pTD[reportType];                          /* select entry depend on report ID*/
                USBFS_1_currentTD.pData = pTD->pData;   /* Bufer pointer */
                USBFS_1_currentTD.count = pTD->count;   /* Bufer Size */
                USBFS_1_currentTD.pStatusBlock = pTD->pStatusBlock;
            }
        }
    }
}


/*******************************************************************************
* Additional user functions supporting HID Requests
********************************************************************************/

/* `#START HID_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif  /* End USBFS_1_ENABLE_HID_CLASS*/


/* [] END OF FILE */
