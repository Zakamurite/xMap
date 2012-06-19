#include "xMap.h"

DWORD WINAPI AutoPartyThread(LPVOID lpParameter)
{
	while(!GameReady ())
		SleepEx(100, true);

	while(true)
	{
		SleepEx(100, true);

		if (!bUseAutoParty)
			continue;

		BnetData *pData = *p_D2LAUNCH_BnData;
		if (bPOIP && strlen(pData->szGamePass) == 0)
			continue;

		if (!GameReady ())
			continue;

		UnitAny *pPlayer = D2CLIENT_GetPlayerUnit ();

		for (RosterUnit* pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
		{
			if (pUnit->dwUnitId == pPlayer->dwUnitId)//We cannot party ourselves!!
				continue;//Continue loop if it is our RosterUnit

			switch(pUnit->dwPartyFlags)//Switch the party flags of this player
			{
				case PARTY_INVITED_YOU://They invited us to a party! Let's accept!
					D2CLIENT_clickParty(pUnit, clickParty_Accept);//Accept Party invitation
				break;
				case PARTY_NOT_IN_PARTY://They aren't in a party:( Let's invite them!:)
					D2CLIENT_clickParty(pUnit, clickParty_Invite);//Invite Player/
				break;
			}
		}
	}
}

DWORD GetPvpFlags(DWORD dwPlayerId)
{
	DWORD dwFlags = 0;
	UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
	for(RosterUnit* pUnit = (*p_D2CLIENT_PlayerList); pUnit; pUnit = pUnit->pNext)
	{
		if(pUnit->dwUnitId != dwPlayerId)
			continue;

		if(pUnit->dwUnitId != pPlayer->dwUnitId)
		{
			if(TestPvpFlag(dwPlayerId, pPlayer->dwUnitId, 8))
				dwFlags |= PVP_HOSTILED_YOU;

			if(TestPvpFlag(pPlayer->dwUnitId, dwPlayerId, 8))
				dwFlags |= PVP_HOSTILED_BY_YOU;

			if(pUnit->dwPartyFlags == 2)
				dwFlags |= PVP_INVITED_YOU;

			if(pUnit->dwPartyFlags == 4)
				dwFlags |= PVP_INVITED_BY_YOU;

			if(pUnit->wPartyId != 0xFFFF && pUnit->dwPartyFlags == 1)
			{
				RosterUnit* pMe = FindPartyById(pPlayer->dwUnitId);
				if(pMe->wPartyId == 0xFFFF)
					dwFlags |= PVP_ALLIED;
				else if(pMe->wPartyId == pUnit->wPartyId)
					dwFlags |= PVP_ALLIED_WITH_YOU;
			}

			return dwFlags;
		}
	}

	return dwFlags;
}

RosterUnit* FindPartyById(DWORD dwUnitId)
{
	for(RosterUnit* pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
		if(pUnit->dwUnitId == dwUnitId)
			return pUnit;
	return NULL;
}