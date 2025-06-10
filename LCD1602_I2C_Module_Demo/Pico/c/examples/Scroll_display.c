/*****************************************************************************
* | File      	:   Scroll_display.c
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
void Scroll_display(void)
{
    // Initialize the DEV module, return if initialization fails
    if(DEV_Module_Init() != 0) {
        return;
    }

    // Output message to indicate demo
    printf("Scroll display Demo\r\n");
    
    /* Initialize LCD screen with 16 columns and 2 rows */
    LCD1602_init(16, 2);
    
    // Set the backlight brightness to 50% (range: 0 to 100)
    LCD1602_set_brightness(50);

    // Set the cursor to column 0, row 0 and display text on the first row
    LCD1602_setCursor(0, 0);
    LCD1602_send_string("Welcome to LCD1602.");  // Show a welcome message on the first row

    // Set the cursor to column 0, row 1 and display text on the second row
    LCD1602_setCursor(0, 1);
    LCD1602_send_string("Let your imagination run wild.");  // Show another message on the second row

    // Optional: Uncomment the next line to set the LED backlight to breathing mode
    // LCD1602_set_led_mode(LED_BREATH_MODE);

    while (1)
    {
        // Scroll the text on the display to the left 14 times
    for (int i = 0; i < 14; i++) {
        LCD1602_scrollDisplayLeft();  // Scroll the text one step to the left
        DEV_Delay_ms(500);  // Wait for 500ms before scrolling again
    }
        
    DEV_Delay_ms(1000);  // Wait for 1 second before the next action

    // Scroll the text on the display to the right 14 times
    for (int i = 0; i < 14; i++) {
        LCD1602_scrollDisplayRight();  // Scroll the text one step to the right
        DEV_Delay_ms(500);  // Wait for 500ms before scrolling again
    }

    DEV_Delay_ms(1000);  // Wait for 1 second before starting the loop again
    }
    
}
