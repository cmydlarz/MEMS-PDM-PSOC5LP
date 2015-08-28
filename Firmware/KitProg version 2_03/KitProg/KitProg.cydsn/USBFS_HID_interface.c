/*****************************************************************************
* File Name: USBFS_HID_interface.c
* Version 2.03
*
* Description: Handles the the USB-I2C Bridge functionality. 
*
* Owner:
*	Ranjith M, Applications Engineer (rnjt@cypress.com)
*
* Related Document:
* 	001-85925 - CY8CKIT-042 PSoC 4 Pioneer Kit IROS
*	RNJT#21
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
* Local Function Prototypes
*****************************************************************************/
void SendToUSB(void);
static uint8 I2CRestart(void);
static void I2CTransaction(uint8 bControlByte, uint8 bLength, 
                    uint8 *bCommandData, uint8 * bReturnData);
static void I2CPinPullUpDriveLow(void);
static void I2CPinTriState(void);
void I2CPullUpDisable(void);
/*****************************************************************************
* Global Variable Declarations
*****************************************************************************/


/*****************************************************************************
* Local Global Variable Declarations
*****************************************************************************/

uint8 bOutEndpointData[64];
uint8 bInEndpointData[64];
uint8 bBulkInEndpointData[513];
uint8 bOutPacketIndex;
uint8 bInPacketIndex;
uint8 bHostInterface;
uint8 i2cSpeed;
uint16 voltage;

/*******************************************************************************
* Function Name: SendToUSB()
********************************************************************************
* Summary:
*  Send data to USB IN endpoint
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SendToUSB(void)
{
    while(USBFS_bGetEPState(HOST_IN_EP) != USBFS_IN_BUFFER_EMPTY)
	{
		/* Wait for the previous IN endpoint trasaction to complete */
	}
    USBFS_LoadInEP(HOST_IN_EP, bInEndpointData, 64);
    USBFS_EnableOutEP(HOST_OUT_EP);
	return;
}
/*******************************************************************************
* Function Name: I2CRestart()
********************************************************************************
* Summary:
*  Restart try to free I2C bus from hanging devices
*
* Parameters:
*  void
*
* Return:
*  status, 0 fail, 1 success
*
*******************************************************************************/    
uint8 I2CRestart(void)
{
    uint8 bCount;
    uint8 bStatus;
	
	/* Stop the I2C hardware */
    I2CHW_Stop();
	
	/* Allow the DSI to drive the I2C SDA and SCL pins */
    I2C_DSIBypassDisable();
    
    /* Make sure the SDA line is not pulled low by master */
    Pin_I2C_SDA_Write(1);
    
    /* send clock signal on SCL and wait for SDA to turn free */
	Pin_I2C_SCL_Write(0);
    for (bCount = 0; bCount < TIMEOUT; bCount++) 
    {
        if(Pin_I2C_SDA_Read()) 
		{
			/* break loop if SDA released by slave */
			break;
		}
		
		/* clock on the SCL line */
        Pin_I2C_SCL_Write(1); 
        CyDelayUs(40);        
        Pin_I2C_SCL_Write(0);        
        CyDelayUs(40);
    }
	
	/* Generate stop condition */
    Pin_I2C_SDA_Write(0);
    Pin_I2C_SCL_Write(1);    
    CyDelayUs(80);
    Pin_I2C_SDA_Write(1);
	
    /* wait for stable signal */
    CyDelayUs(80);
	/* If SCL and SCL lines free, return SUCCESS */
    if (Pin_I2C_SDA_Read() && Pin_I2C_SCL_Read()) 
    {
        bStatus = RESTART_SUCCESS;
    }
    else 
    {
        bStatus = RESTART_FAIL;
    }
    
	/* Transfer the control back to the port control registers */
    I2C_DSIBypassEnable();
	
	/* Start the I2C hardware */
    I2CHW_Start();

    return bStatus;
}
/*******************************************************************************
* Function Name: I2CTransaction()
********************************************************************************
* Summary:
*  Executes an I2C transaction.
*
* Parameters:
*  bControlByte 	- control byte
*  bLength 			- data length
*  bCommandData 	- point to command data buffer
*  bReturnData 		- point to return data buffer
*
* Return:
*  void
*
* Notes:
*  This routine assumes a valid I2C transaction is encoded in the command.
*
*******************************************************************************/
void I2CTransaction(uint8 bControlByte, uint8 bLength, uint8 *bCommandData, uint8 * bReturnData)
{
    uint8 bCounter;
    uint8 bIndex;
    uint8 flag_ACK;
	uint8 flag_exit = CONTINUE;
	
    /* Start the transaction */
    bIndex = 0;
	/* if Start command received */
	if (bControlByte & CONTROL_START)
    {
		/* SDA and SCL must be high (No traffic on the I2C bus) */
        if (!(Pin_I2C_SDA_Read() && Pin_I2C_SCL_Read())) 
        {
            /* Send a stop condition */
            I2CHW_MasterSendStop();
            CyDelayUs(10);
            if(!I2CRestart())	    
            {
                /* Indicate a nACK */
                bReturnData[0] = NACK;
				flag_exit = EXIT;
           }
        }
		if(flag_exit != EXIT)
		{
        	/* Send a start */
        	I2CHW_Stop();
        	I2CHW_Start();        
			if(I2CHW_MasterSendStart(bCommandData[0], (bControlByte & CONTROL_DIRECTION)) == I2CHW_MSTR_NO_ERROR)
	        {
				flag_ACK = OK_ACK;
			}
			else
			{
				flag_ACK = NACK;
			}
			/* Send the ackknowledgement status back to USB */
			bReturnData[0] = flag_ACK;  
	        bIndex++;
	        bCounter = bLength - 1;
		}
    }
	/* if Restart command received */
    else if (bControlByte & CONTROL_RESTART)
    {
        /* Send a restart */
        if(I2CHW_MasterSendRestart(bCommandData[0], (bControlByte & CONTROL_DIRECTION)) == I2CHW_MSTR_NO_ERROR)
		{
			flag_ACK = OK_ACK;
		}
		else
		{
			flag_ACK = NACK;
		}
		/* Send the ackknowledgement status back to USB */
        bReturnData[0] = flag_ACK;
        bIndex++;
        bCounter = bLength - 1;
    }
    else
    {
        /* No start or restart.  Assume the bus is currently busy, and the slave
         * ACK'ed the previous byte.*/
        flag_ACK = OK_ACK;
		
        if ((bControlByte & CONTROL_DIRECTION) == CONTROL_DIRECTION_READ)
        { 
            bReturnData[0] = flag_ACK;
            bIndex++;
            bCounter = bLength - 1;
        }
    }
    
    /* Transfer data */
    if ((flag_ACK == OK_ACK) && (flag_exit != EXIT))
    {
        if ((bControlByte & CONTROL_DIRECTION) == CONTROL_DIRECTION_READ)
        {                
            /* Read */
            if (bLength)
            {
                
				for (; bCounter; bCounter--)
                {    
                    /* Read the I2C lines and store the bytes read in a buffer */
					bReturnData[bIndex] = I2CHW_MasterReadByte(I2CHW_ACK_DATA);
                    bIndex++;
                }
                
				/* If the last byte is a stop condition, donot acknowledge it */
                if (bControlByte & CONTROL_STOP)
                {
                    bReturnData[bIndex] = I2CHW_MasterReadByte(I2CHW_NAK_DATA);
                } 
				else 
				{
                    bReturnData[bIndex] = I2CHW_MasterReadByte(I2CHW_ACK_DATA);
                }                
            }
        }
        else
        {
            /* Write */
            for (bCounter = bLength; bCounter; bCounter--)
            {        
                /* Write the byte and return the acknowledgement status */
				if(I2CHW_MasterWriteByte(bCommandData[bIndex]) == I2CHW_MSTR_NO_ERROR)
				{
					flag_ACK = OK_ACK;
				}
				else
				{
					flag_ACK = NACK;
				}
                bReturnData[bIndex] = flag_ACK;
                if (flag_ACK == NACK)
                {
                    break;	    			
                }  			
                bIndex++;                
            }    
        }
    }
    
    /* End the transaction */
    if (bControlByte & CONTROL_STOP) 
	{
		I2CHW_MasterSendStop();                
	}
}

/*******************************************************************************
* Function Name: I2CPinPullUpDriveLow()
********************************************************************************
* Summary:
*  Set the I2C pins to open drain drive low.
*
* Parameters:
*  void
*
* Return:
*  void
*
*       
*******************************************************************************/
void I2CPinPullUpDriveLow(void)
{
    CyPins_SetPinDriveMode(Pin_I2C_SDA_0, Pin_I2C_SDA_DM_OD_LO);
    CyPins_SetPinDriveMode(Pin_I2C_SCL_0, Pin_I2C_SCL_DM_OD_LO);
}

/*******************************************************************************
* Function Name: I2CPinTriState()
********************************************************************************
* Summary:
*  Tri state the I2C pin set.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2CPinTriState(void)
{
    CyPins_SetPinDriveMode(Pin_I2C_SDA_0, Pin_I2C_SDA_DM_DIG_HIZ);
    CyPins_SetPinDriveMode(Pin_I2C_SCL_0, Pin_I2C_SCL_DM_DIG_HIZ);
}
/*******************************************************************************
* Function Name: I2CPullUpEnable()
********************************************************************************
* Summary:
*  Sets the drive mode of the Pull Up enable pin and sets the pn.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2CPullUpEnable(void)
{
	Pin_SDAPullUp_Enable_Write(1);
	Pin_SCLPullUp_Enable_Write(1);
	CyPins_SetPinDriveMode(Pin_SDAPullUp_Enable_0, Pin_SDAPullUp_Enable_DM_STRONG);
	CyPins_SetPinDriveMode(Pin_SCLPullUp_Enable_0, Pin_SCLPullUp_Enable_DM_STRONG);
}
/*******************************************************************************
* Function Name: I2CPullUpDisable()
********************************************************************************
* Summary:
*  Sets the drive mode of the Pull Up enable pin and sets the pn.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2CPullUpDisable(void)
{
	CyPins_SetPinDriveMode(Pin_SCLPullUp_Enable_0, Pin_SCLPullUp_Enable_DM_DIG_HIZ);
	CyPins_SetPinDriveMode(Pin_SDAPullUp_Enable_0, Pin_SDAPullUp_Enable_DM_DIG_HIZ);
}
/*******************************************************************************
* Function Name: I2C_DSIBypassDisable()
********************************************************************************
* Summary:
*  Disable DSI bypass and let the Port logic data register drives the 
*  corresponding port pin
*
* Parameters:.
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2C_DSIBypassDisable(void)
{
    /* Let the Port logic data register drives the corresponding port pin. */
    Pin_I2C_SDA_BYP = Pin_I2C_SDA_BYP & ~ (Pin_I2C_SDA_MASK | Pin_I2C_SCL_MASK);     
}

/*******************************************************************************
* Function Name: I2C_DSIBypassEnable()
********************************************************************************
* Summary:
*  Enable DSI bypass and  Let digital system interconnect (DSI) drive the  
*  corresponding port pin
*
* Parameters:.
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2C_DSIBypassEnable(void)
{
    /* Let digital system interconnect (DSI) drive the corresponding port pin. */
    Pin_I2C_SDA_BYP = Pin_I2C_SDA_BYP | (Pin_I2C_SDA_MASK | Pin_I2C_SCL_MASK);
}
/*******************************************************************************
* Function Name: HostCommStop()
********************************************************************************
* Summary:
*  Stop USB-I2C Host function. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void HostCommStop(void)
{    
    I2CHW_Stop();
	I2CPinTriState();
}
/*******************************************************************************
* Function Name: HostCommInit()
********************************************************************************
* Summary:
*  Initialize Host parameters. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void HostCommInit(void)
{
    /* Stop the USB-I2C bridge interface */    
    HostCommStop();
	
	/* Set the default interface to be I2C*/
    bHostInterface = INTERFACE_I2C;
	
	/* Start the clock for I2C */
    Clock_I2C_Start();
	
	/* Start the clock for UART */
	Clock_UART_Start();
}
/*******************************************************************************
* Function Name: HostComm()
********************************************************************************
* Summary:
*  Handles the communication between the PC and the PSoC 5LP via the HID interface.
*  Handles the USB-I2C Bridge functionality.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void HostComm(void)
{
    uint8 bControl;
    uint8 bLength;
    uint16 wCount;
    uint8 bCount;

    /* Check for data from the USB host */
    if(USBFS_bGetEPAckState(HOST_OUT_EP))
    {
        /* A new USB packet has been received.  Retrieve it. */                    	
        wCount = USBFS_wGetEPCount(HOST_OUT_EP);
        bCount = USBFS_ReadOutEP(HOST_OUT_EP, bOutEndpointData, (wCount & 0x00FF));

        /* Initialize variables */
        bOutPacketIndex = 0;
        bInPacketIndex  = 0;
        
		/* Retrieve the first two bytes of data received. 
		 * These bytes are the control and length bytes respectively. */
        bControl = bOutEndpointData[bOutPacketIndex];
        bOutPacketIndex++;
		
		/* bLength less than or equal to 61. bLength is the length of data bytes
		 * that will follow.(1 Control byte) + (1 length byte) + (1 command byte) +
		 * (61 data bytes) = 64 (Max. transfer size) */
        bLength = bOutEndpointData[bOutPacketIndex] & 0x3F;
        bOutPacketIndex++;
        
        bInEndpointData[bInPacketIndex] = 0;

        /* Retrieve the command byte if a proper start is detected. */
        if (bControl & CONTROL_CONFIGURE)
        {
            /* Configure command gets highest priority. */    
            I2CHW_Stop();

            /* 00 - 100KHz; 01 - 400KHz; 10 - 50KHz; 11 - 1000KHz */
            if((bControl & CONFIG_I2C_SPEED_MSK)== I2C_SPEED_1000)
            {
                /* Source is 64 MHz, required clock is (1000K * 16 = 16MHz), so divider is 4 */
                Clock_I2C_SetDivider(4 - 1);
				i2cSpeed = I2C_SPEED_1000;
            }
            else if((bControl & CONFIG_I2C_SPEED_MSK)== I2C_SPEED_400)
            {
                /* Source is 64 MHz, required clock is (400K * 16 = 6.4MHz), so divider is 10 */
                Clock_I2C_SetDivider(10 - 1);
				i2cSpeed = I2C_SPEED_400;
            }
            else if((bControl & CONFIG_I2C_SPEED_MSK)== I2C_SPEED_100)
            {
                /* Source is 64 MHz, required clock is (100K * 16 = 1.6MHz), so divider is 40 */
                Clock_I2C_SetDivider(40 - 1);
				i2cSpeed = I2C_SPEED_100;
            }
            else if((bControl & CONFIG_I2C_SPEED_MSK)== I2C_SPEED_050)
            {
                /* Source is 64 MHz, required clock is (50K * 16 = 0.8MHz), so divider is 80 */
                Clock_I2C_SetDivider(80 - 1);
				i2cSpeed = I2C_SPEED_050;
            }
			
			/* Start the I2C and acknowledge */
            I2CHW_Start();
            bInEndpointData[0] = OK_ACK;				
        }
        else if (bControl & CONTROL_RESTART_HW)
        {
            /* HW restart command gets 2nd highest priority */
            /* Restarts the I2C Hardware */
            if(I2CRestart() == RESTART_SUCCESS)
			{
            	bInEndpointData[0] = OK_ACK;
			}
			else
			{
				bInEndpointData[0] = NACK;
			}
        }
        else if ((bControl & CONTROL_START) && (bOutEndpointData[bOutPacketIndex] & PACKET_VALID))
        {   	 		
            /* An extended command gets 3rd highest priority */
            /* Acknowledge the command and indicate presence of Vdev. 
			 * Bit 2 of the ack indicates presence of power. */
            if(GetVoltage() > ONE_VOLT)
			{
           		bInEndpointData[bInPacketIndex] = ACK_WITH_POWER;  
			}
			else
			{
				bInEndpointData[bInPacketIndex] = ACK_WITHOUT_POWER;
			}
           	bInPacketIndex++;
                
            /* Parse the command */
			if (bOutEndpointData[bOutPacketIndex] == GET_POWER_SETTING)
            {
                /* Command 0x80 = GET_POWER_SETTING */
                /* Determine if set or get power */
                if (bControl & 0x01)
                {
                    /* Get power configuration */
                    bInEndpointData[bInPacketIndex++] = POWER_SUPPLIED; 
					/* Not used by KitProg, Used for I2C speed update by TTBridge */
                    bInEndpointData[bInPacketIndex++] = i2cSpeed;
                    voltage = GetVoltage();
					
					/* Return the voltage value to the programmer GUI */
                    bInEndpointData[bInPacketIndex++] = (uint8)(voltage & 0xFF);
                    bInEndpointData[bInPacketIndex++] = (uint8)((voltage >> 8)& 0xFF);
					
					/* Not used by KitProg, Used for VAUX measurement by TTBridge */
                    bInEndpointData[bInPacketIndex++] = 0;
                    bInEndpointData[bInPacketIndex++] = 0;
                }
                else 
                {                        
                    /* Set Power command for powercycle mode. Do nothing for now. */                           
                }
            }
            else if (bOutEndpointData[bOutPacketIndex] == GET_KITPROG_VERSION)
            {
                /* Command 0x81 = Get KitProg version info*/
                bInEndpointData[bInPacketIndex++] = kitProgHWVersion;
                bInEndpointData[bInPacketIndex++] = VER_MINOR ;
                bInEndpointData[bInPacketIndex] = VER_MAJOR;
            }				
            else if (bOutEndpointData[bOutPacketIndex] == RESET_KITPROG)
            {
                /* Command 0x82 = Reset the KitProg */
                CySoftwareReset();
            }
            else if (bOutEndpointData[bOutPacketIndex] == CONFIGURE_INTERFACE)
            {
                /* Command 0x8F = Configure Communication Interface */
				/* Stop all the interface first to avoid any collisions */
                HostCommStop();                
				
				/* Set the interface to be I2C and acknowledge the command */
                bOutPacketIndex++;
                if (bOutEndpointData[bOutPacketIndex] == INTERFACE_I2C)
                {
                    /* Enable the I2C Pull Ups */
					I2CPullUpEnable();
					
					/* Set the I2C pins drive mode */
                    I2CPinPullUpDriveLow();
					
					/* Start the communication interfaces */
                    I2CHW_Start();
                    I2CRestart();
                    bHostInterface = INTERFACE_I2C;                        
                    bInEndpointData[bInPacketIndex] = INTERFACE_I2C;
                }
				else
				{
					/* Disable the I2C Pull Ups */
					I2CPullUpDisable();
				}
			}
            else if (bOutEndpointData[bOutPacketIndex] == ENTER_BOOTLOADER) 
            {
                /* Command 0xA0 = Enter USB bootloader and upgrade firmware */
                Bootloadable_Load();
            }           
            else 
            {
                /* do nothing (ignore other commands) */
            }
        }
        else
        {
            /* A transaction gets last priority */
            if (bHostInterface == INTERFACE_I2C) 
            {
                I2CTransaction(bControl, bLength, &bOutEndpointData[2], bInEndpointData);
            } 
            
            bInPacketIndex = bInPacketIndex + bLength;

        }
        /* Return the acknowledgements and data to the USB */
        SendToUSB();  

    } 
}