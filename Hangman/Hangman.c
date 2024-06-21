#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_GUESSES 26
#define MAX_WORD_LENGTH 50

// TODO: future enhancement - load words from a file
char* words[] =
{
	"mystery",
	"wizard",
	"journey",
	"diamond",
	"galaxy",
	"volcano",
	"rainbow",
	"lantern",
	"pyramid",
	"dinosaur",
	"melody",
	"unicorn",
	"treasure",
	"whisper",
	"knight",
	"glacier",
	"eclipse",
	"lantern",
	"harmony",
	"phantom",
	"carnival",
	"skeleton",
	"festival",
	"hurricane",
	"symphony",
	"lighthouse",
	"waterfall",
	"chocolate",
	"astronaut",
	"adventure",
	"butterfly",
	"dragonfly",
	"telescope",
	"skateboard",
	"microphone",
	"encyclopedia",
	"chameleon",
	"silhouette",
	"labyrinth",
	"quicksand",
	"kaleidoscope",
	"zephyr",
	"xylophone",
	"juggernaut",
	"quarantine",
	"velocity",
	"wilderness",
	"dictionary",
	"zigzag",
	"yachtsman"
};

/**
 * Sets a random word from the predefined list of words as the current word to guess.
 * It initializes the `word` parameter with a randomly selected word from the `words` array.
 * The `guess` parameter is also initialized with the same word, but all characters are replaced with underscores ('_')
 * to represent unguessed letters. This function is used to prepare the game state for a new round.
 *
 * @param word A pointer to a character array where the selected word will be stored.
 * @param guess A pointer to a character array where the guess representation of the word will be stored.
 */
void set_word(char* word, char* guess)
{
	int index = rand() % (sizeof(words) / sizeof(words[0]));
	strcpy(word, words[index]);
	int len = strlen(words[index]);
	for (int i = 0; i < len; i++)
		guess[i] = '_';
	guess[len] = '\0';
}

/**
 * Checks if the word to guess has been fully revealed.
 * This function iterates through the `guess` string to determine if all the letters have been guessed correctly.
 * If any underscore ('_') is found, it indicates that there are still unguessed letters, and the function returns false.
 * If no underscores are found, it means the entire word has been guessed, and the function returns true.
 *
 * @param guess A pointer to a character array representing the current state of the guessed word.
 *              Underscores ('_') represent unguessed letters.
 * @return A boolean value indicating whether the word has been fully revealed (true) or not (false).
 */
bool is_revealed(char* guess)
{
	bool result = true;
	int len = strlen(guess);

	for (int i = 0; i < len; i++)
	{
		if (guess[i] == '_')
		{
			result = false;
			break;
		}
	}

	return result;
}

/**
 * Checks if a specific letter has already been guessed.
 * This function iterates through the `letters_guessed` array to determine if the specified letter
 * is present. It compares each element of the array with the letter. If a match is found, the function
 * returns true, indicating that the letter has already been guessed. If no match is found by the end
 * of the array, the function returns false, indicating that the letter has not been guessed yet.
 *
 * @param letters_guessed A pointer to a character array containing all letters guessed by the player so far.
 * @param letter The character to check for in the `letters_guessed` array.
 * @return A boolean value indicating whether the letter is present in the `letters_guessed` array (true) or not (false).
 */
bool contains_letter(char* letters_guessed, char letter)
{
	int len = strlen(letters_guessed);

	for (int i = 0; i < len; i++)
		if (letters_guessed[i] == letter)
			return true;

	return false;
}

/**
 * Adds a guessed letter to the list of letters guessed by the player.
 * This function checks if the guessed letter is not already in the list of guessed letters.
 * If the letter is not present, it is added to the end of the `letters_guessed` array.
 * The function ensures that the array remains null-terminated by appending the new letter
 * and then a null character ('\0') immediately after it. This operation effectively updates
 * the list of guessed letters to include the new guess while maintaining the integrity of the string.
 *
 * @param letters_guessed A pointer to a character array containing all letters guessed by the player so far.
 *                        This array is modified in-place to include the new letter if it's not already present.
 * @param letter The character representing the player's new guess. This function assumes the letter is valid
 *               (i.e., within the range of 'a'-'z' or 'A'-'Z') and does not perform validation itself.
 */
void add_letter_guessed(char* letters_guessed, char letter)
{
	if (!contains_letter(letters_guessed, letter))
	{
		int len = strlen(letters_guessed);
		letters_guessed[len] = letter;
		letters_guessed[len + 1] = '\0';
	}
}

/**
 * Attempts to guess a letter in the word.
 * This function iterates through each character of the word to be guessed. If the letter
 * matches any character in the word, it updates the corresponding character in the guess
 * string with the guessed letter and marks the attempt as successful by setting the result to true.
 * If the letter does not match any character in the word, the result remains false, indicating
 * an unsuccessful guess.
 *
 * @param word A pointer to a character array representing the word to be guessed.
 * @param guess A pointer to a character array representing the current state of the player's guesses.
 *              Correctly guessed letters are revealed in their correct positions, and unguessed
 *              letters are represented by underscores ('_').
 * @param letter The character being guessed.
 * @return A boolean value indicating whether the guessed letter is in the word (true) or not (false).
 */
bool guess_letter(char* word, char* guess, char letter)
{
	bool result = false;
	int len = strlen(word);

	for (int i = 0; i < len; i++)
	{
		if (word[i] == letter)
		{
			guess[i] = letter;
			result = true;
		}
	}

	return result;
}

/**
 * Clears the console screen.
 * This function provides cross-platform support for clearing the console screen. It checks if the program
 * is being compiled on a Windows system (using the _WIN32 macro). If so, it executes the "cls" command
 * to clear the screen. Otherwise, it assumes a Unix-like environment and uses the "clear" command instead.
 * This ensures that the screen clearing functionality works correctly regardless of the operating system.
 */
void clear_screen() 
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

/**
 * Clears the input buffer to prevent unwanted characters from affecting subsequent input operations.
 * This function reads characters from the standard input (stdin) until it encounters a newline ('\n')
 * character or the end-of-file (EOF) marker. This is particularly useful after a scanf call to ensure
 * that any remaining characters in the input buffer do not interfere with future input reading,
 * especially when expecting single character inputs or switching between reading different types of data.
 */
void clear_input_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int guesses_remaining = 6;
	char letters_guessed[MAX_GUESSES] = { 0 };
	char word[MAX_WORD_LENGTH];
	char guess[MAX_WORD_LENGTH];
	char input;
	char keep_playing = 'y';

	while (keep_playing == 'y')
	{
		memset(letters_guessed, '\0', sizeof(letters_guessed));
		guesses_remaining = 6;
		set_word(word, guess);

		while (!is_revealed(guess) && guesses_remaining > 0)
		{
			clear_screen();

#ifdef _DEBUG
			printf("DEBUG: %s\n", word);
#endif

			printf("Word: %s | Remaining tries: %d\n", guess, guesses_remaining);
			printf("Guesses: %s\n", letters_guessed);
			printf("Select a letter.\n");

			if (scanf(" %c", &input) == 1)
			{
				clear_input_buffer();
				input = tolower(input);

				if (isalpha(input) && !contains_letter(letters_guessed, input))
				{
					add_letter_guessed(letters_guessed, input);

					if (!guess_letter(word, guess, input))
						guesses_remaining--;
				}
			}
		}

		if (is_revealed(guess))
			printf("\n\nYOU WIN, the word was %s\n", guess);
		else
			printf("\n\nYOU LOSE, the word was %s\n", word);

		printf("Play again? [y/n]\n");
		scanf(" %c", &keep_playing);
		clear_input_buffer();
	}

	return 0;
}