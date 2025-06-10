import psutil

def get_ram_usage():
    """Fetch RAM usage details."""
    ram = psutil.virtual_memory()

    total_ram = ram.total / (1024 ** 2)  # Convert bytes to MB
    used_ram = ram.used / (1024 ** 2)
    available_ram = ram.available / (1024 ** 2)
    percent_used = ram.percent  # Percentage used

    print(f"Total RAM: {total_ram:.2f} MB")
    print(f"Used RAM: {used_ram:.2f} MB ({percent_used}%)")
    print(f"Available RAM: {available_ram:.2f} MB")

if __name__ == "__main__":
    get_ram_usage()
