/*****************************************************************************
* File Name: swd.c
*
* Version 2.03
*
* Description:
*  This file provides the source code to handle SWD programming.
*
* Owner:
*	Ranjith M, Applications Engineer (rnjt@cypress.com)
*
* Related Document:
* 	001-85925 - CY8CKIT-042 PSoC 4 Pioneer Kit IROS
*	RNJT#20
*
* Hardware Dependency:
* 	CY8CKIT-042 (KitProg) 
*
* Code Tested With:
* 	Creator 2.2
*	GCC1 4.4.1
*	CY8CKIT-042 Rev 1
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

/*****************************************************************************
* MACRO Definition
*****************************************************************************/
#define SWD_COUNT_BIT \
{ \
    if (bData & 1) bCount++; \
    bData >>= 1; \
}
/*****************************************************************************
* Local Function Prototypes
*****************************************************************************/
uint8 SWDCountBits(uint8 bByte);
void SWDPutByte(uint8 bData);
uint8 SWDGetByte(void);
uint8 SWDAcquirePSoC4(uint8 acquireMode, uint8 attempts);
void SWDPutHeaderSegment(void);  
void SWDClockTrn(void);
void SWDGetAckSegment(void);   
void SWDPutDataSegment(uint8  *pbData);
void SWDGetDataSegment(uint8  *pbData);
uint8 SWDComputeDataParity(uint8  *pbData); 
void SWDPutData(uint8  *pbData); 
void SWDGetData(uint8  *pbData); 
void WriteSWD(uint8 *bufOut, uint8 *buf_ACK);
void ReadSWD(uint8 *bufOut, uint8 *buf_ACK_Data32);
void SWDHalt(void);


/*****************************************************************************
* Global Variable Declarations
*****************************************************************************/


/*****************************************************************************
* Local Global Variable Declarations
*****************************************************************************/
uint8 bufOut[68]; 
uint8 bufIn[384]; 
int16 bufOutOffset;
int16 bufInOffset;
int16 bufOutLen;
uint8 fIsShortPkt = FALSE;

/* 8-bit header */
uint8 gbHeader;
/* 32-bit data */
uint8 gbData[SWD_XFER_SIZE];
/* 8-bt staus */
uint8 gbStatsReg;
uint8 gbParity;
/* 3-bit ACK response */
uint8 gbAck;
uint8 ack0=0;
uint8 ack1=0;
uint8 ack2=0;


/*
Rules:
   - Host emulator generates clock signal

Need:
   - switch direction of data port
   - check parity of read data
   - set parity of write data and headers
   - put data to data wire
   - get data from data
   - generate clock on clock wire
   - data on bus is lsb first to msb last
   - reset bus (50 clock 1's) (see 001-11605 p. 11)
   - goto idle state (clock one 0) (see 001-11605 p. 11) 
   - 2 add'l clocks after final data bit (see Cortex p.12-20) (for a read in order to clock parity and Trn)
   - the data wire is not driven during Trn

   Write sequence:
      - Host reset bus if this is first transfer
   PUT_WRITE_HEADER:
      - Host sets Data dir=out
      - Host packs header (Host: APnDP, Addr[1:0])
         - pack bits
            - b0: Start bit = 1
            - b1: APnDP from Host PC
            - b2: 0 (~wr)
            - b3: Addr[0] lsb
            - b4: Addr[1] msb
            - compute parity (even parity: if number of 1's in the APnDP,RnW,ADDR bits is odd then Parity=1 (see 001-11605 p.10 or Cortex p.12-23))
               - b5: Parity bit
            - b6: Stop bit (sync:0, async:??)
            - set Data dir=in (float the pin so pullup creats ahigh level; device reads this as a 1 (see 001-11605 p.11 or Cortex p.12-23))
               - b7: Park bit
      - Host writes Header (Start bit first)
      - Host sets Data dir=in
      - Host clocks Turn (Trn)
   GET_ACK:
      - Host reads ACK
         - check ACK bits for:
            - ACK    (b'100) (lsb = 1)
            - WAIT   (b'010)
            - FAULT  (b'001) (msb = 1)
   PUT_DATA:
      - if ACK then
         - Host sets Data dir=out
         - Host computes Data Parity
         - Host clocks Turn (Trn)
         - Host puts Data [bit 0 to bit 31]
         - Host puts Data Parity bit
            - if target detects parity error in either header or data (target sets wd_error bit DBGPRT_CFG)
      - else if WAIT
         - if Overrun Detection then (Sticky behavior)
            - continue with PUT_DATA for ACK - data will be ignored by target
         - else
            - no data phase
      - else if FAULT (any sticky bit set)
         - continue with PUT_DATA for ACK
         - sticky bits cleared by ABORT register bits

   Read Sequence:
      - Host reset bus if this is first transfer
   PUT_READ_HEADER:
      - Host sets Data dir=out
      - Host packs header (Host: APnDP, Addr[1:0])
         - pack bits
            - b0: Start bit = 1
            - b1: APnDP from Host PC
            - b2: 1 (rd)
            - b3: Addr[0] lsb
            - b4: Addr[1] msb
            - compute parity (even parity: if number of 1's in the APnDP,RnW,ADDR bits is odd then Parity=1 (see 001-11605 p.10 or Cortex p.12-23))
               - b5: Parity bit
            - b6: Stop bit
            - set Data dir=in (float the pin so pullup creats ahigh level; device reads this as a 1 (see 001-11605 p.11 or Cortex p.12-23))
               - b7: Park bit
      - Host writes Header (Start bit first)
      - Host sets Data dir=in
      - Host clocks Turn (Trn)
   GET_ACK:
      - Host reads ACK
         - check ACK bits for:
            - ACK    (b100) (lsb = 1)
            - WAIT   (b010)
            - FAULT  (b001) (msb = 1)
   GET_DATA:
      - if ACK then
         - Host gets Data [bit 0 to bit 31]
         - Host gets Parity bit
         - Host clocks Turn (Trn)
         - Host compares parity to bit
            - if parity error (?????)
      - else if WAIT
         - if Overrun Detection then (Sticky behavior)
            - continue with GET_DATA for ACK - data will be ignored by host emulator
         - else
            - no data phase
      - else if FAULT (any sticky bit set)
         - continue with GET_DATA for ACK
         - sticky bits cleared by ABORT register bits

*/
/*-----------------------------------------------------------------------------*/

/*******************************************************************************
* Function Name: SWDInit()
********************************************************************************
* Summary:
* Initializes SWD side of communication for PSoC 5LP
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDInit (void)
{
   	uint8 count;
	/* 8-bit header */
   	gbHeader = 0;        
	/* 8-bit status - default goodness */
   	gbStatsReg = SWD_DONE | SWD_ACK;      
	/* 8-bit configuration */
   	gbAck = 0;

   	for (count = 0; count < SWD_XFER_SIZE; count++)
   	{
   		/* 32-bit data */
    	gbData[count] = 0;    
   	}

   	SWD_SET_SCK_IN;
   	SWD_SET_SDA_IN;
	/* data line "parks" high */
	SWD_SET_SDA_HI;      
	/* clock line "parks" high */
   	SWD_SET_SCK_HI;   
	return;
}
/*******************************************************************************
* Function Name: SWDHalt()
********************************************************************************
* Summary:
*  Puts all the SWD Pins in High-Z.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDHalt(void)
{
	SWD_SET_SDA_IN;
	SWD_SET_SCK_IN;
	SWD_SET_XRES_IN;
}
/*******************************************************************************
* Function Name: SWDClockTrn()
********************************************************************************
* Summary:
* Puts the PSoC 5LP in the turn around mode of SWD programming.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDClockTrn (void)
{
	/* float the data line */
    SWD_SET_SDA_IN;   
    SWD_CLOCK_BIT;
    return;
}
/*******************************************************************************
* Function Name: SWDPutHeaderSegment()
********************************************************************************
* Summary:
* Puts the Header segment on to the SWD lines.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDPutHeaderSegment(void)
{
    SWD_SET_SDA_LO;
    SWD_SET_SDA_OUT;
    CY_NOP;
    CY_NOP;
   
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    SWD_CLOCK_BIT;
    
    SWDPutByte(gbHeader);
    SWD_SET_SDA_IN;
	return;
}

/*******************************************************************************
* Function Name: SWDGetAckSegment()
********************************************************************************
* Summary:
* Retrieves the ack bits from the SWD lines. 
* Returns ack = 0:fail, 1:ACK, 2:WAIT, 4:FAULT
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDGetAckSegment(void)
{
    /* get ACK */
    SWD_SET_SDA_IN; 
    
    SWD_SET_SCK_LO;
    ack0 = SWD_GET_SDA;
    SWD_SET_SCK_HI;
    
    SWD_SET_SCK_LO;
    ack1 = SWD_GET_SDA;
    SWD_SET_SCK_HI;
    
    SWD_SET_SCK_LO;
    ack2 = SWD_GET_SDA;
    SWD_SET_SCK_HI;
	return;
}


/*******************************************************************************
* Function Name: SWDPutDataSegment()
********************************************************************************
* Summary:
* Puts the complete data segment received on to the SWD lines.
*
* Parameters:
*  *pbData: Pointer to the address to where the data read from the SWD lines 
*  is to be stored.
*
* Return:
*  void
*
*******************************************************************************/
void SWDPutDataSegment(uint8  *pbData) 
{ 
    SWD_SET_SDA_OUT; 
    SWDPutByte(*pbData++); 
    SWDPutByte(*pbData++); 
    SWDPutByte(*pbData++); 
    SWDPutByte(*pbData); 
	return;
}
/*******************************************************************************
* Function Name: SWDGetDataSegment()
********************************************************************************
* Summary:
* Reads the data segment from the SWD lines.
*
* Parameters:
*  *pbData: Pointer to the address where data to be wriiten to the SWD lines 
*  is stored .
*
* Return:
*  void
*
*******************************************************************************/
void SWDGetDataSegment(uint8  *pbData)
{ 
    SWD_SET_SDA_IN; 
    *pbData++ = SWDGetByte(); 
    *pbData++ = SWDGetByte(); 
    *pbData++ = SWDGetByte(); 
    *pbData = SWDGetByte();
	return;
}


/*******************************************************************************
* Function Name: SWDCountBits()
********************************************************************************
* Summary:
* Counts the number of '1's in the byte passed.
*
* Parameters:
*  bData: Byte for which number of ones is to be calculated
*
* Return:
*  bCount: Number of ones in the byte.
*
*******************************************************************************/
uint8 SWDCountBits(uint8 bData)
{
    register uint8 bCount = 0;
	/* bit 0 to bit 7 */
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    SWD_COUNT_BIT;   
    return bCount;
}
/*******************************************************************************
* Function Name: SWDPutByte()
********************************************************************************
* Summary:
* Write a byte on to the SWD lines.
*
* Parameters:
*  bPutData: Byte which is to be written on to the SWD lines.
*
* Return:
*  void
*
*******************************************************************************/
void SWDPutByte(uint8 bPutData)
{
	
	SWDByte = bPutData;
    
    SWD_SET_SCK_LO; SWD_SDA = B0; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B1; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B2; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B3; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B4; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B5; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B6; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; SWD_SDA = B7; SWD_SET_SCK_HI;
	return;
}
/*******************************************************************************
* Function Name: SWDGetByte()
********************************************************************************
* Summary:
* Read a byte from the SWD lines.
*
* Parameters:
*  void
*
* Return:
*  SWDByte: Byte read from the SWD lines.
*
*******************************************************************************/
uint8 SWDGetByte(void)
{
    SWD_SET_SCK_LO; B0 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B1 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B2 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B3 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B4 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B5 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B6 = SWD_GET_SDA; SWD_SET_SCK_HI;
    SWD_SET_SCK_LO; B7 = SWD_GET_SDA; SWD_SET_SCK_HI;
    
    return SWDByte;
}
/*******************************************************************************
* Function Name: SWDResetBus()
********************************************************************************
* Summary:
* Resetd the SWD bus by clocking 60 times.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SWDResetBus (void)
{
    uint8 enableInterrupts;

    SWD_SET_SCK_OUT;
	/* Disable all the interrupts */
    enableInterrupts = CyEnterCriticalSection();
    /* see 001-11605  4.2.1.2. Clocks more than 52 times to reset the SWD bus */
    SWD_SET_SDA_HI;
    SWD_SET_SDA_OUT;
    SWD_CLOCK_BIT; //  1
    SWD_CLOCK_BIT; //  2
    SWD_CLOCK_BIT; //  3
    SWD_CLOCK_BIT; //  4
    SWD_CLOCK_BIT; //  5
    SWD_CLOCK_BIT; //  6
    SWD_CLOCK_BIT; //  7
    SWD_CLOCK_BIT; //  8
    SWD_CLOCK_BIT; //  9
    SWD_CLOCK_BIT; //  10
    SWD_CLOCK_BIT; //  11
    SWD_CLOCK_BIT; //  12
    SWD_CLOCK_BIT; //  13
    SWD_CLOCK_BIT; //  14
    SWD_CLOCK_BIT; //  15
    SWD_CLOCK_BIT; //  16
    SWD_CLOCK_BIT; //  17
    SWD_CLOCK_BIT; //  18
    SWD_CLOCK_BIT; //  19
    SWD_CLOCK_BIT; //  20
    SWD_CLOCK_BIT; //  21
    SWD_CLOCK_BIT; //  22
    SWD_CLOCK_BIT; //  23
    SWD_CLOCK_BIT; //  24
    SWD_CLOCK_BIT; //  25
    SWD_CLOCK_BIT; //  26
    SWD_CLOCK_BIT; //  27
    SWD_CLOCK_BIT; //  28
    SWD_CLOCK_BIT; //  29
    SWD_CLOCK_BIT; //  30
    SWD_CLOCK_BIT; //  31
    SWD_CLOCK_BIT; //  32
    SWD_CLOCK_BIT; //  33
    SWD_CLOCK_BIT; //  34
    SWD_CLOCK_BIT; //  35
    SWD_CLOCK_BIT; //  36
    SWD_CLOCK_BIT; //  37
    SWD_CLOCK_BIT; //  38
    SWD_CLOCK_BIT; //  39
    SWD_CLOCK_BIT; //  40
    SWD_CLOCK_BIT; //  41
    SWD_CLOCK_BIT; //  42
    SWD_CLOCK_BIT; //  43
    SWD_CLOCK_BIT; //  44
    SWD_CLOCK_BIT; //  45
    SWD_CLOCK_BIT; //  46
    SWD_CLOCK_BIT; //  47
    SWD_CLOCK_BIT; //  48
    SWD_CLOCK_BIT; //  49
    SWD_CLOCK_BIT; //  50
    SWD_CLOCK_BIT; //  51
    SWD_CLOCK_BIT; //  52
    SWD_CLOCK_BIT; //  53
    SWD_CLOCK_BIT; //  54
    SWD_CLOCK_BIT; //  55
    SWD_CLOCK_BIT; //  56
    SWD_CLOCK_BIT; //  57
    SWD_CLOCK_BIT; //  58
    SWD_CLOCK_BIT; //  59
    SWD_CLOCK_BIT; //  60
	/* Enable all the interrupts */
    CyExitCriticalSection(enableInterrupts);
    
    SWD_SET_SDA_IN;
    
    return;
}
/*******************************************************************************
* Function Name: SWDComputeDataParity()
********************************************************************************
* Summary:
* Calculates the parity for the data segment.
*
* Parameters:
*  pbData: Pointer to the address location of data whose parity is to be calculated.
*
* Return:
*  Parity of the data segment.
*
*******************************************************************************/
uint8 SWDComputeDataParity(uint8  *pbData)
{
    uint8 bCount = 0;
    bCount += SWDCountBits(*pbData++);
    bCount += SWDCountBits(*pbData++);
    bCount += SWDCountBits(*pbData++);
    bCount += SWDCountBits(*pbData++);
    return (bCount & 1);
}
/*******************************************************************************
* Function Name: SWDAcquirePSoC4()
********************************************************************************
* Summary:
* Acquires PSoC 4.
*
* Parameters:
*  acquireMode: Reset or Power cycle acquire. For now, only reset mode is supported.
*  attempts   : Number of retries before declaring acquire failed.
*
* Return:
*  bRet: Flag whether the PSoC 4 is acquired or not.
*
*******************************************************************************/
uint8 SWDAcquirePSoC4(uint8 acquireMode, uint8 attempts)
{
	uint8 count;
	uint8 bRet = FALSE;
	uint8 bSwdAcquired;
	/* Number of retries */
	uint16 timeout = 100; 
	uint8 bData[5];
	uint8 bAck;
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

	/* ANDI-73 explains this acquire algotithm */
	for (count = 0; count < attempts; count++)
	{
        if (acquireMode == 0) 
        {
			/* reset acquire */
            /* Generate XRES cycle */
            SWD_SET_XRES_OUT;
            SWD_SET_XRES_LO;
            /* drive the clock and data lines */
            SWD_SET_SCK_OUT;
            SWD_SET_SDA_OUT;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
			/* duration of XRES low */
            CyDelayUs(100);  
            /* remove reset from PSoC4 */
//            SWD_SET_XRES_HI;			//Changed!!
            SWD_SET_XRES_IN; 
            timeout = 100; 
        }
        else
		{
			/* PowerCycle mode acquire. Do nothing now. */
		}
		/* Try to acquire SWD port */
		bSwdAcquired = FALSE;
		do { 
			/* Reset SWD bus */
			SWDResetBus();
			/* Read SWD ID code */
            gbData[0] = 0;
            gbHeader = 0xA5;
			/* gbData contains actual ID */
            SWDGetData(gbData);
            if ((gbStatsReg & (SWD_ACK_BITS | SWD_PERR)) == SWD_ACK )
            {
				bSwdAcquired = TRUE;
				
	        }
	    	timeout--;
		}while((timeout>0) && !bSwdAcquired);
		
		/* Configure Debug Port (DAP) */
		bData[0] = 0xA9; 
		bData[1] = 0x00; bData[2] = 0x00; bData[3] = 0x00; bData[4] = 0x54;
		WriteSWD(bData, &bAck);
		if ((bAck & SWD_ACK_BITS) != SWD_ACK ) 
		{
			/* NACK, try to acquire again */
			continue; 
		}
		bData[0] = 0xB1;
		bData[1] = 0x00; bData[2] = 0x00; bData[3] = 0x00; bData[4] = 0x00;
		WriteSWD(bData, &bAck);
		if ((bAck & SWD_ACK_BITS) != SWD_ACK )
		{
			/* NACK, try to acquire again */
			continue; 
		}
		
		bData[0] = 0xA3;
		bData[1] = 0x02; bData[2] = 0x00; bData[3] = 0x00; bData[4] = 0x00;
		WriteSWD(bData, &bAck);
		if ((bAck & SWD_ACK_BITS) != SWD_ACK )
		{
			/* NACK, try to acquire again */
			continue; 
		}
		/* Enter Test Mode */
		bData[0] = 0x8B;
		bData[1] = 0x14; bData[2] = 0x00; bData[3] = 0x03; bData[4] = 0x40;
		WriteSWD(bData, &bAck);
		if ((bAck & SWD_ACK_BITS) != SWD_ACK )
		{
			/* NACK, try to acquire again */
			continue; 
		}
		
		bData[0] = 0xBB;
		bData[1] = 0x00; bData[2] = 0x00; bData[3] = 0x00; bData[4] = 0x80;
		WriteSWD(bData, &bAck);
		if ((bAck & SWD_ACK_BITS) != SWD_ACK)
		{
			/* NACK, try to acquire again */
			continue; 
		}
						
		bRet = TRUE;
		break;
	}
	
    CyExitCriticalSection(enableInterrupts);
    return (bRet);
}
/*******************************************************************************
* Function Name: SWDPutData()
********************************************************************************
* Summary:
* Calls the functions to write data segment on to the SWD lines and checks the 
* acknowledgement to decide whether the write was successful or not.
*
* Parameters:
*  *pbData: Pointer to the address location where data to be written to the SWD
*  lines is stored.
*
* Return:
*  void
*
*******************************************************************************/
void SWDPutData(uint8  *pbData)
{
    uint8 bParity;
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    gbStatsReg = 0;
    bParity = SWDComputeDataParity(pbData);
    SWDPutHeaderSegment();
    
    SWDClockTrn();
    SWDGetAckSegment();
    gbAck = ack0 | (ack1 << 1) | (ack2 << 2);
    SWDClockTrn();
    switch (gbAck)
    {
        case SWD_ACK:
        {
            SWDPutDataSegment(pbData);
            if (bParity)
			{
				SWD_SET_SDA_HI;
			}
			else 
			{
				SWD_SET_SDA_LO;
			}
			
            /* 46-th clock ends SWD transaction */
			SWD_CLOCK_BIT;
            
			/* keep Data low to not start next SWD transaction on 47th clock */
            SWD_SET_SDA_LO;
			
			/* 47-th clock is required to move Addr/Data from DAP to AHB bus. */
            SWD_CLOCK_BIT; 
            
            SWD_SET_SDA_IN;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
            gbStatsReg |= gbAck;
            break;
        }
    
        case SWD_WAIT:
        case SWD_FAULT:
        {
            SWD_SET_SDA_IN;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
            gbStatsReg |= gbAck;
            break;
        }

        default:
        {
            SWD_SET_SDA_IN;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
			/* Protocol Error - no response from target */
            gbStatsReg |= SWD_ERROR;  
            break;
        }
    }
    CyExitCriticalSection(enableInterrupts);
	return;
}
/*******************************************************************************
* Function Name: SWDGetData()
********************************************************************************
* Summary:
* Invokes the functions to read a data segment from the SWD lines and checks the 
* acknowledgement to decide whether the read operation was successful or not.
*
* Parameters:
*  *pbData: Pointer to the address location where data read from the SWD lines
*  is to be stored.
*
* Return:
*  void
*
*******************************************************************************/
void SWDGetData(uint8  *pbData)
{
    register uint8 i;
    register uint8 bParity;
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    gbStatsReg = 0;
    SWDPutHeaderSegment();
    SWDClockTrn();
    SWDGetAckSegment();
    gbAck = ack0 | (ack1 << 1) | (ack2 << 2);
    switch (gbAck)
    {
		/* This handles error in pre-ES10 silicon for reads */
        case SWD_ACK+SWD_WAIT:  
		/* This handles normal expected response for ACK=OK */
        case SWD_ACK:           
        {
            SWDGetDataSegment(pbData);
            SWD_SET_SCK_LO;
            bParity = SWD_GET_SDA;
            SWD_SET_SCK_HI;
            SWDClockTrn();
            
            if (SWDComputeDataParity(pbData) != bParity)
            {
                gbStatsReg |= SWD_PERR;
            
            }
            SWD_SET_SDA_IN;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
            gbStatsReg |= gbAck;
            break;
        }

        case SWD_WAIT:
        case SWD_FAULT:
        {
            SWDClockTrn();
            for (i = 0; i < SWD_XFER_SIZE; i++)
                *pbData++ = 0;
            
            SWD_SET_SDA_IN;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
            gbStatsReg |= gbAck;
            break;
        }

        default:
        {
            SWDClockTrn();
            SWD_SET_SDA_IN;
            SWD_SET_SDA_HI;
            SWD_SET_SCK_HI;
			/* Protocol Error - no response from target */
            gbStatsReg |= SWD_ERROR;  
            break;
        }
    }
    CyExitCriticalSection(enableInterrupts);
	return;
}


/****************************************************************************/
/* Functions which process SWD batch transactions */
/****************************************************************************/
/*******************************************************************************
* Function Name: ReadSWD()
********************************************************************************
* Summary:
* Executes SWD-read command on the bus. Command located at (bufOut + *bufOutOffset),
* result (ACK+data) is returned to buf_ACK_Data32 buffer.
*
* Parameters:
*  Pointers to buffer addresses.
*
* Return:
*  void
*
*******************************************************************************/
void ReadSWD(uint8 *bufOut, uint8 *buf_ACK_Data32)
{
    uint8 j;
	/* should only take 2 at most */
    register uint8 bRetry = 10; 
    
    for(j=0; j<5; j++)
    {
        buf_ACK_Data32[j] = 0;
    }
    
    gbHeader = bufOut[0];
    do
    {
        SWDGetData(&buf_ACK_Data32[0]);
    }
    while (--bRetry && ((gbStatsReg & SWD_ACK_BITS) == SWD_ACK_BITS));

    buf_ACK_Data32[4] = gbStatsReg | SWD_DONE;
	return;
}

/*******************************************************************************
* Function Name: WriteSWD()
********************************************************************************
* Summary:
* Executes SWD-write command on the bus. Command located at (bufOut + *bufOutOffset),
* result (ACK) is returned to buf_ACK buffer.
*
* Parameters:
*  pointers to the buffer addresses
*
* Return:
*  void
*
*******************************************************************************/
void WriteSWD(uint8 *bufOut, uint8 *buf_ACK)
{
	/* bRetry - should only take 2 at most */
    register uint8 bRetry = 10; 

    gbHeader = bufOut[0];
	
    do
    {
        SWDPutData(&bufOut[1]);
    }while (--bRetry && ((gbStatsReg & SWD_ACK_BITS) == SWD_ACK_BITS));

	buf_ACK[0] = gbStatsReg | SWD_DONE;
	return;
}

/*******************************************************************************
* Function Name: ReceiveSWDRequest()
********************************************************************************
* Summary:
* Reads the SWD request issued by the PSoC programmer and retrieves 
* the data packets from USB lines for the programming operation.
*
* Parameters:
*  bufOut		: OUT EP buffer
*  bufOutOffset	: offset from the starting of bufOut to the location of data
*  bufOutLen	: Number of data bytes stored in the buffer
*
* Return:
*  void
*
*******************************************************************************/
void ReceiveSWDRequest(uint8 *bufOut, int16 *bufOutOffset, int16 *bufOutLen)
{
	int16 size = USBFS_GetEPCount(SWD_OUT_EP);
	*bufOutLen = *bufOutOffset + size;
	USBFS_ReadOutEP(SWD_OUT_EP, bufOut + *bufOutOffset, size);
	USBFS_EnableOutEP(SWD_OUT_EP);

    if(size < 64)
	{
        fIsShortPkt = TRUE;
	}
    else
	{
        fIsShortPkt = FALSE;
	}
	return;
}

/*******************************************************************************
* Function Name: ProcessSWDRequest()
********************************************************************************
* Summary:
* Determines the type of request issued by the Programmer and invokes read or write
* functions until the operations with the received data packet (upto 64 bytes) is complete.
*
* Parameters:
*  bufOut		: OUT EP buffer
*  bufIn		: IN EP buffer
*  bufOutOffset	: offset from the starting of bufOut to the location of data
*  bufInOffset	: offset from the starting of bufIn to the location of data
*  bufOutLen	: Number of data bytes stored in the OUT EP buffer
*
* Return:
*  void
*
*******************************************************************************/
void ProcessSWDRequest(uint8 *bufOut, uint8 *bufIn, int16 *bufOutOffset, 
int16 *bufInOffset, int16 *bufOutLen)
{
	int16 i = 0;
	int16 k = 0;
	for(i = 0; i < *bufOutLen;)
	{
		/* Process Read SWD command */
        if((bufOut[i] & 0x04) == 0x04) 
        {
            /* Execute Read transaction */
            ReadSWD(bufOut + i, bufIn + *bufInOffset);
            
            *bufInOffset = *bufInOffset + 5;
            i = i + 1;
            if(*bufOutLen == i)
			{
				*bufOutOffset = 0;
			}
        }
        else 
        {
			/* Process Write SWD command */
            int16 delTr = *bufOutLen - (i + 5);
            if(delTr < 0)
            {
                for(k = 0; k < (5 + delTr); k++)
                {
                    bufOut[k] = bufOut[i + k];
                }
            }
            else
            {
                /* Execute Write transaction */
                WriteSWD(bufOut + i, bufIn + *bufInOffset);
                *bufInOffset = *bufInOffset + 1;
            }
            if(delTr <= 0)
            {
                if(delTr == 0)
				{
                    *bufOutOffset = 0;
				}
                else
				{
                    *bufOutOffset = 5 + delTr;
				}
                break;
            }
            i = i + 5;
        }
	}
	return;
}
/*******************************************************************************
* Function Name: SWDLoadUsbIn()
********************************************************************************
* Summary:
* Writes data to the USB IN endpoint.
*
* Parameters:
*  bufIn		: IN EP buffer
*  size			: Number of bytes to be sent to the IN endpoint
*
* Return:
*  void
*
*******************************************************************************/
void SWDLoadUsbIn(uint8 *bufIn, int16 size)
{
    while(USBFS_bGetEPState(SWD_IN_EP) != USBFS_IN_BUFFER_EMPTY)
	{
		/* Wait till the previous IN endpoint transaction has completed */
	}
    USBFS_LoadInEP(SWD_IN_EP, bufIn, size);
	return;
}
/*******************************************************************************
* Function Name: SendSwdResult()
********************************************************************************
* Summary:
* Returns the result of SWD programming command request to the PSoC programmer via
* the USB lines.
*
* Parameters:
*  bufIn		: IN EP buffer
*  bufOutOffset	: offset from the starting of bufOut to the location of data
*  bufInSize	: Number of bytes to be sent through the USB lines
*
* Return:
*  void
*
*******************************************************************************/
void SendSwdResult(uint8 *bufIn, int16 *bufOutOffset, int16 *bufInSize)
{
    int16 i = 0;
    int16 offset = 0;
    int16 EPs = ((*bufInSize) / 64);

    *bufInSize = ((*bufInSize) % 64);
    for(i = 0; i < EPs; i++, offset+=64)
    {
		SWDLoadUsbIn(bufIn + offset, 64);
	}

    if(fIsShortPkt)
    {
        SWDLoadUsbIn(bufIn + offset, *bufInSize);
        *bufInSize = 0;
    }
    else
    {
        for(i = 0; i < *bufInSize; i++)
		{
            bufIn[i] = bufIn[offset + i];
		}
    }
	return;
}

/*******************************************************************************
* Function Name: HandleSWDRequest()
********************************************************************************
* Summary:
* Handles the SWD programming requests.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void HandleSWDRequest(void)
{
    ReceiveSWDRequest(bufOut, &bufOutOffset, &bufOutLen);
    ProcessSWDRequest(bufOut, bufIn, &bufOutOffset, &bufInOffset, &bufOutLen);
    SendSwdResult(bufIn, &bufOutOffset, &bufInOffset);
	return;
}


/*******************************************************************************
* Function Name: CmdSWDAcquire()
********************************************************************************
* Summary:
* Calls the SWDAcquirePSoC4() according to the requests initiated by 
* PSoC Programmer via USB lines.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void CmdSWDAcquire(void)
{
	uint8 dev = 0;
	uint8 mode = 0;
	uint8 attempts = 0;
	
	/* Device Type */
    dev = pifData[0] & 0x0F;
	/* Acquire Mode (Power Cycle or Reset) */
	mode = (pifData[0] & 0xF0) >> 4;
	/* Number of retries */
	attempts = pifData[1];
	
	if(dev == ACQUIRE_PSoC4)
	{
		if (SWDAcquirePSoC4(mode, attempts) == TRUE) 
		{
			pifBuf[0] = ACQUIRE_PASS;
		}
		else
		{
			pifBuf[0] = ACQUIRE_FAIL;
		}
	}
	else 
    {	/* Unknown acquire method	*/
		pifBuf[0] = ACQUIRE_FAIL;
    }
	return;
}

/* [] END OF FILE */
