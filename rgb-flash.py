import RPi.GPIO as GPIO
import time
import random
import gc

# Pin setup
GREEN_PIN = 17
YELLOW_PIN = 27
RED_PIN = 22

LED_PINS = [GREEN_PIN, YELLOW_PIN, RED_PIN]

# Setup
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

for pin in LED_PINS:
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

def flash_led(pin, duration=0.2):
    GPIO.output(pin, GPIO.HIGH)
    time.sleep(duration)
    GPIO.output(pin, GPIO.LOW)

try:
    print("Flashing LEDs randomly. Press Ctrl+C to stop.")
    while True:
        led = random.choice(LED_PINS)
        flash_led(led, duration=random.uniform(0.1, 0.5))
        time.sleep(random.uniform(0.1, 0.3))

except KeyboardInterrupt:
    print("\nExiting program...")

finally:
    GPIO.cleanup()
    gc.collect()

