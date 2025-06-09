/*****************************************************************************
* | File      	:   LCD1602.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master
*                and enhance portability
*----------------
* | This version:   V1.0
* | Date        :   2025-01-03
* | Info        :   Basic version
*
******************************************************************************/

#include <stdlib.h>		// itoa()
#include <stdio.h>
#include "LCD1602.h"

uint8_t _showfunction;
uint8_t _showcontrol;
uint8_t _showmode;
uint8_t _numlines, _currline;

// Function to send a command to the LCD
void LCD1602_command(uint8_t value)
{
	DEV_I2C_Write(LCD_ADDRESS, 0x80,  value);  // Send command to the LCD using I2C (0x80 indicates command mode)
}

// Function to send data to the LCD (i.e., text or characters)
void LCD1602_data(uint8_t value)
{
	DEV_I2C_Write(LCD_ADDRESS, 0x40,  value);  // Send data to the LCD using I2C (0x40 indicates data mode)
}

// Function to initialize the LCD
void LCD1602_init(uint8_t cols, uint8_t lines)
{
	_showfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;  // Initialize with 4-bit mode, 1 line, 5x8 dot matrix
	if (lines > 1)
    {
        _showfunction |= LCD_2LINE;  // Enable 2-line display if specified
    }
    _numlines = lines;
    _currline = 0;

    // Wait at least 40ms after power rises above 2.7V before sending commands
    DEV_Delay_ms(50);  // Wait for power stabilization

    // Send function set command to initialize the display (according to the datasheet)
    LCD1602_command(LCD_FUNCTIONSET | _showfunction);
    DEV_Delay_ms(5);  // Wait for at least 4.1ms after function set

    // Try to set function a second and third time to ensure proper setup
    LCD1602_command(LCD_FUNCTIONSET | _showfunction);
    DEV_Delay_ms(5);
    LCD1602_command(LCD_FUNCTIONSET | _showfunction);

    // Turn on the display with no cursor and no blinking by default
    _showcontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    LCD1602_display();  // Apply display settings

    // Clear the display
    LCD1602_clear();

    // Initialize the text entry mode (left to right with no shift)
    _showmode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    LCD1602_command(LCD_ENTRYMODESET | _showmode);  // Set entry mode

	LCD1602_led_init();  // Initialize the LED (if applicable)
}

// Function to turn on the display
void LCD1602_display()
{
    _showcontrol |= LCD_DISPLAYON;  // Set the display on
    LCD1602_command(LCD_DISPLAYCONTROL | _showcontrol);  // Apply display control settings
}

// Function to clear the display
void LCD1602_clear()
{
    LCD1602_command(LCD_CLEARDISPLAY);  // Send clear display command
    DEV_Delay_ms(100);  // Wait for the display to clear
}

// Function to set the cursor to a specific column and row
void LCD1602_setCursor(uint8_t col, uint8_t row)
{
    col = (row == 0 ? col | 0x80 : col | 0xc0);  // Set cursor address based on row (0 or 1)
    LCD1602_command(col);  // Send the cursor position command to the LCD
}

// Function to send a string of characters to the LCD
void LCD1602_send_string(const char *str)
{
    uint8_t i;
    for (i = 0; str[i] != '\0'; i++)  // Iterate over each character of the string
        LCD1602_data(str[i]);  // Send each character as data to the LCD
}

// Function to hide the cursor
void LCD1602_noCursor()
{
    _showcontrol &= ~LCD_CURSORON;  // Clear the cursor on flag
    LCD1602_command(LCD_DISPLAYCONTROL | _showcontrol);  // Apply the updated display control
}
		
// Function to show the cursor
void LCD1602_cursor()
{
    _showcontrol |= LCD_CURSORON;  // Set the cursor on flag
    LCD1602_command(LCD_DISPLAYCONTROL | _showcontrol);  // Apply the updated display control
}

// Function to scroll the display to the left
void LCD1602_scrollDisplayLeft(void)
{
    LCD1602_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);  // Send command to move display content left
}

// Function to scroll the display to the right
void LCD1602_scrollDisplayRight(void)
{
    LCD1602_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);  // Send command to move display content right
}

// Set the text entry mode to left-to-right (characters appear from left to right)
void LCD1602_leftToRight(void)
{
    _showmode |= LCD_ENTRYLEFT;  // Set the left-to-right entry mode
    LCD1602_command(LCD_ENTRYMODESET | _showmode);  // Apply the new entry mode
}

// Set the text entry mode to right-to-left (characters appear from right to left)
void LCD1602_rightToLeft(void)
{
    _showmode &= ~LCD_ENTRYLEFT;  // Disable the left-to-right entry mode
    LCD1602_command(LCD_ENTRYMODESET | _showmode);  // Apply the new entry mode
}

// Disable auto-scrolling of the display (characters don't shift when new characters are written)
void LCD1602_noAutoscroll(void)
{
    _showmode &= ~LCD_ENTRYSHIFTINCREMENT;  // Disable auto-scrolling
    LCD1602_command(LCD_ENTRYMODESET | _showmode);  // Apply the new entry mode
}

// Enable auto-scrolling of the display (characters shift left as new characters are written)
void LCD1602_autoscroll(void)
{
    _showmode |= LCD_ENTRYSHIFTINCREMENT;  // Enable auto-scrolling
    LCD1602_command(LCD_ENTRYMODESET | _showmode);  // Apply the new entry mode
}

// Create a custom character in the CGRAM (Character Generator RAM)
// The character is created from a 5x8 dot matrix provided in 'charmap'
void LCD1602_createChar(uint8_t location, uint8_t charmap[])
{
    location &= 0x7;  // Only 8 locations (0-7) for custom characters
    LCD1602_command(LCD_SETCGRAMADDR | (location << 3));  // Set the CGRAM address for the custom character

    uint8_t data[9];
    data[0] = 0x40;  // CGRAM data start address
    for (int i = 0; i < 8; i++)
    {
        data[i + 1] = charmap[i];  // Copy character map data
    }

    // Write custom character data to LCD via I2C
    DEV_I2C_Write_nByte(LCD_ADDRESS, data, 9);
}

// Initialize the LED control chip (SN3193) for LED operation
void LCD1602_led_init()
{
    DEV_I2C_Write(SN3193_IIC_ADDRESS, SHUTDOWN_REG, 0x20);  // Disable shutdown mode, enable normal operation
    DEV_I2C_Write(SN3193_IIC_ADDRESS, LED_MODE_REG, LED_NORNAL_MODE);  // Set LED to normal operation mode
    DEV_I2C_Write(SN3193_IIC_ADDRESS, CURRENT_SETTING_REG, 0x00);  // Set output current to Imax=42mA
    DEV_Delay_ms(10);
    
    DEV_I2C_Write(SN3193_IIC_ADDRESS, PWM_1_REG, 0x00);  // Set PWM duty cycle to 0 (minimum brightness)
    DEV_Delay_ms(100);
    DEV_I2C_Write(SN3193_IIC_ADDRESS, PWM_UPDATE_REG, 0x00);  // Apply PWM settings
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T0_1_REG, 0x40);  // Set T0 time for OUT1
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T0_2_REG, 0x40);  // Set T0 time for OUT2
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T0_3_REG, 0x40);  // Set T0 time for OUT3
    DEV_Delay_ms(100);

    DEV_I2C_Write(SN3193_IIC_ADDRESS, T1T2_1_REG, 0x26);  // Set T1&T2 time for OUT1
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T1T2_2_REG, 0x26);  // Set T1&T2 time for OUT2  
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T1T2_3_REG, 0x26);  // Set T1&T2 time for OUT3
    DEV_Delay_ms(100);

    DEV_I2C_Write(SN3193_IIC_ADDRESS, T3T4_1_REG, 0x26);  // Set T3&T4 time for OUT1
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T3T4_2_REG, 0x26);  // Set T3&T4 time for OUT2 
    DEV_I2C_Write(SN3193_IIC_ADDRESS, T3T4_3_REG, 0x26);  // Set T3&T4 time for OUT3 
    DEV_Delay_ms(100);

    DEV_I2C_Write(SN3193_IIC_ADDRESS, LED_CONTROL_REG, 0x01);  // Enable OUT1, OUT2, and OUT3 (turn on LEDs)
    DEV_I2C_Write(SN3193_IIC_ADDRESS, TIME_UPDATE_REG, 0x00);  // Load time register data
    DEV_Delay_ms(100);
}

// Set the brightness of the LEDs (range from 0 to 100)
void LCD1602_set_brightness(uint8_t value)
{
    if (value < 0 || value > 100)
    {
        printf("Please enter a value between 0 and 100.\n");
    }
    else
    {
        DEV_I2C_Write(SN3193_IIC_ADDRESS, PWM_1_REG, (int)(value * (0xFF / 100)));  // Set PWM duty cycle based on the value
        DEV_Delay_ms(100);
        DEV_I2C_Write(SN3193_IIC_ADDRESS, PWM_UPDATE_REG, 0x00);  // Apply the new brightness setting
    }
}

// Set the operation mode of the LEDs (e.g., breathing mode or steady mode)
void LCD1602_set_led_mode(uint8_t mode)
{
    DEV_I2C_Write(SN3193_IIC_ADDRESS, LED_MODE_REG, mode);  // Set LED operation mode
    // Mode options: 0x20 for breathing mode, 0x00 for steady mode
}
