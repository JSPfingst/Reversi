#include "board.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Open the main menu and get the players choice
    OpenMainMenu();

    return 0;
}

/// Hab spontan keine Ahnung, in welcher Datei ich die Funktion unterbringen soll.
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
