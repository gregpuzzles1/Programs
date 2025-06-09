/*****************************************************************************
* | File      	:   Character_display.c
* | Author      :   Waveshare team
* | Function    :   
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2025-01-03
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/ 

#include "LCD_Test.h"

// Function to display basic text on the LCD screen
void Character_display(void)
{
    // Initialize the DEV module, return if initialization fails
    if(DEV_Module_Init() != 0) {
        return;
    }

    // Output message to indicate demo
    printf("Character display Demo\r\n");
    
    /* Initialize LCD screen with 16 columns and 2 rows */
    LCD1602_init(16, 2);
    
    // Set the backlight brightness to 50% (range: 0 to 100)
    LCD1602_set_brightness(50);

    // Set cursor to the first row, first column (0, 0)
    LCD1602_setCursor(0, 0);
    LCD1602_send_string("Waveshare");  // Display "Waveshare" on the first row

    // Set cursor to the second row, first column (0, 1)
    LCD1602_setCursor(0, 1);
    LCD1602_send_string("Hello,World!");  // Display "Hello, World!" on the second row
    
    // Optional: Uncomment the next line to set the LED backlight to breathing mode
    // LCD1602_set_led_mode(LED_BREATH_MODE);
}
