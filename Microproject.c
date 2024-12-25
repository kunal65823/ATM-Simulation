#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startStopwatch();
void displayTime(double elapsed_time);

int main() {
    int choice;
    printf("===== Stopwatch Program =====\n");

    do {
        printf("\nMenu:\n");
        printf("1. Start Stopwatch\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startStopwatch();
                break;
            case 2:
                printf("Exiting... Thank you for using the Stopwatch!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

// Function to start the stopwatch
void startStopwatch() {
    char command;
    clock_t start_time, end_time;
    double elapsed_time = 0;

    printf("\nStopwatch started. Press 's' to stop, 'r' to reset, or 'e' to exit.\n");
    start_time = clock();

    while (1) {
        printf("\nEnter command ('s' to stop, 'r' to reset, 'e' to exit): ");
        scanf(" %c", &command);

        if (command == 's') {
            end_time = clock();
            elapsed_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
            displayTime(elapsed_time);
        } else if (command == 'r') {
            printf("\nStopwatch reset.\n");
            elapsed_time = 0;
            start_time = clock();
        } else if (command == 'e') {
            printf("\nExiting stopwatch...\n");
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }

        if (command == 's') {
            start_time = clock(); // Restart timing after stop
        }
    }
}

// Function to display the elapsed time
void displayTime(double elapsed_time) {
    int minutes = (int)elapsed_time / 60;
    double seconds = elapsed_time - (minutes * 60);

    printf("\nElapsed Time: %02d:%06.3f (MM:SS.sss)\n", minutes, seconds);
}