/*******************************************************************************
* File Name: ADC_Voltage_Target2_AMux.h
* Version 1.60
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_ADC_Voltage_Target2_AMux_H)
#define CY_AMUX_ADC_Voltage_Target2_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void ADC_Voltage_Target2_AMux_Start(void);
# define ADC_Voltage_Target2_AMux_Init() ADC_Voltage_Target2_AMux_Start()
void ADC_Voltage_Target2_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void ADC_Voltage_Target2_AMux_Stop(void); */
/* void ADC_Voltage_Target2_AMux_Select(uint8 channel); */
/* void ADC_Voltage_Target2_AMux_Connect(uint8 channel); */
/* void ADC_Voltage_Target2_AMux_Disconnect(uint8 channel); */
/* void ADC_Voltage_Target2_AMux_DisconnectAll(void) */


/***************************************
*     Initial Parameter Constants
***************************************/

#define ADC_Voltage_Target2_AMux_CHANNELS  2
#define ADC_Voltage_Target2_AMux_MUXTYPE   1
#define ADC_Voltage_Target2_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define ADC_Voltage_Target2_AMux_NULL_CHANNEL  0xFFu
#define ADC_Voltage_Target2_AMux_MUX_SINGLE   1
#define ADC_Voltage_Target2_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if ADC_Voltage_Target2_AMux_MUXTYPE == ADC_Voltage_Target2_AMux_MUX_SINGLE
#if !ADC_Voltage_Target2_AMux_ATMOSTONE
# define ADC_Voltage_Target2_AMux_Connect(channel) ADC_Voltage_Target2_AMux_Set(channel)
#endif
# define ADC_Voltage_Target2_AMux_Disconnect(channel) ADC_Voltage_Target2_AMux_Unset(channel)
#else
#if !ADC_Voltage_Target2_AMux_ATMOSTONE
void ADC_Voltage_Target2_AMux_Connect(uint8 channel) ;
#endif
void ADC_Voltage_Target2_AMux_Disconnect(uint8 channel) ;
#endif

#if ADC_Voltage_Target2_AMux_ATMOSTONE
# define ADC_Voltage_Target2_AMux_Stop() ADC_Voltage_Target2_AMux_DisconnectAll()
# define ADC_Voltage_Target2_AMux_Select(channel) ADC_Voltage_Target2_AMux_FastSelect(channel)
void ADC_Voltage_Target2_AMux_DisconnectAll(void) ;
#else
# define ADC_Voltage_Target2_AMux_Stop() ADC_Voltage_Target2_AMux_Start()
void ADC_Voltage_Target2_AMux_Select(uint8 channel) ;
# define ADC_Voltage_Target2_AMux_DisconnectAll() ADC_Voltage_Target2_AMux_Start()
#endif

#endif /* CY_AMUX_ADC_Voltage_Target2_AMux_H */


/* [] END OF FILE */
