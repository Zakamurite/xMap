#include "xMap.h"

BOOL IsMercClassId(DWORD dwClassID)
{
	return dwClassID == MERC_A1 || dwClassID == MERC_A2 || dwClassID == MERC_A3 || dwClassID == MERC_A5;
}

Level* GetUnitLevel(UnitAny* unit)
{
	if (unit && unit->pPath->pRoom1) {
		return unit->pPath->pRoom1->pRoom2->pLevel;
	}
	return NULL;
}

BOOL TestPlayerInTown(UnitAny *unit)
{
	Level* curlvl = GetUnitLevel(unit);
	return curlvl ?
		curlvl->dwLevelNo == 1		// act1
		|| curlvl->dwLevelNo == 40	// act2
		|| curlvl->dwLevelNo == 75	// act3
		|| curlvl->dwLevelNo == 103	// act4
		|| curlvl->dwLevelNo == 109	// act5
		: FALSE;
}

RosterUnit* FindPartyByName(CHAR* szName)
{
	for(RosterUnit* pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
		if(!stricmp(szName, pUnit->szName))
			return pUnit;

	return NULL;
}

void RunToXY(WORD x, WORD y)
{
	Resynch();
	//Say("Going to coords %d %d", x, y);
	BYTE aPacket[5] = {0x03};

	*(WORD*)&aPacket[1] = x;
	*(WORD*)&aPacket[3] = y;

	D2NET_SendPacket(sizeof(aPacket), 0, aPacket);
}

//04   9   Run to entity         04 [DWORD entity kind] [DWORD id] 
void RunToEntity(DWORD unitType, DWORD id)
{
	Resynch();
	//Say("Going to unit %d", id);
	BYTE aPacket[9] = {0x04};

	*(DWORD*)&aPacket[1] = unitType;
	*(DWORD*)&aPacket[5] = id;

	D2NET_SendPacket(sizeof(aPacket), 0, aPacket);
}

UnitAny* FindNearestPortal(string owner)
{
	UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
	if (!pPlayer)
		return NULL;

	UnitAny* portal = NULL;
	long distance = 999999999;
	for (Room1* pRoom1 = pPlayer->pAct->pRoom1; pRoom1; pRoom1 = pRoom1->pRoomNext)
		for (UnitAny* pUnit = pRoom1->pFirstUnit; pUnit; pUnit = pUnit->pListNext)
			if (pUnit->dwType == UNIT_OBJECT && pUnit->dwTxtFileNo == 0x3B)
			{
				if (STRING_EQUAL(pUnit->pObjectData->szOwner, owner))
				{
					if (CalculateDistance(pUnit->pObjectPath->dwPosX, pUnit->pObjectPath->dwPosY, 
										pPlayer->pPath->xPos, pPlayer->pPath->yPos) < distance)
					{
						distance = CalculateDistance(pUnit->pObjectPath->dwPosX, pUnit->pObjectPath->dwPosY, 
										pPlayer->pPath->xPos, pPlayer->pPath->yPos);
						portal = pUnit;
					}
				}
			}


	return portal;
}

BOOL HostilePlayer(DWORD dwUnitId)
{
	if(!GameReady())
		return FALSE;

	DWORD dwFlags = GetPvpFlags(dwUnitId);
	if(dwFlags & PVP_HOSTILED_BY_YOU || dwFlags & PVP_HOSTILED_YOU)
		return FALSE;

	if(!FindPartyById(dwUnitId))
		return FALSE;

	BYTE aPacket[7];
	aPacket[0] = 0x5D;
	*(LPWORD)&aPacket[1] = 0x104;
	*(LPDWORD)&aPacket[3] = dwUnitId;
	D2NET_SendPacket(7, 1, aPacket);

	return TRUE;
}

UnitAny* D2CLIENT_FindUnit(DWORD dwId, DWORD dwType)
{
	UnitAny* pUnit = D2CLIENT_FindServerSideUnit(dwId, dwType);
	if (!pUnit)
		pUnit = D2CLIENT_FindClientSideUnit(dwId, dwType);
/*	if (!pUnit)
	{
		UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
		for(Room1* pRoom1 = pPlayer->pAct->pRoom1; pRoom1; pRoom1 = pRoom1->pRoomNext)
			for(UnitAny* pUnit = pRoom1->pFirstUnit; pUnit; pUnit = pUnit->pListNext)
				if(pUnit->dwType == dwType && pUnit->dwUnitId == dwId)
				{
					return pUnit;
				}
	}*/

	return pUnit;
}

PresetUnit* FindPresetUnit(DWORD dwClassId, DWORD dwType, Room2* *pRoom)
{
	UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
	
	for(Room2* pRoom2 = pPlayer->pPath->pRoom1->pRoom2->pLevel->pRoom2First; pRoom2; pRoom2 = pRoom2->pRoom2Next)
	{
		for(PresetUnit* pUnit = pRoom2->pPreset; pUnit; pUnit = pUnit->pPresetNext)
		{
			if(pUnit->dwType == dwType && pUnit->dwTxtFileNo == dwClassId)
			{
				*pRoom = pRoom2;
				return pUnit;
			}
		}
	}

	return NULL;
}