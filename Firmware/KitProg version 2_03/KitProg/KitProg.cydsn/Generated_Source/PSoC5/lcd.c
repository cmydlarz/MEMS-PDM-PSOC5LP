/*******************************************************************************
* File Name: lcd.c
* Version 1.80
*
* Description:
*  This file provides source code for the Character LCD component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "lcd.h"


static void lcd_WrDatNib(uint8 nibble) ;
static void lcd_WrCntrlNib(uint8 nibble) ;

/* Stores the state of conponent. Indicates wherewer component is 
* in enable state or not.
*/
uint8 lcd_enableState = 0u;

uint8 lcd_initVar = 0u;


/*******************************************************************************
* Function Name: lcd_Init
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void lcd_Init(void) 
{
    /* INIT CODE */
    CyDelay(40u);                                                        /* Delay 40 ms */
    lcd_WrCntrlNib(lcd_DISPLAY_8_BIT_INIT);   /* Selects 8-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */
    lcd_WrCntrlNib(lcd_DISPLAY_8_BIT_INIT);   /* Selects 8-bit mode */
    CyDelay(15u);                                                        /* Delay 15 ms */
    lcd_WrCntrlNib(lcd_DISPLAY_8_BIT_INIT);   /* Selects 8-bit mode */
    CyDelay(1u);                                                         /* Delay 1 ms */
    lcd_WrCntrlNib(lcd_DISPLAY_4_BIT_INIT);   /* Selects 4-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */

    lcd_WriteControl(lcd_CURSOR_AUTO_INCR_ON);    /* Incr Cursor After Writes */
    lcd_WriteControl(lcd_DISPLAY_CURSOR_ON);      /* Turn Display, Cursor ON */
    lcd_WriteControl(lcd_DISPLAY_2_LINES_5x10);   /* 2 Lines by 5x10 Characters */
    lcd_WriteControl(lcd_DISPLAY_CURSOR_OFF);     /* Turn Display, Cursor OFF */
    lcd_WriteControl(lcd_CLEAR_DISPLAY);          /* Clear LCD Screen */
    lcd_WriteControl(lcd_DISPLAY_ON_CURSOR_OFF);  /* Turn Display ON, Cursor OFF */
    lcd_WriteControl(lcd_RESET_CURSOR_POSITION);  /* Set Cursor to 0,0 */
    CyDelay(5u);

    #if(lcd_CUSTOM_CHAR_SET != lcd_NONE)
        lcd_LoadCustomFonts(lcd_customFonts);
    #endif /* lcd_CUSTOM_CHAR_SET != lcd_NONE */
}


/*******************************************************************************
* Function Name: lcd_Enable
********************************************************************************
*
* Summary:
*  Turns on the display.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Theory:
*  This finction has no effect when it called first time as
*  lcd_Init() turns on the LCD.
*
*******************************************************************************/
void lcd_Enable(void) 
{
    lcd_DisplayOn();
    lcd_enableState = 1u;
}


/*******************************************************************************
* Function Name: lcd_Start
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*  If it was not the first call in this project then it just turns on the
*  display
*
*
* Parameters:
*  lcd_initVar - global variable.
*
* Return:
*  lcd_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void lcd_Start(void) 
{
    /* If not initialized then perform initialization */
    if(lcd_initVar == 0u)
    {
        lcd_Init();
        lcd_initVar = 1u;
    }

    /* Turn on the LCD */
    lcd_Enable();
}


/*******************************************************************************
* Function Name: lcd_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void lcd_Stop(void) 
{
    /* Calls LCD Off Macro */
    lcd_DisplayOff();
    lcd_enableState = 0u;
}


/*******************************************************************************
*  Function Name: lcd_Position
********************************************************************************
*
* Summary:
*  Moves active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:     Specific row of LCD module to be written
*  column:  Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays which use the 2X40 address mode.
*  This results in Row 2 offset from row one by 0x28.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void lcd_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            lcd_WriteControl(lcd_ROW_0_START + column);
            break;
        case (uint8) 1:
            lcd_WriteControl(lcd_ROW_1_START + column);
            break;
        case (uint8) 2:
            lcd_WriteControl(lcd_ROW_2_START + column);
            break;
        case (uint8) 3:
            lcd_WriteControl(lcd_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: lcd_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string:  pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        lcd_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: lcd_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character:  character to be written to the LCD
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_PutChar(char8 character) 
{
    lcd_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: lcd_WriteData
********************************************************************************
*
* Summary:
*  Writes a data byte to the LCD module's Data Display RAM.
*
* Parameters:
*  dByte:  byte to be written to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_WriteData(uint8 dByte) 
{
    uint8 nibble;

    lcd_IsReady();
    nibble = dByte >> lcd_NIBBLE_SHIFT;

    /* Write high nibble */
    lcd_WrDatNib(nibble);

    nibble = dByte & lcd_NIBBLE_MASK;
    /* Write low nibble */
    lcd_WrDatNib(nibble);
}


/*******************************************************************************
*  Function Name: lcd_WriteControl
********************************************************************************
*
* Summary:
*  Writes a command byte to the LCD module.
*
* Parameters:
*  cByte:   byte to be written to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_WriteControl(uint8 cByte) 
{
    uint8 nibble;

    lcd_IsReady();

    nibble = cByte >> lcd_NIBBLE_SHIFT;
    
    /* WrCntrlNib(High Nibble) */
    lcd_WrCntrlNib(nibble);
    nibble = cByte & lcd_NIBBLE_MASK;

    /* WrCntrlNib(Low Nibble) */
    lcd_WrCntrlNib(nibble);
}


/*******************************************************************************
* Function Name: lcd_IsReady
********************************************************************************
*
* Summary:
*  Polls LCD until the ready bit is set.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes pins to High-Z.
*
*******************************************************************************/
void lcd_IsReady(void) 
{
    uint8 value;

    /* Clear the LCD port*/
    lcd_PORT_DR_REG &= ((uint8)(~lcd_PORT_MASK));

    /* PSoC4 has a bit different port/pin organization for setting Drive Modes than
    * PSoC3/5.
    */
    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = lcd_PORT_PC_REG & ((uint8)(~ lcd_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_PORT_PC_REG = value | lcd_HIGH_Z_DATA_DM;

    #else
    
        /* Change Port to High-Z Status on data pins */

        /* Mask off data pins to clear old values out */
        value = lcd_PORT_DM0_REG & ((uint8)(~lcd_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_PORT_DM0_REG = value | (lcd_HIGH_Z_DM0 & lcd_DATA_MASK);

        /* Mask off data pins to clear old values out */
        value = lcd_PORT_DM1_REG & ((uint8)(~lcd_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_PORT_DM1_REG = value;

        /* Mask off data pins to clear old values out */
        value = lcd_PORT_DM2_REG & ((uint8)(~lcd_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_PORT_DM2_REG = value;
    
    #endif /* CY_PSOC4 */
    
    /* Make sure RS is low */
    lcd_PORT_DR_REG &= ((uint8)(~lcd_RS));

    /* Set R/W high to read */
    lcd_PORT_DR_REG |= lcd_RW;

    do
    {
        /* 40 ns delay required before rising Enable and 500ns between neighbour Enables */
        CyDelayUs(0u);

        /* Set E high */
        lcd_PORT_DR_REG |= lcd_E;

        /* 360 ns delay the setup time for data pins */
        CyDelayUs(1u);

        /* Get port state */
        value = lcd_PORT_PS_REG;

        /* Set enable low */
        lcd_PORT_DR_REG &= ((uint8)(~lcd_E));

        /* Extract ready bit */
        value &= lcd_READY_BIT;

        /* Set E high as we in 4-bit interface we need extra oparation */
        lcd_PORT_DR_REG |= lcd_E;

        /* 360 ns delay the setup time for data pins */
        CyDelayUs(1u);

        /* Set enable low */
        lcd_PORT_DR_REG &= ((uint8)(~lcd_E));

        /* Repeat until bit 4 is not zero. */

    } while (value != 0u);

    /* Set R/W low to write */
    lcd_PORT_DR_REG &= ((uint8)(~lcd_RW));

    /* Clear the LCD port*/
    lcd_PORT_DR_REG &= ((uint8)(~lcd_PORT_MASK));

    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = lcd_PORT_PC_REG & ((uint32)(~ lcd_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_PORT_PC_REG = value | lcd_STRONG_DATA_DM;

    #else

        /* Change Port to Output (Strong) on data pins */
        /* Mask off data pins to clear high z values out. Configure data pins 
        * to Strong Drive, others unchanged.
        */
        lcd_PORT_DM0_REG &= ((uint8)(~lcd_DATA_MASK));
        /* Mask off data pins to clear high z values out */
        value = lcd_PORT_DM1_REG & ((uint8)(~lcd_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        lcd_PORT_DM1_REG = value | (lcd_STRONG_DM1 & lcd_DATA_MASK);

        /* Mask off data pins to clear high z values out */
        value = lcd_PORT_DM2_REG & ((uint8)(~lcd_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        lcd_PORT_DM2_REG = value | (lcd_STRONG_DM2 & lcd_DATA_MASK);
    
    #endif /* CY_PSOC4 */
}


/*******************************************************************************
*  Function Name: lcd_WrDatNib
********************************************************************************
*
* Summary:
*  Writes a data nibble to the LCD module.
*
* Parameters:
*  nibble:  byte containing nibble in least significant nibble to be written
*           to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void lcd_WrDatNib(uint8 nibble) 
{
    lcd_IsReady();

    /* RS shoul be low to select data register */
    lcd_PORT_DR_REG |= lcd_RS;
    /* Reset RW for write operation */
    lcd_PORT_DR_REG &= ((uint8)(~lcd_RW));

    /* Two following lines of code will provide us with 40ns delay */
    /* Clear data pins */
    lcd_PORT_DR_REG &= ((uint8)(~lcd_DATA_MASK));

    /* Write in data, bring E high*/
    #if(0u != lcd_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        lcd_PORT_DR_REG |= 
            (lcd_E | ((uint8)(((uint8) nibble) << lcd_PORT_SHIFT)));
    #else
        lcd_PORT_DR_REG |= (lcd_E | nibble);
    #endif /* (0u != lcd_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    lcd_PORT_DR_REG &= ((uint8)(~lcd_E));
}


/*******************************************************************************
*  Function Name: lcd_WrCntrlNib
********************************************************************************
*
* Summary:
*  Writes a control nibble to the LCD module.
*
* Parameters:
*  nibble:  byte containing nibble in least significant nibble to be written
*           to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void lcd_WrCntrlNib(uint8 nibble) 
{
    /* RS and RW shoul be low to select instruction register and  write operation respectively */
    lcd_PORT_DR_REG &= ((uint8)(~(lcd_RS | lcd_RW)));

    /* Two following lines of code will give provide ua with 40ns delay */
    /* Clear data pins */
    lcd_PORT_DR_REG &= ((uint8)(~lcd_DATA_MASK));

    /* Write control data and set enable signal */
    #if(0u != lcd_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        lcd_PORT_DR_REG |= 
            (lcd_E | ((uint8)(((uint8) nibble) << lcd_PORT_SHIFT)));
    #else
        lcd_PORT_DR_REG |= (lcd_E | nibble);
    #endif /* (0u != lcd_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    lcd_PORT_DR_REG &= ((uint8)(~lcd_E));
}


#if(lcd_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: lcd_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE lcd_hex[16u] = "0123456789ABCDEF";
        
        lcd_PutChar((char8) lcd_hex[value >> lcd_BYTE_UPPER_NIBBLE_SHIFT]);
        lcd_PutChar((char8) lcd_hex[value & lcd_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: lcd_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value:   The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_PrintInt16(uint16 value) 
    {
        lcd_PrintInt8((uint8)(value >> lcd_U16_UPPER_BYTE_SHIFT));
        lcd_PrintInt8((uint8)(value & lcd_U16_LOWER_BYTE_MASK));
    }


    /*******************************************************************************
    *  Function Name: lcd_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_PrintNumber(uint16 value) 
    {

        char8 number[lcd_NUMBER_OF_REMAINDERS];
        char8 temp[lcd_NUMBER_OF_REMAINDERS];

        uint8 digIndex = 0u;
        uint8 numDigits;

        /* Load these in reverse order */
        while(value >= lcd_TEN)
        {
            temp[digIndex] = (value % lcd_TEN) + '0';
            value /= lcd_TEN;
            digIndex++;
        }

        temp[digIndex] = (value % lcd_TEN) + '0';
        numDigits = digIndex;

        /* While index is greater than or equal to zero copy number
        * from temporary array to number[].
        */
        while (digIndex != 0u)
        {
            number[numDigits - digIndex] = temp[digIndex];
            digIndex--;
        }
        
        /* Copy last digit */
        number[numDigits] = temp[0u];

        /* Null Termination */
        number[numDigits + 1u] = (char8) '\0';

        /* Print out number */
        lcd_PrintString(&number[0u]);
    }

#endif /* lcd_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
