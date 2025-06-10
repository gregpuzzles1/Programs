/*****************************************************************************
* | File      	:   Custom_char.c
* | Author      :   Waveshare team
* | Function    :
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2025-01-03
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "LCD_Test.h"

void Custom_char(void)
{
    // Initialize the module, return if initialization fails
    if (DEV_Module_Init() != 0)
    {
        return;
    }

    printf("Custom char Demo\r\n");

    /* LCD Initialization */
    LCD1602_init(16, 2); // Initialize the LCD with 16 columns and 2 rows

    // Set the backlight brightness to 50% (value range: 0 to 100)
    LCD1602_set_brightness(50);

    // Define custom characters (8x5 pixel matrix) to be used on the LCD screen
    uint8_t bell[8] __attribute__((unused)) = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4, 0x0};      // Bell pattern
    uint8_t note[8] __attribute__((unused)) = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0, 0x0};      // Musical note pattern
    uint8_t clock[8] __attribute__((unused)) = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0, 0x0};   // Clock pattern
    uint8_t heart[8] __attribute__((unused)) = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0, 0x0};    // Heart pattern
    uint8_t duck[8] __attribute__((unused)) = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0, 0x0};      // Duck pattern
    uint8_t check[8] __attribute__((unused)) = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0, 0x0};    // Check mark pattern
    uint8_t cross[8] __attribute__((unused)) = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0, 0x0};    // Cross pattern
    uint8_t retarrow[8] __attribute__((unused)) = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4, 0x0};  // Right arrow pattern
    uint8_t aUmlaut[8] __attribute__((unused)) = {0xa, 0x0, 0xe, 0x1, 0xf, 0x11, 0xf, 0x0};   // 'ä' umlaut character
    uint8_t oUmlaut[8] __attribute__((unused)) = {0xa, 0x0, 0xe, 0x11, 0x11, 0x11, 0xe, 0x0}; // 'ö' umlaut character

    // Create custom characters on the LCD
    LCD1602_createChar(0, aUmlaut);  // Create 'ä' character at position 0
    LCD1602_createChar(1, oUmlaut);  // Create 'ö' character at position 1
    LCD1602_createChar(2, clock);    // Create clock character at position 2
    LCD1602_createChar(3, heart);    // Create heart character at position 3
    LCD1602_createChar(4, duck);     // Create duck character at position 4
    LCD1602_createChar(5, check);    // Create check mark character at position 5
    LCD1602_createChar(6, cross);    // Create cross mark character at position 6
    LCD1602_createChar(7, retarrow); // Create right arrow character at position 7

    // Display custom characters on the LCD screen
    for (int i = 0; i < 8; i++)
    {                                // Loop through custom characters 0-7
        LCD1602_setCursor(i * 2, 0); // Set cursor at the first row and column 2*i
        LCD1602_data(i);             // Display the custom character at position i
        LCD1602_setCursor(i * 2, 1); // Set cursor at the second row and column 2*i
        LCD1602_data(i);             // Display the same character on the second row
        DEV_Delay_ms(100);           // Wait for 100ms before moving to the next character
    }
}
