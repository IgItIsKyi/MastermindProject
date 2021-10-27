#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// global constants
#define COLORS 8
#define THREE 3
#define FOUR 4
#define TEN 10
#define TRUE 1
#define FALSE 0
#define NINE 9
#define ZERO 0
#define INVALID -1



// function prototypes
void welcomeScreen();
void clearScreen();
void displayBoard();
int getColor();
void convertColor(int color);
void populateColorArray(char colors[COLORS]);
void setCode(int codeArray[FOUR]);
void initializeArray(int guesses[TEN][FOUR]);
void getGuess(int guesses[TEN][FOUR], char colors[COLORS]);
int isValid(char colors[COLORS], char color);

// enumeration
enum color
{
    BLACK,
    GREEN,
    NAVY,
    ORANGE,
    PINK,
    RED,
    VIOLET,
    WHITE
};

// main function
int main()
{
    int turn = 0;
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
   // displayBoard();

    // populate the color array with the single character color
    populateColorArray(colors);

    // initialize the guesses array
    initializeArray(guesses);

    //Gets the clues
    initializeArray(clues);

    displayBoard(guesses,clues);
    while(turn < TEN)
    {
        
        getGuess(guesses, colors);
        displayBoard(guesses,clues);
        turn++;
        

    }
    // get player guess
    // this only performs one turn of the game

  /*  printf("guesses array updated... \n");

    for(int row = 0; row < TEN; row++)
        for(int col = 0; col < FOUR; col++)
            printf("%c ", guesses[row][col]);
  */  
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
void displayBoard(int guesses[TEN][FOUR],int clues[TEN][FOUR])
{
    int row = 9;
    int col = ZERO;

    printf("+----------------------------------------+ \n");
    printf("|            SECRET CODE                 | \n");
    printf("+----------------------------------------+ \n");
    printf("|          ?    ?    ?    ?              | \n");
    printf("+----------------------------------------+ \n");
    printf("|     PLAYER GUESS        |    CLUES     | \n");
    printf("+----------------------------------------+ \n");
    // Don't touch the ones above (They never change)

    //Runs through the Guesses to print out board part for guesses
    for(row = 9; row >= ZERO; row--)
    {
        printf("|");
        for(col = ZERO; col < FOUR; col++)
        {
            if(guesses[row][col] == INVALID)
            {
                printf("   ? ");
            }            
            else 
            {
                printf("   %c ",guesses[row][col]);

            }
            //After the guesses are done, start printing out clues
            if(col == 3)
            {
                printf("|");
                    
                for(col = 0; col < FOUR; col++)
                {   
                    if(clues[row][col] == INVALID)
                    {
                        printf("   ?");
                    }
                    else
                    {
                        printf("   %c",clues[row][col]);
                    }
                }
                printf("   |");       
            }
        }
        //After row of clues are done print out the seperating line and start over again.
        printf("\n");
        printf("+----------------------------------------+ \n");
    }
/*
    
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
    */
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

//    // display character color array
//    printf("\nCharacter colors are \n");
//    for(color = 0; color < COLORS; color++)
//    {
//        printf("%c ", colors[color]);
//    }
}

// initialize the array guesses to be all -1
void initializeArray(int guesses[TEN][FOUR])
{
    int row;
    int col;

    // this is a nested loop to traverse a 2-d array
    for(row = 0; row < TEN; row++)
        for(col = 0; col < FOUR; col++)
            guesses[row][col] = -1;
}

// prompt the Code Breaker for their guess
void getGuess(int guesses[TEN][FOUR], char colors[COLORS])
{
    // use static variable to keep track of the turn number
    // turn number is the row index for the array
    static int row = 0;
    int col;
    char guess[TEN];
    int valid = FALSE;

    printf("\nCharacter colors are \n");
    for(col = 0; col < COLORS; col++)
    {
        printf("%c ", colors[col]);
    }

    while(!valid)
    {
        printf("\nEnter your guess of four colors (no spaces): \n");

        scanf("%s", guess);
        printf("You entered %s\n", guess);
//        printf("size of guess is %d\n", strlen(guess));

        if(strlen(guess) == FOUR)
        {
            for(col = 0; col < FOUR; col++)
            {
//                guess[col] = toupper(guess[col]);
printf("313: checking %c ", guess[col]);
                guess[col] = toupper(guess[col]);

                if(isalpha(guess[col]))
                {
//                    printf("getGuess: letter %d isalpha: checking isValid %c ...\n", col, guess[col]);

                    if(isValid(colors, guess[col]))
                    {
//                        printf("getGuess: Storing %c in row: %d col: %d\n", guess[col], row, col);
                        guesses[row][col] = guess[col];

                        if(col == THREE)
                            valid = TRUE;
                    }
                    else
                    {
                        printf("getGuess: Invalid value entered %c, try again\n", guess[col]);
                        valid = FALSE;
                        break;
                    }
                }
                else
                {
                    printf("getGuess: Invalid value entered %c, try again\n", guess[col]);
                    valid = FALSE;
                    break;
                }
            }
        }
        else
        {
            printf("getGuess: Incorrect number of letters entered\n");
            valid = FALSE;
        }
    }

    row++;
}

// check if the Code Breaker's guess is valid
int isValid(char colors[COLORS], char color)
{
    int c;
    // initialize valid to false, 0
    int valid = FALSE;

//    printf("isValid: Checking if %c isValid\n", color);

    for(c = 0; c < COLORS; c++)
    {
        if(color == colors[c])
        {
//            printf("isValid: Found it!\n");
            return TRUE;
        }
    }

    return FALSE;
}
