/*****************************************************************************
* | File      	:   Display_time.c
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

#include <time.h>  // Include the time library to work with time functions
#include "LCD_Test.h"  // Include the LCD test library

// Function to display the current date and time on the LCD screen
void Display_time(void)
{
    // Initialize the DEV module (hardware); return if initialization fails
    if (DEV_Module_Init() != 0)
    {
        return;
    }

    // Output a message to indicate the demo is running
    printf("Display time Demo\r\n");

    /* Initialize LCD screen with 16 columns and 2 rows */
    LCD1602_init(16, 2);  // Set the LCD screen to 16x2 format

    // Set the backlight brightness to 50% (range: 0 to 100)
    LCD1602_set_brightness(50);

    time_t current_time;  // Variable to store the current time as a time_t type
    struct tm timeinfo = {  // Initialize timeinfo with a specific date and time
        .tm_year = 2025 - 1900, // Year is from 1900, so subtract 1900
        .tm_mon = 1 - 1,        // January (0-based index)
        .tm_mday = 3,           // Day of the month (3rd)
        .tm_hour = 16,          // Hour (16:00)
        .tm_min = 28,           // Minute (28)
        .tm_sec = 0             // Second (0)
    };

    // Convert the struct tm to time_t (Unix timestamp)
    current_time = mktime(&timeinfo);
    if (current_time == -1)
    {
        printf("Unable to convert time to time_t\n");
        return;
    }

    char date[100];  // Array to hold the formatted date
    char time[20];   // Array to hold the formatted time

    while (1)  // Loop to continuously update and display time
    {
        localtime_r(&current_time, &timeinfo);  // Convert time_t to struct tm (UTC)

        // Print the current time in YYYY-MM-DD Weekday HH:MM:SS format
        printf("Current time: %04d-%02d-%02d %d %02d:%02d:%02d\n",
               timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_wday,
               timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

        current_time += 1;  // Increment the current time by 1 second

        // Set the cursor to the first row, first column of the LCD (top-left corner)
        LCD1602_setCursor(0, 0);

        // Format the current date (year, month, day, day of the week) and store in the 'date' array
        sprintf(date, "%d %02d %02d %d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_wday); 
        // Format the current time (hour, minute, second) and store in the 'time' array
        sprintf(time, "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

        // Display the formatted date on the first row of the LCD
        LCD1602_send_string(date);

        // Set the cursor to the second row, first column of the LCD
        LCD1602_setCursor(0, 1);

        // Display the formatted time on the second row of the LCD
        LCD1602_send_string(time);

        // Pause for 1 second (1000 milliseconds) before updating the display again
        DEV_Delay_ms(1000);  // Delay for 1 second
    }

    // Optional: Uncomment the next line to set the LED backlight to breathing mode
    // LCD1602_set_led_mode(LED_BREATH_MODE);
}
