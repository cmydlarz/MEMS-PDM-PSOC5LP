/*******************************************************************************
* File Name: Bootloadable_1.h
* Version 1.0
*
*  Description:
*   Provides an API for the Bootloadable application. The API includes a
*   single function for starting bootloader.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/


#ifndef CY_BOOTLOADABLE_Bootloadable_1_H
#define CY_BOOTLOADABLE_Bootloadable_1_H

#include "cydevice_trm.h"
#include "CyFlash.h"


/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Bootloadable_v1_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5X) */


#define Bootloadable_1_START_APP      (0x80u)  /* Mask used to indicate starting application */
#define Bootloadable_1_START_BTLDR    (0x40u)  /* Mask used to indicate starting bootloader */

#ifndef CYDEV_FLASH_BASE
    #define CYDEV_FLASH_BASE            CYDEV_FLS_BASE
    #define CYDEV_FLASH_SIZE            CYDEV_FLS_SIZE
#endif /* CYDEV_FLASH_BASE */

#define Bootloadable_1_META_DATA_SIZE                 64
#define Bootloadable_1_META_APP_CHECKSUM_OFFSET       0

#if(CY_PSOC3)

    #define Bootloadable_1_APP_ADDRESS                uint16
    #define Bootloadable_1_GET_CODE_DATA(idx)         *((uint8  CYCODE *) idx)
    #define Bootloadable_1_GET_CODE_WORD(idx)         *((uint32 CYCODE *) idx)

    /* Offset by 2 from 32 bit start because only need 16 bits */
    #define Bootloadable_1_META_APP_ADDR_OFFSET         3   /* 2 bytes */
    #define Bootloadable_1_META_APP_BL_LAST_ROW_OFFSET  7   /* 4 bytes */
    #define Bootloadable_1_META_APP_BYTE_LEN_OFFSET     11  /* 4 bytes */
    #define Bootloadable_1_META_APP_RUN_TYPE_OFFSET     15  /* 1 byte  */

#else

    #define Bootloadable_1_APP_ADDRESS                uint32
    #define Bootloadable_1_GET_CODE_DATA(idx)         *((uint8  *)(CYDEV_FLASH_BASE + (idx)))
    #define Bootloadable_1_GET_CODE_WORD(idx)         *((uint32 *)(CYDEV_FLASH_BASE + (idx)))

    #define Bootloadable_1_META_APP_ADDR_OFFSET         1   /* 4 bytes */
    #define Bootloadable_1_META_APP_BL_LAST_ROW_OFFSET  5   /* 4 bytes */
    #define Bootloadable_1_META_APP_BYTE_LEN_OFFSET     9   /* 4 bytes */
    #define Bootloadable_1_META_APP_RUN_TYPE_OFFSET     13  /* 1 byte  */

#endif /* (CY_PSOC3) */

#define Bootloadable_1_META_APP_ACTIVE_OFFSET           16  /* 1 byte  */
#define Bootloadable_1_META_APP_VERIFIED_OFFSET         17  /* 1 byte  */

#define Bootloadable_1_META_APP_BL_BUILD_VER_OFFSET     18  /* 2 bytes */
#define Bootloadable_1_META_APP_ID_OFFSET               20  /* 2 bytes */
#define Bootloadable_1_META_APP_VER_OFFSET              22  /* 2 bytes */
#define Bootloadable_1_META_APP_CUST_ID_OFFSET          24  /* 4 bytes */


#if ((CYDEV_DEBUGGING_XRES) && (CY_PSOC5_ES1))
    #define WORKAROUND_OPT_XRES 1
#endif  /* ((CYDEV_DEBUGGING_XRES) && (CY_PSOC5_ES1)) */


#if(CY_PSOC4)

    extern uint8 appRunType;

    #define Bootloadable_1_SOFTWARE_RESET CY_SET_REG32(CYREG_CM0_AIRCR, 0x05FA0004)

    #define Bootloadable_1_GET_RUN_TYPE   (((CY_GET_REG32(CYREG_RES_CAUSE) & 0x10) > 0) \
                                            ? (CY_GET_REG8(CYDEV_SRAM_BASE + (4 * (CYINT_IRQ_BASE + NUM_INTERRUPTS)))) \
                                            : 0)

    #define CYBTDLR_SET_RUN_TYPE(x)         CY_SET_REG8(CYDEV_SRAM_BASE + (4 * (CYINT_IRQ_BASE + NUM_INTERRUPTS)), (x))

#else

    #define Bootloadable_1_SOFTWARE_RESET CY_SET_REG8(CYREG_RESET_CR2, 0x01)

    #define Bootloadable_1_GET_RUN_TYPE   (CY_GET_REG8(CYREG_RESET_SR0) & \
                                            (Bootloadable_1_START_BTLDR | Bootloadable_1_START_APP))

    #if defined(WORKAROUND_OPT_XRES)
        #define CYBTDLR_SET_RUN_TYPE(x)     Bootloadable_1_SetFlashByte(Bootloadable_1_MD_APP_RUN_ADDR(Bootloadable_1_activeApp), (x))
    #else
        #define CYBTDLR_SET_RUN_TYPE(x)     CY_SET_REG8(CYREG_RESET_SR0, (x))
    #endif  /* defined(WORKAROUND_OPT_XRES) */

#endif  /* (CY_PSOC4) */


#define Bootloadable_1_SetFlashRunType(runType)        Bootloadable_1_SetFlashByte(Bootloadable_1_MD_APP_RUN_ADDR(0), (runType))


/***************************************
*     Function Prototypes
***************************************/
void Bootloadable_1_SetFlashByte(uint32 address, uint8 value) ;
extern void Bootloadable_1_Load(void) ;


#endif /* CY_BOOTLOADABLE_Bootloadable_1_H */


/* [] END OF FILE */
