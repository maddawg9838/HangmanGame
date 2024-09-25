# Hangman Game

## Overview
Hangman is a classic word-guessing game where one player selects a word and the other attempts to guess it by suggesting letters. This implementation allows two players to participate in a fun and interactive game of Hangman.

## Features
- **User Input**: Players can input the length of the word and their guesses.
- **Game Logic**: Implements game rules including strikes and win conditions.
- **Replay Option**: Players can choose to play again after the game ends.

## How to Play
1. **Starting the Game**: Run the program, and the first player will be prompted to enter the length of the word.
2. **Guessing**: The second player will guess letters until they either guess the word or reach five incorrect attempts.
3. **Winning**: If the player guesses all the letters in the word, they win!

## Prerequisites
- A C++ compiler (like g++) to run the code.

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/HangmanGame.git
   cd HangmanGame
```
2. Compile the code:
```bash
g++ -o HangmanGame HangmanGame.cpp
```
3. Run the game:
```bash
./HangmanGame
```

## Code Overview
The game is implemented in C++ and consists of functions that handle game initialization, letter guessing, and replaying the game.

### Key Functions
- game() : Contains the main game logic
- message() : Displays a congratulatory message upon winning
- replay() : Prompts the user to play again

## Author
Madison Humphries
