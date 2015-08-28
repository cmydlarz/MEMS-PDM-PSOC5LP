/*****************************************************************************
* File Name: USBUART.c
* Version 2.03
*
* Description:
*  This file provides the source code to handle USBUART Bridge functionality
*
* Owner:
*	Sree Harsha Angara, Applications Engineer (sreh@cypress.com)
*
* Related Document:
* 	001-85925 CY8CKIT-042 IROS
*
* Hardware Dependency:
* 	CY8CKIT-042 REV 1 
*
* Code Tested With:
* 	Creator 2.2
*	GCC1 4.4.1
*	CY8CKIT-042 REV 1
* 
******************************************************************************
* Copyright (2013), Cypress Semiconductor Corporation.
******************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*****************************************************************************/

#include "kitprog.h"

/*******************************************************************************
* Macro Name: CheckLine
********************************************************************************
* Summary:
* Checks for line change, Reconfigures the UART clock to match host baud rate
*******************************************************************************/

#define CheckLine() {																				\
																									\
	uint32 dDTERate;																				\
	uint16 wDivider;																				\
																									\
	if(USBFS_IsLineChanged())																		\
	{																								\
		/* Get Baud Rate */																			\
		dDTERate = USBFS_GetDTERate();  															\
																									\
		/* Check for Baud Rate Upper Limit */														\
		if(dDTERate > 115200)																		\
		{																							\
			dDTERate  = 115200;																		\
		}																							\
																									\
		/* Check for Baud Rate Lower Limit */														\
		if(dDTERate < 1200)																			\
		{																							\
			dDTERate  = 1200;																		\
		}																							\
																									\
		/* Sets the required Clock divider for UART */												\
		switch(dDTERate)																			\
	    {																							\
																									\
			case 115200:																			\
	            wDivider = DIVIDER115200;															\
	            break;																				\
	        case 57600:																				\
	            wDivider = DIVIDER57600;															\
	            break;																				\
	        case 38400:																				\
	            wDivider = DIVIDER38400;															\
	            break;																				\
	        case 19200:																				\
	            wDivider = DIVIDER19200;															\
	            break;																				\
	        case 9600:																				\
	            wDivider = DIVIDER9600;																\
	            break;																				\
	        case 4800:																				\
	            wDivider = DIVIDER4800;																\
	            break;																				\
	        case 2400:																				\
	            wDivider = DIVIDER2400;																\
	            break;																				\
	        case 1200:																				\
	            wDivider = DIVIDER1200;																\
	            break;																				\
	        default: 																				\
	            wDivider = DIVIDER115200;															\
	            break;																				\
	    }																							\
																									\
		/* Stop UART for new Clock */																\
	    UART_Bridge_Stop();   																		\
	    																							\
		/* Set new Clock Frequency */																\
		Clock_UART_SetDivider(wDivider-1);															\
	    																							\
		/* Restart UART */																			\
		UART_Bridge_Start();																		\
		UART_Bridge_ClearRxBuffer();																\
		UART_Bridge_ClearTxBuffer();																\
	}																								\
}																									

/*******************************************************************************
* Macro Name: USBUARTTransmit
********************************************************************************
* Summary:
* Checks if USB host has sent data and transfers it to the UART Transmitter 
*
*******************************************************************************/

#define USBUARTTransmit()   {																		\
																									\
	uint8 size;																						\
	uint8 buffer[64]; 																				\
																									\
	/* Check for USB host packet */																	\
	if(USBFS_GetEPState(UART_OUT_EP))						 										\
	{  																								\
		/* Get size of packet */ 																	\
		size = USBFS_GetEPCount(UART_OUT_EP);										  				\
																									\
		/* Read from USB Buffer */ 																	\
		USBFS_ReadOutEP(UART_OUT_EP,&buffer[0],size);												\
																									\
		/* Send to UART Tx */																		\
		UART_Bridge_PutArray(&buffer[0] , size);								 					\
	}																								\
}


/*******************************************************************************
* Macro Name: USBUARTReceive
********************************************************************************
* Summary:
* Checks if the UART has received data and sends it to the USB host 
*******************************************************************************/

#define USBUARTReceive() {																											\
																																	\
	uint8 wCount; 																													\
	uint8 wRxBufferRead;																											\
	uint8 bIndex;																													\
																																	\
	if(UART_Bridge_ReadRxStatus() == UART_Bridge_RX_STS_SOFT_BUFF_OVER)																\
	{																																\
		UART_Bridge_ClearRxBuffer();																								\
	}																																\
																																	\
	/* Get the Received UART data size */																							\
	wCount = UART_Bridge_GetRxBufferSize();                  		 																\
																																	\
	/* Check if Rx has data and USB has finished sending old data */																\
	if( (wCount != 0) && 																											\
	( USBFS_bGetEPState(UART_IN_EP) == USBFS_IN_BUFFER_EMPTY ))																		\
	{																																\
	    /* Limit data size to USB EP Packet Size */																					\
		if( wCount > USBINPACKETSIZE )																								\
	    {																															\
	        wCount = USBINPACKETSIZE;                       																		\
	    }																															\
	    																															\
	    /* Read current Rx Buffer pointer to a temporary pointer */ 																\
		wRxBufferRead = UART_Bridge_rxBufferRead;																					\
	    																															\
	    for( bIndex = 0; bIndex < wCount; bIndex++, wRxBufferRead++)																\
	    {																															\
	        /* Reset temporary Buffer pointer on overflow */ 																		\
	        if(wRxBufferRead >= UART_Bridge_RXBUFFERSIZE)																			\
	        {																														\
	            wRxBufferRead = 0u;																									\
	        }																														\
			/*Load from UART RX Buffer to USB */ 																					\
	        CY_SET_REG8((uint8 *)USBUART_INEP_WRITE_DATA_PTR,  UART_Bridge_rxBuffer[wRxBufferRead]); 								\
	    }																															\
	  																																\
		/* Send out data */																											\
	    TransmittoUSBHost();                  																						\
																																	\
		/* Load new Rx Buffer Pointer */																							\
	    UART_Bridge_rxBufferRead = wRxBufferRead;																					\
		UART_Bridge_rxBufferLoopDetect = 0;																							\
																																	\
	}																																\
}



/*******************************************************************************
* Macro Name: TransmittoUSBHost
********************************************************************************
* Summary:
* Sets registers to transmit from USB INEP Buffer
*
*******************************************************************************/

#define TransmittoUSBHost() {																		\
    																								\
	/* Write WAx */ 																				\
    CY_SET_REG8(USBUART_INEP_WRITE_PTR,     USBFS_EP[UART_IN_EP].buffOffset & 0xFFu);				\
    CY_SET_REG8(USBUART_INEP_WRITE_MSB_PTR, (USBFS_EP[UART_IN_EP].buffOffset >> 8u));				\
    																								\
	/* Set the count and data toggle */																\
    CY_SET_REG8(USBUART_INEP_CNT0_PTR, (wCount >> 8u) | (USBFS_EP[UART_IN_EP].epToggle)); 			\
    CY_SET_REG8(USBUART_INEP_CNT1_PTR,  wCount & 0xFFu); 											\
    																								\
	/* Write the RAx */ 																			\
    CY_SET_REG8(USBUART_INEP_READ_PTR,     USBFS_EP[UART_IN_EP].buffOffset & 0xFFu); 				\
    CY_SET_REG8(USBUART_INEP_READ_MSB_PTR, (USBFS_EP[UART_IN_EP].buffOffset >> 8u)); 				\
																									\
	USBFS_EP[USBFS_EP6].apiEpState = USBFS_NO_EVENT_PENDING; 										\
    																								\
	/* Write the Mode register */ 																	\
    CY_SET_REG8(USBUART_INEP_MODE_REG_PTR, USBFS_EP[UART_IN_EP].epMode); 							\
}


/*******************************************************************************
* Function Name: UARTBridgeComm()
********************************************************************************
* Summary:
* This function handles the USB-UART bridge interface.
* It handles,
* a) Selection of UART clock based on host baud rate
* b) Transmit host packet to UART TX
* c) Transmit UART RX packet to host
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/

void UARTBridgeComm (void)
{
	/* Check for Line configuration change, Reconfigure UART based on host parameters */
	CheckLine();
	
	/* USB to UART Transmit */
	USBUARTTransmit();
	
    /* UART to USB Receive */
	USBUARTReceive();

	return;

}


/*******************************************************************************
* Function Name: USBUARTInit()
********************************************************************************
* Summary:
* Starts the UART, sets Tx Pin to HiZ to save power during enumeration
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/

void USBUARTInit (void)
{

	UART_Bridge_Start();
	Pin_UART_Tx_SetDriveMode(Pin_UART_Tx_DM_DIG_HIZ);

}

/*******************************************************************************
* Function Name: USBUARTStart()
********************************************************************************
* Summary:
* Initializes CDC Interface, Sets Tx Pin to Strong Drive
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/

void USBUARTStart (void)
{
	/* Initialize CDC Interface for USB-UART Bridge */
	USBFS_CDC_Init();
	Pin_UART_Tx_SetDriveMode(Pin_UART_Tx_DM_STRONG);

}


/* [] END OF FILE */

