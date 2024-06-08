// Recreate the famous Rock, Paper, Scissors game.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	char play_again = 'y';
	int user_score = 0;
	int computer_score = 0;

	while (play_again == 'y')
	{
		int user_choice;
		int computer_choice = (rand() % 3) + 1;
		printf("Score: You %d - %d Computer\n", user_score, computer_score);
		printf("1. Rock\n");
		printf("2. Paper\n");
		printf("3. Scissors\n");
		printf("Choose wisely: ");
		scanf_s("%d", &user_choice);

		if (user_choice == 1)
		{
			if (computer_choice == 1)
			{
				printf("It's a tie!\n");
			}
			else if (computer_choice == 2)
			{
				printf("Paper beats rock. You lose!\n");
				computer_score++;
			}
			else if (computer_choice == 3)
			{
				printf("Rock beats scissors. You win!\n");
				user_score++;
			}
		}
		else if (user_choice == 2)
		{
			if (computer_choice == 1)
			{
				printf("Paper beats rock. You win!\n");
				user_score++;
			}
			else if (computer_choice == 2)
			{
				printf("It's a tie!\n");
			}
			else if (computer_choice == 3)
			{
				printf("Scissors beats paper. You lose!\n");
				computer_score++;
			}
		}
		else if (user_choice == 3)
		{
			if (computer_choice == 1)
			{
				printf("Rock beats scissors. You lose!\n");
				computer_score++;
			}
			else if (computer_choice == 2)
			{
				printf("Scissors beats paper. You win!\n");
				user_score++;
			}
			else if (computer_choice == 3)
			{
				printf("It's a tie!\n");
			}
		}
		else
		{
			printf("Invalid choice!\n");
		}

		printf("Do you want to play again? (y/n): ");
		scanf_s(" %c", &play_again);
		system("cls");
	}

	printf("Final score: You %d - %d Computer\n", user_score, computer_score);
	printf("Thanks for playing!\n");

	return 0;
}