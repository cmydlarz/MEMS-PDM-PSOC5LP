/*****************************************************************************
* File Name: USBFS_HID_interface.h
* Version 2.03
*
* Description:
*  This file contains the function prototypes and constants used in
*  the USBFS_HID_interface.c.
*
* Note:
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
#if !defined(USB_HID_INTERFACE_H) 
#define USB_HID_INTERFACE_H 

/*****************************************************************************
* MACRO Definition
*****************************************************************************/
/* Macros used in power supply monitoring */
#define ACK_WITHOUT_POWER			0x01
#define POWER_SUPPLIED				0x01
#define ACK_WITH_POWER 				0x05


/* Host communication interface */
#define INTERFACE_I2C               0x00

/* USB-I2C protocol */
#define CONTROL_DIRECTION           0x01
#define CONTROL_START               0x02
#define CONTROL_RESTART             0x04
#define CONTROL_STOP                0x08
#define CONTROL_RESTART_HW          0x10
#define CONTROL_CONFIGURE           0x20
#define CONTROL_INTERFACE           0x0C

#define CONTROL_DIRECTION_WRITE     0x00
#define CONTROL_DIRECTION_READ      0x01

/* I2C speed mask */
#define CONFIG_I2C_SPEED_MSK    	0x0C
#define I2C_SPEED_1000				0x0C
#define I2C_SPEED_400				0x04
#define I2C_SPEED_100				0x00	
#define I2C_SPEED_050				0x08	

/* I2C response macros */
#define NACK						0x00
#define OK_ACK						0x01
#define RESTART_FAIL				0x00
#define RESTART_SUCCESS				0x01
#define TIMEOUT						0x32

#define PACKET_VALID				0x80
#define GET_POWER_SETTING			0x80
#define GET_KITPROG_VERSION			0x81
#define RESET_KITPROG				0x82
#define CONFIGURE_INTERFACE			0x8F
#define ENTER_BOOTLOADER			0xA0

#define ONE_VOLT					1000
#define CONTINUE					0x00
#define EXIT						0x01
/*****************************************************************************
* Data Type Definition
*****************************************************************************/



/*****************************************************************************
* Enumerated Data Definition
*****************************************************************************/


/*****************************************************************************
* Data Struct Definition
*****************************************************************************/


/*****************************************************************************
* Global Variable Declaration
*****************************************************************************/
extern uint8 i2cSpeed;
extern uint8 bI2CIntFace;
extern uint8 bOutEndpointData[64];
extern uint8 bInEndpointData[64];
extern uint8 bBulkInEndpointData[513];
extern uint8 bOutPacketIndex;
extern uint8 bInPacketIndex;
/*****************************************************************************
* External Function Prototypes
*****************************************************************************/
void I2C_DSIBypassDisable(void);
void I2C_DSIBypassEnable(void);
void SendToUSB(void);
/*****************************************************************************
* External Function Prototypes
*****************************************************************************/
extern void HostCommInit(void);
extern void HostComm(void);
extern void HostCommStop();
extern void I2CPullUpDisable(void);

#endif /* USB_HID_INTERFACE_H */
