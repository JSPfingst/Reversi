#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

void OpenMainMenu();
void PrintMainMenu(int selectedItem);
void OpenPauseMenu(struct Board *board);
void PrintPauseMenu(int selectedItem);
void printBoard(struct Board *board);

#endif // OUTPUT_H_INCLUDED
