#include "board.h"
#include "input.h"
#include "output.h"
#include "file.h"
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
    int selectedItem = 0, key = 0, exitGame = 0;

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

        //If the <Enter> key was pressed, return the current selection
        if(key == 13)
        {
            switch(selectedItem)
            {
                //Create a new board and start the game
                case 0:
                    GenerateStartingBoard(&board);
                    StartGame(&board);
                break;
                //Load a board from a specified save file and start the game
                case 1:
                    LoadGame(&board);
                    StartGame(&board);
                break;
                //Set the flag to close the application
                case 2:
                    exitGame = 1;
                break;
            }

            //Reset the key and set the reprint flag
            key = 0;
            reprintMenu = 1;
        }

        //Reprint the menu, if the reprint flag is set
        if(reprintMenu)
        {
            PrintMainMenu(selectedItem);
        }

        //Reset the reprint flag
        reprintMenu = 0;
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
        printf(" > Spiel starten <\n");
    }
    else
    {
        printf("   Spiel starten\n");
    }

    if(selectedItem == 1)
    {
        printf(" > Spiel laden \x20\x20<\n");
    }
    else
    {
        printf("   Spiel laden\n");
    }

    if(selectedItem == 2)
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
    int selectedItem = 0, reprintMenu = 1, pauseDuration = 0, key = 0;

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

            reprintMenu = 0;
        }

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
                    SaveGame(board);

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
                break;
            }
        }
    }

    pauseDuration = difftime(pauseEnd, pauseStart);

    if(pauseDuration != -1)
    {
        board->pauseDuration += pauseDuration;
    }
    else
    {
        board->gameIsOngoing = 0;
    }
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
    printf("   Reversi - Pausiert\n");
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
        printf(" > Zurueck zum Hauptmenue <\n");
    }
    else
    {
        printf("   Zurueck zum Hauptmenue\n");
    }
}

///
/// Prints the current game state to the console.
///
/// board: A pointer to the game state structure of the game.
///
void printBoard(struct Board *board)
{
    char field[5];
    field[3] = '|';
    field[4] = 0;

    system("cls");

    printf(" Current Player: %i\n", board->currentPlayer);
    printf(" Time: %i\n", (int)difftime(board->time, board->starttime) - board->pauseDuration);
    printf("\n");

    /*
     * The starting point of the Reversi board is on the bottom left,
     * therefore the rows are iterated decrementally.
     */
    for(int row = 8; row >= 0; row--)
    {
        for(int column = 0; column <= 8; column++)
        {
            if(row == board->selectedRow && column == board->selectedColumn)
            {
                field[0] = '>';
                field[2] = '<';
            }
            else
            {
                field[0] = ' ';
                field[2] = ' ';
            }

            switch(board->field[row][column])
            {
                //0: The position is empty.
                case 0:
                    field[1] = ' ';
                break;
                //1: Player 1 has a stone at this position.
                case 1:
                    field[1] = 177;
                break;
                //2: Player 2 has a stone at this position.
                case 2:
                    field[1] = 219;
                break;
                //3: The position is one of the label positions.
                case 3:
                    if(row == 0)
                    {
                        if(column != 0)
                        {
                            //Print the number for this label
                            field[1] = (char)(column + 48);
                        }
                        else
                        {
                            //Empty field
                            field[1] = ' ';
                        }
                    }
                    else
                    {
                        //Print the character for this label
                        field[1] = (char)(row + 64);
                    }
                break;
            }

            printf("%s", field);
        }

        printf("\n");
    }
}
