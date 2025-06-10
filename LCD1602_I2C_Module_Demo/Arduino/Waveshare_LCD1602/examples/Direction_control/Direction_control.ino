#include <Waveshare_LCD1602.h>  // Include the Waveshare LCD1602 library

// Initialize LCD with 16 columns and 2 rows
Waveshare_LCD1602 lcd(16, 2);  // 16 characters and 2 lines of display

void setup() {
    // Initialize the LCD
    lcd.init();  // Set up the LCD screen
    
    // Set the backlight brightness to 50% (value range: 0 to 100)
    lcd.set_brightness(50);

    lcd.cursor();  // Enable cursor on the LCD

    // Define the text to be displayed
    char text[10] = "Waveshare";  // First text to display
    char text1[13] = "Hello World!";  // Second text to scroll
    
    // Set the cursor to column 0, row 0
    lcd.setCursor(0, 0);
    lcd.leftToRight();  // Set text direction to left-to-right

    // Display the text "Waveshare" on the first row
    for (int i = 0; i < 9; i++) {  // Loop through the "Waveshare" text
        lcd.data(text[i]);  // Send character to LCD
        delay(200);  // Wait for 0.2 seconds before displaying next character
    }

    lcd.rightToLeft();  // Change text direction to right-to-left for scrolling

    // Set initial position for scrolling text
    uint8_t x = 39;  // The X-coordinate for the last pixel (out of screen)
    for (int i = 11; i >= 0; i--) {  // Loop through the "Hello World!" text (backwards)
        if (i < 2) {
            // Scroll display to the right when near the left edge
            lcd.scrollDisplayRight();
            lcd.setCursor(x, 0);  // Set cursor to the updated X position
            x = x - 1;  // Move cursor left for each new character
        }
        // Display the character of the second text
        lcd.data(text1[i]);
        delay(200);  // Wait for 0.2 seconds before displaying next character
    }

    // Uncomment the following lines to enable breathing mode for the backlight
    // led.set_mode(LCD1602.LED_BREATH_MODE)
    // time.sleep(0.1)
}

void loop() {
    // Nothing to do here, as the LCD display is static in this example
}
