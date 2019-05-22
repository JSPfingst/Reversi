#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

///
/// The Board struct represents the current game state.
/// It contains all data that is
///
struct Board
{
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
int GetRowIndex(char row);

#endif // BOARD_H_INCLUDED
