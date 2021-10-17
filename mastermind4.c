#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// global constants
#define COLORS 8
#define FOUR 4
#define TEN 10
#define TRUE 1
#define FALSE 0
#define THREE 3

// function prototypes
void welcomeScreen();
void clearScreen();
void displayBoard();
int getColor();
void convertColor(int color);
void populateColorArray(char colors[COLORS]);
void setCode(int codeArray[FOUR]);
void initializeArray(int guesses[TEN][FOUR]);
void getGuess(int guesses[TEN][FOUR],char colors[COLORS]);
int isValid(char colors[COLORS], char color);

// enumeration
enum color
{
    BLACK,  // 0
    GREEN,  // 1
    NAVY,   // 2
    ORANGE, // 3
    PINK,   // 4
    RED,    // 5
    VIOLET, // 6
    WHITE   // 7
};

// main function
int main()
{
    int i;
    int j;
    // array of valid colors as characters
    char colors[COLORS];

    // array for the secret code
    int secretCode[FOUR];

    // array for the player guesses
    int guesses[TEN][FOUR];

    // array for the code maker clues
    int clues[TEN][FOUR];

    // seed the random
    srand(time(NULL));

    // display welcome screen
    welcomeScreen();

    // clear the screen
    clearScreen();

    // set secret code
    setCode(secretCode);

    // clear the screen
    clearScreen();

    // display the board
    displayBoard();

    // populate the color array with the single character color
    populateColorArray(colors);

    //initialize the guesses array
    initializeArray(guesses);

    //this only preforms one turn of the game
    getGuess(guesses,colors);

    printf("Guesses array updated... \n");

    //output updated array
    for(i = 0; i <= 0; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%c ",guesses[i][j]);
        }
    }

    return 0;
}

// welcome screen
void welcomeScreen()
{
    printf("\t\t##########################################################\n");
    printf("\t\t##########################################################\n");
    printf("\t\t############                                  ############\n");
    printf("\t\t############            Mastermind            ############\n");
    printf("\t\t############                                  ############\n");
    printf("\t\t##########################################################\n");
    printf("\t\t##########################################################\n");

    printf("Rules:\n");
    printf("1. The Codemaker sets a secret code\n");
    printf("2. The Codebreaker tries to match the code using logic and deduction\n");
    printf("3. After each move, the Codemaker gives clues to the Codebreaker\n");
    printf("4. The Codebreaker has 10 attempts to guess the secret code\n");

}

// clear the screen
void clearScreen()
{
    char enter;

    printf("\n\t\t\t\t <Hit Enter to continue>\n\n");

    scanf("%c", &enter);

    // windows
    //system("cls");

    // linux and mac
     system("clear");
}

// Mastermind board
void displayBoard()
{

    printf("+----------------------------------------+ \n");
    printf("|            SECRET CODE                 | \n");
    printf("+----------------------------------------+ \n");
    printf("|          ?    ?    ?    ?              | \n");
    printf("+----------------------------------------+ \n");
    printf("|     PLAYER GUESS        |    CLUES     | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
    printf("|   ?    ?    ?    ?      |  ?  ?  ?  ?  | \n");
    printf("+----------------------------------------+ \n");
}

// Code Maker creates the secret code
void setCode(int codeArray[FOUR])
{
    int code;

    // randomly select four colors to be the secret code
    for(code = 0; code < FOUR; code++)
    {
        codeArray[code] = getColor();
    }

    printf("Integer Secret Code\n");

    for(code = 0; code < FOUR; code++)
    {
        printf("%d ", codeArray[code]);
    }

    printf("\n");

    printf("\nColor Secret Code\n");

    for(code = 0; code < FOUR; code++)
    {
        convertColor(codeArray[code]);
    }
}

// randomly select a member of enum color
int getColor()
{
    // returns a random color from enum
    int color = rand() % COLORS;
    return color;
}

// convert the integer color to a string
void convertColor(int color)
{
    switch(color)
    {
        case BLACK:
            printf("Black ");
            break;
        case GREEN:
            printf("Green ");
            break;
        case NAVY:
            printf("Navy ");
            break;
        case ORANGE:
            printf("Orange ");
            break;
        case PINK:
            printf("Pink ");
            break;
        case RED:
            printf("Red ");
            break;
        case VIOLET:
            printf("Violet ");
            break;
        case WHITE:
            printf("White ");
            break;
    }
}

// populate the character array with single letters for the player to enter
void populateColorArray(char colors[COLORS])
{
    int color;

    for(color = BLACK; color <= WHITE; color++)
    {
        switch(color)
        {
            case BLACK:
                colors[color] = 'B';
                break;
            case GREEN:
                colors[color] = 'G';
                break;
            case NAVY:
                colors[color] = 'N';
                break;
            case ORANGE:
                colors[color] = 'O';
                break;
            case PINK:
                colors[color] = 'P';
                break;
            case RED:
                colors[color] = 'R';
                break;
            case VIOLET:
                colors[color] = 'V';
                break;
            case WHITE:
                colors[color] = 'W';
                break;
        }
    }

    //display character color array
    printf("\nCharacter colors are \n");
    for(color = 0; color < COLORS; color++)
    {
        printf("%c ", colors[color]);
    } 
}

void initializeArray(int guesses[TEN][FOUR])
{
    int row;
    int col;
    for(row = 0; row < TEN; row++)
    {
        for(col = 0; col < FOUR; col++)
        {
            guesses[row][col] = -1;
        }
    }

}

void getGuess(int guesses[TEN][FOUR], char colors[COLORS])
{
    static int row = 0;
    int curCol = 0; 
    int valid = FALSE;
    char guess[TEN];
    
   /*() for(curCol = 0; curCol < COLORS; curCol++)
    {
        printf("%c ", colors[curCol]);
    } */
    while(valid != TRUE)
    {
        printf("\nChoose four letters for colors (no spaces)\n");

        scanf("%s", guess);

        printf("%s\n", guess);

       // printf("Guesses array updated... \n");
        if(strlen(guess) == 4)
        {
            for(curCol = 0; curCol < 4; ++curCol)
            {
                guess[curCol] = toupper(guess[curCol]);
                
                if(isalpha(guess[curCol]))
                {
                    if((isValid(colors,guess[curCol]) == TRUE))
                    {
                        
                        guesses[row][curCol] = guess[curCol];
                        if(curCol == 3)
                        {
                            valid = TRUE;
                        } 
                    }
                    else
                    {
                        printf("Value is invalid.\n");
                        valid = FALSE;
                        break;   

                        printf("%c is not valid.\n", guess[curCol]);
                        valid = FALSE;
                        break;
                    } 
                    
                } 
            }
           // row += 1;
        }
       if(strlen(guess) != 4)
       {
            printf("User did not enter enough characters.\n");
            valid = FALSE; 
        }

    }
}

int isValid(char colors[COLORS], char color)
{
    int e;
    int valid = FALSE;
    int returN;

    for(e = 0; e < COLORS; e++)
    {
        if(colors[e] == color)
        {
            returN = TRUE;
            break; //stops when it figures out the letter otherwise it will go back to false.
        }
        else {
            returN = FALSE;
        }
    } 
    return returN;
    
}
