#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

///
/// The Board struct represents the current game state.
/// It contains the field, the score of each player, whose
/// turn it and how much time has passed.
///
struct Board
{
    int field[9][9];
    int currentPlayer;
    int scorePlayer1, scorePlayer2;
    int starttime;
    int time;
    int isPaused;
    int pauseDuration;
    int selectedRow, selectedColumn;
};

struct Board UpdateCurrentPlayer(struct Board board);
struct Board GenerateStartingBoard();
long GetCurrentTime();
int GetRowIndex(char row);
int PauseGame();

#endif // BOARD_H_INCLUDED
