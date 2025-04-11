import random

def quiz():
    questions = [
        {"question": "What does GPIO stand for in Raspberry Pi?", "choices": ["A) General Purpose Input Output", "B) General Pin Input Output", "C) Graphical Processing Integrated Output", "D) General Purpose Integrated Output"], "answer": "A", "explanation": "GPIO stands for General Purpose Input Output, which allows Raspberry Pi to interact with other electronic components."},
        {"question": "True or False: A resistor is used to limit current in a circuit.", "choices": ["A) True", "B) False"], "answer": "A", "explanation": "Resistors are used to limit current and prevent damage to components by reducing voltage and current flow."},
        {"question": "Which of the following is a common resistor value?", "choices": ["A) 220Ω", "B) 1kΩ", "C) 10kΩ", "D) All of the above"], "answer": "D", "explanation": "220Ω, 1kΩ, and 10kΩ are all commonly used resistor values in electronic circuits."},
        {"question": "True or False: An LED requires a resistor to prevent excessive current flow.", "choices": ["A) True", "B) False"], "answer": "A", "explanation": "Without a resistor, too much current could flow through the LED, causing it to burn out."},
        {"question": "What is the purpose of a transistor in a circuit?", "choices": ["A) To store charge", "B) To amplify or switch signals", "C) To generate voltage", "D) To measure current"], "answer": "B", "explanation": "A transistor is used to amplify or switch electronic signals in a circuit."},
        {"question": "True or False: A capacitor is used to store energy in an electric field.", "choices": ["A) True", "B) False"], "answer": "A", "explanation": "Capacitors temporarily store energy in an electric field and can discharge when needed."},
        {"question": "What is Ohm's Law?", "choices": ["A) V = IR", "B) P = IV", "C) R = V/I", "D) Both A and C"], "answer": "D", "explanation": "Ohm's Law states that voltage (V) is equal to current (I) times resistance (R), and resistance can be derived as R = V/I."},
        {"question": "Which component is used to convert AC to DC?", "choices": ["A) Resistor", "B) Capacitor", "C) Diode", "D) Transformer"], "answer": "C", "explanation": "A diode is used in rectifier circuits to convert alternating current (AC) to direct current (DC)."},
        {"question": "True or False: The Raspberry Pi has built-in analog-to-digital converters (ADC).", "choices": ["A) True", "B) False"], "answer": "B", "explanation": "Raspberry Pi does not have built-in ADCs; external components like the MCP3008 are needed for reading analog signals."},
        {"question": "Which protocol is commonly used for communication between Raspberry Pi and sensors?", "choices": ["A) UART", "B) I2C", "C) SPI", "D) All of the above"], "answer": "D", "explanation": "Raspberry Pi supports multiple communication protocols including UART, I2C, and SPI, depending on the sensor and use case."},
        {"question": "True or False: A relay acts as a switch controlled by an electrical signal.", "choices": ["A) True", "B) False"], "answer": "A", "explanation": "A relay is an electrically operated switch that can control a high-power device using a low-power signal."},
        {"question": "Which Raspberry Pi model introduced built-in WiFi and Bluetooth?", "choices": ["A) Raspberry Pi 2", "B) Raspberry Pi 3", "C) Raspberry Pi Zero", "D) Raspberry Pi 1"], "answer": "B", "explanation": "Raspberry Pi 3 was the first model to include built-in WiFi and Bluetooth connectivity."}
    ]

    random.shuffle(questions)
    score = 0

    for i, q in enumerate(questions[:30]):
        print(f"\nQuestion {i + 1}: {q['question']}")
        for choice in q.get("choices", []):
            print(choice)
        
        if len(q["choices"]) == 2:  # True/False question
            user_answer = input("Your answer (A or B): ").strip().upper()
        else:
            user_answer = input("Your answer (A, B, C, D): ").strip().upper()
        
        if user_answer == q["answer"].upper():
            print(f"✅ Correct! {q['explanation']}")
            score += 1
        else:
            print(f"❌ Incorrect! The correct answer was: {q['answer']}. {q['explanation']}")
    
    final_score = (score / 12) * 100
    print(f"\n🎉 Quiz Complete! You scored {score}/12 ({final_score:.2f}%)!")
    if final_score >= 90:
        print("🏆 Fantastic! You really know your circuits and Raspberry Pi!")
    elif final_score >= 70:
        print("👍 Great job! A little more practice and you’ll be an expert!")
    else:
        print("📚 Keep learning! You're on the right track!")

if __name__ == "__main__":
    quiz()
