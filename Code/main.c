#include "board.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct Board board;

    int endGame = 0, gameIsOngoing = 1;
    int row = 0, column = 1, chosenMenuOption = 0;
    int reprintBoard = 0, key = 0;

    while(endGame == 0)
    {
        //Open the main menu and get the players choice
        chosenMenuOption = OpenMainMenu();

        switch(chosenMenuOption)
        {
            //Set the flag to close the application
            case 1:
                endGame = 1;
                gameIsOngoing = 0;
            break;
            //Create a new board and start the game
            case 2:
                board = GenerateStartingBoard();
                board.starttime = GetCurrentTime();
                gameIsOngoing = 1;
            break;
        }

        while(gameIsOngoing)
        {
            //Check if the timer has updated
            if(board.time != GetCurrentTime())
            {
                board.time = GetCurrentTime();
                reprintBoard = 1;
            }

            //Reprint the current game state to the console
            if(reprintBoard)
            {
                printBoard(board);
            }

            //Reset the reprint flag
            reprintBoard = 0;

            //Check if a key was pressed
            if(kbhit())
            {
                key = getch();
                if(key == 224)
                {
                    key = getch();
                    reprintBoard = 1;
                }

                switch(key)
                {
                    //Place a stone, when the <Enter> key was pressed
                    case 13:
                        //Place a stone at the chosen location
                        board.field[board.selectedRow][board.selectedColumn] = board.currentPlayer;

                        //Set the next players turn
                        board = UpdateCurrentPlayer(board);
                    break;
                    //End the game, when the <End> key was pressed
                    case 79:
                        gameIsOngoing = 0;
                    break;
                    //Pause the game, when the 'p' key was pressed
                    case 112:
                        board.isPaused = 1;

                        //Print the board with the 'pause' annotation
                        printBoard(board);

                        //Pause the game and get the duration of the pause
                        int pauseDuration = PauseGame();

                        if(pauseDuration != -1)
                        {
                            board.pauseDuration += pauseDuration;
                        }
                        else
                        {
                            gameIsOngoing = 0;
                        }

                        board.isPaused = 0;
                    break;
                }

                key = 0;
            }
        }

        //Reset the menu option chosen by the player
        chosenMenuOption = 0;
    }

    return 0;
}
