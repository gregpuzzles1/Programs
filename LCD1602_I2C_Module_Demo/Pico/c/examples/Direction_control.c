/*****************************************************************************
* | File      	:   Direction_control.c
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
void Direction_control(void)
{
    // Initialize the DEV module, return if initialization fails
    if(DEV_Module_Init() != 0) {
        return;
    }

    // Output message to indicate demo
    printf("Direction control Demo\r\n");
    
    /* Initialize LCD screen with 16 columns and 2 rows */
    LCD1602_init(16, 2);
    
    // Set the backlight brightness to 50% (range: 0 to 100)
    LCD1602_set_brightness(50);

    LCD1602_cursor();  // Enable cursor on the LCD

    // Define the text to be displayed
    char text[10] = "Waveshare";  // First text to display
    char text1[13] = "Hello World!";  // Second text to scroll
    
    LCD1602_setCursor(0, 0);
    LCD1602_leftToRight();  // Set text direction to left-to-right

    // Display the text "Waveshare" on the first row
    for (int i = 0; i < 9; i++) {  // Loop through the "Waveshare" text
        LCD1602_data(text[i]);  // Send character to LCD
        DEV_Delay_ms(200);  // Wait for 0.2 seconds before displaying next character
    }

    LCD1602_rightToLeft();  // Change text direction to right-to-left for scrolling

    // Set initial position for scrolling text
    uint8_t x = 39;  // The X-coordinate for the last pixel (out of screen)
    for (int i = 11; i >= 0; i--) {  // Loop through the "Hello World!" text (backwards)
        if (i < 2) {
            // Scroll display to the right when near the left edge
            LCD1602_scrollDisplayRight();
            LCD1602_setCursor(x, 0);  // Set cursor to the updated X position
            x = x - 1;  // Move cursor left for each new character
        }
        // Display the character of the second text
        LCD1602_data(text1[i]);
        DEV_Delay_ms(200);  // Wait for 0.2 seconds before displaying next character
    }

    // Optional: Uncomment the next line to set the LED backlight to breathing mode
    // LCD1602_set_led_mode(LED_BREATH_MODE);
}
