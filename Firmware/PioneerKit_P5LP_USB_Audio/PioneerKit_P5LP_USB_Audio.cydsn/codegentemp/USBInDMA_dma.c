/***************************************************************************
* File Name: USBInDMA_dma.c  
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
#include <USBInDMA_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* USBInDMA__DRQ_CTL_REG
* 
* 
* USBInDMA__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* USBInDMA__NUMBEROF_TDS
* 
* Priority of this channel.
* USBInDMA__PRIORITY
* 
* True if USBInDMA_TERMIN_SEL is used.
* USBInDMA__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* USBInDMA__TERMIN_SEL
* 
* 
* True if USBInDMA_TERMOUT0_SEL is used.
* USBInDMA__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* USBInDMA__TERMOUT0_SEL
* 
* 
* True if USBInDMA_TERMOUT1_SEL is used.
* USBInDMA__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* USBInDMA__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of USBInDMA dma channel */
uint8 USBInDMA_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 USBInDMA_DmaInitalize
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
uint8 USBInDMA_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    USBInDMA_DmaHandle = (uint8)USBInDMA__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(USBInDMA_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)USBInDMA__TERMOUT0_SEL,
                                  (uint8)USBInDMA__TERMOUT1_SEL,
                                  (uint8)USBInDMA__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(USBInDMA_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(USBInDMA_DmaHandle, (uint8)USBInDMA__PRIORITY);
    
    return USBInDMA_DmaHandle;
}

/*********************************************************************
* Function Name: void USBInDMA_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with USBInDMA.
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
void USBInDMA_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(USBInDMA_DmaHandle);
}

