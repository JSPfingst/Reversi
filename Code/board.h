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
    int updated;
    int gameIsOngoing;
    int currentPlayer;
    int scorePlayer1, scorePlayer2;
    int starttime;
    int time;
    int isPaused;
    int pauseDuration;
    int selectedRow, selectedColumn;
};

void UpdateCurrentPlayer(struct Board *board);
void GenerateStartingBoard(struct Board *board);
long GetCurrentTime();

#endif // BOARD_H_INCLUDED
