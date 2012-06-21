#include "xMap.h"

int awaitingPortal;
/*int tickCount;
CritSection CS;*/
DWORD WINAPI ChickenThread(LPVOID lpParameter)
{
    while (true)
    {
        SleepEx(20, true);

        if (!GameReady())
            continue;

        if (TestPlayerInTown(D2CLIENT_GetPlayerUnit()) && bBackToTown)
            bBackToTown = FALSE;

        ChickenLife();
    }
}

void ChickenLife()
{
    if (!bToggleChicken && !bToggleChickenHostile || awaitingPortal)
        return;

    UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
    if (!pPlayer)
        return;    

    int dwLevelNo = pPlayer->pPath->pRoom1->pRoom2->pLevel->dwLevelNo;
    //in in town <=> no chickan
    if (TestPlayerInTown(pPlayer))
        return;

    if (nChickenPing && *p_D2CLIENT_Ping > nChickenPing)
        if (bChickenToTown)
        {
            if (!bBackToTown)
                if (OpenPortal())
                {
                    bBackToTown = TRUE;
                    PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Too high ping, chickening to town!");
                    while (!TestPlayerInTown(pPlayer))
                        SleepEx(1, true);
                    return;
                }
                else
                {
                    ChickenQuit("ÿc4[xMap]ÿc0: ÿc1Too high ping and out of TP's, exiting game.");
                    return;
                }
        }
        else
        {
            ChickenQuit("ÿc4[xMap]ÿc0: ÿc1Too high ping, exiting game.");
            return;
        }
    //get curr life
    DWORD life = D2COMMON_GetUnitStat(pPlayer, 6, 0);
    if (!life)
        return;
    life >>= 8; // actual life
    //get maxlife
    DWORD maxlife = D2COMMON_GetUnitStat(D2CLIENT_GetPlayerUnit(), 7, 0);
    maxlife >>= 8; // actual maxlife
    
    if (bToggleChicken && (nChickenLife && life <= nChickenLife || nChickenLifePercent && life * 100 <= maxlife * nChickenLifePercent))
    {
        if (bChickenToTown)
        {
            if (OpenPortal())
            {
                bBackToTown = TRUE;
                PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Life below chicken threshold, chickening to town!");
                while (!TestPlayerInTown(pPlayer))
                    SleepEx(1, true);
                return;
            }
            else
            {
                ChickenQuit("ÿc4[xMap]ÿc0: ÿc1Life below chicken threshold and out of TP's, exiting game.");
                return;
            }
        }
        else
        {
            ChickenQuit("ÿc4[xMap]ÿc0: ÿc1Life below chicken threshold, exiting game.");
            return;
        }
    } 

    if (bToggleChickenHostile)
        for (RosterUnit* pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
        {
            if (pUnit->dwUnitId == pPlayer->dwUnitId)
                continue; //Continue loop if it is our RosterUnit

            if (TestPvpFlag(pUnit->dwUnitId, pPlayer->dwUnitId, 8))
            {
                if (bChickenToTownOnHostile)
                {
                    if (OpenPortal())
                    {
                        bBackToTown = TRUE;
                        PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Hostiled! Chickening to town!");
                        while(!TestPlayerInTown(pPlayer))
                            SleepEx(1, true);
                        return;
                    }
                    else
                    {
                        ChickenQuit("ÿc4[xMap]ÿc0: ÿc1Hostiled and out of TP's! Chickening!");
                        return;
                    }
                }
                else
                {
                    ChickenQuit("ÿc4[xMap]ÿc0: ÿc1Hostiled! Chickening!");
                    return;
                }

                return;
            }
        }
}

void ChickenQuit(char* quitInfo)
{
    if (GameReady())
    {
        PrintAtBottomLeft("%s", quitInfo);

        ExitGame_ASM();
    }    
}

void __declspec(naked) ExitGame_ASM()
{
    __asm
    {
        mov ebx, 6FB2AB00h;
        call ebx;
        ret;
    }
}

BOOL OpenPortal()
{
    UnitAny* pUnit = NULL;
    INT nQuantity = 0;
    BOOL bIsBook = FALSE;

    if (!GameReady() || TestPlayerInTown(D2CLIENT_GetPlayerUnit()))
        return FALSE;

    if (GetPlayerArea() == 136)
    {
        PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Warning! Failed to open portal! You are in Uber Tristram!");
        return FALSE;
    }

    pUnit = FindItem("tbk", STORAGE_INVENTORY);
    if (!pUnit || GetUnitStat(pUnit, STAT_AMMOQUANTITY) == 0)
        pUnit = FindItem("tsc", STORAGE_INVENTORY);
    else
        bIsBook = TRUE;

    if (!pUnit)
        pUnit = FindItem("tsc", STORAGE_BELT);

    if (!pUnit)
    {
        PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Warning! Failed to open portal! Out of TP's.");
        return FALSE;
    }

    UseItem(pUnit);

    if (bIsBook)
    {
        nQuantity =  GetUnitStat(pUnit, STAT_AMMOQUANTITY);

        if (nQuantity <= 5)
            PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Warning: %d TP's Left", nQuantity - 1);
    }

    return TRUE;
}