// random numbers
// stdio.h provides printf, scanf
#include <stdio.h>
// stdlib.h provides rand, srand, system, and exit
#include <stdlib.h>
// time.h provides time() used for seeding RNG
#include <time.h>
// unistd.h is present for POSIX helpers (may be unused on Windows)
#include <unistd.h>

// function prototypes
int modeinput();
int valueinput();
void zen();
void trial();
int rng(int min, int max);

int main(){ 
    while (1){ 
        // THEME UPDATE: Main Menu
        printf("THE GRAND NUMERICAL DIVINATION\n");
        printf("[A] The Path of Zen (Infinite Pondering)\n");
        printf("[B] The Path of Trials (A Test of Wits)\n");
        printf("Which path calls to you, young apprentice? ");
        
        switch (modeinput())
        {
        case 'a':
        case 'A':
            zen();
            break;

        case 'b':
        case 'B':
            trial();
            break;

        default:
            printf("Alas! That rune is unknown to me.\n");
            break;
        }
        
        // THEME UPDATE: Replay
        printf("Shall we consult the oracles again? (1=Yes, 0=No): ");
        int try = valueinput(); 
        if (try == 1){
            system("cls");
            continue;
        }
        else{
            printf("Farewell, seeker of truth! May your calculations always be correct.\n");
            break;
        }
    }

    return 0; 
} 

void zen(){ 
    int min = 1, max = 1000; 
    int randomNum = rng(min, max); 
    system("cls"); 
    int guess = -1, tally = 0; 
    int last_guess = -1; 
    int last_relation = 0; 

    while(randomNum != guess){
        // THEME UPDATE: Zen Header
        printf("==== THE PATH OF ZEN ====\n");
        printf("I have plucked a number from the ether between %d and %d!\n", min, max);
        printf("Clear your mind and gaze into the crystal ball...\n");

        if (last_guess != -1) {
            if (last_relation == 0) printf("Previous vision: %d (IT WAS DESTINY!)\n", last_guess);
            else if (last_relation == 1) printf("Previous vision: %d (Too High! The number floats below!)\n", last_guess);
            else if (last_relation == -1) printf("Previous vision: %d (Too Low! Aim for the stars!)\n", last_guess);
            else printf("Previous vision: %d (A chaotic, invalid number!)\n", last_guess);
        }

        printf("What is your divination? ");
        
        guess = valueinput();
        last_guess = guess;

        if (randomNum == guess){
            last_relation = 0;
            // THEME UPDATE: Win Message
            printf("EUREKA! By the beard of Pythagoras, you found it!\n");
            printf("The number was indeed %d!\n", randomNum);
            tally++; 
            break; 
        }

        else if (guess > randomNum && guess <= max){
            last_relation = 1;
            printf("Alas, your ambition is too great! Lower your gaze!\n");
        }

        else if (guess < randomNum && guess >= min){
            last_relation = -1;
            printf("Not quite! You must elevate your thinking! Higher!\n");
        }

        else{
            last_relation = 2;
            printf("That number is from another dimension! Stick to the %d-%d range!\n", min, max);
        }
        tally++; 
        system("pause"); 
        system("cls"); 
    }
    // THEME UPDATE: Summary
    printf("It took you %d attempts to align the stars, my brilliant apprentice!\n", tally);
} 

void trial(){
    system("cls");
    // THEME UPDATE: Difficulty Menu
    printf("==== THE PATH OF TRIALS ====\n");
    printf("[A] Novice (Easy)\n");
    printf("[B] Adept (Medium)\n");
    printf("[C] Archmage (Hard)\n");
    printf("Choose your difficulty level: ");
    
    int valid = 0; 
    int count = 0, min = 1, max = 0, win = 0; 
    do{
        switch (modeinput()){
        case 'a':
        case 'A':
            count = 10; max = 100; valid = 1;
            break;
        case 'b':
        case 'B':
            count = 5; max = 50; valid = 1;
            break;
        case 'c':
        case 'C':
            count = 3; max = 20; valid = 1;
            break;
        default:
            printf("That is not a valid spell difficulty! Choose A, B, or C.\n");
            break;
        }
    }while (!valid); 
    
    int randomNum = rng(min, max);
    system("cls"); 
    int last_guess = -1; 
    int last_relation = 0; 

    for (size_t i = 0; i < count; i++){
        // THEME UPDATE: Trial Header
        printf("==== TRIAL IN PROGRESS ====\n");
        printf("The sands of time flow! You have %d attempts remaining.\n", count-i);
        printf("Find the number between %d and %d before the portal closes!\n", min, max);
        
        if (last_guess != -1) {
            if (last_relation == 0) printf("Last guess: %d (Correct!)\n", last_guess);
            else if (last_relation == 1) printf("Last guess: %d (Too High!)\n", last_guess);
            else if (last_relation == -1) printf("Last guess: %d (Too Low!)\n", last_guess);
            else printf("Last guess: %d (Invalid!)\n", last_guess);
        }

        printf("Cast your number: ");
        int guess = valueinput();
        last_guess = guess; 

        if (randomNum == guess){
            last_relation = 0; 
            // THEME UPDATE: Win Message
            printf("MAGNIFICENT! The equations balance perfectly!\n");
            win = 1;
            break; 
        }

        else if (guess > randomNum && guess <= max){
            last_relation = 1; 
            printf("Too high! Reduce your variables!\n");
        }

        else if (guess < randomNum && guess >= min){
            last_relation = -1; 
            printf("Too low! Increment your expectations!\n");
        }

        else{
            last_relation = 2; 
            printf("Focus! That number is not even in this realm!\n");
        }
        
        system("pause"); 
        system("cls"); 
    }
    
    if (win == 0){
        // THEME UPDATE: Lose Message
        printf("The portal has closed! The number %d fades into the void...\n", randomNum);
        printf("Study your charts and return when you are ready.\n");
    } 
} 

int modeinput(){
    char mode;
    int valid=0;
    do{
        if (scanf(" %c", &mode) != 1){
            printf("A letter, apprentice! I need a letter!\n");
            int c; while ((c = getchar()) != '\n' && c != EOF); 
            continue; 
        }
        valid = 1; 
    } while (!valid);
    return mode; 
}

int valueinput(){
    int value;
    int valid=0;
    do{
        if (scanf(" %d", &value) != 1){
            // THEME UPDATE: Error Handling
            printf("By the void! That is not a number! Try again:\n");
            int c; while ((c = getchar()) != '\n' && c != EOF); 
            continue;
        }
        valid = 1; 
    } while (!valid);
    return value; 
}

int rng(int min, int max){
    srand(time(NULL));
    int randomNum = (rand() % (max - min + 1)) + min; 
    return randomNum;
}