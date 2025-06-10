#include <Waveshare_LCD1602.h>  // Include the Waveshare LCD1602 library
#include "Date_time.h"  // Include the Date and Time library for managing system time

// Note: TimeLib depends on millis() and cannot provide accurate system time (like actual year, month, day) unless you manually set the initial time.

// Set initial time
static date_time_t Set_Time = {
    .year = 2025,  // Set year to 2025
    .month = 01,   // Set month to January
    .day = 02,     // Set day to 1
    .dotw = 4,     // Set day of the week to Thursday (0=Sunday, 1=Monday, etc.)
    .hour = 19,    // Set hour to 19 (7:00 PM)
    .min = 30,     // Set minute to 30
    .sec = 0};     // Set second to 0

// Initialize LCD with 16 columns and 2 rows
Waveshare_LCD1602 lcd(16, 2);  // 16 characters and 2 lines of display

void setup() {
    // Initialize the LCD
    lcd.init();  // Set up the LCD screen
    // Set the backlight brightness to 50% (value range: 0 to 100)
    lcd.set_brightness(50);

    // Set the initial time from Set_Time structure
    setTime(Set_Time.hour, Set_Time.min, Set_Time.sec, Set_Time.day, Set_Time.month, Set_Time.year);

    // Uncomment the following line to enable breathing mode for the backlight
    // lcd.set_mode(LCD1602.LED_BREATH_MODE)
}

char Date[100];  // Array to hold the formatted date
char Time[20];   // Array to hold the formatted time

void loop() {
    // Set the cursor to column 0, row 0 (first row of LCD)
    lcd.setCursor(0, 0);

    // Format the current date (year, month, day, day of the week) and store in the 'date' array
    sprintf(Date, "%d %02d %02d %d", year(), month(), day(), weekday() - 1);  // Note: weekday() - 1 to match 1=Monday, 0=Sunday
    // Format the current time (hour, minute, second) and store in the 'time' array
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    // Display the formatted date on the first row
    lcd.send_string(Date);

    // Set the cursor to column 0, row 1 (second row of LCD)
    lcd.setCursor(0, 1);

    // Display the formatted time on the second row
    lcd.send_string(Time);

    // Pause for 1 second (1000 milliseconds) before updating the display
    delay(100);
}
