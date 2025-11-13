import RPi.GPIO as GPIO
import time

BUZZER_PIN = 17  # BCM numbering

GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

# Start PWM at 50% duty cycle
pwm = GPIO.PWM(BUZZER_PIN, 440)  # Initial frequency (A4)
pwm.start(50)

# Notes for Happy Birthday (note frequencies in Hz)
notes = {
    'C4': 262,
    'D4': 294,
    'E4': 330,
    'F4': 349,
    'G4': 392,
    'A4': 440,
    'B4': 494,
    'C5': 523
}

# Song: (note, duration in seconds)
song = [
    ('C4', 0.4), ('C4', 0.4), ('D4', 0.8), ('C4', 0.8), ('F4', 0.8), ('E4', 1.0),
    ('C4', 0.4), ('C4', 0.4), ('D4', 0.8), ('C4', 0.8), ('G4', 0.8), ('F4', 1.0),
    ('C4', 0.4), ('C4', 0.4), ('C5', 0.8), ('A4', 0.8), ('F4', 0.8), ('E4', 0.8), ('D4', 1.0),
    ('Bb4', 0.4), ('Bb4', 0.4), ('A4', 0.8), ('F4', 0.8), ('G4', 0.8), ('F4', 1.0)
]

# Add Bb4 manually (466 Hz)
notes['Bb4'] = 466

# Play song
try:
    for note, duration in song:
        if note == 'R':
            pwm.ChangeDutyCycle(0)
        else:
            pwm.ChangeFrequency(notes[note])
            pwm.ChangeDutyCycle(50)
        time.sleep(duration)
        pwm.ChangeDutyCycle(0)
        time.sleep(0.05)  # short pause between notes

finally:
    pwm.stop()
    GPIO.cleanup()
    print("Done playing Happy Birthday!")
