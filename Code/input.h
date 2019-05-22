#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int HandleMainMenuInput(int key, int *selectedItem);
int HandlePauseMenuInput(int key, int *selectedItem);
void HandleGameInput(struct Board *board);
void PromptForFilePath(char filePath[]);

#endif // INPUT_H_INCLUDED
