import os

def get_cpu_temp():
    """Fetch CPU temperature from Raspberry Pi system."""
    try:
        # Get temperature from vcgencmd
        temp_output = os.popen("vcgencmd measure_temp").readline()
        temp_c = float(temp_output.replace("temp=", "").replace("'C\n", ""))
        
        # Convert to Fahrenheit
        temp_f = (temp_c * 9/5) + 32
        
        return temp_c, temp_f
    except Exception as e:
        print("Error reading temperature:", e)
        return None, None

if __name__ == "__main__":
    temp_c, temp_f = get_cpu_temp()
    if temp_c is not None:
        print(f"CPU Temperature: {temp_c:.2f}°C / {temp_f:.2f}°F")
    else:
        print("Could not read CPU temperature.")
import os

temp = os.popen("vcgencmd measure_temp").readline()
print("CPU Temperature:", temp)
