import RPi.GPIO as GPIO
import time

# Set up GPIO
LED_PIN = 17  # GPIO pin where LED is connected

GPIO.setmode(GPIO.BCM)  # Use Broadcom pin numbering
GPIO.setup(LED_PIN, GPIO.OUT)  # Set pin as output

# Initialize LED to LOW (OFF)
GPIO.output(LED_PIN, GPIO.LOW)

try:
    while True:
        GPIO.output(LED_PIN, GPIO.HIGH)  # Turn LED ON
        print("LED ON")
        time.sleep(1)  # Wait for 1 second
        GPIO.output(LED_PIN, GPIO.LOW)   # Turn LED OFF
        print("LED OFF")
        time.sleep(1)  # Wait for 1 second

except KeyboardInterrupt:
    print("\nExiting program...")
    GPIO.cleanup()  # Reset GPIO settings
