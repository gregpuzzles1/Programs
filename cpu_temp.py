import os
import time

def get_cpu_temp():
    temp = os.popen("vcgencmd measure_temp").readline()
    return float(temp.replace("temp=", "").replace("'C\n", ""))

while True:
    print("CPU Temp:", get_cpu_temp(), "°C")
    time.sleep(5)  # Check every 5 seconds
