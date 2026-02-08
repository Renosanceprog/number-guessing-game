// random numbers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int modeinput();
int valueinput();
void zen();
void trial();
int rng(int min, int max);

int main(){
    while (1){
        printf("NUMBER GUESSING GAME\n[A]Zen mode\n[B]Trial mode\nChoose your mode: ");
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
            printf("invalid input.\n");
            break;
        }
        
        printf("try again? 0/1: ");
        int try = valueinput();
        if (try == 1){
            system("cls");
            continue;
        }
        else{
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
    int last_relation = 0; /* 0=correct, 1=too high, -1=too low, 2=invalid */

    while(randomNum != guess){
        printf("==== ZEN MODE ====\ni have generated a random number ranging %d - %d, try to guess what it is\n", min, max);
        if (last_guess != -1) {
            if (last_relation == 0) printf("Last guess: %d (correct).\n", last_guess);
            else if (last_relation == 1) printf("Last guess: %d (too high).\n", last_guess);
            else if (last_relation == -1) printf("Last guess: %d (too low).\n", last_guess);
            else printf("Last input: %d (invalid/out of range).\n", last_guess);
        }
        printf("What is the number: ");
        
        guess = valueinput();
        last_guess = guess;

        if (randomNum == guess){
            last_relation = 0;
            printf("you guessed correctly! amazing boy you are perhaps\n");
            tally++;
            break;
        }

        else if (guess > randomNum && guess <= max){
            last_relation = 1;
            printf("oof wrong guess! you shot too high\n");
        }

        else if (guess < randomNum && guess >= min){
            last_relation = -1;
            printf("oof wrong guess! you shot too low\n");
        }

        else{
            last_relation = 2;
            printf("you didnt even try! disappointing boy you are truly\n");
        }
        tally++;
        system("pause");
        system("cls");
    }
    printf("it took you %d tries to get it right, my incredible joyous boy!\n", tally);
}

void trial(){
    system("cls");
    printf("==== TRIAL MODE ====\n[A]Easy\n[B]medium\n[C]hard\nChoose your difficulty: ");
    int valid = 0;
    int count = 0, min = 1, max = 0, win = 0;
    do{
        switch (modeinput()){
        case 'a':
        case 'A':
            count = 10;
            max = 100;
            valid = 1;
            break;
        case 'b':
        case 'B':
            count = 5;
            max = 50;
            valid = 1;
            break;
        case 'c':
        case 'C':
            count = 3;
            max = 20;
            valid = 1;
            break;
        
        default:
            printf("choose only from the given modes.");
            break;
        }
    }while (!valid);
    
    int randomNum = rng(min, max);
    system("cls");
    int last_guess = -1;
    int last_relation = 0; /* 0=correct, 1=too high, -1=too low, 2=invalid */

    for (size_t i = 0; i < count; i++){
        printf("==== TRIAL MODE ====\ni have generated a random number ranging %d - %d, try to guess what it is in %d tries\n", min, max, count-i);
        if (last_guess != -1) {
            if (last_relation == 0) printf("Last guess: %d (correct).\n", last_guess);
            else if (last_relation == 1) printf("Last guess: %d (too high).\n", last_guess);
            else if (last_relation == -1) printf("Last guess: %d (too low).\n", last_guess);
            else printf("Last input: %d (invalid/out of range).\n", last_guess);
        }
        printf("What is the number: ", min, max, count-i);
        int guess = valueinput();
        last_guess = guess;

        if (randomNum == guess){
            last_relation = 0;
            printf("you guessed correctly! amazing boy you are perhaps\n");
            win = 1;
            break;
        }

        else if (guess > randomNum && guess <= max){
            last_relation = 1;
            printf("oof wrong guess! you shot too high\n");
        }

        else if (guess < randomNum && guess >= min){
            last_relation = -1;
            printf("oof wrong guess! you shot too low\n");
        }

        else{
            last_relation = 2;
            printf("you didnt even try! disappointing boy you are truly\n");
        }
        
        system("pause");
        system("cls");
    }
        if (win == 0){
        printf("you didn't discover the number! you poor boy you...\n");
    } else {
        /* win == 1 */
    }
}

int modeinput(){
    char mode;
    int valid=0;
        do{
            if (scanf(" %c", &mode) != 1){
            printf("Invalid input.\n");
            int c; while ((c = getchar()) != '\n' && c != EOF); /* clear bad input */
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
            printf("Invalid input.\n");
            int c; while ((c = getchar()) != '\n' && c != EOF); /* clear bad input */
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



