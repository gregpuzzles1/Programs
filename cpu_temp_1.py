import time

def get_cpu_temperature():
    """Reads the CPU temperature from the system."""
    try:
        with open("/sys/class/thermal/thermal_zone0/temp", "r") as file:
            temp = int(file.read()) / 1000  # Convert from millidegrees to degrees Celsius
        return temp
    except FileNotFoundError:
        print("Could not read temperature. Are you running this on a Raspberry Pi?")
        return None

def monitor_temperature(interval=5):
    """Monitors and prints the CPU temperature at a regular interval."""
    print("Monitoring CPU Temperature... Press Ctrl+C to stop.")
    try:
        while True:
            temp = get_cpu_temperature()
            if temp is not None:
                print(f"CPU Temperature: {temp:.2f}°C")
            time.sleep(interval)
    except KeyboardInterrupt:
        print("\nMonitoring stopped.")

if __name__ == "__main__":
    monitor_temperature()
