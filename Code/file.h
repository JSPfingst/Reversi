#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

void SaveGame(struct Board *board);
void LoadGame(struct Board *board);
int GetSaveFileValue(char saveFileContent[], int *valueTarget, int index);

#endif // FILE_H_INCLUDED
