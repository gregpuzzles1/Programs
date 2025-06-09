package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	target := rand.Intn(100) + 1 // Random number between 1 and 100

	fmt.Println("🔢 Welcome to Guess the Number!")
	fmt.Println("I'm thinking of a number between 1 and 100.")
	fmt.Println("Can you guess it? Type your guess and hit Enter.")

	reader := bufio.NewReader(os.Stdin)

	for attempts := 1; ; attempts++ {
		fmt.Print("Enter your guess: ")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)

		guess, err := strconv.Atoi(input)
		if err != nil {
			fmt.Println("❌ That's not a valid number. Try again.")
			continue
		}

		if guess < target {
			fmt.Println("📉 Too low!")
		} else if guess > target {
			fmt.Println("📈 Too high!")
		} else {
			fmt.Printf("🎉 You got it in %d attempts! The number was %d.\n", attempts, target)
			break
		}
	}
}
