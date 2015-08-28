/***************************************************************************
* File Name: CICOut_R_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <CICOut_R_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* CICOut_R__DRQ_CTL_REG
* 
* 
* CICOut_R__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* CICOut_R__NUMBEROF_TDS
* 
* Priority of this channel.
* CICOut_R__PRIORITY
* 
* True if CICOut_R_TERMIN_SEL is used.
* CICOut_R__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* CICOut_R__TERMIN_SEL
* 
* 
* True if CICOut_R_TERMOUT0_SEL is used.
* CICOut_R__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* CICOut_R__TERMOUT0_SEL
* 
* 
* True if CICOut_R_TERMOUT1_SEL is used.
* CICOut_R__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* CICOut_R__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of CICOut_R dma channel */
uint8 CICOut_R_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 CICOut_R_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 CICOut_R_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    CICOut_R_DmaHandle = (uint8)CICOut_R__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(CICOut_R_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)CICOut_R__TERMOUT0_SEL,
                                  (uint8)CICOut_R__TERMOUT1_SEL,
                                  (uint8)CICOut_R__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(CICOut_R_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(CICOut_R_DmaHandle, (uint8)CICOut_R__PRIORITY);
    
    return CICOut_R_DmaHandle;
}

/*********************************************************************
* Function Name: void CICOut_R_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with CICOut_R.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void CICOut_R_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(CICOut_R_DmaHandle);
}

