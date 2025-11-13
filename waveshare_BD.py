#!/usr/bin/env python3
# Birthday greeting for Leon with scrolling hearts and blessing

import sys
sys.path.append('./lcdlib')  # Adjust if your driver path is different

import LCD1602
import time

# Initialize LCD and backlight
lcd = LCD1602.LCD1602(16, 2)
led = LCD1602.SN3193()

# Custom heart character (CGRAM slot 0)
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

# Scroll message and heart pattern
message = "HAPPY BIRTHDAY, Susan!!   "
hearts = chr(0) * 3 + "   "  # Three hearts and space

try:
    lcd.clear()
    led.set_brightness(90)

    # Load heart shape into CGRAM slot 0
    lcd.createChar(0, heart_char)

    scroll_len = max(len(message), len(hearts)) - 15
    scroll_count = 3

    # Scroll the message and hearts 3 times
    for _ in range(scroll_count):
        for i in range(scroll_len):
            # Line 1: Scrolling birthday message
            lcd.setCursor(0, 0)
            lcd.printout(message[i:i+16].ljust(16))

            # Line 2: Scrolling hearts
            h = hearts[i % len(hearts):] + hearts[:i % len(hearts)]
            h = (h + " " * 16)[:16]
            lcd.setCursor(0, 1)
            lcd.printout(h)

            time.sleep(0.3)

    # Final blessing message
    lcd.clear()
    lcd.setCursor(0, 0)
    lcd.printout("Have a Blessed")
    lcd.setCursor(0, 1)
    lcd.printout("Day.")

    time.sleep(6)

except KeyboardInterrupt:
    print("\nStopped by user.")

finally:
    lcd.clear()
    del lcd
