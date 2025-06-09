#!/usr/bin/env python3
# waveshare.py – Scroll a Father's Day message and display real heart characters

import sys
sys.path.append('./lcdlib')  # Adjust if lcdlib is in a different path

import LCD1602
import time

# Initialize the LCD and backlight controller
lcd = LCD1602.LCD1602(16, 2)
led = LCD1602.SN3193()

# Define a custom heart character (5x8 pixel design)
heart_char = [
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
]

# Scroll message (Line 1)
message = "HAPPY FATHER'S DAY DAD! We Love You. Marsha and Greg   "

# Scroll hearts (Line 2)
hearts = chr(0) * 3 + "   "  # Custom char in slot 0 (3 hearts and space)

try:
    # Clear screen and set brightness
    lcd.clear()
    led.set_brightness(85)

    # Load the heart pattern into CGRAM location 0
    lcd.createChar(0, heart_char)

    # Calculate scroll length based on longest string
    max_scroll = max(len(message), len(hearts)) - 15

    while True:
        for i in range(max_scroll):
            # Scroll top line (message)
            lcd.setCursor(0, 0)
            lcd.printout(message[i:i+16].ljust(16))

            # Scroll bottom line (hearts)
            h = hearts[i % len(hearts):] + hearts[:i % len(hearts)]
            h = (h + " " * 16)[:16]
            lcd.setCursor(0, 1)
            lcd.printout(h)

            time.sleep(0.3)

except KeyboardInterrupt:
    print("\nStopped by user.")

finally:
    # Clear display on exit
    lcd.clear()
    del lcd
