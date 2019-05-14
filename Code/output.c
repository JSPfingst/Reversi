#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void printPossibleCharacters()
{
    for(int c = 0; c <= 254; c++)
    {
        printf("%i: '%c'\n", c, c);
    }
}

/// Prints the Board to the console.
///
/// board: The current state of the game.
///
void printBoard(struct Board board)
{
    system("cls");
    /*
     * The starting point of the Reversi board is on the bottom left,
     * therefore the rows are iterated decrementally.
     */

     printf("Laufzeit des aktuellen Spiels:%lds\n\n",board.currenttime);

    for(int row = 8; row >= 0; row--)
    {
        for(int column = 0; column <= 8; column++)
        {
            switch(board.field[row][column])
            {
            //0: The position is empty.
            //0: The position is empty.
            case 0:
                printf("  | ");
                break;
            //1: Player 1 has a stone at this position.
            case 1:
                printf("%c | ", 177);
                break;
            //2: Player 2 has a stone at this position.
            case 2:
                printf("%c | ", 219);
                break;
            //3: The position is one of the label positions.
            case 3:
                if(row == 0)
                {
                    if(column != 0)
                    {
                        //Print the number for this label
                        printf("%c | ", column + 48);
                    }
                    else
                    {
                        printf("  | ");
                    }
                }
                else
                {
                    //Print the character for this label
                    printf("%c | ", row + 64);
                }
                break;
            }
        }

        printf("\n");
    }
}
