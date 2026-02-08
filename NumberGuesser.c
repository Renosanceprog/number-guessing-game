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
            break;
        }
        
        printf("do you want to play again? 0/1: ");
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
    int guess, tally=0;
    while(randomNum != guess){
        printf("==== ZEN MODE ====\ni have generated a random number ranging %d - %d, try to guess what it is\nWhat is the number: ", min, max);
        
        guess = valueinput();

        if (randomNum == guess){
            printf("you guessed correctly! amazing boy you are perhaps\n");
            break;
        }

        else if (guess > randomNum && guess <= max){
            printf("oof wrong guess! you shot too high\n");
        }

        else if (guess < randomNum && guess >= min){
            printf("oof wrong guess! you shot too low\n");
        }

        else{
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
    for (size_t i = 0; i < count; i++){
        printf("==== TRIAL MODE ====\ni have generated a random number ranging %d - %d, try to guess what it is in %d tries\nWhat is the number: ", min, max, count-i);
        int guess = valueinput();

        if (randomNum == guess){
            printf("you guessed correctly! amazing boy you are perhaps\n");
            win = 1;
            break;
        }

        else if (guess > randomNum && guess <= max){
            printf("oof wrong guess! you shot too high\n");
        }

        else if (guess < randomNum && guess >= min){
            printf("oof wrong guess! you shot too low\n");
        }

        else{
            printf("you didnt even try! disappointing boy you are truly\n");
        }
        
        system("pause");
        system("cls");
    }
        if (win == 0){
        printf("you didn't discover the number! you poor boy you...\n");
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



