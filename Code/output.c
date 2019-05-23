/**
File which handles all operations regarding the output of the menus and the gameboard
**/
#include "board.h"
#include "input.h"
#include "output.h"
#include "file.h"
#include "gameflow.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

///
/// Opens the arrow key navigable main menu to the console
/// and lets the user choose to start a new game load a
/// game from a save file or to exit the game.
///
/// returns: The choice of the player.
///
void OpenMainMenu()
{
    struct Board board;
    int selectedItem = 0, key = 0, exitGame = 0, loadResult = 0, printLoadErrorMessage = 0;

    /*
     * Flag to reprint the menu to the console.
     * Default value is 1 to print the menu during the first run.
     */
    int reprintMenu = 1;

    /*
     * Endless loop, to simplify the maneuverability of the menu. =>
     * No redundant condition required.
     */
    while(exitGame != 1)
    {
        //Check if a key was pressed
        if(kbhit())
        {
            key = getch();
            if(key == 224)
            {
                key = getch();
            }

            reprintMenu = HandleMainMenuInput(key, &selectedItem);
        }

        //Reprint the menu, if the reprint flag is set
        if(reprintMenu)
        {
            PrintMainMenu(selectedItem);

            //Reset the reprint flag
            reprintMenu = 0;

            if(printLoadErrorMessage)
            {
                printf("\n");
                printf(" Der eingegebene Pfad konnte nicht gefunden werden. Dr%ccken Sie <Enter> zum Fortfahren.", '\x81');
                fflush(stdin);

                //Wait for the <Enter> key to be pressed
                while(getch() != 13) { }
                printLoadErrorMessage = 0;

                //Set the flag to reprint the menu without the error message
                reprintMenu = 1;
            }
        }

        //Check if the <Enter> key was pressed
        if(key == 13)
        {
            switch(selectedItem)
            {
                //Create a new board and start a game against the AI
                case 0:
                    GenerateStartingBoard(&board, 0);
                    StartGame(&board);
                break;
                //Create a new board and start a game with two players
                case 1:
                    GenerateStartingBoard(&board, 1);
                    StartGame(&board);
                break;
                //Load a board from a specified save file and start the game
                case 2:
                    loadResult = LoadGame(&board);
                    if(loadResult == 1)
                    {
                        StartGame(&board);
                    }
                    else if(loadResult == -1)
                    {
                        printLoadErrorMessage = 1;
                    }
                break;
                //Set the flag to close the application
                case 3:
                    exitGame = 1;
                break;
            }

            //Reset the key and set the reprint flag
            key = 0;
            reprintMenu = 1;
        }
    }
}

///
/// Prints the main menu to the console.
///
/// selectedItem: The menu item, that is currently selected.
///
void PrintMainMenu(int selectedItem)
{
    system("cls");

    printf("\n");
    printf("   Reversi\n");
    printf("\n");

    if(selectedItem == 0)
    {
        printf(" > Einzelspieler <\n");
    }
    else
    {
        printf("   Einzelspieler\n");
    }

    if(selectedItem == 1)
    {
        printf(" > Mehrspieler\x20\x20 <\n");
    }
    else
    {
        printf("   Mehrspieler\x20\x20\n");
    }

    if(selectedItem == 2)
    {
        printf(" > Spiel laden\x20\x20 <\n");
    }
    else
    {
        printf("   Spiel laden\x20\x20\n");
    }

    if(selectedItem == 3)
    {
        printf(" > Spiel beenden <\n");
    }
    else
    {
        printf("   Spiel beenden\n");
    }
}

///
/// Opens the arrow key navigable pause menu to the console and lets
/// the user continue, save or end the game.
/// While the pause menu is open, the timer of the current game is halted.
///
/// board: A pointer to the game state structure of the game.
///
void OpenPauseMenu(struct Board *board)
{
    time_t pauseStart = time(&pauseStart), pauseEnd = 0;
    int selectedItem = 0, reprintMenu = 1, printSaveErrorMessage = 0, pauseDuration = 0, key = 0, saveResult = 0;

    while(pauseEnd == 0)
    {
        if(kbhit())
        {
            //Get the ASCII code of the pressed key
            key = getch();
            //Get the second code, if the first was a function code
            if(key == 224)
            {
                key = getch();
            }

            reprintMenu = HandlePauseMenuInput(key, &selectedItem);
        }

        if(reprintMenu)
        {
            PrintPauseMenu(selectedItem);

            //Reset the reprint flag
            reprintMenu = 0;

            if(printSaveErrorMessage)
            {
                printf("\n");
                printf(" Der eingegebene Pfad konnte nicht gefunden werden. Dr%ccken Sie <Enter> zum Fortfahren.", '\x81');
                fflush(stdin);

                //Wait for the <Enter> key to be pressed
                while(getch() != 13) { }
                printSaveErrorMessage = 0;

                //Set the flag to reprint the menu without the error message.
                reprintMenu = 1;
            }
        }

        //Check if the <Enter> key was pressed
        if(key == 13)
        {
            switch(selectedItem)
            {
                //Continue the game
                case 0:
                    pauseEnd = time(&pauseEnd);
                break;
                //Save the game
                case 1:
                    saveResult = SaveGame(board);
                    if(saveResult == -1)
                    {
                        //Set the flag to signal, that an error occured while saving the game
                        printSaveErrorMessage = 1;
                    }

                    /*
                     * Reset the key and set the reprint flag,
                     * so the user returns to the pause menu.
                     */
                    reprintMenu = 1;
                    key = 0;
                break;
                //Set the flag to return to the main menu
                case 2:
                    pauseEnd = time(&pauseEnd);
                    board->gameIsOngoing = 0;
                    board->isQuitGame = 1;
                break;
            }
        }
    }

    pauseDuration = difftime(pauseEnd, pauseStart);

    board->pauseDuration += pauseDuration;
}

///
/// Prints the pause menu to the console.
///
/// selectedItem: The menu item, that is currently selected.
///
void PrintPauseMenu(int selectedItem)
{
    system("cls");

    printf("\n");
    printf("   Pause\n");
    printf("\n");

    if(selectedItem == 0)
    {
        printf(" > Spiel fortsetzen <\n");
    }
    else
    {
        printf("   Spiel fortsetzen\n");
    }

    if(selectedItem == 1)
    {
        printf(" > Spiel speichern <\n");
    }
    else
    {
        printf("   Spiel speichern\n");
    }

    if(selectedItem == 2)
    {
        printf(" > Zur%cck zum Hauptmen\x81 <\n", '\x81');
    }
    else
    {
        printf("   Zur%cck zum Hauptmen\x81\n", '\x81');
    }
}

///
/// Prints the current game state to the console.
///
/// board: A pointer to the game state structure of the game.
///
void printBoard(struct Board *board)
{
    char playerChar = 0;
    if(board->currentPlayer == 1)
    {
        playerChar = 219;
    }
    else
    {
        playerChar = 177;
    }

    char cell[5];

    system("cls");

    printf("\n");
    printf(" Verwenden Sie die Pfeiltasten, um ein Feld auszuw\x84hlen und dr%ccken Sie <Enter>\n", '\x81');
    printf(" um in dem Feld einen Stein Ihrer Farbe zu platzieren\n");
    printf("\n");
    printf(" Am Zug ist derzeit: Spieler %i %c\n", board->currentPlayer, playerChar);
    printf(" Steine Spieler 1 %c: %i\n", 219, board->scorePlayer1);
    printf(" Steine Spieler 2 %c: %i\n", 177, board->scorePlayer2);
    printf(" Vergangene Zeit: %i | Dr%ccken Sie 'p' um das Spiel zu pausieren\n", (int)difftime(board->time, board->starttime) - board->pauseDuration, '\x81');
    printf("\n");

    //Print the field to the console.
    for(int row = 1; row <= 17; row++)
    {
        if(row%2 == 0)
        {
            //Print the beginning of this line
            printf(" %c", 186);
            cell[3] = 186;

            //Print the all cells
            for(int column = 1; column <= 8; column++)
            {
                if(row / 2 == board->selectedRow && column == board->selectedColumn)
                {
                    //Highlighted cell
                    cell[0] = '>';
                    cell[2] = '<';
                }
                else
                {
                    //Normal cell
                    cell[0] = ' ';
                    cell[2] = ' ';
                }

                switch(board->field[row / 2][column])
                {
                    //0: The position is empty.
                    case 0:
                        cell[1] = ' ';
                    break;
                    //1: Player 1 has a stone at this position.
                    case 1:
                        cell[1] = 219;
                    break;
                    //2: Player 2 has a stone at this position.
                    case 2:
                        cell[1] = 177;
                    break;
                }

                //Print the cell to the console
                printf("%s", cell);
            }
        }
        else
        {
            //Default
            cell[0] = 205;
            cell[1] = 205;
            cell[2] = 205;
            cell[4] = 0;

            switch(row)
            {
                //First row
                case 1:
                    //Print the beginning of this line
                    printf(" %c", 201);

                    cell[3] = 203;

                    for(int column = 1; column <= 7; column++)
                    {
                        printf("%s", cell);
                    }

                    //Last column
                    cell[3] = 187;
                    printf("%s", cell);
                break;
                //Last row
                case 17:
                    //Print the beginning of this line
                    printf(" %c", 200);

                    cell[3] = 202;

                    for(int column = 1; column <= 7; column++)
                    {
                        printf("%s", cell);
                    }

                    //Last column
                    cell[3] = 188;
                    printf("%s", cell);
                break;
                default:
                    //Print the beginning of this line
                    printf(" %c", 204);

                    cell[3] = 206;

                    for(int column = 1; column <= 7; column++)
                    {
                        printf("%s", cell);
                    }

                    //Last column
                    cell[3] = 185;
                    printf("%s", cell);
                break;
            }
        }

        printf("\n");
    }
}
