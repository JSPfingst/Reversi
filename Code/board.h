#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

///
/// The Board struct represents the current game state and contains
/// all data that is required for the games core functionality.
///
struct Board
{
    /*
     * The field is 9x9 instead of 8x8, because we initially intended
     * to use a coordinate based user input. The additional line and column
     * where used to display A-H and 1-8, to show the user which coordinates
     * he'd need to input to place a stone in a certain field.
     */
    int field[9][9];
    //Indicates whether the second player is AI-controlled
    int isMultiplayer;
    //Indicates whether the board selection was updated
    int updated;
    //Indicates whether the player has quit the game
    int gameIsOngoing;
    //The player who is currently placing a stone
    int currentPlayer;
    //The score of player one and player 2
    int scorePlayer1, scorePlayer2;
    //The time at which the game was started
    int starttime;
    //The current time of the game
    int time;
    //Indicates whether the game is currently paused
    int isPaused;
    /*
     * The overall time that the game wasn't active
     * Includes both paused time and time at which the game was
     * inactive as a save file.
     */
    int pauseDuration;
    //The currently selected row and column of the field
    int selectedRow, selectedColumn;
    //Indicates wether the game was quit from the pause menu
    int isQuitGame;
};

int UpdateCurrentPlayer(struct Board *board);
void GenerateStartingBoard(struct Board *board, int isMultiplayer);
void CalculateScore(struct Board *board);
long GetCurrentTime();

#endif // BOARD_H_INCLUDED
