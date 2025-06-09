import paho.mqtt.client as mqtt
import time

# Define MQTT Broker (Raspberry Pi 5's IP)
BROKER_IP = "10.0.0.229"  # Change to your Pi 5's local IP
TOPIC = "pi5/temperature"

# Function to get CPU temperature
def get_cpu_temp():
    try:
        with open("/sys/class/thermal/thermal_zone0/temp", "r") as f:
            temp = int(f.read()) / 1000.0  # Convert to Celsius
        return temp
    except Exception as e:
        print(f"Error reading temperature: {e}")
        return None

# Create MQTT Client
client = mqtt.Client()

# Connect to the broker
client.connect(BROKER_IP, 1883, 60)

print("MQTT Publisher Connected! Sending CPU temperature...")

try:
    while True:
        temp = get_cpu_temp()
        if temp is not None:
            message = f"{temp:.2f}"
            client.publish(TOPIC, message)
            print(f"Published: {message}°C")
        else:
            print("Failed to get CPU temperature")
        time.sleep(5)  # Send temperature every 5 seconds
except KeyboardInterrupt:
    print("Stopping Publisher...")
    client.disconnect()
