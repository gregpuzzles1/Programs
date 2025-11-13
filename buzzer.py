import RPi.GPIO as GPIO
import time

# Morse code dictionary
MORSE_CODE_DICT = {
    'A': '.-',     'B': '-...',   'C': '-.-.', 
    'D': '-..',    'E': '.',      'F': '..-.',
    'G': '--.',    'H': '....',   'I': '..',
    'J': '.---',   'K': '-.-',    'L': '.-..',
    'M': '--',     'N': '-.',     'O': '---',
    'P': '.--.',   'Q': '--.-',   'R': '.-.',
    'S': '...',    'T': '-',      'U': '..-',
    'V': '...-',   'W': '.--',    'X': '-..-',
    'Y': '-.--',   'Z': '--..',
    '1': '.----',  '2': '..---',  '3': '...--',
    '4': '....-',  '5': '.....',  '6': '-....',
    '7': '--...',  '8': '---..',  '9': '----.',
    '0': '-----',  ' ': '/'
}

# GPIO setup
BUZZER_PIN = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

# Timing (seconds)
DOT = 0.1
DASH = DOT * 3
GAP_BETWEEN_SYMBOLS = DOT
GAP_BETWEEN_LETTERS = DOT * 3
GAP_BETWEEN_WORDS = DOT * 7

def beep(duration):
    GPIO.output(BUZZER_PIN, GPIO.HIGH)
    time.sleep(duration)
    GPIO.output(BUZZER_PIN, GPIO.LOW)
    time.sleep(GAP_BETWEEN_SYMBOLS)

def play_morse(message):
    for char in message.upper():
        if char in MORSE_CODE_DICT:
            code = MORSE_CODE_DICT[char]
            if code == '/':
                time.sleep(GAP_BETWEEN_WORDS)
                continue
            for symbol in code:
                if symbol == '.':
                    beep(DOT)
                elif symbol == '-':
                    beep(DASH)
            time.sleep(GAP_BETWEEN_LETTERS - GAP_BETWEEN_SYMBOLS)

try:
    sentence = "the sky is yellow from the forest fires"
    print("Playing Morse code for:")
    print(sentence)
    play_morse(sentence)
finally:
    GPIO.cleanup()
    print("Done.")
