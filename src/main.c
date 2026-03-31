#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumber(int max) {
    return rand() % max + 1;
}

void playGame(int maxAttempts, int range) {
    int number = generateNumber(range);
    int guess, attempts = 0;

    printf("\nGuess a number between 1 and %d\n", range);

    while (attempts < maxAttempts) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            printf("🎉 Correct! You guessed in %d attempts!\n", attempts);
            return;
        } else if (guess > number) {
            printf("Too high!\n");
        } else {
            printf("Too low!\n");
        }
    }

    printf("❌ Out of attempts! The number was %d\n", number);
}

int main() {
    srand(time(0));

    int choice;

    do {
        printf("\n=== Number Guessing Game ===\n");
        printf("1. Easy (1-50, 10 attempts)\n");
        printf("2. Medium (1-100, 7 attempts)\n");
        printf("3. Hard (1-200, 5 attempts)\n");
        printf("0. Exit\n");
        printf("Choose difficulty: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame(10, 50);
                break;
            case 2:
                playGame(7, 100);
                break;
            case 3:
                playGame(5, 200);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}