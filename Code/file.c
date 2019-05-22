#include "board.h"
#include "file.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

///
/// Prompts the user for a file path and daves the current game state
/// to the specified file.
///
/// board: A pointer to the current game state of the game.
///
void SaveGame(struct Board *board)
{
    char filePath[256];

    //Prompt the user for a path
    PromptForFilePath(filePath);

    //Open the file
    FILE *saveFile = fopen(filePath, "w");

    if(saveFile == NULL)
    {
        return;
    }

    //Write the field to the save file
    for(int row = 0; row <= 8; row++)
    {
        for(int column = 0; column <= 8; column++)
        {
            fprintf(saveFile, "%i", board->field[row][column]);
        }
    }

    //Write the single value members to the save file
    fprintf(saveFile, "\n%i", board->currentPlayer);
    fprintf(saveFile, "\n%i", board->starttime);
    fprintf(saveFile, "\n%i", board->time);
    fprintf(saveFile, "\n%i", board->pauseDuration);
    fprintf(saveFile, "\n%i", board->selectedRow);
    fprintf(saveFile, "\n%i", board->selectedColumn);
    fprintf(saveFile, "\n");

    //Close the save file
    fclose(saveFile);
}

///
/// Prompts the user for a file path and loads the game state from
/// the specified file.
///
/// board: A pointer to the current game state of the game.
///
void LoadGame(struct Board *board)
{
    char filePath[256];
    char saveFileContent[256];
    int index = 0, indexValue;
    char c;

    PromptForFilePath(filePath);

    //Open the file
    FILE *saveFile = fopen(filePath, "r");

    if(saveFile == NULL)
    {
        board->gameIsOngoing = 0;
        return;
    }

    //Read all characters from the file
    while((c = getc(saveFile)) != EOF && index < 256)
    {
        saveFileContent[index] = c;
        index++;
    }

    //Construct the field from the save file
    index = 0;
    for(int row = 0; row <= 8; row++)
    {
        for(int column = 0; column <= 8; column++)
        {
            index = (row * 9) + column;
            indexValue = saveFileContent[index] - 48;
            if(indexValue >= 0 && indexValue < 4)
            {
                board->field[row][column] = indexValue;
            }
        }
    }

    //Iterate to the next newline character
    while(saveFileContent[index] != '\n')
    {
        index++;
    }
    //Set the index to the character after the newline character;
    index++;

    //Set the single value members of the structure
    index = GetSaveFileValue(saveFileContent, &board->currentPlayer, index);
    index = GetSaveFileValue(saveFileContent, &board->starttime, index);
    index = GetSaveFileValue(saveFileContent, &board->time, index);
    index = GetSaveFileValue(saveFileContent, &board->pauseDuration, index);
    index = GetSaveFileValue(saveFileContent, &board->selectedRow, index);
    index = GetSaveFileValue(saveFileContent, &board->selectedColumn, index);

    int currentTime = GetCurrentTime();
    board->pauseDuration += difftime(currentTime, board->time);
    board->time = currentTime;

    //Set fixed single value members of the structure
    board->updated = 1;
    board->gameIsOngoing = 1;
    board->isPaused = 0;

    //Score berechnen
    //board->scorePlayer1 = 2;
    //board->scorePlayer2 = 2;

    //Close the save file
    fclose(saveFile);
};

///
/// Extracts the value starting at 'index' from the save file content char[] and assigns it to
/// the 'valueTarget' parameter.
///
/// saveFileContent: A char[] with the entire content of the save file.
/// valueTarget: A pointer to the variable, that the extracted value should be assigned to.
/// index: The index of the first character of the value, that should be extracted.
///
/// returns: The index of the first digit of the next value.
///
int GetSaveFileValue(char saveFileContent[], int *valueTarget, int index)
{
    int initialIndex = index;
    char value[32];

    //Extract all digits of the value
    while(saveFileContent[index] != '\n')
    {
        value[index - initialIndex] = saveFileContent[index];
        index++;
    }
    //Terminate the value char[] with a NULL character
    value[index - initialIndex] = 0;

    //Assign the value to the value target
    *valueTarget = atoi(value);

    //Return the index of the character after the newline character
    return index + 1;
}
