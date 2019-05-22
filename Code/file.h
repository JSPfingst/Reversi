#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

int SaveGame(struct Board *board);
int LoadGame(struct Board *board);
int GetSaveFileValue(char saveFileContent[], int *valueTarget, int index);

#endif // FILE_H_INCLUDED
