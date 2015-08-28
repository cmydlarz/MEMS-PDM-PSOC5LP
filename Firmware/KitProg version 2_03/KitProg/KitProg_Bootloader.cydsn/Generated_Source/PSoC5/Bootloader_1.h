/*******************************************************************************
* File Name: Bootloader_1.h
* Version 1.0
*
*  Description:
*   Provides an API for the Bootloader. The API includes functions for starting
*   boot loading operations, validating the application and jumping to the
*   application.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_BOOTLOADER_Bootloader_1_H)
#define CY_BOOTLOADER_Bootloader_1_H

#include "device.h"
#include <string.h>


/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Bootloader_v1_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5X) */

/* Map existing call to the instance specific one */
#define CyBtldr_Start   Bootloader_1_Start

#define Bootloader_1_DUAL_APP_BOOTLOADER        (0)
#define Bootloader_1_BOOTLOADER_APP_VERSION     (1)
#define Bootloader_1_FAST_APP_VALIDATION        (0)
#define Bootloader_1_PACKET_CHECKSUM_CRC        (0)
#define Bootloader_1_WAIT_FOR_COMMAND           (0)
#define Bootloader_1_WAIT_FOR_COMMAND_TIME      (200)
#define Bootloader_1_BOOTLOADABLE_APP_VALID     (1)

#define Bootloader_1_CMD_GET_FLASH_SIZE_AVAIL   (1)
#define Bootloader_1_CMD_ERASE_ROW_AVAIL        (1)
#define Bootloader_1_CMD_VERIFY_ROW_AVAIL       (1)
#define Bootloader_1_CMD_SYNC_BOOTLOADER_AVAIL  (1)
#define Bootloader_1_CMD_SEND_DATA_AVAIL        (1)

#if(0u != Bootloader_1_DUAL_APP_BOOTLOADER)
    #define Bootloader_1_CMD_GET_APP_STATUS_AVAIL   (1)
#endif  /* (0u != Bootloader_1_DUAL_APP_BOOTLOADER) */


/*******************************************************************************
* A common code for the Bootloader and Bootloadable
*******************************************************************************/

/* Mask used to indicate starting application */
#define Bootloader_1_START_APP                      0x80

 /* Mask used to indicate starting bootloader */
#define Bootloader_1_START_BTLDR                    0x40


#ifndef CYDEV_FLASH_BASE
    #define CYDEV_FLASH_BASE                            CYDEV_FLS_BASE
    #define CYDEV_FLASH_SIZE                            CYDEV_FLS_SIZE
#endif /* CYDEV_FLASH_BASE */


#define Bootloader_1_META_DATA_SIZE                 64
#define Bootloader_1_META_APP_CHECKSUM_OFFSET       0


#if(CY_PSOC3)

    #define Bootloader_1_APP_ADDRESS                uint16
    #define Bootloader_1_GET_CODE_DATA(idx)         *((uint8  CYCODE *) idx)
    #define Bootloader_1_GET_CODE_WORD(idx)         *((uint32 CYCODE *) idx)

    /* Offset by 2 from 32 bit start because only need 16 bits */
    #define Bootloader_1_META_APP_ADDR_OFFSET           3       /* 2 bytes */
    #define Bootloader_1_META_APP_BL_LAST_ROW_OFFSET    7       /* 4 bytes */
    #define Bootloader_1_META_APP_BYTE_LEN_OFFSET       11      /* 4 bytes */
    #define Bootloader_1_META_APP_RUN_TYPE_OFFSET       15      /* 1 byte  */

#else

    #define Bootloader_1_APP_ADDRESS                uint32
    #define Bootloader_1_GET_CODE_DATA(idx)         *((uint8  *)(CYDEV_FLASH_BASE + (idx)))
    #define Bootloader_1_GET_CODE_WORD(idx)         *((uint32 *)(CYDEV_FLASH_BASE + (idx)))

    #define Bootloader_1_META_APP_ADDR_OFFSET           1   /* 4 bytes */
    #define Bootloader_1_META_APP_BL_LAST_ROW_OFFSET    5   /* 4 bytes */
    #define Bootloader_1_META_APP_BYTE_LEN_OFFSET       9   /* 4 bytes */
    #define Bootloader_1_META_APP_RUN_TYPE_OFFSET       13  /* 1 byte  */

#endif /* (CY_PSOC3) */

#define Bootloader_1_META_APP_ACTIVE_OFFSET             16  /* 1 byte  */
#define Bootloader_1_META_APP_VERIFIED_OFFSET           17  /* 1 byte  */

#define Bootloader_1_META_APP_BL_BUILD_VER_OFFSET       18  /* 2 bytes */
#define Bootloader_1_META_APP_ID_OFFSET                 20  /* 2 bytes */
#define Bootloader_1_META_APP_VER_OFFSET                22  /* 2 bytes */
#define Bootloader_1_META_APP_CUST_ID_OFFSET            24  /* 4 bytes */


#if ((CYDEV_DEBUGGING_XRES) && (CY_PSOC3_ES2 || CY_PSOC5_ES1))
    #define WORKAROUND_OPT_XRES                                 1
#endif


#if(CY_PSOC4)

    extern uint8 appRunType;

    #define Bootloader_1_SOFTWARE_RESET CY_SET_REG32(CYREG_CM0_AIRCR, 0x05FA0004)

    #define Bootloader_1_GET_RUN_TYPE   (((CY_GET_REG32(CYREG_RES_CAUSE) & 0x10) > 0) \
                                            ? (CY_GET_REG8(CYDEV_SRAM_BASE + (4 * (CYINT_IRQ_BASE + NUM_INTERRUPTS)))) \
                                            : 0)

    #define Bootloader_1_SET_RUN_TYPE(x)         CY_SET_REG8(CYDEV_SRAM_BASE + (4 * (CYINT_IRQ_BASE + NUM_INTERRUPTS)), (x))

#else

    #define Bootloader_1_SOFTWARE_RESET CY_SET_REG8(CYREG_RESET_CR2, 0x01)

    #define Bootloader_1_GET_RUN_TYPE   (CY_GET_REG8(CYREG_RESET_SR0) & \
                                            (Bootloader_1_START_BTLDR | Bootloader_1_START_APP))

    #if defined(WORKAROUND_OPT_XRES)
        #define Bootloader_1_SET_RUN_TYPE(x)     Bootloader_1_SetFlashByte(Bootloader_1_MD_APP_RUN_ADDR(Bootloader_1_activeApp), (x))
    #else
        #define Bootloader_1_SET_RUN_TYPE(x)     CY_SET_REG8(CYREG_RESET_SR0, (x))
    #endif  /* defined(WORKAROUND_OPT_XRES) */

#endif  /* (CY_PSOC4) */


#define Bootloader_1_SetFlashRunType(runType)        Bootloader_1_SetFlashByte(Bootloader_1_MD_APP_RUN_ADDR(0), (runType))


void Bootloader_1_SetFlashByte(uint32 address, uint8 value) ;


/*******************************************************************************
* Metadata addresses and pointer defines
*******************************************************************************/

#define Bootloader_1_META_BASE(x)                 (CYDEV_FLASH_BASE + (CYDEV_FLASH_SIZE - ((x) * CYDEV_FLS_ROW_SIZE) - Bootloader_1_META_DATA_SIZE))
#define Bootloader_1_META_ARRAY                   (Bootloader_1_FLASH_NUMBER_SECTORS - 1)

#define Bootloader_1_META_APP_ENTRY_POINT_ADDR(x) (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_ADDR_OFFSET)
#define Bootloader_1_META_APP_BYTE_LEN(x)         (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_BYTE_LEN_OFFSET)
#define Bootloader_1_META_APP_RUN_ADDR(x)         (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_RUN_TYPE_OFFSET)
#define Bootloader_1_META_APP_ACTIVE_ADDR(x)      (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_ACTIVE_OFFSET)
#define Bootloader_1_META_APP_VERIFIED_ADDR(x)    (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_VERIFIED_OFFSET)
#define Bootloader_1_META_APP_BLDBL_VER_ADDR(x)   (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_BL_BUILD_VER_OFFSET)
#define Bootloader_1_META_APP_VER_ADDR(x)         (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_VER_OFFSET)
#define Bootloader_1_META_APP_ID_ADDR(x)          (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_ID_OFFSET)
#define Bootloader_1_META_APP_CUST_ID_ADDR(x)     (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_CUST_ID_OFFSET)
#define Bootloader_1_META_LAST_BLDR_ROW_ADDR(x)   (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_BL_LAST_ROW_OFFSET)
#define Bootloader_1_META_CHECKSUM_ADDR(x)        (Bootloader_1_META_BASE(x) + Bootloader_1_META_APP_CHECKSUM_OFFSET)


#if(0u == Bootloader_1_DUAL_APP_BOOTLOADER)

    #define Bootloader_1_MD_BASE                    Bootloader_1_META_BASE(0)
    #define Bootloader_1_MD_ROW                     ((FLASH_NUMBER_ROWS / Bootloader_1_FLASH_NUMBER_SECTORS) - 1)
    #define Bootloader_1_MD_CHECKSUM_ADDR           Bootloader_1_META_CHECKSUM_ADDR(0)
    #define Bootloader_1_MD_LAST_BLDR_ROW_ADDR      Bootloader_1_META_LAST_BLDR_ROW_ADDR(0)
    #define Bootloader_1_MD_APP_BYTE_LEN            Bootloader_1_META_APP_BYTE_LEN(0)
    #define Bootloader_1_MD_APP_VERIFIED_ADDR       Bootloader_1_META_APP_VERIFIED_ADDR(0)
    #define Bootloader_1_MD_APP_ENTRY_POINT_ADDR    Bootloader_1_META_APP_ENTRY_POINT_ADDR(0)
    #define Bootloader_1_MD_APP_RUN_ADDR            Bootloader_1_META_APP_RUN_ADDR(0)

#else

    #define Bootloader_1_MD_ROW(x)                  ((FLASH_NUMBER_ROWS / Bootloader_1_FLASH_NUMBER_SECTORS) - 1 - (x))
    #define Bootloader_1_MD_CHECKSUM_ADDR           Bootloader_1_META_CHECKSUM_ADDR(appId)
    #define Bootloader_1_MD_LAST_BLDR_ROW_ADDR      Bootloader_1_META_LAST_BLDR_ROW_ADDR(appId)
    #define Bootloader_1_MD_APP_BYTE_LEN            Bootloader_1_META_APP_BYTE_LEN(appId)
    #define Bootloader_1_MD_APP_VERIFIED_ADDR       Bootloader_1_META_APP_VERIFIED_ADDR(appId)
    #define Bootloader_1_MD_APP_ENTRY_POINT_ADDR    Bootloader_1_META_APP_ENTRY_POINT_ADDR(Bootloader_1_activeApp)
    #define Bootloader_1_MD_APP_RUN_ADDR            Bootloader_1_META_APP_RUN_ADDR(Bootloader_1_activeApp)

#endif  /* (0u == Bootloader_1_DUAL_APP_BOOTLOADER) */

/* Pointers to the Bootloader metadata items */
#define Bootloader_1_P_APP_ACTIVE(x)             ((uint8 CYCODE *)        Bootloader_1_META_APP_ACTIVE_ADDR(x))

#define Bootloader_1_MD_PTR_CHECKSUM                 ((uint8  CYCODE *)       Bootloader_1_MD_CHECKSUM_ADDR)
#define Bootloader_1_MD_PTR_APP_ENTRY_POINT          ((Bootloader_1_APP_ADDRESS CYCODE *) Bootloader_1_MD_APP_ENTRY_POINT_ADDR)
#define Bootloader_1_MD_PTR_LAST_BLDR_ROW            ((uint16 CYCODE *)       Bootloader_1_MD_LAST_BLDR_ROW_ADDR)
#define Bootloader_1_MD_PTR_APP_BYTE_LEN             ((Bootloader_1_APP_ADDRESS CYCODE *) Bootloader_1_MD_APP_BYTE_LEN)
#define Bootloader_1_MD_PTR_APP_RUN_ADDR             ((uint8  CYCODE *)        Bootloader_1_MD_APP_RUN_ADDR)
#define Bootloader_1_MD_PTR_APP_VERIFIED             ((uint8  CYCODE *)        Bootloader_1_MD_APP_VERIFIED_ADDR)
#define Bootloader_1_MD_PTR_APP_BLD_BL_VER           ((uint16 CYCODE *)       Bootloader_1_MD_APP_BLDBL_VER_ADDR)
#define Bootloader_1_MD_PTR_APP_VER                  ((uint16 CYCODE *)       Bootloader_1_MD_APP_VER_ADDR)
#define Bootloader_1_MD_PTR_APP_ID                   ((uint16 CYCODE *)       Bootloader_1_MD_APP_ID_ADDR)
#define Bootloader_1_MD_PTR_APP_CUST_ID              ((uint32 CYCODE *)       Bootloader_1_MD_APP_CUST_ID_ADDR)


/*******************************************************************************
* External References
*******************************************************************************/
extern void LaunchApp(uint32 addr);
extern void Bootloader_1_Start(void) CYSMALL ;
extern void Bootloader_1_LaunchApplication(void) CYSMALL ;
extern void Bootloader_1_HostLink(uint8 TimeOut) ;

#if(1u == Bootloader_1_DUAL_APP_BOOTLOADER)

    extern cystatus Bootloader_1_ValidateApp(uint8 appId) CYSMALL ;
    #define Bootloader_1_ValidateApplication()   Bootloader_1_ValidateApp(0)

#else

    extern cystatus Bootloader_1_ValidateApplication(void) CYSMALL ;
    #define Bootloader_1_ValidateApp(x) Bootloader_1_ValidateApplication()

#endif  /* (1u == Bootloader_1_DUAL_APP_BOOTLOADER) */


/* If using custom interface as the IO Component, user must provide these functions */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && (CYDEV_BOOTLOADER_IO_COMP == Bootloader_1_Custom_Interface)

    extern void CyBtldrCommStart(void);
    extern void CyBtldrCommStop (void);
    extern void CyBtldrCommReset(void);
    extern cystatus CyBtldrCommWrite(uint8* buffer, uint16 size, uint16* count, uint8 timeOut);
    extern cystatus CyBtldrCommRead (uint8* buffer, uint16 size, uint16* count, uint8 timeOut);

#endif  /* defined(CYDEV_BOOTLOADER_IO_COMP) && (CYDEV_BOOTLOADER_IO_COMP == Bootloader_1_Custom_Interface) */


#endif /* CY_BOOTLOADER_Bootloader_1_H */


/* [] END OF FILE */
