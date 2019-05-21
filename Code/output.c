#include "board.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

///
/// Prints the main menu to the console.
///
/// returns: The choice of the player.
///
int OpenMainMenu()
{
    /*
     * Flag to reprint the menu to the console.
     * Default value is 1 to print the menu during the first run.
     */
    int reprintMenu = 1;
    int key = 0, selectedItem = 1;

    //Endless loop, to simplify the maneuverability of the menu. =>
    //  No redundant condition required
    while(1)
    {
        //Check if a key was pressed
        if(kbhit())
        {
            key = getch();
            if(key == 224)
            {
                key = getch();
                reprintMenu = 1;
            }
        }

        //If the <Enter> key was pressed, return the current selection
        if(key == 13)
        {
            return selectedItem;
        }

        //Reprint the menu, if the reprint flag is set
        if(reprintMenu)
        {
            selectedItem = UpdateSelectedItem(key, selectedItem);

            system("cls");

            printf("\n");
            printf("   Reversi\n");
            printf("\n");
            if(selectedItem == 1)
            {
                printf(" > Spiel beenden <\n");
            }
            else
            {
                printf("   Spiel beenden\n");
            }

            if(selectedItem == 2)
            {
                printf(" > Spiel starten <\n");
            }
            else
            {
                printf("   Spiel starten\n");
            }
        }

        //Reset the reprint flag
        reprintMenu = 0;
    }
}

///
/// Prints the Board to the console.
///
/// board: The current state of the game.
///
void printBoard(struct Board board)
{
    system("cls");

    printf(" Current Player: %i\n", board.currentPlayer);
    printf(" Time: %i\n", (int)difftime(board.time, board.starttime) - board.pauseDuration);
    printf("\n");

    if(board.isPaused)
    {
        printf(" PAUSIERT\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("\n");
    }

    /*
     * The starting point of the Reversi board is on the bottom left,
     * therefore the rows are iterated decrementally.
     */
    for(int row = 8; row >= 0; row--)
    {
        for(int column = 0; column <= 8; column++)
        {
            switch(board.field[row][column])
            {
                //0: The position is empty.
                case 0:
                    printf("   | ");
                break;
                //1: Player 1 has a stone at this position.
                case 1:
                    printf(" %c | ", 177);
                break;
                //2: Player 2 has a stone at this position.
                case 2:
                    printf(" %c | ", 219);
                break;
                //3: The position is one of the label positions.
                case 3:
                    if(row == 0)
                    {
                        if(column != 0)
                        {
                            //Print the number for this label
                            printf(" %c | ", column + 48);
                        }
                        else
                        {
                            printf("   | ");
                        }
                    }
                    else
                    {
                        //Print the character for this label
                        printf(" %c | ", row + 64);
                    }
                break;
            }
        }

        printf("\n");
    }
}

///
/// Updates the selected item depending on the pressed key and the current selected item.
///
/// key: The ASCII value of the pressed key.
/// position: The current position of the selection.
///
int UpdateSelectedItem(int key, int position)
{
    switch(key)
    {
    case 72:
        if(position > 1)
        {
            position--;
        }
        break;
    case 80:
        if(position < 2)
        {
            position++;
        }
        break;
    }

    return position;
}
