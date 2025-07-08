#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get computer's choice
char getComputerChoice() {
    int num = rand() % 3; // 0, 1, or 2
    if (num == 0) return 's'; // snake
    else if (num == 1) return 'w'; // water
    else return 'g'; // gun
}

// Function to determine winner
int compareChoices(char user, char comp) {
    if (user == comp) return 0; // draw
    if ((user == 's' && comp == 'w') ||
        (user == 'w' && comp == 'g') ||
        (user == 'g' && comp == 's')) return 1; // user wins
    return -1; // computer wins
}

int main() {
    int rounds, userScore = 0, compScore = 0;
    char userChoice, compChoice;

    srand(time(0)); // Seed random number generator

    printf("🐍 Welcome to Snake-Water-Gun Game!\n");
    printf("Rules:\n");
    printf("Snake drinks Water 🐍 > 💧\nWater douses Gun 💧 > 🔫\nGun kills Snake 🔫 > 🐍\n");
    printf("Enter 's' for Snake, 'w' for Water, and 'g' for Gun.\n\n");

    printf("How many rounds do you want to play? ");
    scanf("%d", &rounds);

    for (int i = 1; i <= rounds; i++) {
        printf("\n--- Round %d ---\n", i);
        printf("Your choice (s/w/g): ");
        scanf(" %c", &userChoice);

        compChoice = getComputerChoice();

        printf("Computer chose: %c\n", compChoice);

        int result = compareChoices(userChoice, compChoice);

        if (result == 1) {
            printf("✅ You win this round!\n");
            userScore++;
        } else if (result == -1) {
            printf("❌ Computer wins this round!\n");
            compScore++;
        } else {
            printf("🤝 It's a draw!\n");
        }

        printf("Score: You %d - %d Computer\n", userScore, compScore);
    }

    printf("\n🏁 Final Result: ");
    if (userScore > compScore)
        printf("🎉 You WIN the game!\n");
    else if (userScore < compScore)
        printf("💻 Computer WINS the game!\n");
    else
        printf("😐 It's a DRAW!\n");

    return 0;
}
