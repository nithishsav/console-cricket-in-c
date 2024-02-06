#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char playerChoice[5] = "";

int playerScore = 0;
int computerScore = 0;


void choice();
void play();
int main(){
    
    char y;
    do{
        choice();
        play();
        printf("\nEnter y to Play again: ");
        scanf("%s",&y);
    }while (y == 'Y' || y =='y');
	return 0;

}

void choice(){
    srand(time(0));
    printf("Enter E for Even and O for Odd: ");
    char c;
    scanf("%c", &c);
    int num = rand() % 2;
    if(c == 'E' || c == 'e')
    {
        int pNum, cNum;
        printf("\nYou choose even.\nEnter a number: ");
        scanf("%d", &pNum);
        cNum = (rand() % 6) + 1; 
        printf("Your number %d and computer number %d\n", pNum, cNum);

        if((cNum + pNum) % 2 == 0)
        {

            printf("%d is even Your Win\n", (cNum + pNum));
            printf("Enter bat or bowl: ");
            scanf("%5s", playerChoice);
        }
        else 
        {
            int r = rand() % 2;

            if(r == 0)
            {
                strcpy(playerChoice,"bowl");
                printf("Computer choose bat first");
            }
            else
            {
                strcpy(playerChoice,"bat");
                printf("Computer choose bowl first");
            }
        }

    }
    else if(c == 'O' || c == 'o')
    {
        int pNum, cNum;
        printf("\nYou choose odd.\nEnter a number: ");
        scanf("%d", &pNum);
        cNum = (rand() % 6) + 1; 
        printf("Your number %d and computer number %d\n", pNum, cNum);

        if((cNum + pNum) % 2 == 1)
        {
            printf("%d is odd Your Win\n", (cNum + pNum));
            printf("Enter bat or bowl: ");
            scanf("%5s", playerChoice);

        }
        else 
        {
            printf("%d is even Computer choice wins\n", (cNum + pNum));
            int r = rand() % 2;

            if(r == 0)
            {
                strcpy(playerChoice,"bat");
                printf("Computer choose bowl first");
            }
            else
            {
                strcpy(playerChoice,"bowl");
                printf("Computer choose bat first");
            }
        }
    }
}

void play()
{
    srand(time(0));
    if(!strcmp(playerChoice, "bat"))
    {
        int run;
        int wick;
        printf("\nEnter your number: ");
        scanf("%d", &run);
        wick = (rand() % 6) + 1;

        while (run != wick) {
            
            if(run < 7 && run != 0)
            {
                playerScore += run; 
            } 
            else 
            {
                printf("Invalid number");
                printf("\n");
            }
            printf("\nYour number %d ", run);
            printf("\nComputer number %d ", wick);
            printf("\nYour score %d ", playerScore);
            printf("\nEnter your number: ");
            scanf( "%d" ,&run);
            wick = (rand() % 6) + 1;
        }
        
        printf("\nYour number %d ", run);
        printf("\nComputer number %d ", wick);
        printf("\nYour OUT........ ");
        printf("\nTarget %d ", playerScore);
        printf("\nEnter your number: ");
        scanf("%d", &wick);
        run = (rand() % 6) + 1;

        while (run != wick) 
        {
            computerScore +=  run;
            if(computerScore > playerScore)
            {
                printf("\nComputer number %d ", run);
                printf("\nYour number %d ", wick);
                printf("Computer Wins at %d ", computerScore);
                printf("\n");
                break;
            }
            
            printf("\nComputer number %d ", run);
            printf("\nYour number %d ", wick);
            printf("\nComputer score %d ", computerScore);
            printf("\nEnter your number: ");
            scanf("%d", &wick);
            run = (rand() % 6) + 1;
        }
            printf("\nComputer number %d ", run);
            printf("\nYour number %d ", wick);
            printf("\nComputer score %d ", computerScore);
        if(computerScore == playerScore)
        {
            printf("\nDraw match\n");
        }
        else if(computerScore < playerScore)
        {
            printf("\nYou win\n");
        }
    }

    if(!strcmp(playerChoice, "bowl"))
    {
        int run;
        int wick;
        printf("\nEnter your number: ");
        scanf("%d", &wick);
        run = (rand() % 6) + 1;

        while (run != wick) 
        {
            computerScore += run;
            printf("\nYour number %d ", run);
            printf("\nComputer number %d ", wick);
            printf("\nComputer score %d ", computerScore);
            printf("\nEnter your number: ");
            scanf("%d", &wick);
            run = (rand() % 6) + 1;
        }

        printf("\nComputer number %d ", run);
        printf("\nYour number %d ", wick);
        printf("\nComputer OUT........ ");
        printf("\nTarget %d ", computerScore);
        printf("\nEnter your number: ");
        scanf("%d", &run);
        wick = (rand() % 6) + 1;

        while (run != wick) {

            if(run < 7 && run != 0) 
            {
                playerScore += run; 
            } 
            else 
            {
                printf("Invalid number\n");
            }

            if(playerScore > computerScore) 
            {
                printf("\nYou win at %d ", playerScore);
                printf("\n");
                break;
            }
            
            
            printf("\nYour number %d ", run);
            printf("\nComputer number %d ", wick);
            printf("\nYour score %d ", playerScore);
            printf("\nEnter your number: ");
            scanf( "%d" ,&run);
            wick = (rand() % 6) + 1;
        }

        if(computerScore == playerScore)
        {
            printf("Draw match\n");
        }
        else if(playerScore < computerScore)
        {
            printf("Computer win\n");
        }

    }
}
