// random numbers
// stdio.h provides printf, scanf
#include <stdio.h>
// stdlib.h provides rand, srand, system, and exit
#include <stdlib.h>
// time.h provides time() used for seeding RNG
#include <time.h>
// unistd.h is present for POSIX helpers (may be unused on Windows)
#include <unistd.h>

// function prototypes (declared so functions can be used before they are defined)
// read a single character mode choice (e.g., 'A' or 'B') with validation
int modeinput();
// read a validated integer from stdin
int valueinput();
// play the unlimited-tries mode
void zen();
// play the limited-tries trial mode with difficulty selection
void trial();
// generate a random integer between min and max (inclusive)
int rng(int min, int max);

int main(){ // program entry point
    while (1){ // repeat until the user chooses to exit
        // display the main menu and prompt for mode selection
        printf("NUMBER GUESSING GAME\n[A]Zen mode\n[B]Trial mode\nChoose your mode: ");
        // read a validated mode character
        switch (modeinput())
        {
        case 'a':
        case 'A':
            // user selected Zen mode (case-insensitive)
            zen();
            break;

        case 'b':
        case 'B':
            // user selected Trial mode
            trial();
            break;

        default:
            // any other input is invalid; notify and continue loop
            printf("invalid input.\n");
            break;
        }
        
        // ask whether to play another round (1 = yes, 0 = no)
        printf("try again? 0/1: ");
        int try = valueinput(); // validated integer input
        if (try == 1){
            // user wants to play again: clear the screen and restart menu
            system("cls");
            continue;
        }
        else{
            // exit the loop and terminate the program normally
            break;
        }
    }

    return 0; // success
} 

void zen(){ // Zen mode: unlimited attempts to guess the number
    int min = 1, max = 1000; // valid range for the random number
    int randomNum = rng(min, max); // generate the target number
    system("cls"); // clear the console for clean UI
    int guess = -1, tally = 0; // initialize guess and attempt counter
    int last_guess = -1; // stores the previous guess to display between rounds
    int last_relation = 0; /* relation: 0=correct, 1=too high, -1=too low, 2=invalid */

    // repeat until the player's guess equals the random number
    while(randomNum != guess){
        // header: show mode and range
        printf("==== ZEN MODE ====\ni have generated a random number ranging %d - %d, try to guess what it is\n", min, max);
        // if there was a previous guess, show its relation in the header
        if (last_guess != -1) {
            if (last_relation == 0) printf("Last guess: %d (correct).\n", last_guess);
            else if (last_relation == 1) printf("Last guess: %d (too high).\n", last_guess);
            else if (last_relation == -1) printf("Last guess: %d (too low).\n", last_guess);
            else printf("Last input: %d (invalid/out of range).\n", last_guess);
        }
        // prompt user for a guess
        printf("What is the number: ");
        
        // read a validated integer from stdin
        guess = valueinput();
        // save the guess to show on the next header cycle if needed
        last_guess = guess;

        // check guess relation to random number and respond accordingly
        if (randomNum == guess){
            // correct guess
            last_relation = 0;
            printf("you guessed correctly! amazing boy you are perhaps\n");
            tally++; // include the successful attempt in the tally
            break; // exit the guessing loop
        }

        else if (guess > randomNum && guess <= max){
            // guess is higher than the target but within allowed max
            last_relation = 1;
            printf("oof wrong guess! you shot too high\n");
        }

        else if (guess < randomNum && guess >= min){
            // guess is lower than the target but within allowed min
            last_relation = -1;
            printf("oof wrong guess! you shot too low\n");
        }

        else{
            // guess is outside the permitted range
            last_relation = 2;
            printf("you didnt even try! disappointing boy you are truly\n");
        }
        tally++; // increment attempt count after a failed/invalid try
        system("pause"); // wait for user to acknowledge
        system("cls"); // clear the screen before next attempt
    }
    // show summary when the round ends
    printf("it took you %d tries to get it right, my incredible joyous boy!\n", tally);
} 

void trial(){
    // clear the console and ask the player to choose difficulty
    system("cls");
    printf("==== TRIAL MODE ====\n[A]Easy\n[B]medium\n[C]hard\nChoose your difficulty: ");
    int valid = 0; // validation flag for difficulty selection
    int count = 0, min = 1, max = 0, win = 0; // count = attempts allowed, min/max range
    do{
        // read mode choice and set difficulty parameters accordingly
        switch (modeinput()){
        case 'a':
        case 'A':
            // Easy: 10 attempts, numbers up to 100
            count = 10;
            max = 100;
            valid = 1;
            break;
        case 'b':
        case 'B':
            // Medium: 5 attempts, numbers up to 50
            count = 5;
            max = 50;
            valid = 1;
            break;
        case 'c':
        case 'C':
            // Hard: 3 attempts, numbers up to 20
            count = 3;
            max = 20;
            valid = 1;
            break;
        
        default:
            // invalid selection; prompt again
            printf("choose only from the given modes.");
            break;
        }
    }while (!valid); // repeat until a valid difficulty is chosen
    
    // generate the target number for the trial
    int randomNum = rng(min, max);
    system("cls"); // clear screen for the game UI
    int last_guess = -1; // store last guess for header display
    int last_relation = 0; /* 0=correct, 1=too high, -1=too low, 2=invalid */

    // loop `count` times for the limited attempts
    for (size_t i = 0; i < count; i++){
        printf("==== TRIAL MODE ====\ni have generated a random number ranging %d - %d, try to guess what it is in %d tries\n", min, max, count-i);
        // if we have a last guess, display its relation in the header
        if (last_guess != -1) {
            if (last_relation == 0) printf("Last guess: %d (correct).\n", last_guess);
            else if (last_relation == 1) printf("Last guess: %d (too high).\n", last_guess);
            else if (last_relation == -1) printf("Last guess: %d (too low).\n", last_guess);
            else printf("Last input: %d (invalid/out of range).\n", last_guess);
        }
        // prompt and read the player's guess
        printf("What is the number: ", min, max, count-i);
        int guess = valueinput();
        last_guess = guess; // remember this guess for next header

        // respond according to the relation between guess and target
        if (randomNum == guess){
            last_relation = 0; // correct
            printf("you guessed correctly! amazing boy you are perhaps\n");
            win = 1;
            break; // exit early if guessed correctly
        }

        else if (guess > randomNum && guess <= max){
            last_relation = 1; // too high
            printf("oof wrong guess! you shot too high\n");
        }

        else if (guess < randomNum && guess >= min){
            last_relation = -1; // too low
            printf("oof wrong guess! you shot too low\n");
        }

        else{
            last_relation = 2; // invalid/out of range
            printf("you didnt even try! disappointing boy you are truly\n");
        }
        
        system("pause"); // give the player time to view the message
        system("cls"); // clear the screen before next attempt
    }
        if (win == 0){
        // player used all attempts without winning
        printf("you didn't discover the number! you poor boy you...\n");
    } else {
        /* win == 1: player guessed correctly */
    }
} 

int modeinput(){
    // read a single non-whitespace character from stdin and validate
    char mode;
    int valid=0;
        do{
            // the leading space in the format string skips whitespace
            if (scanf(" %c", &mode) != 1){
            // clear invalid characters from stdin if scanf fails
            printf("Invalid input.\n");
            int c; while ((c = getchar()) != '\n' && c != EOF); /* clear bad input */
            continue; // re-prompt
            }
            valid = 1; // successful read
    } while (!valid);
    return mode; // return the character read
}

int valueinput(){
    // read and validate an integer from stdin
    int value;
    int valid=0;
        do{
            if (scanf(" %d", &value) != 1){
            // invalid integer input; clear the buffer and re-prompt
            printf("Invalid input.\n");
            int c; while ((c = getchar()) != '\n' && c != EOF); /* clear bad input */
            continue;
            }
            valid = 1; // successful integer read
    } while (!valid);
    return value; // return the parsed integer
}

int rng(int min, int max){
    // seed the RNG with current time.
    // Note: calling srand() on every call reseeds repeatedly; for many programs
    // it's preferable to call srand() once in main(). This implementation keeps
    // previous behavior to avoid changing semantics.
    srand(time(NULL));
    int randomNum = (rand() % (max - min + 1)) + min; // map rand() to [min,max]
    return randomNum;
}