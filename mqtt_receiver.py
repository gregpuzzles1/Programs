

import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
import time

# Define GPIO Pins for LEDs
GREEN_LED = 17  # Safe (Below 50°C)
YELLOW_LED = 27  # Warm (50°C - 65°C)
RED_LED = 22  # Hot (Above 65°C)

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(GREEN_LED, GPIO.OUT)
GPIO.setup(YELLOW_LED, GPIO.OUT)
GPIO.setup(RED_LED, GPIO.OUT)

# Define MQTT Broker (Raspberry Pi 5's IP)
BROKER_IP = "10.0.0.229"  # Change this to your Pi 5's local IP
TOPIC = "pi5/temperature"

# Function to turn off all LEDs
def reset_leds():
    GPIO.output(GREEN_LED, GPIO.LOW)
    GPIO.output(YELLOW_LED, GPIO.LOW)
    GPIO.output(RED_LED, GPIO.LOW)

# Callback function when message is received
def on_message(client, userdata, message):
    try:
        temp = float(message.payload.decode())
        print(f"CPU Temperature from Pi 5: {temp:.2f}°C")

        reset_leds()  # Turn off all LEDs

        if temp < 50:
            GPIO.output(GREEN_LED, GPIO.HIGH)  # Green LED for Safe
            print("Status: Safe (Green LED ON)")
        elif 50 <= temp <= 65:
            GPIO.output(YELLOW_LED, GPIO.HIGH)  # Yellow LED for Warm
            print("Status: Warm (Yellow LED ON)")
        else:
            GPIO.output(RED_LED, GPIO.HIGH)  # Red LED for Hot
            print("Status: Hot (Red LED ON)")

    except ValueError:
        print("Invalid temperature received.")

# Create MQTT Client
client = mqtt.Client()
client.on_message = on_message

# Connect to the broker
client.connect(BROKER_IP, 1883, 60)

# Subscribe to the temperature topic
client.subscribe(TOPIC)

print("MQTT Subscriber Connected! Listening for CPU temperature updates...")

# Cleanup GPIO on exit
try:
    client.loop_forever()
except KeyboardInterrupt:
    print("Stopping...")
finally:
    GPIO.cleanup()  # Turns off LEDs and resets GPIO
