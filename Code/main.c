/**
File which starts the Menu and the Game itself
**/
#include "board.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    //Open the main menu and get the players choice
    OpenMainMenu();

    return 0;
}

///
/// Starts a game with the game state in the board structure.
///
/// board: The current game state of the game.
///
void StartGame(struct Board *board)
{
    /*
     * Clear the input buffer, so that no remaining keyboard
     * inputs from the main menu are processed.
     */
    fflush(stdin);

    while(board->gameIsOngoing)
    {
        //Check if the timer has updated
        if(board->time != GetCurrentTime())
        {
            board->time = GetCurrentTime();
            board->updated = 1;
        }

        //Reprint the current game state to the console
        if(board->updated)
        {
            printBoard(board);

            //Reset the reprint flag
            board->updated = 0;
        }

        //Check if a key was pressed
        if(kbhit())
        {
            HandleGameInput(board);
        }
    }
}
