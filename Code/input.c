#include "board.h"
#include "output.h"
#include "gamelogic.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

///
/// Handles keyboard input in the main menu.
///
/// selectedItem: A pointer to the index of the currently selected menu item.
///
/// returns: 1 if the output needs to be reprinted, 0 if not.
///
int HandleMainMenuInput(int key, int *selectedItem)
{
    int reprintMenu = 0;

    switch(key)
    {
        //Navigate up
        case 72:
            if(*selectedItem > 0)
            {
                *selectedItem -= 1;

                //Set the reprint flag
                reprintMenu = 1;
            }
        break;
        //Navigate down
        case 80:
            if(*selectedItem < 3)
            {
                *selectedItem += 1;

                //Set the reprint flag
                reprintMenu = 1;
            }
        break;
    }

    return reprintMenu;
}

///
/// Handles keyboard input in the pause menu.
///
/// key: The key that was pressed.
/// selectedItem: A pointer to the index of the currently selected menu item.
///
/// returns: 1 if the output needs to be reprinted, 0 if not.
///
int HandlePauseMenuInput(int key, int *selectedItem)
{
    int reprintMenu = 0;

    switch(key)
    {
        //Navigate up
        case 72:
            if(*selectedItem > 0)
            {
                *selectedItem -= 1;
            }

            reprintMenu = 1;
        break;
        //Navigate down
        case 80:
            if(*selectedItem < 2)
            {
                *selectedItem += 1;
            }

            //Set the reprint flag
            reprintMenu = 1;
        break;
    }

    return reprintMenu;
}

///
/// This method determines which key was pressed and executes
/// specific logic depending on the pressed key.
///
/// board: A pointer to the game state structure of the game.
///
void HandleGameInput(struct Board *board)
{
    //Get the ASCII code of the pressed key
    int key = getch();
    //Get the second code, if the first was a function code
    if(key == 224)
    {
        key = getch();
    }

    switch(key)
    {
        //Navigate up
        case 72:
            if(board->selectedRow > 1)
            {
                //Update the selected field
                board->selectedRow -= 1;

                //Set the flag to reprint the board to the console
                board->updated = 1;
            }
        break;
        //Navigate down
        case 80:
            if(board->selectedRow < 8)
            {
                //Update the selected field
                board->selectedRow += 1;

                //Set the flag to reprint the board to the console
                board->updated = 1;
            }
        break;
        //Navigate right
        case 77:
            if(board->selectedColumn < 8)
            {
                //Update the selected field
                board->selectedColumn += 1;

                //Set the flag to reprint the board to the console
                board->updated = 1;
            }
        break;
        //Navigate left
        case 75:
            if(board->selectedColumn > 1)
            {
                //Update the selected field
                board->selectedColumn -= 1;

                //Set the flag to reprint the board to the console
                board->updated = 1;
            }
        break;
        //Place a stone, when the <Enter> key was pressed
        case 13:
            //Run the game logic
            *board = CheckIfValidTurn(*board, board->selectedRow, board->selectedColumn);

            //Recalculate the current score
            CalculateScore(board);

            //Set the flag to reprint the board to the console
            board->updated = 1;
        break;
        //Open the pause menu, when the 'p' key was pressed
        case 112:
            OpenPauseMenu(board);
        break;
    }
}

///
/// Prompt the user to input a path on the file system to load or save a file.
///
/// filePath: A pointer to the char[], the path will be saved to.
///
void PromptForFilePath(char filePath[])
{
    printf("\n");
    printf("Geben Sie den Dateipfad ein (Beispiel: 'C:\\save.txt', geben Sie 'cancel' zum Abbrechen ein): ");
    scanf("%s", filePath);
}
