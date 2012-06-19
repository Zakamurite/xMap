#include "xMap.h"

BOOL Interact(DWORD dwUnitId, DWORD dwType, BOOL bCheckOverride)
{
	if(!bCheckOverride)
		//if(!D2CLIENT_GetUnitFromId(dwUnitId, dwType))
		if (!D2CLIENT_FindUnit(dwUnitId, dwType))
			return FALSE;

	BYTE aPacket[9];
	aPacket[0] = 0x13;
	*(DWORD*)&aPacket[1] = dwType;
	*(DWORD*)&aPacket[5] = dwUnitId;
	D2NET_SendPacket(9, 1, aPacket);

	return TRUE;
}

void __declspec(naked) OnGamePacketSent_STUB()
{
	__asm
	{
		pushad;

		mov ecx, [esp + 0x20 + 0xC];
		mov edx, [esp + 0x20 + 0x4];
		call OnGamePacketSent;
		test eax, eax;

		popad;
		jnz OldCode;

		mov [esp + 0x4], 0;

OldCode:
		jmp D2NET_SendPacket;
	}
}

BOOL __fastcall OnGamePacketSent(LPBYTE aPacket, DWORD aLen)
{
	if (aPacket[0] <= 0x11)
	{
		if(bBackToTown)
			return FALSE;
	}
	//28   9   Socket item         28 [DWORD item to socket id] [DWORD socketable item id] 
	if (aPacket[0] == 0x28 && bSocketProtect)
	{
		return FALSE;		
	}

	//58   3   Quest Completed         58 [WORD Quest id] 
	if (aPacket[0] == 0x58 )
	{
		return FALSE;

	}

	if (aPacket[0] == 0x66 && bShowWardenNotifications)
	{
		PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Warden response activity detected.");
		LogPacket(aPacket, aLen, false);
		return TRUE;
	}

	return TRUE;
}

VOID __declspec(naked) OnGamePacketReceived_STUB()
{
	__asm
	{
		pop ebp;
		pushad;

		call OnGamePacketReceived;
		test eax, eax;

		popad;
		jnz OldCode;

		mov edx, 0;

OldCode:
		call D2NET_ReceivePacket_I;

		push ebp;
		ret;
	}
}

BOOL __fastcall OnGamePacketReceived(LPBYTE aPacket, DWORD aLen)
{
	//0d   13   Player Stop      0d [BYTE Unit Type] [DWORD Unit Id] [BYTE  Unknown] [WORD Unit X] [WORD Unit Y] [BYTE Unknown] [BYTE Life] 
	if (aPacket[0] == 0x0D)
	{
		if (bFollowBotToggle && !bFollowBotWaiting)
		{
			if (aPacket[1] == UNIT_PLAYER)
			{
				if (*(DWORD*)&aPacket[2] != D2CLIENT_GetPlayerUnit()->dwUnitId)
				{
					UnitAny* pUnit = D2CLIENT_FindUnit(*(DWORD*)&aPacket[2], UNIT_PLAYER);
			
					if (pUnit)
					{
						if (STRING_EQUAL(pUnit->pPlayerData->szName, cFollowBotLeaderName))
						{
							RunToEntity(UNIT_PLAYER, pUnit->dwUnitId);
							//RunToXY(pUnit->pPath->xPos + cFollowBotXOffset, pUnit->pPath->yPos + cFollowBotYOffset);
						}
					}
				}
			}
		}

		return TRUE;
	}

	//0f   16   Player Move      0f [BYTE Unit Type] [DWORD Unit Id] [BYTE  0x01 = Walk || 0x23 = Run || 0x20 = Knockback] [WORD Target X] [WORD Target Y] 00  [WORD Current X] [WORD Current Y] 
	if (aPacket[0] == 0x0F)
	{
		if (bFollowBotToggle && !bFollowBotWaiting)
		{
			if (aPacket[1] == UNIT_PLAYER && aPacket[6] != 0x20) //and not stunned
			{
				if (*(DWORD*)&aPacket[2] != D2CLIENT_GetPlayerUnit()->dwUnitId)
				{
					UnitAny* pUnit = D2CLIENT_FindUnit(*(DWORD*)&aPacket[2], UNIT_PLAYER);
			
					if (pUnit)
					{
						if (STRING_EQUAL(pUnit->pPlayerData->szName, cFollowBotLeaderName))
						{
							RunToEntity(UNIT_PLAYER, pUnit->dwUnitId);
							//RunToXY(pUnit->pPath->xPos + cFollowBotXOffset, pUnit->pPath->yPos + cFollowBotYOffset);
						}
					}
				}
			}
		}

		return TRUE;
	}

	//15   11   Reassign Player   15 [BYTE Unit Type] [DWORD Unit Id] [WORD  X] [WORD Y] [BYTE 0x01 = True || 0x00 = False] 
	if(aPacket[0] == 0x15)
	{
		if (bFollowBotToggle && !bFollowBotWaiting)
		{
			if (aPacket[1] == UNIT_PLAYER && *(DWORD*)&aPacket[2] != D2CLIENT_GetPlayerUnit()->dwUnitId)
			{
				UnitAny* pUnit = D2CLIENT_FindUnit(*(DWORD*)&aPacket[2], UNIT_PLAYER);
			
				if (pUnit)
				{
					if (STRING_EQUAL(pUnit->pPlayerData->szName, cFollowBotLeaderName))
					{
						//RunToEntity(UNIT_PLAYER, pUnit->dwUnitId);
						RunToXY(pUnit->pPath->xPos /*+ cFollowBotXOffset*/, pUnit->pPath->yPos/* + cFollowBotYOffset*/);
					}
				}
			}
		}

		if (bAntiFlash && *(LPDWORD)&aPacket[2] == D2CLIENT_GetPlayerUnit()->dwUnitId)
				aPacket[10] = 0;

		if(bFastTeleport)
		{
			UnitAny* pUnit = D2CLIENT_GetPlayerUnit();
			if(*(DWORD*)&aPacket[2] == pUnit->dwUnitId)
			{
				if(pUnit->dwMode == PLAYER_MODE_DEATH || pUnit->dwMode == PLAYER_MODE_STAND_OUTTOWN ||
					pUnit->dwMode == PLAYER_MODE_WALK_OUTTOWN || pUnit->dwMode == PLAYER_MODE_RUN || 
					pUnit->dwMode == PLAYER_MODE_STAND_INTOWN || pUnit->dwMode == PLAYER_MODE_WALK_INTOWN ||
					pUnit->dwMode == PLAYER_MODE_DEAD || pUnit->dwMode == PLAYER_MODE_SEQUENCE ||
					pUnit->dwMode == PLAYER_MODE_BEING_KNOCKBACK)
					return TRUE;

				pUnit->dwFrameRemain = 0;
			}
		}

		return TRUE;
	}

	if(aPacket[0] == 0x26)
	{
		CHAR* lpPlayerName = (CHAR*)&aPacket[10];
		CHAR* lpMessage = (CHAR*)&aPacket[strlen(lpPlayerName) + 11];

		LPENCHANTINFO lpEnchInfo = new ENCHANTINFO;
		RosterUnit* lpPlayer = FindPartyByName(lpPlayerName);

		if(!lpPlayer)
			return TRUE;

		if (bFollowBotToggle && !_stricmp(lpPlayerName, cFollowBotLeaderName.c_str()))
		{
			if(!_stricmp(lpMessage, cWaitCommand.c_str()))
			{
				if (!bSilentBots)
					Say("Waiting for %s to command", cFollowBotLeaderName.c_str());								

				bFollowBotWaiting = TRUE;
			}

			if(!_stricmp(lpMessage, cGoCommand.c_str()))
			{
				if (!bSilentBots)
					Say("Following %s!", cFollowBotLeaderName.c_str());
				
				bFollowBotWaiting = FALSE;
			}

			if(!_stricmp(lpMessage, cTakeMyTpCommand.c_str()))
			{
				UnitAny* portal = FindNearestPortal(cFollowBotLeaderName);
				if (portal)
				{
					if(CalculateDistance(D2CLIENT_GetPlayerUnit()->pPath->xPos, D2CLIENT_GetPlayerUnit()->pPath->yPos, 
											portal->pObjectPath->dwPosX, portal->pObjectPath->dwPosY) <= 18)
						Interact(portal->dwUnitId, UNIT_OBJECT, TRUE);
					else
					{
						if(!bSilentBots)
							Say("Portal too far away!");
					}
				}
				else
				{
					if(!bSilentBots)
						Say("Can't find any portals to go to!");
				}
			}

			if(!_stricmp(lpMessage, cTakeOwnTpCommand.c_str()))
			{
				UnitAny* portal = FindNearestPortal(D2CLIENT_GetPlayerUnit()->pPlayerData->szName);
				if (portal)
				{
					if(CalculateDistance(D2CLIENT_GetPlayerUnit()->pPath->xPos, D2CLIENT_GetPlayerUnit()->pPath->yPos, 
											portal->pObjectPath->dwPosX, portal->pObjectPath->dwPosY) <= 15)
						Interact(portal->dwUnitId, UNIT_OBJECT, TRUE);
					else
					{
						if(!bSilentBots)
							Say("Portal too far away!");
					}
				}
				else
				{
					if(!bSilentBots)
						Say("Can't find any portals to go to!");
				}
			}


			if(!_stricmp(lpMessage, cOpenTpCommand.c_str()))
			{
				if (!TestPlayerInTown(D2CLIENT_GetPlayerUnit()))
				{
					if (!OpenPortal())
						if (!bSilentBots)
							Say("No TP's left!");
				}
			}

			if(!_stricmp(lpMessage, cTownCommand.c_str()))
			{
				if (!TestPlayerInTown(D2CLIENT_GetPlayerUnit()))
				{
					if (OpenPortal())
						bBackToTown = TRUE;
					else
						if (!bSilentBots)
							Say("No TP's left!");
				}
			}

			if(!_stricmp(lpMessage, cExitGameCommand.c_str()))
			{
				if (!bSilentBots)
					Say("Bye!");
				ExitGame_ASM();
			}

			if(!_stricmp(lpMessage, cBoCommand.c_str()))
			{
				SleepEx(300, true);
				if (CastSkillXY(D2S_BATTLECOMMAND))
					SleepEx(300, true);
				if (CastSkillXY(D2S_BATTLEORDERS))
					SleepEx(300, true);
			}
		}

		if (cEnchantBotToggle)
		{
			lpEnchInfo->dwPlayerId = lpPlayer->dwUnitId;
			lpEnchInfo->nEnchantType = NULL;

			if(!_stricmp(lpMessage, cEnchantMe.c_str()))
			{
				lpEnchInfo->nEnchantType = ENCHANT_ME;
				EnchantQueue.Add(lpEnchInfo);
			}
			else
			if(!_stricmp(lpMessage, cEnchantMerc.c_str()))
			{
				lpEnchInfo->nEnchantType = ENCHANT_MERC;
				EnchantQueue.Add(lpEnchInfo);
			}
			else
			if(!_stricmp(lpMessage, cEnchantAll.c_str()))
			{
				lpEnchInfo->nEnchantType = ENCHANT_ME;
				EnchantQueue.Add(lpEnchInfo);

				lpEnchInfo = new ENCHANTINFO;
				lpEnchInfo->dwPlayerId = lpPlayer->dwUnitId;
				lpEnchInfo->nEnchantType = ENCHANT_MERC;
				EnchantQueue.Add(lpEnchInfo);
			}
			else
				delete lpEnchInfo;
		}

		return TRUE;
	}

	if (aPacket[0] == 0x51)
	{
		if (aPacket[1] == UNIT_OBJECT && *(WORD*)&aPacket[6] == 0x3B) 	//0x3B - portal
		{
			//if(v_FastTpOpen) aPacket[12] = 2;
			aPacket[12] = 2; //this reduces delay when entering portal

			/*		UnitAny* pUnit = D2CLIENT_GetPlayerUnit();
			if(*(DWORD*)&aPacket[2] == pUnit->dwUnitId)
			{
				if(pUnit->dwMode == PLAYER_MODE_DEATH || pUnit->dwMode == PLAYER_MODE_STAND_OUTTOWN ||
					pUnit->dwMode == PLAYER_MODE_WALK_OUTTOWN || pUnit->dwMode == PLAYER_MODE_RUN || 
					pUnit->dwMode == PLAYER_MODE_STAND_INTOWN || pUnit->dwMode == PLAYER_MODE_WALK_INTOWN ||
					pUnit->dwMode == PLAYER_MODE_DEAD || pUnit->dwMode == PLAYER_MODE_SEQUENCE ||
					pUnit->dwMode == PLAYER_MODE_BEING_KNOCKBACK)
					return TRUE;

				pUnit->dwFrameRemain = 0;
			}
			*/
			if(bBackToTown && !TestPlayerInTown(D2CLIENT_GetPlayerUnit()))
			{
				if (CalculateDistance(D2CLIENT_GetPlayerUnit()->pPath->xPos, D2CLIENT_GetPlayerUnit()->pPath->yPos, *(LPWORD)&aPacket[8], *(LPWORD)&aPacket[10]) <= 10)
				{
					Interact(*(LPDWORD)&aPacket[2], UNIT_OBJECT, TRUE);
					bBackToTown = FALSE;
					if (bHostilePlayers)
					{
						for (RosterUnit* pUnit = (*p_D2CLIENT_PlayerList); pUnit; pUnit = pUnit->pNext)
						{
							HostilePlayer(pUnit->dwUnitId);
						}

						bHostilePlayers = FALSE;
					}
				}
			}
		}
		return TRUE;
	}

	if (*(BYTE*)&aPacket[0] == 0x5A)
	{
		//player dies
		if (*(BYTE*)&aPacket[1] == 0x06 && bShowTauntMessages && cDeathMessage.size() > 0)
		{
			Say("%s", cDeathMessage.c_str());

			return TRUE;
		}

		//players dropped
		if (*(BYTE*)&aPacket[1] == 0x00 && bShowTauntMessages && cDropMessage.size() > 0)
		{
			Say("%s", cDropMessage.c_str());

			return TRUE;
		}

		//sojs sold
		if (*(BYTE*)&aPacket[1] == 0x11 && bShowTauntMessages && cSojsSoldMessage.size() > 0)
		{
			Say("%s", cSojsSoldMessage.c_str());

			return TRUE;
		}

		//diablo walks
		if (*(BYTE*)&aPacket[1] == 0x12  && bShowTauntMessages && cDiCloneMessage.size() > 0)
		{
			Say("%s", cDiCloneMessage.c_str());

			return TRUE;
		}

		//on user join
		if (*(BYTE*)&aPacket[1] == 0x02  && cEnchantBotToggle && !bSilentBots)
		{
			CHAR* lpCharName = (CHAR*)&aPacket[8];
			Say("Hello %s. Chant bot active. Commands are: %s, %s, %s", lpCharName, cEnchantMe.c_str(), cEnchantMerc.c_str(), cEnchantAll.c_str());

			return TRUE;
		}

		return TRUE;
	}

	if (aPacket[0] == 0xA7)
	{
		if(bFastTeleport)
		{
			//if(aPacket[6] == AFFECT_JUST_PORTALED)
			if(aPacket[6] == 102)
				return FALSE;
		}

		return TRUE;
	}

	if (aPacket[0] == 0xAE && bShowWardenNotifications)
	{
		PrintAtBottomLeft("ÿc4[xMap]ÿc0: ÿc1Warden request activity detected.");
		LogPacket(aPacket, aLen, true);
		return TRUE;
	}
	
	/////test shit
	//0E   12   Object State      0e [BYTE Unit Type] [DWORD Unit Id] [BYTE  Unknown (0x03)] [BYTE 0x00 = Can't Change Back || 0x01 = Can Change Back]
	if(aPacket[0] == 0x0E)
	{
		UnitAny* pUnit = D2CLIENT_FindUnit(*(DWORD*)&aPacket[2], (DWORD)aPacket[1]);
		if (pUnit && pUnit->dwTxtFileNo == 0x3B)	//0x3B - portal
			return FALSE;

		return TRUE;
	}

	//5d   5   Quest Item State   5d [BYTE Unknown (Id?)]  [DWORD State?] 
	if(aPacket[0] == 0x5D)
	{
		//if(bNoQuestBox && !D2CLIENT_GetUiVar(UI_QUEST))
		if (bNoQuestBox && !D2CLIENT_GetUiVar(0x0F))
			return FALSE;

		return TRUE;
	}

	return TRUE;
}

void OpenStash()
{
	BYTE c[2] = {0x77};
	*(BYTE*)&c[1] = 0x10;
	D2NET_ReceivePacket(c, sizeof(c));				
}

void OpenCube()
{
	BYTE c[2] = {0x77};
	*(BYTE*)&c[1] = 0x15;
	D2NET_ReceivePacket(c, sizeof(c));				
}

void Resynch()
{
	BYTE c[9] = {0x4b};
	*(DWORD*)&c[1] = 0x00;
	*(DWORD*)&c[5] = D2CLIENT_GetPlayerUnit()->dwUnitId;
	D2NET_SendPacket(sizeof(c), 0 ,c);	
}

void MoveNPC(DWORD npcId)
{
//59   17   Make entity move      59 [DWORD entity kind] [DWORD entity id] [WORD x] 00 00 [WORD y] 00 00 
	BYTE *pPacket = new BYTE[17];
	*(BYTE*)&pPacket[0] = 0x59;
	*(DWORD*)&pPacket[1] = UNIT_NPC;
	*(DWORD*)&pPacket[5] = npcId;
	*(WORD*)&pPacket[9] = D2CLIENT_GetPlayerUnit()->pPath->xPos;
	*(WORD*)&pPacket[11] = 0;
	*(WORD*)&pPacket[13] = D2CLIENT_GetPlayerUnit()->pPath->yPos;
	*(WORD*)&pPacket[15] = 0;
	D2NET_SendPacket(17, 0, pPacket);
	delete pPacket;
}

void LogPacket(LPBYTE aPacket, DWORD aLen, bool in)
{
	FILE* f;
	if (in)
		fopen_s(&f, ".\\plugin\\packets_in.log", "a");
	else
		fopen_s(&f, ".\\plugin\\packets_out.log", "a");
	String s = "";

	SYSTEMTIME lt;
	GetLocalTime(&lt);    
    //printf(" The local time is: %02d:%02d\n", lt.wHour, lt.wMinute);

	char c[0x400];
	sprintf_s(c, sizeof(c), "[%d/%02d/%02d %02d:%02d:%02d.%03d ", 
		lt.wYear, lt.wMonth, lt.wDay, lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds);
	s += c;

	if (in)
		s += "In] : ";
	else
		s += "Out]: ";

	for (int i = 0; i < aLen; i++)
	{
		char c[0x400];
		sprintf_s(c, sizeof(c), "%02X ", aPacket[i]);
		//Print("%x", aPacket[i]);
		s += c;
	}
	fprintf_s(f, "%s\n", s.c_str());
	fclose(f);
	
}