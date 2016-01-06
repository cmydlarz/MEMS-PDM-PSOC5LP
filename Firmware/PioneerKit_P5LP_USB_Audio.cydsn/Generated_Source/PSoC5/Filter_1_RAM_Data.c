#include "Filter_1.h"
#include "Filter_1_PVT.h"

const uint8 CYCODE Filter_1_control[] = 
{
    0x20, 0x13, 0x00, 0x25, 0x61, 0x17, 0x80, 0x26,
    0x01, 0x00, 0x80, 0x26, 0xE0, 0x0E, 0x80, 0x26,
    0xC2, 0x0C, 0x80, 0x26, 0x02, 0x00, 0x80, 0x06,
    0x65, 0x87, 0x18, 0x6D, 0x64, 0x09, 0x18, 0x3E,
    0x00, 0x00, 0x80, 0x26, 0x03, 0x20, 0x80, 0x26,
    0x21, 0x02, 0x18, 0x7F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   };

const uint8 CYCODE Filter_1_data_a[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   };

const uint8 CYCODE Filter_1_data_b[] = 
{
    0x48, 0x03, 0x00, 0x00, 0x17, 0xF0, 0xFF, 0x00,
    0x6F, 0xDC, 0xFF, 0x00, 0x98, 0xC8, 0xFF, 0x00,
    0xDE, 0xB4, 0xFF, 0x00, 0x91, 0xA1, 0xFF, 0x00,
    0xFF, 0x8E, 0xFF, 0x00, 0x78, 0x7D, 0xFF, 0x00,
    0x4B, 0x6D, 0xFF, 0x00, 0xC6, 0x5E, 0xFF, 0x00,
    0x33, 0x52, 0xFF, 0x00, 0xD7, 0x47, 0xFF, 0x00,
    0xF2, 0x3F, 0xFF, 0x00, 0xBE, 0x3A, 0xFF, 0x00,
    0x6F, 0x38, 0xFF, 0x00, 0x2D, 0x39, 0xFF, 0x00,
    0x19, 0x3D, 0xFF, 0x00, 0x4A, 0x44, 0xFF, 0x00,
    0xCC, 0x4E, 0xFF, 0x00, 0x9F, 0x5C, 0xFF, 0x00,
    0xB7, 0x6D, 0xFF, 0x00, 0xFE, 0x81, 0xFF, 0x00,
    0x50, 0x99, 0xFF, 0x00, 0x7D, 0xB3, 0xFF, 0x00,
    0x49, 0xD0, 0xFF, 0x00, 0x6D, 0xEF, 0xFF, 0x00,
    0x94, 0x10, 0x00, 0x00, 0x61, 0x33, 0x00, 0x00,
    0x6C, 0x57, 0x00, 0x00, 0x41, 0x7C, 0x00, 0x00,
    0x67, 0xA1, 0x00, 0x00, 0x5B, 0xC6, 0x00, 0x00,
    0x93, 0xEA, 0x00, 0x00, 0x81, 0x0D, 0x01, 0x00,
    0x91, 0x2E, 0x01, 0x00, 0x2C, 0x4D, 0x01, 0x00,
    0xB9, 0x68, 0x01, 0x00, 0x9E, 0x80, 0x01, 0x00,
    0x3E, 0x94, 0x01, 0x00, 0xFE, 0xA2, 0x01, 0x00,
    0x43, 0xAC, 0x01, 0x00, 0x72, 0xAF, 0x01, 0x00,
    0xF1, 0xAB, 0x01, 0x00, 0x23, 0xA1, 0x01, 0x00,
    0x6B, 0x8E, 0x01, 0x00, 0x25, 0x73, 0x01, 0x00,
    0xA4, 0x4E, 0x01, 0x00, 0x2A, 0x20, 0x01, 0x00,
    0xE2, 0xE6, 0x00, 0x00, 0xCE, 0xA1, 0x00, 0x00,
    0xB9, 0x4F, 0x00, 0x00, 0x15, 0xEF, 0xFF, 0x00,
    0xD2, 0x7D, 0xFF, 0x00, 0x14, 0xF9, 0xFE, 0x00,
    0xC5, 0x5C, 0xFE, 0x00, 0xCE, 0xA2, 0xFD, 0x00,
    0xB9, 0xC1, 0xFC, 0x00, 0x0E, 0xAA, 0xFB, 0x00,
    0xCF, 0x40, 0xFA, 0x00, 0xA2, 0x52, 0xF8, 0x00,
    0xED, 0x70, 0xF5, 0x00, 0x48, 0x7B, 0xF0, 0x00,
    0xB2, 0x4E, 0xE5, 0x00, 0x71, 0xAB, 0xAE, 0x00,
    0x8F, 0x54, 0x51, 0x00, 0x4E, 0xB1, 0x1A, 0x00,
    0xB8, 0x84, 0x0F, 0x00, 0x13, 0x8F, 0x0A, 0x00,
    0x5E, 0xAD, 0x07, 0x00, 0x31, 0xBF, 0x05, 0x00,
    0xF2, 0x55, 0x04, 0x00, 0x47, 0x3E, 0x03, 0x00,
    0x32, 0x5D, 0x02, 0x00, 0x3B, 0xA3, 0x01, 0x00,
    0xEC, 0x06, 0x01, 0x00, 0x2E, 0x82, 0x00, 0x00,
    0xEB, 0x10, 0x00, 0x00, 0x47, 0xB0, 0xFF, 0x00,
    0x32, 0x5E, 0xFF, 0x00, 0x1E, 0x19, 0xFF, 0x00,
    0xD6, 0xDF, 0xFE, 0x00, 0x5C, 0xB1, 0xFE, 0x00,
    0xDB, 0x8C, 0xFE, 0x00, 0x95, 0x71, 0xFE, 0x00,
    0xDD, 0x5E, 0xFE, 0x00, 0x0F, 0x54, 0xFE, 0x00,
    0x8E, 0x50, 0xFE, 0x00, 0xBD, 0x53, 0xFE, 0x00,
    0x02, 0x5D, 0xFE, 0x00, 0xC2, 0x6B, 0xFE, 0x00,
    0x62, 0x7F, 0xFE, 0x00, 0x47, 0x97, 0xFE, 0x00,
    0xD4, 0xB2, 0xFE, 0x00, 0x6F, 0xD1, 0xFE, 0x00,
    0x7F, 0xF2, 0xFE, 0x00, 0x6D, 0x15, 0xFF, 0x00,
    0xA5, 0x39, 0xFF, 0x00, 0x99, 0x5E, 0xFF, 0x00,
    0xBF, 0x83, 0xFF, 0x00, 0x94, 0xA8, 0xFF, 0x00,
    0x9F, 0xCC, 0xFF, 0x00, 0x6C, 0xEF, 0xFF, 0x00,
    0x93, 0x10, 0x00, 0x00, 0xB7, 0x2F, 0x00, 0x00,
    0x83, 0x4C, 0x00, 0x00, 0xB0, 0x66, 0x00, 0x00,
    0x02, 0x7E, 0x00, 0x00, 0x49, 0x92, 0x00, 0x00,
    0x61, 0xA3, 0x00, 0x00, 0x34, 0xB1, 0x00, 0x00,
    0xB6, 0xBB, 0x00, 0x00, 0xE7, 0xC2, 0x00, 0x00,
    0xD3, 0xC6, 0x00, 0x00, 0x91, 0xC7, 0x00, 0x00,
    0x42, 0xC5, 0x00, 0x00, 0x0E, 0xC0, 0x00, 0x00,
    0x29, 0xB8, 0x00, 0x00, 0xCD, 0xAD, 0x00, 0x00,
    0x3A, 0xA1, 0x00, 0x00, 0xB5, 0x92, 0x00, 0x00,
    0x88, 0x82, 0x00, 0x00, 0x01, 0x71, 0x00, 0x00,
    0x6F, 0x5E, 0x00, 0x00, 0x22, 0x4B, 0x00, 0x00,
    0x68, 0x37, 0x00, 0x00, 0x91, 0x23, 0x00, 0x00,
    0xE9, 0x0F, 0x00, 0x00, 0xB8, 0xFC, 0xFF, 0x00,
   };

const uint8 CYCODE Filter_1_acu[] = 
{
    0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   };

const uint8 CYCODE Filter_1_cfsm[] = 
{
    0x21, 0xF8, 0x05, 0x01, 0x42, 0x10, 0x86, 0x40,
    0x64, 0xF8, 0x15, 0x01, 0x81, 0xF8, 0x05, 0x01,
    0x43, 0x51, 0x8E, 0x21, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   };
