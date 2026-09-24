// Ata Cuhan 2637585

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice();
int play_computer();
int play_user();
int scorecalculator(int,int,int,int);
void scoresheet(int score_pc,int score_user);


int main() {
    srand(time(NULL));

    printf("Welcome to the Crag game.\nLet's get started!\n");

    int round,comp,user,roundnum; // comp and user stands for the dices rolled for the start of the game.
    printf("\nHow many rounds would you like to play?:");
    scanf("%d",&round);

    user = 0;
    comp = 0;
    int PC_Point = 0;
    int USER_Point = 0;
    int PC_GENERAL_POINT = 0;
    int USER_GENERAL_POINT = 0;

    while(user==comp){ // If dices are the same it keeps dicing it again and again.
        user = roll_a_dice();
        comp = roll_a_dice();
    }

    printf("\nI have rolled the dice and got %d !\n",comp);
    printf("I have rolled the dice for your and you got %d!\n",user);

    for(roundnum=1;roundnum<=round;roundnum++) {

        if (user > comp) {
            printf("\nRound %d -- Your Turn:\n",roundnum);
            printf("------------------------------------------------\n");
            USER_Point = play_user();
            USER_GENERAL_POINT += USER_Point;
            printf("Your score: %d Total score: %d", USER_Point, USER_GENERAL_POINT);


            printf("\nRound %d -- My Turn:\n",roundnum);
            printf("------------------------------------------------\n");
            PC_Point = play_computer();
            PC_GENERAL_POINT += PC_Point;
            printf("My score: %d Total score: %d", PC_Point, PC_GENERAL_POINT);

        }
        else {
            printf("\nRound %d -- My Turn:\n",roundnum);
            printf("------------------------------------------------\n");
            PC_Point = play_computer();
            PC_GENERAL_POINT += PC_Point;
            printf("My score: %d Total score: %d", PC_Point, PC_GENERAL_POINT);

            printf("\nRound %d -- Your Turn:\n",roundnum);
            printf("------------------------------------------------\n");
            USER_Point = play_user();
            USER_GENERAL_POINT += USER_Point;
            printf("Your score: %d Total score: %d", USER_Point, USER_GENERAL_POINT);
        }
    }
    scoresheet(PC_GENERAL_POINT,USER_GENERAL_POINT);

    return 0;
}

int roll_a_dice(){
    int x = (rand() % 6) + 1;
    return x;
}

int play_computer(){
    printf("I rolled them and got\n");
    int Dice1,Dice2,Dice3;

    Dice1 = roll_a_dice();
    Dice2 = roll_a_dice();
    Dice3 = roll_a_dice();

    printf("[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n",Dice1,Dice2,Dice3);

    if((Dice1 == 4 && Dice2 == 5) && Dice3!=6 ){ // These if statements help the computer to get a high strait.
        Dice3 = roll_a_dice();
        printf("Rolled dice 3!\n");
        printf("[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",Dice1,Dice2,Dice3);
    } else if ((Dice1 == 4 && Dice3 == 6) && Dice3!=5){
        Dice2 = roll_a_dice();
        printf("Rolled dice 2!\n");
        printf("[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",Dice1,Dice2,Dice3);
    }else if ((Dice2 == 5 && Dice3 == 6) && Dice1!=4){
        Dice1 = roll_a_dice();
        printf("Rolled dice 1!\n");
        printf("[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",Dice1,Dice2,Dice3);
    }

    return scorecalculator(Dice1,Dice2,Dice3,1);
}

int play_user(){
    int Dice1User,Dice2User,Dice3User,keep1,keep2;
    char answer;

    Dice1User = roll_a_dice();
    Dice2User = roll_a_dice();
    Dice3User = roll_a_dice();

    printf("You got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n",Dice1User,Dice2User,Dice3User);

    printf("Shall I roll for you (Y/N)? \n"); // Asks user to roll a dice of his/her choice once
    scanf(" %c",&answer);

    while(answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'){ // If other than Y or N program asks again.
        printf("Sorry I don't understand!\n");
        printf("Shall I roll for you (Y/N)? \n");
        scanf(" %c",&answer);
    }

    if(answer == 'Y' || answer == 'y'){
        printf("Which ones do you want to keep? \n");
        scanf("%d %d",&keep1,&keep2);

        while (keep1 < 1 || keep1 > 3 || keep2 < 1 || keep2 > 3 || keep1 == keep2){ // Stops user from selecting any other dice other than dice 1, 2 or 3.
            printf("Sorry, wrong input!\n");
            printf("\nWhich ones do you want to keep? \n");
            scanf("%d %d",&keep1,&keep2);
        }

        if(keep1 == 1 && keep2 == 2){
            Dice3User = roll_a_dice();
            printf("You got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n",Dice1User,Dice2User,Dice3User);
        }
        else if(keep1 == 1 && keep2 == 3){
            Dice2User = roll_a_dice();
            printf("You got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n",Dice1User,Dice2User,Dice3User);
        }
        else if(keep1 == 2 && keep2 == 3){
            Dice1User = roll_a_dice();
            printf("You got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n",Dice1User,Dice2User,Dice3User);
        }
    }

    return scorecalculator(Dice1User,Dice2User,Dice3User,2);
}

int scorecalculator(int x,int y,int z,int player) { // Player value selects who gets credited for the score
    int score_computer, score_user, total_computer, total_user;
    score_computer = 0;
    score_user = 0;


    if (player == 1) { // Checks computers dices according to scoring table
        if (x + y + z == 13 && (x == y || x == z || z == y)) { // Crag
            score_computer += 50;
            printf("\nCrag!!\n");
        } else if (x + y + z == 13) { // Thirteen
            score_computer += 26;
        } else if (x == y && y == z) { // Three-Of-A-Kind
            score_computer += 25;
        } else if (x == 1 && y == 2 && z == 3) { // Low Straight
            score_computer += 20;
        } else if (x == 4 && y == 5 && z == 6) { // High Straight
            score_computer += 20;
        } else if (x == 1 && y == 3 && z == 5) { // Odd Straight
            score_computer += 20;
        } else if (x == 2 && y == 4 && z == 6) { // Even Straight
            score_computer += 20;
        } else {
            score_computer += x + y + z;
        }

    }

    if (player == 2) { // Checks user dices according to scoring table
        if (x + y + z == 13 && (x == y || x == z || z == y)) { // Crag
            score_user += 50;
            printf("\nCrag!!\n");
        } else if (x + y + z == 13) { // Thirteen
            score_user += 26;
        } else if (x == y && y == z) { // Three-Of-A-Kind
            score_user += 25;
        } else if (x == 1 && y == 2 && z == 3) { // Low Straight
            score_user += 20;
        } else if (x == 4 && y == 5 && z == 6) { // High Straight
            score_user += 20;
        } else if (x == 1 && y == 3 && z == 5) { // Odd Straight
            score_user += 20;
        } else if (x == 2 && y == 4 && z == 6) { // Even Straight
            score_user += 20;
        } else {
            score_user += x + y + z;
        }

    }
}

void scoresheet(int pc,int user){
    printf("\nMy score              Your score\n %d                      %d", pc, user);
    if (pc<user){
        printf("\nYou are WINNER!");
    }
    else if(pc>user){
        printf("\nPC is WINNER!");
    }
    else
        printf("TIE!!");
}