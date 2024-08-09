#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <time.h>
#include<conio.h>

// ANSI escape codes for text color and cursor movement
#define COLOR_RED   "\x1b[31m"
#define COLOR_RESET "\x1b[0m"
#define MOVE_UP     "\033[A"
#define CLEAR_LINE  "\033[K"
void welcome1(){
    system("cls");
        printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("TRAVASSO's Stop Watch");
    printf("-------------------------------\n");
    printf("\033[0m");
}

void stop() {
    int duration;
    
    printf(RED"\n\n\n\n                  Enter the duration of the timer (in seconds): "BHYEL);
    scanf("%d", &duration);
    welcome1();
    printf("\n\n\n\n                                  Timer started. Press Ctrl+C to stop.\n");

    while (duration >= 0) {
        printf("\r" COLOR_RED "                        Time remaining:"BHGRN" %d"RED" seconds" COLOR_RESET "   ", duration);
        fflush(stdout); // Flush output buffer
        sleep(1); // Wait for 1 second
        duration--;
    }
    // welcome();
    printf(BHGRN"\n\n\n\n\n\n                                       Time's up!\n");
    getche();
    // system("cls");


    // return 0;
}