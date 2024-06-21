# Hangman Game

This is a simple console-based implementation of the classic Hangman game written in C. The player has to guess the word by suggesting letters within a certain number of guesses.

## Features

- Randomly selects a word from a predefined list of words.
- Allows the player to guess letters and keeps track of guessed letters.
- Displays the current state of the word with underscores for unguessed letters.
- Provides feedback on the number of guesses remaining.
- Handles input validation and avoids counting repeated guesses.
- Clears the console screen for a better user experience.
- Option to play again after winning or losing.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC, Visual Studio, Clang)
- Basic knowledge of C programming

### Running the Game

1. **Clone the repository or download the source code:**
    ```sh
    git clone https://github.com/retromatey/CProjects.git
    cd CProjects/Hangman
    ```

2. **Compile the code:**
    If you are using GCC:
    ```sh
    gcc Hangman.c -o Hangman
    ```

    If you are using Visual Studio, follow these steps:
    - Open Visual Studio and create a new Console App project.
    - Add `hangman.c` to the project.
    - Set `_DEBUG` in the preprocessor definitions for Debug configuration (optional).
    - Build the project.

3. **Run the game:**
    ```sh
    ./Hangman
    ```

## How to Play

- The game will randomly select a word from the list.
- You will be prompted to guess a letter.
- If the letter is in the word, it will be revealed in its correct positions.
- If the letter is not in the word, the number of remaining tries will decrease.
- The game ends when you either guess the word correctly or run out of tries.
- You will have the option to play again after the game ends.

## Code Structure

- **words**: An array of strings containing the words to be guessed.
- **set_word**: Function to initialize the word and guess arrays.
- **is_revealed**: Function to check if the word has been fully guessed.
- **contains_letter**: Function to check if a letter has already been guessed.
- **add_letter_guessed**: Function to add a guessed letter to the list of guessed letters.
- **guess_letter**: Function to process a guessed letter and update the game state.
- **clear_screen**: Function to clear the console screen for a better user experience.
- **clear_input_buffer**: Function to clear the input buffer to avoid unexpected behavior.

## Future Enhancements

- Load words from an external file.
- Add difficulty levels with varying word lengths and number of tries.
- Implement a graphical user interface (GUI) version of the game.

## Acknowledgments

- Inspired by the classic Hangman game.

---

Enjoy playing Hangman!
