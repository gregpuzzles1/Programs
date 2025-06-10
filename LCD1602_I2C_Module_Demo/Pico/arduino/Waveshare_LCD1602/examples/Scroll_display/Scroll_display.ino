#include <Waveshare_LCD1602.h>  // Include the Waveshare LCD1602 library

// Initialize LCD with 16 columns and 2 rows
Waveshare_LCD1602 lcd(16, 2);  // 16 characters and 2 lines of display

void setup() {
    // Initialize the LCD
    lcd.init();  // Set up the LCD screen
    // Set the backlight brightness to 50% (value range: 0 to 100)
    lcd.set_brightness(50);

    // Set the cursor to column 0, row 0 and display text on the first row
    lcd.setCursor(0, 0);
    lcd.send_string("Welcome to LCD1602.");  // Show a welcome message on the first row

    // Set the cursor to column 0, row 1 and display text on the second row
    lcd.setCursor(0, 1);
    lcd.send_string("Let your imagination run wild.");  // Show another message on the second row
}

void loop() {
    // Scroll the text on the display to the left 14 times
    for (int i = 0; i < 14; i++) {
        lcd.scrollDisplayLeft();  // Scroll the text one step to the left
        delay(500);  // Wait for 500ms before scrolling again
    }
        
    delay(1000);  // Wait for 1 second before the next action

    // Scroll the text on the display to the right 14 times
    for (int i = 0; i < 14; i++) {
        lcd.scrollDisplayRight();  // Scroll the text one step to the right
        delay(500);  // Wait for 500ms before scrolling again
    }

    delay(1000);  // Wait for 1 second before starting the loop again
}
