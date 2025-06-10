#include <Waveshare_LCD1602.h>  // Include the Waveshare LCD1602 library

// Initialize LCD with 16 columns and 2 rows
Waveshare_LCD1602 lcd(16, 2);  // 16 characters and 2 lines of display

void setup() {
    // Initialize the LCD
    lcd.init();  // Set up the LCD screen
    
    // Set the backlight brightness to 50%
    lcd.set_brightness(50);

    // Set the cursor to the first row and first column
    lcd.setCursor(0, 0);
    lcd.send_string("Waveshare");  // Display "Waveshare" on the first row

    // Set the cursor to the second row and first column
    lcd.setCursor(0, 1);
    lcd.send_string("Hello,World!");  // Display "Hello, World!" on the second row

    // Optional: Uncomment the next line to set the LED backlight to breathing mode
    // lcd.set_led_mode(LED_BREATH_MODE);
}

void loop() {
    // Nothing to do here, the LCD display is static in this example
}
