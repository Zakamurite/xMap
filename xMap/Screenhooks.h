
#ifndef _STUBS_H
#define _STUBS_H

void GameDrawAutomapInfo_STUB();
void DrawAutomapInfos(void);
void GameDraw_STUB();
void GameDraw(void);
//VOID DrawExactLife ();
VOID DrawPercents ();
void TextHook(INT xPos, INT yPos, DWORD dwColor, BOOL Automap, INT dwFont, BOOL dwCenter, LPSTR Text,...);
void BoxHook(INT x, INT y, INT xSize, INT ySize, DWORD dwColor, DWORD Trans, BOOL Automap);
void LineHook(INT x, INT y, INT xPos, INT yPos, DWORD dwColor, BOOL Automap);
VOID ScreenToAutomap(POINT *ptPos, int x, int y);
VOID ScreenToAutomap(int &x1, int &y1, int x, int y);
VOID AutomapToScreen(POINT *ptPos, int x, int y);
VOID SexyRectangle(int left, int right, int top, int bottom);
VOID DrawCross(INT nX, INT nY, DWORD dwColor, BOOL Automap);
VOID ShowStats(UnitAny* pUnit);
void DrawShrines();

#endif