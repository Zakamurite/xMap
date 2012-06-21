#include "xMap.h"

BOOL ExecuteEnchantQueue(LPENCHANTINFO EnchInfo)
{
    if (!GameReady() || !EnchInfo)
        return FALSE;

    UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
    if (EnchInfo->dwPlayerId == pPlayer->dwUnitId)
        return FALSE;

    
    if (EnchInfo->nEnchantType == ENCHANT_ME)
    {
        for(Room1* pRoom1 = pPlayer->pAct->pRoom1; pRoom1; pRoom1 = pRoom1->pRoomNext)
            for (UnitAny* pUnit = pRoom1->pFirstUnit; pUnit; pUnit = pUnit->pListNext)
                if (pUnit->dwType == UNIT_PLAYER && pUnit->dwUnitId == EnchInfo->dwPlayerId)
                {
                    CastOnUnit(D2S_ENCHANT, pUnit, FALSE);
                    return TRUE;
                }
        
        if (!bSilentBots)
            Say("You're out of range!");

        return FALSE;
    }

    if(EnchInfo->nEnchantType == ENCHANT_MERC)
    {
        for (Room1* pRoom1 = pPlayer->pAct->pRoom1; pRoom1; pRoom1 = pRoom1->pRoomNext)
            for (UnitAny* pUnit = pRoom1->pFirstUnit; pUnit; pUnit = pUnit->pListNext)
                if (pUnit->dwType == UNIT_NPC && IsMercClassId(pUnit->dwTxtFileNo))
                {
                    DWORD dwOwner = D2CLIENT_GetMonsterOwner(pUnit->dwUnitId);
                    if (dwOwner == EnchInfo->dwPlayerId)
                    {
                        CastOnUnit(D2S_ENCHANT, pUnit, FALSE);
                        return TRUE;
                    }
                }

        if (!bSilentBots)
            Say("Couldn't find your mercenary!");

        return FALSE;
    }

    return FALSE;
}

DWORD WINAPI EnchantThread(LPVOID lpParameter)
{
    EnchantQueue.RemoveAll();

    while(true)
    {
        SleepEx(800, true);

        if (!GameReady())
            continue;

        if (!cEnchantBotToggle)
            continue;

        if (EnchantQueue.IsEmpty() || EnchantQueue.IsLocked)
                continue;

        ExecuteEnchantQueue(EnchantQueue[0]);
        EnchantQueue.RemoveAt(0);
        EnchantQueue.FreeExtra();
    }
}