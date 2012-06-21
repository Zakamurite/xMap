#include "xMap.h"

#define M_PI 3.14159265358979323846

/* GameDrawAutomapInfo_STUB
 * Created By: Sheppard
 */
void __declspec(naked) GameDrawAutomapInfo_STUB()
{
    __asm
    {
        push eax;
        call DrawAutomapInfos;
        pop eax;
        pop edi;
        pop esi;
        ret;
    }
} 

/* GameDraw_STUB ()
 * Created By: Sheppard
 */
void __declspec(naked) GameDraw_STUB()
{
    __asm
    {
        call GameDraw;
        POP ESI
        POP EBX
        POP ECX
        RETN 4
    }
} 

/* DrawAutomapInfos ()
 *This holds all the screenhooks we are going to draw when 
 * it gets called by the Stub Above.
 */
void DrawAutomapInfos(void)
{
    if (bShowActiveRooms)
        DrawActiveRooms();
    DrawAutomapText ();
    DrawShrines();
}

void DrawShrines()
{
    UnitAny* pUnit = D2CLIENT_GetPlayerUnit();
    for (int i = 0; i < cMap->m_Shrines.GetSize(); ++i)
    {
        if (cMap->m_Shrines[i]->nAct != pUnit->dwAct)
            continue;

        if (cShrineBlobCells[cMap->m_Shrines[i]->ID])
            myDrawAutomapCell(cShrineBlobCells[cMap->m_Shrines[i]->ID], 
                cMap->m_Shrines[i]->nX, cMap->m_Shrines[i]->nY, 1, TRUE);
        else if (cShrineBlobCells[23])
            myDrawAutomapCell(cShrineBlobCells[23], 
                cMap->m_Shrines[i]->nX, cMap->m_Shrines[i]->nY, 1, TRUE);
    }
}

void GameDraw(void)
{
    TextHook(320, 588, 0x08, false, 8, 1, "xMap v2.0");

    if (bShowPercents)
        DrawPercents();

    if (D2CLIENT_GetUiVar(2) && (D2COMMON_GetQuestFlag(D2CLIENT_GetQuestInfo(), 4, 10)))
        TextHook(90, 450, 0, false, 0, -1, "ÿc1*ÿc0King Killedÿc1*");
    if (D2CLIENT_GetUiVar(2))
        TextHook(90, 438, 0, false, 0, -1, "Magic Find: %i", GetPlayerStat(80, 0));
    if (bShowStats)
        ShowStats(D2CLIENT_GetPlayerUnit());
    if (uViewingUnit)
        ShowStats(uViewingUnit);

    UnitAny* pUnit = D2CLIENT_GetSelectedUnit();

    if (pUnit && bShowMonsterBarResists && pUnit->dwType == UNIT_MONSTER /*&& IsValidMonster(pUnit)*/)
    {
        if (PlainScreen())
        {
            TextHook(400, 71, 0, false, 8, 1, "%s", GetMonsterResists(pUnit).c_str());        
            //TextHook(400, 81, 0, false, 8, 1, "LVL:%d TC:%d", GetMonsterLvl(pUnit), GetMonsterTC(pUnit));        
        }
    }

    if (bShowTPsLeft)
    {
        int numTps = GetNumberOfTPs();
        if (numTps != -1)
            //TextHook(320, 588, numTps > 5 ? 0 : 1, false, 8, 1, "TPs left: %d", numTps);
            TextHook(625, 550, numTps > 5 ? 0 : 1, false, 8, 1, "TPs Left: %d", numTps);
    }

    CheckD2WinEditBox();
}

/* TextHook(xPos, yPos, dwColor, Text, ...)
 * This is a text hook function that converts the text
 * to wide character, changes the font, prints, then changes font back.
 * -- Taken from http://www.edgeofnowhere.cc/viewtopic.php?t=390854
 */
void TextHook(INT xPos, INT yPos, DWORD dwColor, BOOL Automap, INT dwFont, INT dwCenter, LPSTR Text,...)
{
    // Setup a point variable
    POINT nPos = { xPos, yPos };
    DWORD dwOldSize, wWidth, dwFileNo;

    //Check if we are drawing this on Automap
    if (Automap)
    {
        if (!p_D2CLIENT_AutomapOn)
            return;
        ScreenToAutomap(&nPos, xPos * 32, yPos * 32);
    }

    CHAR szBuffer[800] = "";
    va_list Args;
    va_start(Args, Text);
    vsprintf_s(szBuffer, Text, Args);
    va_end(Args);

    wchar_t wBuffer[0x130];
    MyMultiByteToWideChar(nCharTable, 1, szBuffer, 100, wBuffer, 100);
    
    dwOldSize = D2WIN_SetTextSize(dwFont);
    if (dwCenter != -1)
    {
        D2WIN_GetTextWidthFileNo(wBuffer, &wWidth, &dwFileNo);
        nPos.x -= (wWidth >> dwCenter);
    }
    
    D2WIN_DrawText (wBuffer,nPos.x, nPos.y, dwColor, -1);
    D2WIN_SetTextSize(dwOldSize);
} 

/*BoxHook(x, y, xSize, ySize, dwColor, Trans)
 * A simple box hook function which calls D2GFX_DrawRectangle
 * Example: BoxHook(100, 100, 50, 50, 1, 1); //Makes a 50 by 50 box at X: 100, Y:100
 */
void BoxHook(INT x, INT y, INT xSize, INT ySize, DWORD dwColor, DWORD Trans, BOOL Automap)
{
    POINT Start = {x, y};
    POINT End = {xSize, ySize};
    if (Automap)
    {
        if (!p_D2CLIENT_AutomapOn)
            return;
        ScreenToAutomap(&Start, x * 32, y * 32);
    }

    return D2GFX_DrawRectangle(Start.x, Start.y, End.x + Start.x, End.y + Start.y, dwColor, Trans);
}

/* LineHook(x, y, xPos, yPos, dwColor)
 * A simple line hook function which calls D2GFX_DrawLine
 * Example: LineHook(100, 100, 150, 150, 1); //Draws a Line hook from 100,100 to 150,150 and colors it with red.
 */
void LineHook(INT x, INT y, INT xPos, INT yPos, DWORD dwColor, BOOL Automap)
{
    POINT Start = {x, y};
    POINT End = {xPos, yPos};
    if (Automap)
    {
        if (!p_D2CLIENT_AutomapOn)
            return;
        ScreenToAutomap(&Start, x * 32, y * 32);
        ScreenToAutomap(&End, xPos * 32, yPos * 32);
    }

    return D2GFX_DrawLine(Start.x, Start.y, End.x, End.y, dwColor, 0);
}

VOID ScreenToAutomap(POINT *ptPos, int x, int y)
{
    ptPos->x = (x - y) / (*p_D2CLIENT_Divisor) / 2 -(*p_D2CLIENT_Offset).x + 8;
    ptPos->y = (x + y) / (*p_D2CLIENT_Divisor) / 4 -(*p_D2CLIENT_Offset).y - 8;
    if (D2CLIENT_GetAutomapSize())
    {
        --ptPos->x;
        ptPos->y += 5;
    }
}

VOID ScreenToAutomap(int &x1, int &y1, int x, int y)
{
    x1 = (x - y) / (*p_D2CLIENT_Divisor) / 2 - (*p_D2CLIENT_Offset).x + 8;
    y1 = (x + y) / (*p_D2CLIENT_Divisor) / 4 - (*p_D2CLIENT_Offset).y - 8;
    if (D2CLIENT_GetAutomapSize())
    {
        --x1;
        y1 += 5;
    }
}

VOID AutomapToScreen(POINT *ptPos, int x, int y)
{
    if (D2CLIENT_GetAutomapSize())
    {
        ++ptPos->x;
        ptPos->y -= 5;
    }

    ptPos->x = 1.0 / 2 * (2 * *p_D2CLIENT_Divisor * (x + (*p_D2CLIENT_Offset).x - 8) + 4 * *p_D2CLIENT_Divisor * (y + (*p_D2CLIENT_Offset).y + 8));
    ptPos->y = 1.0 / 2 * (4 * *p_D2CLIENT_Divisor * (y + (*p_D2CLIENT_Offset).y + 8) - 2 * *p_D2CLIENT_Divisor * (x + (*p_D2CLIENT_Offset).x - 8));

    ptPos->x /= 32;
    ptPos->y /= 32;
}

VOID DrawCross(INT nX, INT nY, DWORD dwColor, BOOL Automap)
{
    POINT nPos = { nX, nY };
    if (Automap)
    {
        if (!p_D2CLIENT_AutomapOn)
            return;
        ScreenToAutomap(&nPos, nX * 32, nY * 32);
    }

    CHAR szLines[][2] = { 0,-2, 4,-4, 8,-2, 4,0, 8,2, 4,4, 0,2, -4,4, -8,2, -4,0, -8,-2, -4,-4, 0,-2 };
    for (INT x = 0; x < ArraySize(szLines) - 1; ++x)
        D2GFX_DrawLine(nPos.x + szLines[x][0], nPos.y + szLines[x][1], nPos.x + szLines[x+1][0], nPos.y + szLines[x+1][1], dwColor, -1);
}

VOID SexyRectangle(int x, int y, int xsize, int ysize)
{
    RECT pRect;
    pRect.left = x;
    pRect.top = y;
    pRect.right = xsize + x;
    pRect.bottom = ysize + y;
    //BoxHook(x, y, xsize, ysize, 0x00, 4, false);
    BoxHook(x, y, xsize, ysize, 0x00, 1, false);
    D2DrawRectFrame_STUB(&pRect);
}

VOID DrawPercents()
{
    UnitAny* pUnit = D2CLIENT_GetPlayerUnit ();

    int nLifePercent = abs((float)((double)(D2COMMON_GetUnitStat(pUnit, 6, 0) >> 8) / (double)(D2COMMON_GetUnitStat(pUnit, 7, 0) >> 8)) * 100);
    int nManaPercent = abs((float)((double)(D2COMMON_GetUnitStat(pUnit, 8, 0) >> 8) / (double)(D2COMMON_GetUnitStat(pUnit, 9, 0) >> 8)) * 100);

    SexyRectangle(53, 523, 36, 19);
    SexyRectangle(713, 523, 36, 19);
    TextHook(67, 540, 1, false, 1, 1, "%i", nLifePercent);
    TextHook(727, 540, 3, false, 1, 1, "%i", nManaPercent);
}

VOID ShowStats (UnitAny* pUnit)
{
    if (!pUnit)
        return;

    BnetData *pData = *p_D2LAUNCH_BnData;
    if (!pData)
        return;

    int nNegRes[3] = { 0, -40, -100 };
    int yPos = 10;
    SexyRectangle(10, 10, 200, 503);
    TextHook(105, yPos += 16, 0, false, 1, 1, "Character Stats");
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Name:ÿc0 %s", pUnit->pPlayerData->szName);
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Level:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 12, 0));
    if (pUnit == D2CLIENT_GetPlayerUnit())
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc4Experience:ÿc0 %u", (unsigned int)D2COMMON_GetUnitStat(pUnit, 13, 0));
    yPos+=16;

    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Strength: ÿc0%i+%i=%i", D2COMMON_GetBaseStat(pUnit, STAT_STRENGTH, 0), D2COMMON_GetUnitStat(pUnit, STAT_STRENGTH, 0) - D2COMMON_GetBaseStat(pUnit, STAT_STRENGTH, 0), D2COMMON_GetUnitStat(pUnit, STAT_STRENGTH, 0)); //str
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Dexterity: ÿc0%i+%i=%i", D2COMMON_GetBaseStat(pUnit, STAT_DEXTERITY, 0), D2COMMON_GetUnitStat(pUnit, STAT_DEXTERITY, 0) - D2COMMON_GetBaseStat(pUnit, STAT_DEXTERITY, 0), D2COMMON_GetUnitStat(pUnit, STAT_DEXTERITY, 0)); //dex
    if (pUnit == D2CLIENT_GetPlayerUnit())
    {
        TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Vitality: ÿc0%i+%i=%i", D2COMMON_GetBaseStat(pUnit, STAT_VITALITY, 0), D2COMMON_GetUnitStat(pUnit, STAT_VITALITY, 0) - D2COMMON_GetBaseStat(pUnit, STAT_VITALITY, 0), D2COMMON_GetUnitStat(pUnit, STAT_VITALITY, 0)); //vita
        TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Energy: ÿc0%i+%i=%i", D2COMMON_GetBaseStat(pUnit, STAT_ENERGY, 0), D2COMMON_GetUnitStat(pUnit, STAT_ENERGY, 0) - D2COMMON_GetBaseStat(pUnit, STAT_ENERGY, 0), D2COMMON_GetUnitStat(pUnit, STAT_ENERGY, 0)); //nrg

        yPos += 16;
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc1Fire Resist:ÿc0 %i - %i = %i / %i", D2COMMON_GetUnitStat(pUnit, 39, 0), abs(nNegRes[D2CLIENT_GetDifficulty()]), D2COMMON_GetUnitStat(pUnit, 39, 0) + nNegRes[pData->nDifficulty], D2COMMON_GetUnitStat(pUnit, 40,0) + 75);
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc3Cold Resist:ÿc0 %i - %i = %i / %i", D2COMMON_GetUnitStat(pUnit, 43, 0), abs(nNegRes[D2CLIENT_GetDifficulty()]), D2COMMON_GetUnitStat(pUnit, 43, 0) + nNegRes[pData->nDifficulty], D2COMMON_GetUnitStat(pUnit, 44,0) + 75);
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc9Light Resist:ÿc0 %i - %i = %i / %i", D2COMMON_GetUnitStat(pUnit, 41, 0), abs(nNegRes[D2CLIENT_GetDifficulty()]), D2COMMON_GetUnitStat(pUnit, 41, 0) + nNegRes[pData->nDifficulty], D2COMMON_GetUnitStat(pUnit, 42,0) + 75);
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc2Poison Resist:ÿc0 %i - %i = %i / %i", D2COMMON_GetUnitStat(pUnit, 45, 0), abs(nNegRes[D2CLIENT_GetDifficulty()]), D2COMMON_GetUnitStat(pUnit, 45, 0) + nNegRes[pData->nDifficulty], D2COMMON_GetUnitStat(pUnit, 46,0) + 75);
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc8Magic Resist:ÿc0 %i - %i = %i / %i", D2COMMON_GetUnitStat(pUnit, 37, 0), abs(nNegRes[D2CLIENT_GetDifficulty()]), D2COMMON_GetUnitStat(pUnit, 37, 0) + nNegRes[pData->nDifficulty], D2COMMON_GetUnitStat(pUnit, 38,0) + 75);
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc7Damage Resist:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 36, 0));
        TextHook(15, (yPos += 16), 0, false, 6, -1, "ÿc4Absorb Percents: ÿc1%i%%ÿc0/ÿc3%i%%ÿc0/ÿc9%i%%ÿc0/ÿc8%i%%", D2COMMON_GetUnitStat(pUnit, 142, 0), D2COMMON_GetUnitStat(pUnit, 148, 0), D2COMMON_GetUnitStat(pUnit, 144, 0), D2COMMON_GetUnitStat(pUnit, 146, 0));
    }

    yPos += 16;
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Magic Find:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 80, 0));
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Gold Find:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 79, 0));
    yPos += 16;
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Faster Cast Rate:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 105, 0));
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Faster Hit Recovery:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 99, 0));
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Increased Attack Speed:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 93, 0));
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Faster Block Rate:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 102, 0));
    TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc4Faster Run/Walk:ÿc0 %i", D2COMMON_GetUnitStat(pUnit, 96, 0));

    if (pUnit == D2CLIENT_GetPlayerUnit())
    {
        yPos += 16;
        TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc1Chicken Toggle:ÿc0 %s", bToggleChicken ? "true" : "false");
        TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc1Chicken Hostile Toggle:ÿc0 %s", bToggleChickenHostile ? "true" : "false");
        if (bToggleChicken)
        {
            TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc1Chicken Life:ÿc0 %i", nChickenLife);
            TextHook(15, yPos += 16, 0, false, 6, -1, "ÿc1Chicken Life Percent:ÿc0 %i", nChickenLifePercent);
        }
    }
}