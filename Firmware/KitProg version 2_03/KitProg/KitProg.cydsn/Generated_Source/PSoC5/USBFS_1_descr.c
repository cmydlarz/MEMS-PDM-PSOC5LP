/*******************************************************************************
* File Name: USBFS_descr.c
* Version 2.50
*
* Description:
*  USB descriptors and storage.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBFS.h"


/*****************************************************************************
*  User supplied descriptors.  If you want to specify your own descriptors,
*  remove the comments around the define USER_SUPPLIED_DESCRIPTORS below and
*  add your descriptors.
*****************************************************************************/
/* `#START USER_DESCRIPTORS_DECLARATIONS` Place your declaration here */
#include "kitprog.h"

#define USER_SUPPLIED_DESCRIPTORS

/*********************************************************************
* Device Descriptors
*********************************************************************/
const uint8 CYCODE USBFS_DEVICE0_DESCR[] = {
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: DEVICE                  */ 0x01u,
/* bcdUSB (ver 2.0)                        */ 0x00u, 0x02u,
/* bDeviceClass                            */ 0xEFu,
/* bDeviceSubClass                         */ 0x02u,
/* bDeviceProtocol                         */ 0x01u,
/* bMaxPacketSize0                         */ 0x08u,
/* idVendor                                */ 0xB4u, 0x04u,
/* idProduct                               */ 0x39u, 0xF1u,
/* bcdDevice                               */ 0x02u, 0x01u,
/* iManufacturer                           */ 0x01u,
/* iProduct                                */ 0x02u,
/* iSerialNumber                           */ 0x80u,
/* bNumConfigurations                      */ 0x01u
};
/*********************************************************************
* Config Descriptor  
*********************************************************************/
const uint8 CYCODE USBFS_DEVICE0_CONFIGURATION0_DESCR[] = {
/*  Config Descriptor Length               */ 0x09u,
/*  DescriptorType: CONFIG                 */ 0x02u,
/*  wTotalLength                           */ 0x82u, 0x00u,
/*  bNumInterfaces                         */ 0x04u,
/*  bConfigurationValue                    */ 0x01u,
/*  iConfiguration                         */ 0x02u,
/*  bmAttributes                           */ 0x80u,
/*  bMaxPower                              */ 0xC8u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x00u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x03u,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x05u,
/*********************************************************************
* HID Class Descriptor
*********************************************************************/
/*  HID Class Descriptor Length            */ 0x09u,
/*  DescriptorType: HID_CLASS              */ 0x21u,
/*  bcdHID                                 */ 0x11u, 0x01u,
/*  bCountryCode                           */ 0x00u,
/*  bNumDescriptors                        */ 0x01u,
/*  bDescriptorType                        */ 0x22u,
/*  wDescriptorLength (LSB)                */ USBFS_HID_RPT_1_SIZE_LSB,
/*  wDescriptorLength (MSB)                */ USBFS_HID_RPT_1_SIZE_MSB,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x83u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x04u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x01u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x01u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0xFFu,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x03u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x81u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x02u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,

/*********************************************************************
 Interface Association Descriptor
 *********************************************************************/
/*  Descriptor Length            	       */ 0x08u,
/*  DescriptorType: IAD              	   */ 0x0Bu,
/*  bFirstInterface                        */ 0x02u,
/*  bInterfaceCount                        */ 0x02u,
/*  bFunctionClass                         */ 0x02u,
/*  bFunctionSubClass :                	   */ 0x00u,
/*  bFunctionProtocol :           		   */ 0x00u,
/*  iFunction                              */ 0x06u,

/*********************************************************************
* CDC Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x02u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x02u,
/*  bInterfaceSubClass                     */ 0x02u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x07u,
/*********************************************************************
* Header Descriptor
*********************************************************************/
/*  Header Descriptor Length               */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x00u,
/*  bcdADC                                 */ 0x10u, 0x01u,
/*********************************************************************
* Abstract Control Management Descriptor
*********************************************************************/
/*  Abstract Control Management Descriptor Length*/ 0x04u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x02u,
/*  bmCapabilities                         */ 0x02u,
/*********************************************************************
* Union Descriptor
*********************************************************************/
/*  Union Descriptor Length                */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x06u,
/*  bControlInterface                      */ 0x00u,
/*  bSubordinateInterface                  */ 0x01u,
/*********************************************************************
* Call Management Descriptor
*********************************************************************/
/*  Call Management Descriptor Length      */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x01u,
/*  bmCapabilities                         */ 0x00u,
/*  bDataInterface                         */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x85u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x08u, 0x00u,
/*  bInterval                              */ 0x02u,
/*********************************************************************
* Data Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x03u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x0Au,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x08u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x86u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x07u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u
};

/*********************************************************************
* String Descriptor Table
*********************************************************************/
const uint8 CYCODE USBFS_STRING_DESCRIPTORS[] = {
/*********************************************************************
* Language ID Descriptor
*********************************************************************/
/* Descriptor Length                       */ 0x04u,
/* DescriptorType: STRING                  */ 0x03u,
/* Language Id                             */ 0x09u, 0x04u,
/*********************************************************************
* String Descriptor: "Cypress Semiconductor"
*********************************************************************/
/* Descriptor Length                       */ 0x2Cu,
/* DescriptorType: STRING                  */ 0x03u,
 'C', 0,'y', 0,'p', 0,'r', 0,'e', 0,'s', 0,'s', 0,' ', 0,'S', 0,'e', 0
,'m', 0,'i', 0,'c', 0,'o', 0,'n', 0,'d', 0,'u', 0,'c', 0,'t', 0,'o', 0
,'r', 0,
/*********************************************************************
* String Descriptor: "Cypress KitProg"
*********************************************************************/
/* Descriptor Length                       */ 0x20u,
/* DescriptorType: STRING                  */ 0x03u,
 'C', 0,'y', 0,'p', 0,'r', 0,'e', 0,'s', 0,'s', 0,' ', 0,'K', 0,'i', 0
,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,
/*********************************************************************
* String Descriptor: "KitProg Programmer"
*********************************************************************/
/* Descriptor Length                       */ 0x26u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'P', 0,'r', 0
,'o', 0,'g', 0,'r', 0,'a', 0,'m', 0,'m', 0,'e', 0,'r', 0,
/*********************************************************************
* String Descriptor: "KitProg Bridge"
*********************************************************************/
/* Descriptor Length                       */ 0x1Eu,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'B', 0,'r', 0
,'i', 0,'d', 0,'g', 0,'e', 0,
/*********************************************************************
* String Descriptor: "KitBridge"
*********************************************************************/
/* Descriptor Length                       */ 0x14u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'B', 0,'r', 0,'i', 0,'d', 0,'g', 0,'e', 0,
/*********************************************************************
* String Descriptor: "KitProg"
*********************************************************************/
/* Descriptor Length                       */ 0x10u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,
/*********************************************************************
* String Descriptor: "KitProg USBUART"
*********************************************************************/
/* Descriptor Length                       */ 0x20u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'U', 0,'S', 0
,'B', 0,'U', 0,'A', 0,'R', 0,'T', 0,
/*********************************************************************
* String Descriptor: "KitProg USBUART"
*********************************************************************/
/* Descriptor Length                       */ 0x20u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'U', 0,'S', 0
,'B', 0,'U', 0,'A', 0,'R', 0,'T', 0,
/*********************************************************************/
/* Marks the end of the list.              */ 0x00u};
/*********************************************************************/

/*********************************************************************
* Serial Number String Descriptor
*********************************************************************/
const uint8 CYCODE USBFS_SN_STRING_DESCRIPTOR[] = {
/* Descriptor Length                       */ 0x02u,
/* DescriptorType: STRING                  */ 0x03u,

};

/*********************************************************************
* HID Report Descriptor: HID Report Descriptor
*********************************************************************/
const uint8 CYCODE USBFS_HIDREPORT_DESCRIPTOR1[] = {
/*  Descriptor Size (Not part of descriptor)*/ USBFS_HID_RPT_1_SIZE_LSB,
USBFS_HID_RPT_1_SIZE_MSB,
/* USAGE_PAGE                              */ 0x06u, 0xA0u, 0xFFu, 
/* USAGE                                   */ 0x09u, 0x01u, 
/* COLLECTION                              */ 0xA1u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x02u, 
/* COLLECTION                              */ 0xA1u, 0x00u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x03u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x43u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0xFFu, 0x00u, 
/* REPORT_SIZE                             */ 0x75u, 0x08u, 
/* REPORT_COUNT                            */ 0x95u, 0x40u, 
/* OUTPUT                                  */ 0x91u, 0x02u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x44u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x74u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0xFFu, 0x00u, 
/* REPORT_SIZE                             */ 0x75u, 0x08u, 
/* REPORT_COUNT                            */ 0x95u, 0x40u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* END_COLLECTION                          */ 0xC0u, 
/* END_COLLECTION                          */ 0xC0u, 
/*********************************************************************/
/* End of the HID Report Descriptor        */ 0x00u, 0x00u};
/*********************************************************************/
/*********************************************************************
* HID Report Descriptor: HID Report Descriptor 1
*********************************************************************/
const uint8 CYCODE USBFS_HIDREPORT_DESCRIPTOR2[] = {
/*  Descriptor Size (Not part of descriptor)*/ USBFS_HID_RPT_2_SIZE_LSB,
USBFS_HID_RPT_2_SIZE_MSB,
/* USAGE_PAGE                              */ 0x05u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x02u, 
/* COLLECTION                              */ 0xA1u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x01u, 
/* COLLECTION                              */ 0xA1u, 0x00u, 
/* USAGE_PAGE                              */ 0x05u, 0x09u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x01u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x03u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x25u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x03u, 
/* REPORT_SIZE                             */ 0x75u, 0x01u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* REPORT_COUNT                            */ 0x95u, 0x01u, 
/* REPORT_SIZE                             */ 0x75u, 0x05u, 
/* INPUT                                   */ 0x81u, 0x01u, 
/* USAGE_PAGE                              */ 0x05u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x30u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0xD6u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x01u, 
/* REPORT_SIZE                             */ 0x75u, 0x10u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* USAGE                                   */ 0x09u, 0x31u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0x72u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x01u, 
/* REPORT_SIZE                             */ 0x75u, 0x10u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* END_COLLECTION                          */ 0xC0u, 
/* END_COLLECTION                          */ 0xC0u, 
/*********************************************************************/
/* End of the HID Report Descriptor        */ 0x00u, 0x00u};
/*********************************************************************/

#define USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_HID_RPT_STORAGE
/*********************************************************************
* HID Input Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF_SIZE];

/*********************************************************************
* HID Input Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_TABLE[] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF[0],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_SCB},
};
/*********************************************************************
* HID Output Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF_SIZE];

/*********************************************************************
* HID Output Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_TABLE[] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF[0],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_SCB},
};
/*********************************************************************
* HID Report Look Up Table         This table has four entries:
*                                        IN Report Table
*                                        OUT Report Table
*                                        Feature Report Table
*                                        HID Report Descriptor
*                                        HID Class Descriptor
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_TABLE[] = {
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_TABLE},
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_TABLE},
    {0x00u,    NULL},
    {0x01u,     (void *)&USBFS_HIDREPORT_DESCRIPTOR1[0]},
    {0x01u,     (void *)&USBFS_DEVICE0_CONFIGURATION0_DESCR[18]}
};


/*********************************************************************
* Interface Dispatch Table -- Points to the Class Dispatch Tables
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_TABLE[] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_COUNT, 
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_TABLE}
};
/*********************************************************************
* Endpoint Setting Table -- This table contain the endpoint setting
*                           for each endpoint in the configuration. It
*                           contains the necessary information to
*                           configure the endpoint hardware for each
*                           interface and alternate setting.
*********************************************************************/
const T_USBFS_EP_SETTINGS_BLOCK CYCODE USBFS_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[] = {
/* IFC  ALT    EPAddr bmAttr MaxPktSize Class ********************/
{0x00u, 0x00u, 0x83u, 0x03u, 0x0040u,   0x03u},
{0x00u, 0x00u, 0x04u, 0x03u, 0x0040u,   0x03u},
{0x01u, 0x00u, 0x81u, 0x02u, 0x0040u,   0xFFu},
{0x01u, 0x00u, 0x02u, 0x02u, 0x0040u,   0xFFu},
{0x02u, 0x00u, 0x85u, 0x03u, 0x0008u,   0x02u},
{0x03u, 0x00u, 0x86u, 0x02u, 0x0040u,   0x0Au},
{0x03u, 0x00u, 0x07u, 0x02u, 0x0040u,   0x0Au}
};
const uint8 CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[] = {
0x03u, 0xFFu, 0x02u, 0x0Au
};
/*********************************************************************
* Config Dispatch Table -- Points to the Config Descriptor and each of
*                          and endpoint setup table and to each
*                          interface table if it specifies a USB Class
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_TABLE[] = {
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_DESCR},
    {0x07u,     &USBFS_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_TABLE},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE_CLASS}
};
/*********************************************************************
* Device Dispatch Table -- Points to the Device Descriptor and each of
*                          and Configuration Tables for this Device 
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_TABLE[] = {
    {0x01u,     &USBFS_DEVICE0_DESCR},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_TABLE}
};
/*********************************************************************
* Device Table -- Indexed by the device number.
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_TABLE[] = {
    {0x01u,     &USBFS_DEVICE0_TABLE}
};

/* `#END` */


/***************************************
*  USB Customizer Generated Descriptors
***************************************/

#if !defined(USER_SUPPLIED_DESCRIPTORS)
/*********************************************************************
* Device Descriptors
*********************************************************************/
const uint8 CYCODE USBFS_DEVICE0_DESCR[] = {
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: DEVICE                  */ 0x01u,
/* bcdUSB (ver 2.0)                        */ 0x00u, 0x02u,
/* bDeviceClass                            */ 0x00u,
/* bDeviceSubClass                         */ 0x00u,
/* bDeviceProtocol                         */ 0x00u,
/* bMaxPacketSize0                         */ 0x08u,
/* idVendor                                */ 0xB4u, 0x04u,
/* idProduct                               */ 0x40u, 0xF1u,
/* bcdDevice                               */ 0x00u, 0x01u,
/* iManufacturer                           */ 0x01u,
/* iProduct                                */ 0x02u,
/* iSerialNumber                           */ 0x80u,
/* bNumConfigurations                      */ 0x01u
};
/*********************************************************************
* Config Descriptor  
*********************************************************************/
const uint8 CYCODE USBFS_DEVICE0_CONFIGURATION0_DESCR[] = {
/*  Config Descriptor Length               */ 0x09u,
/*  DescriptorType: CONFIG                 */ 0x02u,
/*  wTotalLength                           */ 0x7Au, 0x00u,
/*  bNumInterfaces                         */ 0x04u,
/*  bConfigurationValue                    */ 0x01u,
/*  iConfiguration                         */ 0x02u,
/*  bmAttributes                           */ 0x80u,
/*  bMaxPower                              */ 0xC8u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x00u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x03u,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x05u,
/*********************************************************************
* HID Class Descriptor
*********************************************************************/
/*  HID Class Descriptor Length            */ 0x09u,
/*  DescriptorType: HID_CLASS              */ 0x21u,
/*  bcdHID                                 */ 0x11u, 0x01u,
/*  bCountryCode                           */ 0x00u,
/*  bNumDescriptors                        */ 0x01u,
/*  bDescriptorType                        */ 0x22u,
/*  wDescriptorLength (LSB)                */ USBFS_HID_RPT_1_SIZE_LSB,
/*  wDescriptorLength (MSB)                */ USBFS_HID_RPT_1_SIZE_MSB,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x83u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x04u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x01u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x01u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0xFFu,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x03u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x81u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x02u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* CDC Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x02u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x02u,
/*  bInterfaceSubClass                     */ 0x02u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x09u,
/*********************************************************************
* Header Descriptor
*********************************************************************/
/*  Header Descriptor Length               */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x00u,
/*  bcdADC                                 */ 0x10u, 0x01u,
/*********************************************************************
* Abstract Control Management Descriptor
*********************************************************************/
/*  Abstract Control Management Descriptor Length*/ 0x04u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x02u,
/*  bmCapabilities                         */ 0x02u,
/*********************************************************************
* Union Descriptor
*********************************************************************/
/*  Union Descriptor Length                */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x06u,
/*  bControlInterface                      */ 0x00u,
/*  bSubordinateInterface                  */ 0x01u,
/*********************************************************************
* Call Management Descriptor
*********************************************************************/
/*  Call Management Descriptor Length      */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x01u,
/*  bmCapabilities                         */ 0x00u,
/*  bDataInterface                         */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x85u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x08u, 0x00u,
/*  bInterval                              */ 0x02u,
/*********************************************************************
* Data Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x03u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x0Au,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x09u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x86u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x07u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u
};

/*********************************************************************
* String Descriptor Table
*********************************************************************/
const uint8 CYCODE USBFS_STRING_DESCRIPTORS[] = {
/*********************************************************************
* Language ID Descriptor
*********************************************************************/
/* Descriptor Length                       */ 0x04u,
/* DescriptorType: STRING                  */ 0x03u,
/* Language Id                             */ 0x09u, 0x04u,
/*********************************************************************
* String Descriptor: "Cypress Semiconductor"
*********************************************************************/
/* Descriptor Length                       */ 0x2Cu,
/* DescriptorType: STRING                  */ 0x03u,
 'C', 0,'y', 0,'p', 0,'r', 0,'e', 0,'s', 0,'s', 0,' ', 0,'S', 0,'e', 0
,'m', 0,'i', 0,'c', 0,'o', 0,'n', 0,'d', 0,'u', 0,'c', 0,'t', 0,'o', 0
,'r', 0,
/*********************************************************************
* String Descriptor: "Cypress KitProg"
*********************************************************************/
/* Descriptor Length                       */ 0x20u,
/* DescriptorType: STRING                  */ 0x03u,
 'C', 0,'y', 0,'p', 0,'r', 0,'e', 0,'s', 0,'s', 0,' ', 0,'K', 0,'i', 0
,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,
/*********************************************************************
* String Descriptor: "KitProg Programmer"
*********************************************************************/
/* Descriptor Length                       */ 0x26u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'P', 0,'r', 0
,'o', 0,'g', 0,'r', 0,'a', 0,'m', 0,'m', 0,'e', 0,'r', 0,
/*********************************************************************
* String Descriptor: "KitProg Bridge"
*********************************************************************/
/* Descriptor Length                       */ 0x1Eu,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'B', 0,'r', 0
,'i', 0,'d', 0,'g', 0,'e', 0,
/*********************************************************************
* String Descriptor: "KitBridge"
*********************************************************************/
/* Descriptor Length                       */ 0x14u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'B', 0,'r', 0,'i', 0,'d', 0,'g', 0,'e', 0,
/*********************************************************************
* String Descriptor: "KitProg"
*********************************************************************/
/* Descriptor Length                       */ 0x10u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,
/*********************************************************************
* String Descriptor: "KitProg USBUART"
*********************************************************************/
/* Descriptor Length                       */ 0x20u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'U', 0,'S', 0
,'B', 0,'U', 0,'A', 0,'R', 0,'T', 0,
/*********************************************************************
* String Descriptor: "KitProg USBUART"
*********************************************************************/
/* Descriptor Length                       */ 0x20u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'P', 0,'r', 0,'o', 0,'g', 0,' ', 0,'U', 0,'S', 0
,'B', 0,'U', 0,'A', 0,'R', 0,'T', 0,
/*********************************************************************
* String Descriptor: "KitBridge USBUART"
*********************************************************************/
/* Descriptor Length                       */ 0x24u,
/* DescriptorType: STRING                  */ 0x03u,
 'K', 0,'i', 0,'t', 0,'B', 0,'r', 0,'i', 0,'d', 0,'g', 0,'e', 0,' ', 0
,'U', 0,'S', 0,'B', 0,'U', 0,'A', 0,'R', 0,'T', 0,
/*********************************************************************/
/* Marks the end of the list.              */ 0x00u};
/*********************************************************************/

/*********************************************************************
* Serial Number String Descriptor
*********************************************************************/
const uint8 CYCODE USBFS_SN_STRING_DESCRIPTOR[] = {
/* Descriptor Length                       */ 0x02u,
/* DescriptorType: STRING                  */ 0x03u,

};

/*********************************************************************
* HID Report Descriptor: HID Report Descriptor
*********************************************************************/
const uint8 CYCODE USBFS_HIDREPORT_DESCRIPTOR1[] = {
/*  Descriptor Size (Not part of descriptor)*/ USBFS_HID_RPT_1_SIZE_LSB,
USBFS_HID_RPT_1_SIZE_MSB,
/* USAGE_PAGE                              */ 0x06u, 0xA0u, 0xFFu, 
/* USAGE                                   */ 0x09u, 0x01u, 
/* COLLECTION                              */ 0xA1u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x02u, 
/* COLLECTION                              */ 0xA1u, 0x00u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x03u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x43u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0xFFu, 0x00u, 
/* REPORT_SIZE                             */ 0x75u, 0x08u, 
/* REPORT_COUNT                            */ 0x95u, 0x40u, 
/* OUTPUT                                  */ 0x91u, 0x02u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x44u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x74u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0xFFu, 0x00u, 
/* REPORT_SIZE                             */ 0x75u, 0x08u, 
/* REPORT_COUNT                            */ 0x95u, 0x40u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* END_COLLECTION                          */ 0xC0u, 
/* END_COLLECTION                          */ 0xC0u, 
/*********************************************************************/
/* End of the HID Report Descriptor        */ 0x00u, 0x00u};
/*********************************************************************/
/*********************************************************************
* HID Report Descriptor: HID Report Descriptor 1
*********************************************************************/
const uint8 CYCODE USBFS_HIDREPORT_DESCRIPTOR2[] = {
/*  Descriptor Size (Not part of descriptor)*/ USBFS_HID_RPT_2_SIZE_LSB,
USBFS_HID_RPT_2_SIZE_MSB,
/* USAGE_PAGE                              */ 0x05u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x02u, 
/* COLLECTION                              */ 0xA1u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x01u, 
/* COLLECTION                              */ 0xA1u, 0x00u, 
/* USAGE_PAGE                              */ 0x05u, 0x09u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x01u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x03u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x25u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x03u, 
/* REPORT_SIZE                             */ 0x75u, 0x01u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* REPORT_COUNT                            */ 0x95u, 0x01u, 
/* REPORT_SIZE                             */ 0x75u, 0x05u, 
/* INPUT                                   */ 0x81u, 0x01u, 
/* USAGE_PAGE                              */ 0x05u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x30u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0xD6u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x01u, 
/* REPORT_SIZE                             */ 0x75u, 0x10u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* USAGE                                   */ 0x09u, 0x31u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x26u, 0x72u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x01u, 
/* REPORT_SIZE                             */ 0x75u, 0x10u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/* END_COLLECTION                          */ 0xC0u, 
/* END_COLLECTION                          */ 0xC0u, 
/*********************************************************************/
/* End of the HID Report Descriptor        */ 0x00u, 0x00u};
/*********************************************************************/

#if !defined(USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_HID_RPT_STORAGE)
/*********************************************************************
* HID Input Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF_SIZE];

/*********************************************************************
* HID Input Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_TABLE[] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF[0],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_SCB},
};
/*********************************************************************
* HID Output Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF_SIZE];

/*********************************************************************
* HID Output Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_TABLE[] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_BUF[0],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_SCB},
};
/*********************************************************************
* HID Report Look Up Table         This table has four entries:
*                                        IN Report Table
*                                        OUT Report Table
*                                        Feature Report Table
*                                        HID Report Descriptor
*                                        HID Class Descriptor
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_TABLE[] = {
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_TABLE},
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_OUT_RPT_TABLE},
    {0x00u,    NULL},
    {0x01u,     (void *)&USBFS_HIDREPORT_DESCRIPTOR1[0]},
    {0x01u,     (void *)&USBFS_DEVICE0_CONFIGURATION0_DESCR[18]}
};
#endif /* USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_HID_RPT_STORAGE */

/*********************************************************************
* Interface Dispatch Table -- Points to the Class Dispatch Tables
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_TABLE[] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_COUNT, 
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_TABLE}
};
/*********************************************************************
* Endpoint Setting Table -- This table contain the endpoint setting
*                           for each endpoint in the configuration. It
*                           contains the necessary information to
*                           configure the endpoint hardware for each
*                           interface and alternate setting.
*********************************************************************/
const T_USBFS_EP_SETTINGS_BLOCK CYCODE USBFS_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[] = {
/* IFC  ALT    EPAddr bmAttr MaxPktSize Class ********************/
{0x00u, 0x00u, 0x83u, 0x03u, 0x0040u,   0x03u},
{0x00u, 0x00u, 0x04u, 0x03u, 0x0040u,   0x03u},
{0x01u, 0x00u, 0x81u, 0x02u, 0x0040u,   0xFFu},
{0x01u, 0x00u, 0x02u, 0x02u, 0x0040u,   0xFFu},
{0x02u, 0x00u, 0x85u, 0x03u, 0x0008u,   0x02u},
{0x03u, 0x00u, 0x86u, 0x02u, 0x0040u,   0x0Au},
{0x03u, 0x00u, 0x07u, 0x02u, 0x0040u,   0x0Au}
};
const uint8 CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[] = {
0x03u, 0xFFu, 0x02u, 0x0Au
};
/*********************************************************************
* Config Dispatch Table -- Points to the Config Descriptor and each of
*                          and endpoint setup table and to each
*                          interface table if it specifies a USB Class
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_TABLE[] = {
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_DESCR},
    {0x07u,     &USBFS_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_TABLE},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE_CLASS}
};
/*********************************************************************
* Device Dispatch Table -- Points to the Device Descriptor and each of
*                          and Configuration Tables for this Device 
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_TABLE[] = {
    {0x01u,     &USBFS_DEVICE0_DESCR},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_TABLE}
};
/*********************************************************************
* Device Table -- Indexed by the device number.
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_TABLE[] = {
    {0x01u,     &USBFS_DEVICE0_TABLE}
};

#endif /* USER_SUPPLIED_DESCRIPTORS */

#if defined(USBFS_ENABLE_MSOS_STRING)

    /******************************************************************************
    *  USB Microsoft OS String Descriptor
    *  "MSFT" identifies a Microsoft host
    *  "100" specifies version 1.00
    *  USBFS_GET_EXTENDED_CONFIG_DESCRIPTOR becomes the bRequest value
    *  in a host vendor device/class request
    ******************************************************************************/

    const uint8 CYCODE USBFS_MSOS_DESCRIPTOR[] = {
    /* Descriptor Length                       */   0x12u,
    /* DescriptorType: STRING                  */   0x03u,
    /* qwSignature */                               'M', 0, 'S', 0, 'F', 0, 'T', 0, '1', 0, '0', 0, '0', 0,
    /* bMS_VendorCode:                         */   USBFS_GET_EXTENDED_CONFIG_DESCRIPTOR,
    /* bPad                                    */   0x00u
    };

    /* Extended Configuration Descriptor */

    const uint8 CYCODE USBFS_MSOS_CONFIGURATION_DESCR[] = {
    /*  Length of the descriptor 4 bytes       */   0x28u, 0x00u, 0x00u, 0x00u,
    /*  Version of the descriptor 2 bytes      */   0x00u, 0x01u,
    /*  wIndex - Fixed:INDEX_CONFIG_DESCRIPTOR */   0x04u, 0x00u,
    /*  bCount - Count of device functions.    */   0x01u,
    /*  Reserved : 7 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    /*  bFirstInterfaceNumber                  */   0x00u,
    /*  Reserved                               */   0x01u,
    /*  compatibleID    - "CYUSB\0\0"          */   'C', 'Y', 'U', 'S', 'B', 0x00, 0x00u, 0x00u,
    /*  subcompatibleID - "00001\0\0"          */   '0', '0', '0', '0', '1', 0x00, 0x00u, 0x00u,
    /*  Reserved : 6 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };

#endif /* USBFS_ENABLE_MSOS_STRING */


/* [] END OF FILE */
