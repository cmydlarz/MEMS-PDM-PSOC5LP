/*******************************************************************************
* FILENAME: cyfitter_cfg.c
* PSoC Creator 2.2 Component Pack 6
*
* Description:
* This file is automatically generated by PSoC Creator with device 
* initialization code.  Except for the user defined sections in
* CyClockStartupError(), this file should not be modified.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include <cytypes.h>
#include <cydevice_trm.h>
#include <cyfitter.h>
#include <CyLib.h>
#include <cyfitter_cfg.h>

/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0u
#define CYCLOCKSTART_XTAL_ERROR  1u
#define CYCLOCKSTART_32KHZ_ERROR 2u
#define CYCLOCKSTART_PLL_ERROR   3u

#ifdef CY_NEED_CYCLOCKSTARTUPERROR
/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc.), the system will end up here.  Unless reimplemented by
*  the customer, this function will stop in an infinite loop.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void CyClockStartupError(uint8 errorCode);
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* `#START CyClockStartupError` */

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

    /* `#END` */

    /* If nothing else, stop here since the clocks have not started         */
    /* correctly.                                                           */
    while(1) {}
}
#endif


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
	#define CYPACKED __attribute__ ((packed))
	#define CYALIGNED __attribute__ ((aligned))
	
	#if defined(__ARMCC_VERSION)
		#define CY_CFG_MEMORY_BARRIER() __memory_changed()
	#else
		#define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
	#endif
	

	__attribute__ ((unused))
	static void CYMEMZERO(void *s, size_t n);
	__attribute__ ((unused))
	static void CYMEMZERO(void *s, size_t n)
	{
		(void)memset(s, 0, n);
	}
	__attribute__ ((unused))
	static void CYCONFIGCPY(void *dest, const void *src, size_t n);
	__attribute__ ((unused))
	static void CYCONFIGCPY(void *dest, const void *src, size_t n)
	{
		(void)memcpy(dest, src, n);
	}
	__attribute__ ((unused))
	static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
	__attribute__ ((unused))
	static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
	{
		(void)memcpy(dest, src, n);
	}
#else
	#error Unsupported toolchain
#endif

#define CY_CFG_BASE_ADDR_COUNT 17u
typedef struct
{
	uint8 offset;
	uint8 value;
} CYPACKED cy_cfg_addrvalue_t;



/*******************************************************************************
* Function Name: cfg_write_bytes32
********************************************************************************
* Summary:
*  This function is used for setting up the chip configuration areas that
*  contain relatively sparse data.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[]);
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[])
{
	/* For 32-bit little-endian architectures */
	uint32 i, j = 0u;
	for (i = 0u; i < CY_CFG_BASE_ADDR_COUNT; i++)
	{
		uint32 baseAddr = addr_table[i];
		uint8 count = (uint8)baseAddr;
		baseAddr &= 0xFFFFFF00u;
		while (count != 0u)
		{
			CY_SET_XTND_REG8((void CYFAR *)(baseAddr + data_table[j].offset), data_table[j].value);
			j++;
			count--;
		}
	}
}

/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*  Performs the initialization of all of the clocks in the device based on the
*  settings in the Clock tab of the DWR.  This includes enabling the requested
*  clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void ClockSetup(void);
static void ClockSetup(void)
{


	/* Configure Digital Clocks based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x0003u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0 + 0x2u), 0x1Bu);

	/* Configure ILO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_SLOWCLK_ILO_CR0), 0x06u);

	/* Configure IMO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_FASTCLK_IMO_CR), 0x52u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8((void CYFAR *)CYREG_FLSHID_CUST_TABLES_IMO_USB)));

	/* Configure Bus/Master Clock based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x0000u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x07u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG2), 0x48u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00u);

	/* Configure USB Clock based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_UCFG), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_LD), 0x02u);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG2), ((CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG2) | 0x01u)));
}


/* Analog API Functions */


/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void AnalogSetDefault(void);
static void AnalogSetDefault(void)
{
	uint8 bg_xover_inl_trim = CY_GET_XTND_REG8((void CYFAR *)(CYREG_FLSHID_MFG_CFG_BG_XOVER_INL_TRIM + 1u));
	CY_SET_XTND_REG8((void CYFAR *)CYREG_BG_DFT0, bg_xover_inl_trim & 0x07u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_BG_DFT1, ((uint8)((uint8)bg_xover_inl_trim >> 4)) & 0x0Fu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, 0x44u);
}


/*******************************************************************************
* Function Name: SetAnalogRoutingPumps
********************************************************************************
*
* Summary:
* Enables or disables the analog pumps feeding analog routing switches.
* Intended to be called at startup, based on the Vdda system configuration;
* may be called during operation when the user informs us that the Vdda voltage
* crossed the pump threshold.
*
* Parameters:
*  enabled - 1 to enable the pumps, 0 to disable the pumps
*
* Return:
*  void
*
*******************************************************************************/
void SetAnalogRoutingPumps(uint8 enabled)
{
	uint8 regValue = CY_GET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0);
	if (enabled != 0u)
	{
		regValue |= 0x00u;
	}
	else
	{
		regValue &= (uint8)~0x00u;
	}
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, regValue);
}

#define CY_AMUX_UNUSED CYREG_BOOST_SR


/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/

void cyfitter_cfg(void)
{
	/* IOPINS0_8 Address: CYREG_PRT15_DR Size (bytes): 10 */
	static const uint8 CYCODE BS_IOPINS0_8_VAL[] = {
		0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0xC0u, 0x00u};

	/* IOPINS0_2 Address: CYREG_PRT2_DR Size (bytes): 10 */
	static const uint8 CYCODE BS_IOPINS0_2_VAL[] = {
		0x10u, 0x00u, 0x10u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};

	/* IOPINS0_3 Address: CYREG_PRT3_DM0 Size (bytes): 8 */
	static const uint8 CYCODE BS_IOPINS0_3_VAL[] = {
		0x00u, 0x02u, 0x02u, 0x00u, 0x02u, 0x00u, 0x00u, 0x00u};

#ifdef CYGlobalIntDisable
	/* Disable interrupts by default. Let user enable if/when they want. */
	CYGlobalIntDisable
#endif

	{
		static const uint32 CYCODE cy_cfg_addr_table[] = {
			0x40004501u, /* Base address: 0x40004500 Count: 1 */
			0x40005203u, /* Base address: 0x40005200 Count: 3 */
			0x40006501u, /* Base address: 0x40006500 Count: 1 */
			0x4001143Du, /* Base address: 0x40011400 Count: 61 */
			0x4001151Cu, /* Base address: 0x40011500 Count: 28 */
			0x40011701u, /* Base address: 0x40011700 Count: 1 */
			0x40011901u, /* Base address: 0x40011900 Count: 1 */
			0x40014003u, /* Base address: 0x40014000 Count: 3 */
			0x40014102u, /* Base address: 0x40014100 Count: 2 */
			0x40014202u, /* Base address: 0x40014200 Count: 2 */
			0x40014302u, /* Base address: 0x40014300 Count: 2 */
			0x40014703u, /* Base address: 0x40014700 Count: 3 */
			0x40014803u, /* Base address: 0x40014800 Count: 3 */
			0x40014904u, /* Base address: 0x40014900 Count: 4 */
			0x40014C02u, /* Base address: 0x40014C00 Count: 2 */
			0x40015002u, /* Base address: 0x40015000 Count: 2 */
			0x40015101u, /* Base address: 0x40015100 Count: 1 */
		};

		static const cy_cfg_addrvalue_t CYCODE cy_cfg_data_table[] = {
			{0x7Eu, 0x02u},
			{0x14u, 0x10u},
			{0x18u, 0x02u},
			{0x7Cu, 0x40u},
			{0x84u, 0x2Du},
			{0x08u, 0x01u},
			{0x34u, 0x01u},
			{0x38u, 0x08u},
			{0x3Eu, 0x10u},
			{0x40u, 0x20u},
			{0x41u, 0x04u},
			{0x49u, 0xFFu},
			{0x4Au, 0xFFu},
			{0x4Bu, 0xFFu},
			{0x4Du, 0xA0u},
			{0x4Fu, 0x04u},
			{0x50u, 0x18u},
			{0x54u, 0x25u},
			{0x58u, 0x04u},
			{0x5Au, 0x04u},
			{0x5Bu, 0x04u},
			{0x5Fu, 0x01u},
			{0x60u, 0x40u},
			{0x62u, 0xC0u},
			{0x64u, 0x40u},
			{0x65u, 0x40u},
			{0x66u, 0xC0u},
			{0x68u, 0xC0u},
			{0x6Au, 0xC0u},
			{0x6Cu, 0xC0u},
			{0x6Eu, 0xC0u},
			{0x94u, 0x08u},
			{0x9Cu, 0x0Eu},
			{0xA4u, 0x0Eu},
			{0xAEu, 0x03u},
			{0xB0u, 0x08u},
			{0xB2u, 0x04u},
			{0xB4u, 0x01u},
			{0xB6u, 0x02u},
			{0xC0u, 0x20u},
			{0xC1u, 0x04u},
			{0xC5u, 0xD0u},
			{0xC6u, 0x02u},
			{0xC7u, 0x10u},
			{0xC8u, 0x2Eu},
			{0xC9u, 0xFFu},
			{0xCAu, 0xFFu},
			{0xCBu, 0xFFu},
			{0xCDu, 0xAFu},
			{0xCEu, 0x0Fu},
			{0xCFu, 0x04u},
			{0xD0u, 0x18u},
			{0xD2u, 0x80u},
			{0xD8u, 0x04u},
			{0xDAu, 0x04u},
			{0xDBu, 0x04u},
			{0xDFu, 0x01u},
			{0xE0u, 0x40u},
			{0xE2u, 0xC0u},
			{0xE4u, 0x40u},
			{0xE5u, 0x40u},
			{0xE6u, 0xC0u},
			{0xE8u, 0xC0u},
			{0xEAu, 0xC0u},
			{0xECu, 0xC0u},
			{0xEEu, 0xC0u},
			{0x00u, 0x10u},
			{0x0Eu, 0x20u},
			{0x0Fu, 0x02u},
			{0x16u, 0x20u},
			{0x17u, 0x80u},
			{0x18u, 0x14u},
			{0x1Cu, 0x02u},
			{0x1Du, 0x20u},
			{0x1Eu, 0x60u},
			{0x41u, 0x20u},
			{0x42u, 0x80u},
			{0x45u, 0x20u},
			{0x46u, 0x80u},
			{0x4Du, 0x02u},
			{0x56u, 0xA0u},
			{0x57u, 0x01u},
			{0x59u, 0x02u},
			{0x5Au, 0x44u},
			{0x60u, 0x04u},
			{0x77u, 0x80u},
			{0x84u, 0x01u},
			{0x86u, 0x84u},
			{0xC0u, 0x02u},
			{0xC2u, 0xA0u},
			{0xC4u, 0xA0u},
			{0xD0u, 0xA5u},
			{0xD6u, 0x0Bu},
			{0xD8u, 0x04u},
			{0xEEu, 0x0Au},
			{0xEEu, 0x0Au},
			{0x33u, 0x80u},
			{0x36u, 0x40u},
			{0xCCu, 0x30u},
			{0xA6u, 0x40u},
			{0xA7u, 0x80u},
			{0xA6u, 0x40u},
			{0xA7u, 0x80u},
			{0xA6u, 0x40u},
			{0xA7u, 0x80u},
			{0x08u, 0x08u},
			{0x0Fu, 0x40u},
			{0xC2u, 0x0Cu},
			{0xAEu, 0x40u},
			{0xAFu, 0x80u},
			{0xEEu, 0x50u},
			{0x57u, 0x20u},
			{0x87u, 0x20u},
			{0xD4u, 0x40u},
			{0xE6u, 0x10u},
			{0xACu, 0x08u},
			{0xAFu, 0x40u},
			{0x10u, 0x01u},
			{0x1Au, 0x01u},
			{0x00u, 0x0Au},
		};



		typedef struct {
			void CYFAR *address;
			uint16 size;
		} CYPACKED cfg_memset_t;

		static const cfg_memset_t CYCODE cfg_memset_list [] = {
			/* address, size */
			{(void CYFAR *)(CYREG_PRT0_DR), 32u},
			{(void CYFAR *)(CYREG_PRT4_DR), 48u},
			{(void CYFAR *)(CYREG_PRT12_DR), 16u},
			{(void CYFAR *)(CYDEV_UCFG_B0_P0_U0_BASE), 4096u},
			{(void CYFAR *)(CYDEV_UCFG_B1_P2_U0_BASE), 2048u},
			{(void CYFAR *)(CYDEV_UCFG_DSI0_BASE), 2560u},
			{(void CYFAR *)(CYDEV_UCFG_DSI12_BASE), 512u},
			{(void CYFAR *)(CYREG_BCTL0_MDCLK_EN), 32u},
		};

		uint8 CYDATA i;

		/* Zero out critical memory blocks before beginning configuration */
		for (i = 0u; i < (sizeof(cfg_memset_list)/sizeof(cfg_memset_list[0])); i++)
		{
			const cfg_memset_t CYCODE * CYDATA ms = &cfg_memset_list[i];
			CYMEMZERO(ms->address, (uint32)(ms->size));
		}

		cfg_write_bytes32(cy_cfg_addr_table, cy_cfg_data_table);

		/* Enable digital routing */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL) | 0x02u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0) | 0x40u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2) | 0x10u);
	}

	/* Perform second pass device configuration. These items must be configured in specific order after the regular configuration is done. */
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT15_DR), (const void CYCODE *)(BS_IOPINS0_8_VAL), 10u);
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT2_DR), (const void CYCODE *)(BS_IOPINS0_2_VAL), 10u);
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT3_DM0), (const void CYCODE *)(BS_IOPINS0_3_VAL), 8u);

	/* Switch Boost to the precision bandgap reference from its internal reference */
	CY_SET_REG8((void CYXDATA *)CYDEV_BOOST_CR2, (CY_GET_REG8((void CYXDATA *)CYDEV_BOOST_CR2) | 0x08u));

	/* Set Flash Cycles based on max possible frequency in case a glitch occurs during ClockSetup(). */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0x01u : 0x00u));
	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();
	/* Set Flash Cycles based on newly configured 24.00MHz Bus Clock. */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0x81u : 0x80u));

	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (const void CYFAR *)CYDEV_PM_ACT_BASE, 14u);
}
