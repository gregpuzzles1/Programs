import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO

# Define GPIO pins for LEDs
GREEN_LED = 17
YELLOW_LED = 27
RED_LED = 22

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(GREEN_LED, GPIO.OUT)
GPIO.setup(YELLOW_LED, GPIO.OUT)
GPIO.setup(RED_LED, GPIO.OUT)

# Ensure LEDs start off
GPIO.output(GREEN_LED, False)
GPIO.output(YELLOW_LED, False)
GPIO.output(RED_LED, False)

# Callback function when a message is received
def on_message(client, userdata, message):
    try:
        cpu_temp = float(message.payload.decode())
        print(f"Received: CPU Temp {cpu_temp}°C")

        # LED Logic
        GPIO.output(GREEN_LED, cpu_temp < 50)   # Green LED ON if temp < 50°C
        GPIO.output(YELLOW_LED, 50 <= cpu_temp < 70)  # Yellow LED ON if 50°C ≤ temp < 70°C
        GPIO.output(RED_LED, cpu_temp >= 70)    # Red LED ON if temp ≥ 70°C

    except ValueError:
        print("Received invalid data.")

# MQTT Setup
client = mqtt.Client("PiZero2W_Receiver")
client.on_message = on_message

try:
    client.connect("10.0.0.229")  # Replace with Pi 5's IP
    client.subscribe("pi5/cpu_temp")
    print("Connected to MQTT Broker. Listening for temperature updates...")
    
    client.loop_forever()  # Keep listening
except Exception as e:
    print(f"MQTT Connection Error: {e}")
finally:
    print("Cleaning up GPIO...")
    GPIO.cleanup()  # Ensures GPIO pins are reset
