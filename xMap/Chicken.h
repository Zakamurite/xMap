#ifndef _CHICKEN_H
#define _CHICKEN_H

DWORD WINAPI ChickenThread(LPVOID lpParameter);

void ChickenLife();
void ChickenQuit(char* quitInfo);
void ExitGame_ASM();
BOOL OpenPortal();

#endif