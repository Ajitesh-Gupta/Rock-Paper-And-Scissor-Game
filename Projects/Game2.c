/*                      Rock, Paper And Scissor Game
    Player 1 -> Rock
    Player 2 (Computer) -> Scissor => Player 1 gets 1 point

    Rock vs Scissor -> Rock Wins
    Paper vs Scissor -> Scissor Wins
    Rock vs Scissor -> Rock Wins
    Program to Allow user to Play this Game Three times with the Computer
    Log the Scores of Computer and the player
    Display the Name of the Winner at the End
    Note: You have to display Name of the Player during the Game. Take User's Name as an Input
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL)); // srand takes seed as an input and is defined inside stdlib.h
    return rand() % n;
}

int greater(char Char1, char Char2)
{
    // Return 1 if C1 > C2 and 0 otherwise
    // If C1 == C2 it will return -1
    if (Char1 == Char2)
    {
        return -1;
    }
    else if (Char1 == 'r')
    {
        if (Char2 == 'p')
        {
            return 1;
        }
        else if (Char2 == 's')
        {
            return 0;
        }
    }
    else if (Char1 == 'p')
    {
        if (Char2 == 'r')
        {
            return 0;
        }
        else if (Char2 == 's')
        {
            return 1;
        }
    }
    else if (Char1 == 's')
    {
        if (Char2 == 'r')
        {
            return 1;
        }
        else if (Char2 == 'p')
        {
            return 0;
        }
    }
}

int main()
{
    char name[25], PlayerChar, CompChar;
    int i, temp, PlayerScore = 0, CompScore = 0;
    char dict[] = {'r', 'p', 's'};
    printf("\n\t\t\tWelcome to Rock, Paper and Scissor Game!\n");
    printf("\nEnter your Name: ");
    gets(name);
    for (i = 0; i < 3; i++)
    {
        // Take Player 1's Input
        printf("\n\t\tChoose 1 for Rock (r)\n");
        printf("\t\tChoose 2 for Paper (p)\n");
        printf("\t\tChoose 3 for Scissor (s)\n");
        printf("\n%s's Turn: ", name);
        scanf("%d", &temp);
        PlayerChar = dict[temp - 1];
        printf("You chose %c\n", PlayerChar);

        // Generate Computer's Input
        temp = generateRandomNumber(3) + 1;
        CompChar = dict[temp - 1];
        printf("Computer's Turn: %d\n", temp);
        printf("Computer chose %c\n", CompChar);

        // Compare the Scores
        if (greater(PlayerChar, CompChar) == 1)
        {
            CompScore++;
            printf("\tComputer Wins the Round\n");
        }
        else if (greater(PlayerChar, CompChar) == 0)
        {
            PlayerScore++;
            printf("\t%s Wins the Rounnd", name);
        }
        else if (greater(PlayerChar, CompChar) == -1)
        {
            CompScore++;
            PlayerScore++;
            printf("\tDraw Round\n");
        }
        printf("\nYour Score: %d     Computer Score: %d\n", PlayerScore, CompScore);
    }

    if (PlayerScore > CompScore)
    {
        printf("\n\t\t%s Wins the Game!\n", name);
    }
    else if (CompScore > PlayerScore)
    {
        printf("\n\t\tComputer Wins the Game!\n");
    }
    else
    {
        printf("\n\t\tIt is a Draw!\n");
    }
    printf("\t\t\tThank You for Playing\n\n");
    return 0;
}
