from gpiozero import RGBLED
from time import sleep
from math import sin, pi

led = RGBLED(red=17, green=27, blue=22)

def breathe_with_color_shift(cycle_steps=100, delay=0.02):
    step = 0
    while True:
        # Breathing brightness using sine wave
        t = step * pi / (cycle_steps / 2)
        brightness = (sin(t) + 1) / 2  # 0 to 1

        # Slowly shift color using sine waves offset from each other
        r = (sin(step * 0.03 + 0) + 1) / 2
        g = (sin(step * 0.03 + 2) + 1) / 2
        b = (sin(step * 0.03 + 4) + 1) / 2

        # Apply brightness to color
        led.color = (r * brightness, g * brightness, b * brightness)

        step += 1
        sleep(delay)

try:
    breathe_with_color_shift()

except KeyboardInterrupt:
    led.off()
    print("\nColor breathing effect stopped by user.")
