#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro()
{
     printf("Rules And Reulations Of The Game : \n");
     printf("--> You Enter A choice And Computer takes A choice\n");
     printf("For every choice you give \n");
     printf("The choice adds up as your runs every time BUT\n");
     printf("--> If your choice and Computer choice matches\n");
     printf("||You are Out||\n");
}

void blush()
{
    printf("\xF0\x9F\x98\x8A\n"); // Unicode escape sequence for a blushing emoji
}

void clap()
{
         printf("\xF0\x9F\x91\x8F\n"); // Unicode escape sequence for a clapping emoj
}

int hand() {
    int player_runs = 0;
    int player_choice, computer_runs = 0, computer_choice;
        char playAgain = 'y';

        while (playAgain == 'y' || playAgain == 'Y') {


    srand(time(0)); // Seed for random number generation

    printf("Welcome to Hand Cricket Game!\n\n");
    intro();

    while (1) {
        printf("Enter your choice (1-6): ");
        scanf("%d", &player_choice);

        // Validate player's choice
        if (player_choice < 1 || player_choice > 6) {
            printf("Invalid choice! Please enter a number between 1 and 6.\n\n");
            continue;
        }

        // Generate computer's choice
        computer_choice = rand() % 6 + 1;

        printf("Computer's choice: %d\n", computer_choice);

        // Check if player is out
        if (player_choice == computer_choice) {
            printf("Out! Your total runs: %d\n", player_runs);
            break;
        }

        // Add runs based on player's choice
        player_runs += player_choice;
        printf("Your total runs: %d\n\n", player_runs);

        // Generate computer's runs
        computer_runs += computer_choice;
    }

    printf("Computer's total runs: %d\n", computer_runs);

    if (player_runs > computer_runs) {
        printf("Congratulations! You win!\n");
        blush();
    } else if (player_runs < computer_runs) {
        printf("Computer wins!\n Well Played Champ \n");
        clap();
        printf("Better luck next time!");
    } else {
        printf("It's a tie!\n");
    }
     printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
}
     printf("Thanks for playing\n");
    return 0;
        
}
