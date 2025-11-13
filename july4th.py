#!/usr/bin/env python3
# Fourth of July message with scrolling and heart-shaped finale

import sys
sys.path.append('./lcdlib')

import LCD1602
import time

# Initialize LCD and backlight
lcd = LCD1602.LCD1602(16, 2)
led = LCD1602.SN3193()

# Custom characters
firework1 = [
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01110,
    0b00100,
    0b01010,
    0b10001
]

firework2 = [
    0b00000,
    0b00100,
    0b01010,
    0b11111,
    0b01010,
    0b00100,
    0b00000,
    0b00000
]

firework3 = [
    0b10101,
    0b01110,
    0b11111,
    0b01110,
    0b10101,
    0b00000,
    0b01010,
    0b00100
]

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

# Message and fireworks scroll content
message = "HAPPY FOURTH OF JULY!!   "
fw_display = chr(0) + chr(1) + chr(2) + "   "

try:
    lcd.clear()
    led.set_brightness(100)

    # Load custom characters
    lcd.createChar(0, firework1)
    lcd.createChar(1, firework2)
    lcd.createChar(2, firework3)
    lcd.createChar(3, heart_char)

    scroll_len = len(message) - 15

    # Scroll message and fireworks
    for i in range(scroll_len):
        lcd.setCursor(0, 0)
        lcd.printout(message[i:i+16].ljust(16))

        fw = fw_display[i % len(fw_display):] + fw_display[:i % len(fw_display)]
        lcd.setCursor(0, 1)
        lcd.printout((fw + " " * 16)[:16])

        time.sleep(0.3)

    # Display hearts and blessing
    heart = chr(3)
    lcd.clear()
    lcd.setCursor(0, 0)
    lcd.printout(f"{heart} GOD BLESS {heart}")
    lcd.setCursor(0, 1)
    lcd.printout(f"{heart}  AMERICA!  {heart}")

    time.sleep(6)

except KeyboardInterrupt:
    print("\nStopped.")

finally:
    lcd.clear()
    del lcd
