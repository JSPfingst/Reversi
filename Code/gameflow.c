#include "board.h"
#include "output.h"
#include "gameflow.h"
#include "input.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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

    if(board->isQuitGame == 0)
    {
        printf("\n");
        printf("Dr%ccken Sie <Enter> um zum Hauptmen%c zur%cckzukehren", '\x81', '\x81', '\x81');
        getchar();
    }
}
