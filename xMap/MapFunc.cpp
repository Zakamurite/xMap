#include "xMap.h"

DWORD __declspec(naked) __fastcall D2CLIENT_InitAutomapLayer_STUB(DWORD nLayerNo)
{
	__asm 
	{
		push eax;
		mov eax, ecx;
		call D2CLIENT_InitAutomapLayer_I;
		pop eax;
		ret;
	}
}

CMap::CMap()
{
	m_ActLevels[0] = 1;
	m_ActLevels[1] = 40;
	m_ActLevels[2] = 75;
	m_ActLevels[3] = 103;
	m_ActLevels[4] = 109;
	m_ActLevels[5] = 137;

	memset(m_RevealedActs, 0, sizeof(UCHAR) * 5);
	m_LastLevel = -1;
}

CMap::~CMap()
{
	for (int i = 0; i < m_LevelExits.GetSize(); i++)
		delete m_LevelExits[i];

	for (int i = 0; i < m_Shrines.GetSize(); i++)
		delete m_Shrines[i];
}

VOID CMap::RevealAutomap()
{
	UnitAny* pPlayer = *p_D2CLIENT_PlayerUnit;
	if (!pPlayer)
		return;
	Act* pAct = pPlayer->pAct;
	DWORD dwAct = pPlayer->dwAct;

	if(m_RevealedActs[dwAct])
		return;

	/*for(INT i = 0; i < m_LevelExits.GetSize(); i++)
		delete m_LevelExits[i];
	m_LevelExits.RemoveAll();*/

	//We are going to loop every level in the current act.
	for (int nLevel = m_ActLevels[pPlayer->dwAct] + 1; nLevel < m_ActLevels[pPlayer->dwAct + 1]; nLevel++)
	{
		Level *pLevel = GetLevelPointer(pPlayer->pAct->pMisc, nLevel);

		//Insure we have a good level struct
		if(!pLevel)
			continue;

		//Init the level so we can add map to it
		if(!pLevel->pRoom2First)
			D2COMMON_InitLevel(pLevel);

		if(!pLevel->pRoom2First)
			continue;

		//Reveal the level!
		RevealLevel(pLevel);
	}

	PrintAtBottomLeft("ÿc4[xMap]ÿc0: Revealed Act %i", pPlayer->dwAct + 1);
	m_RevealedActs[dwAct] = 1;
}

Level* GetLevelPointer(ActMisc *pActMisc, int nLevel)
{
	if ((!pActMisc) || (nLevel < 0))
		return false;

	for (Level *pLevel = pActMisc->pLevelFirst; pLevel; pLevel = pLevel->pNextLevel)
	{
		if (!pLevel)
			continue;

		if ((pLevel->dwLevelNo == nLevel) && (pLevel->dwSizeX > 0))
			return pLevel;
	}
	return D2COMMON_GetLevel(pActMisc, nLevel);
}

bool CMap::RevealLevel(Level *pLevel)
{
	if (!pLevel)
		return false;

	//Initalize the automap layer to the level given
	if (!InitAutomapLayer(pLevel->dwLevelNo))
		return false;

	UnitAny *pUnit = D2CLIENT_GetPlayerUnit ();
	if (!pUnit)
		return false;

	//Loop each room in this level
	for (Room2 *pRoom2 = pLevel->pRoom2First; pRoom2; pRoom2 = pRoom2->pRoom2Next)
	{
		//A bool to check if we have added Room Data
		bool nAdded = false;

		//Add the room data if it is needed
		if (!pRoom2->pRoom1)
		{
			D2COMMON_AddRoomData(pLevel->pMisc->pAct,pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, pUnit->pPath->pRoom1);
			nAdded = true;
		}

		//Insure that we have a valid room before revealing it.
		if (!pRoom2->pRoom1)
			continue;
	
		//Reveal the map!
		D2CLIENT_RevealAutomapRoom(pRoom2->pRoom1, TRUE, (*p_D2CLIENT_AutomapLayer));

		DrawPresets(pRoom2);

		//Remove Room Data if we added it!
		if (nAdded)
			D2COMMON_RemoveRoomData(pLevel->pMisc->pAct, pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, D2CLIENT_GetPlayerUnit()->pPath->pRoom1);
	}

	//Reset the map layer to the current area
	InitAutomapLayer(pUnit->pPath->pRoom1->pRoom2->pLevel->dwLevelNo);

	return true;
}

AutomapLayer* CMap::InitAutomapLayer(DWORD levelno)
{
	AutomapLayer2 *pLayer = D2COMMON_GetLayer(levelno);
	if (!pLayer)
		return false;
	return D2CLIENT_InitAutomapLayer(pLayer->nLayerNo);
}

void CMap::DrawPresets (Room2 *pRoom2)
{
	UnitAny *pPlayer = D2CLIENT_GetPlayerUnit ();

	for (PresetUnit *pUnit = pRoom2->pPreset; pUnit; pUnit = pUnit->pPresetNext)
	{
		int mCell = -1;
		if (pUnit->dwType == 1)//Special NPCs.
		{
			if (pUnit->dwTxtFileNo == 256)//Izzy
				mCell = 300;
			if (pUnit->dwTxtFileNo == 745)//Hephasto
				mCell = 745;
		} else if (pUnit->dwType == UNIT_OBJECT) { //Objects on Map
			
			//Add's a special Chest icon over the hidden uberchests in Lower Kurast
			if (pUnit->dwTxtFileNo == 580 && pRoom2->pLevel->dwLevelNo == 79)		
				mCell = 318;
			
			//Special Units that require special checking:)
			if (pUnit->dwTxtFileNo == 371) 
				mCell = 301; //Countess Chest
			if (pUnit->dwTxtFileNo == 152) 
				mCell = 300; //A2 Orifice
			if (pUnit->dwTxtFileNo == 460) 
				mCell = 1468; //Frozen Anya
			if ((pUnit->dwTxtFileNo == 402) && (pRoom2->pLevel->dwLevelNo == 46))
				mCell = 0; //Canyon/Arcane Waypoint
			if ((pUnit->dwTxtFileNo == 267) && (pRoom2->pLevel->dwLevelNo != 75) && (pRoom2->pLevel->dwLevelNo != 103))
				mCell = 0;
			if ((pUnit->dwTxtFileNo == 376) && (pRoom2->pLevel->dwLevelNo == 107))
				mCell = 376;

			if (mCell == -1)
			{
				//Check for stupid objects.
				if(pUnit->dwTxtFileNo > 574)
					mCell = pUnit->dwTxtFileNo - 574;
				else {
					//Get the object cell
					ObjectTxt *obj = D2COMMON_GetObjectTxt(pUnit->dwTxtFileNo);
					if (obj->nAutoMap == 310)
					{
						ShrineDesc* sd = new ShrineDesc;
						sd->ID = 0;
						sd->nX = pUnit->dwPosX + (pRoom2->dwPosX * 5);
						sd->nY = pUnit->dwPosY + (pRoom2->dwPosY * 5);
						sd->nAct = pPlayer->dwAct;
						cMap->m_Shrines.Add(sd);
					}

					if (mCell == -1)
					{
						//Check if it is an shrine.
						if(obj->nAutoMap == 310) {
							mCell = (obj->nSubClass & 1) ? 310 : 0;//Check to see if it is a bad shrine.
						}
						else
							if (mCell == -1)
							{
								mCell = obj->nAutoMap;//Set the cell number then.
							}
					}
				}
			}
		} else if (pUnit->dwType == UNIT_TILE) {
			DWORD dwTargetLevel = GetTileLevelNo(pRoom2, pUnit->dwTxtFileNo);
			if(dwTargetLevel)
			{
				for(INT i = 0; i < m_LevelExits.GetSize(); i++)
				{
					if((m_LevelExits[i]->ptPos.x == (pRoom2->dwPosX * 5) + pUnit->dwPosX) && 
						(m_LevelExits[i]->ptPos.y == (pRoom2->dwPosY * 5) + pUnit->dwPosY))
						return;
				}

				LPCAVEDESC LevelDesc = new CAVEDESC;

				memset(LevelDesc, 0, sizeof(CAVEDESC));
				
				sprintf(LevelDesc->szName, "%s", D2GetMapName((INT)dwTargetLevel).c_str());
				LevelDesc->ptPos.x = (pRoom2->dwPosX * 5) + pUnit->dwPosX - (8 << 1);
				LevelDesc->ptPos.y = (pRoom2->dwPosY * 5) + pUnit->dwPosY - 10;
				LevelDesc->dwLevelNo = pRoom2->pLevel->dwLevelNo;
				LevelDesc->dwTargetLevelNo = dwTargetLevel;
				LevelDesc->dwAct = pPlayer->dwAct;

				if(dwTargetLevel == pRoom2->pLevel->pMisc->dwStaffTombLevel)
					strcat(LevelDesc->szName, "ÿc2*");

				m_LevelExits.Add(LevelDesc);
			}
		}

		if ((mCell > 0) && (mCell < 1258))
		{
			AutomapCell *pCell = D2CLIENT_NewAutomapCell();
			pCell->nCellNo = mCell;
			int pX = (pUnit->dwPosX + (pRoom2->dwPosX * 5));
			int pY = (pUnit->dwPosY + (pRoom2->dwPosY * 5));
			pCell->xPixel = (((pX - pY) * 16) / 10) + 1;
			pCell->yPixel = (((pY + pX) * 8) / 10) - 3;

			D2CLIENT_AddAutomapCell(pCell, &((*p_D2CLIENT_AutomapLayer)->pObjects));
		}
	}
}

VOID CMap::AddAutomapRoom(Room2* pRoom2)
{
	UnitAny* pUnit = *p_D2CLIENT_PlayerUnit;
	D2COMMON_AddRoomData(pRoom2->pLevel->pMisc->pAct,
		pRoom2->pLevel->dwLevelNo,
		pRoom2->dwPosX,
		pRoom2->dwPosY,
		pUnit->pPath->pRoom1);
}

VOID CMap::RemoveAutomapRoom(Room2* pRoom2)
{
	UnitAny* pUnit = *p_D2CLIENT_PlayerUnit;
	D2COMMON_RemoveRoomData(pRoom2->pLevel->pMisc->pAct,
		pRoom2->pLevel->dwLevelNo,
		pRoom2->dwPosX,
		pRoom2->dwPosY,
		pUnit->pPath->pRoom1);
}

BOOL CMap::GetCaveExits(LPCAVEDESC *lpLevel, INT nMaxExits, DWORD dwAct)
{
	INT nTotal = 0;

	for(INT i = 0; i < m_LevelExits.GetSize(); i++)
	{
		if(nTotal > nMaxExits)
			return FALSE;

		if (dwAct != m_LevelExits[i]->dwAct)
			continue;

		lpLevel[nTotal] = m_LevelExits[i];
		nTotal++;
	}

	return nTotal;
}

INT CMap::GetUnitCellNumber(DWORD dwClassId, DWORD dwLevelNo)
{
	if(dwClassId == 397) return 318;
	if(dwClassId == 371) return 301;
	if(dwClassId == 152) return 300;
	if(dwClassId == 460) return 1468;

	if(dwClassId == 402 && dwLevelNo == MAP_A2_CANYON_OF_THE_MAGI) return 0;
	if(dwClassId == 267 && dwLevelNo != MAP_A3_KURAST_DOCKS && dwLevelNo != MAP_A4_THE_PANDEMONIUM_FORTRESS) return 0;
	if(dwClassId == 376 && dwLevelNo == MAP_A4_RIVER_OF_FLAME) return 376;

	if(dwClassId > 574)
		return 0;

	ObjectTxt* pTxt = D2COMMON_GetObjectTxt(dwClassId);
	if(pTxt->nAutoMap == 310)
		return (pTxt->nSubClass & 1) ? 310 : 0;

	return pTxt->nAutoMap;
}

DWORD CMap::GetTileLevelNo(Room2* lpRoom2, DWORD dwTileNo)
{
	for(RoomTile* pRoomTile = lpRoom2->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
	{
		if(*(pRoomTile->nNum) == dwTileNo)
			return pRoomTile->pRoom2->pLevel->dwLevelNo;
	}

	return NULL;
}

BOOL CMap::CreateCollisionMap()
{
	if(GetUnitLevel((*p_D2CLIENT_PlayerUnit))->dwLevelNo == m_LastLevel)
		return TRUE;

	if(!*p_D2CLIENT_PlayerUnit)
		return FALSE;

	if(!(*p_D2CLIENT_PlayerUnit)->pPath->pRoom1)
		return FALSE;

	Level* pLevel = (*p_D2CLIENT_PlayerUnit)->pPath->pRoom1->pRoom2->pLevel;
	if(!pLevel)
		return FALSE;

	if(m_Map.IsCreated())
		m_Map.Destroy();

	m_LastLevel = pLevel->dwLevelNo;
	m_LevelOrigin.x = pLevel->dwPosX * 5;
	m_LevelOrigin.y = pLevel->dwPosY * 5;
	m_SizeX = pLevel->dwSizeX * 5;
	m_SizeY = pLevel->dwSizeY * 5;

	m_Map.Lock();
	if(!m_Map.Create(pLevel->dwSizeX * 5, pLevel->dwSizeY * 5, MAP_DATA_NULL))
	{
		m_Map.Unlock();
		return FALSE;
	}

	CArrayEx<DWORD, DWORD> aSkip;
	AddCollisionData((*p_D2CLIENT_PlayerUnit)->pPath->pRoom1->pRoom2, aSkip);

	FillGaps();
	FillGaps();

	m_Map.Unlock();
	return TRUE;
}

BOOL CMap::IsGap(INT nX, INT nY)
{
	if(m_Map[nX][nY] % 2)
		return FALSE;

	INT nSpaces = 0;
	INT i = 0;

	for(i = nX - 2; i <= nX + 2 && nSpaces < 3; i++)
	{
		if(i < 0 || i >= m_Map.GetCX() || (m_Map[i][nY] % 2))
			nSpaces = 0;
		else
			nSpaces++;
	}

	if(nSpaces < 3)
		return TRUE;

	nSpaces = 0;
	for(i = nY - 2; i <= nY + 2 && nSpaces < 3; i++)
	{
		if(i < 0 || i >= m_Map.GetCY() || (m_Map[nX][i] % 2))
			nSpaces = 0;
		else
			nSpaces++;
	}

	return nSpaces < 3;
}

BOOL CMap::FillGaps()
{
	if(!m_Map.IsCreated())
		return FALSE;

	INT nCX = m_Map.GetCX();
	INT nCY = m_Map.GetCY();

	for(INT x = 0; x < nCX; x++)
	{
		for(INT y = 0; y < nCY; y++)
		{
			if(IsGap(x, y))
				m_Map[x][y] = MAP_DATA_FILL;
		}
	}

	return TRUE;
}

BOOL CMap::AddCollisionData(CollMap* pColl)
{
	if(!pColl)
		return FALSE;

	INT nX = pColl->dwPosGameX - m_LevelOrigin.x;
	INT nY = pColl->dwPosGameY - m_LevelOrigin.y;
	INT nCX = pColl->dwSizeGameX;
	INT nCY = pColl->dwSizeGameY;

	if(!m_Map.IsValidIndex(nX, nY))
		return FALSE;

	INT nLimitX = nX + nCX;
	INT nLimitY = nY + nCY;

	LPWORD p = pColl->pMapStart;
	if(!p)
		return FALSE;

	for(INT y = nY; y < nLimitY; y++)
	{
		for(INT x = nX; x < nLimitX; x++)
		{
			m_Map[x][y] = *p;

			if(m_Map[x][y] == 1024)
				m_Map[x][y] = MAP_DATA_AVOID;

			p++;
		}
	}

	return TRUE;
}

BOOL CMap::AddCollisionData(Room2* pRoom2, CArrayEx<DWORD, DWORD>& aSkip)
{
	if(!pRoom2)
		return FALSE;

	if(pRoom2->pLevel->dwLevelNo != m_LastLevel)
		return FALSE;

	if(aSkip.Find((DWORD)pRoom2) != -1)
		return TRUE;

	aSkip.Add((DWORD)pRoom2);

	BOOL bAdd = FALSE;
	if(!pRoom2->pRoom1)
	{
		AddAutomapRoom(pRoom2);
		bAdd = TRUE;
	}

	if(pRoom2->pRoom1)
		AddCollisionData(pRoom2->pRoom1->pColl);

	Room2* *pRoomNear = pRoom2->pRoom2Near;
	for(DWORD i = 0; i < pRoom2->dwRoomsNear; i++)
		AddCollisionData(pRoomNear[i], aSkip);

	if(bAdd)
		RemoveAutomapRoom(pRoom2);

	return TRUE;
}

BOOL CMap::GetLevelExits(LPLEVELEXIT *lpLevel, INT nMaxExits)
{
	LPCAVEDESC pCaves[0x40] = {NULL};
	POINT ptExitPoints[0x40][2];
	INT nTotalPoints = 0, nCurrentExit = 0;

	GetCaveExits(pCaves, 0x40, D2CLIENT_GetPlayerUnit()->dwAct);
	
	for(INT i = 0; i < 0x40; i++)
	{
		if(!pCaves[i])
			break;

		if(pCaves[i]->dwLevelNo == GetUnitLevel((*p_D2CLIENT_PlayerUnit))->dwLevelNo)
		{
			if(nCurrentExit >= nMaxExits)
				return FALSE;

			lpLevel[nCurrentExit] = new LEVELEXIT;
			lpLevel[nCurrentExit]->dwTargetLevel = pCaves[i]->dwTargetLevelNo;
			lpLevel[nCurrentExit]->ptPos.x = pCaves[i]->ptPos.x + (8 << 1);
			lpLevel[nCurrentExit]->ptPos.y = pCaves[i]->ptPos.y + 10;
			nCurrentExit++;
		}
	}

	for(INT i = 0; i < m_Map.GetCX(); i++)
	{
		if(!(m_Map[i][0] % 2))
		{
			ptExitPoints[nTotalPoints][0].x = i;
			ptExitPoints[nTotalPoints][0].y = 0;

			for(i++; i < m_Map.GetCX(); i++)
			{
				if(m_Map[i][0] % 2)
				{
					ptExitPoints[nTotalPoints][1].x = i - 1;
					ptExitPoints[nTotalPoints][1].y = 0;
					break;
				}
			}

			nTotalPoints++;
			break;
		}
	}

	for(INT i = 0; i < m_Map.GetCX(); i++)
	{
		if(!(m_Map[i][m_Map.GetCY() - 1] % 2))
		{
			ptExitPoints[nTotalPoints][0].x = i;
			ptExitPoints[nTotalPoints][0].y = m_Map.GetCY() - 1;

			for(i++; i < m_Map.GetCX(); i++)
			{
				if((m_Map[i][m_Map.GetCY() - 1] % 2))
				{
					ptExitPoints[nTotalPoints][1].x = i - 1;
					ptExitPoints[nTotalPoints][1].y = m_Map.GetCY() - 1;
					break;
				}
			}

			nTotalPoints++;
			break;
		}
	}

	for(INT i = 0; i < m_Map.GetCY(); i++)
	{
		if(!(m_Map[0][i] % 2))
		{
			ptExitPoints[nTotalPoints][0].x = 0;
			ptExitPoints[nTotalPoints][0].y = i;

			for(i++; i < m_Map.GetCY(); i++)
			{
				if((m_Map[0][i] % 2))
				{
					ptExitPoints[nTotalPoints][1].x = 0;
					ptExitPoints[nTotalPoints][1].y = i - 1;
					break;
				}
			}

			nTotalPoints++;
			break;
		}
	}

	for(INT i = 0; i < m_Map.GetCY(); i++)
	{
		if(!(m_Map[m_Map.GetCX() - 1][i] % 2))
		{
			ptExitPoints[nTotalPoints][0].x = m_Map.GetCX() - 1;
			ptExitPoints[nTotalPoints][0].y = i;

			for(i++; i < m_Map.GetCY(); i++)
			{
				if((m_Map[m_Map.GetCX() - 1][i] % 2))
				{
					ptExitPoints[nTotalPoints][1].x = m_Map.GetCX() - 1;
					ptExitPoints[nTotalPoints][1].y = i - 1;
					break;
				}
			}

			nTotalPoints++;
			break;
		}
	}

	LPPOINT ptCenters = new POINT[nTotalPoints];
	for(INT i = 0; i < nTotalPoints; i++)
	{
		INT nXDiff = ptExitPoints[i][1].x - ptExitPoints[i][0].x;
		INT nYDiff = ptExitPoints[i][1].y - ptExitPoints[i][0].y;
		INT nXCenter = 0, nYCenter = 0;

		if(nXDiff > 0)
		{
			if(nXDiff % 2)
				nXCenter = ptExitPoints[i][0].x + ((nXDiff - (nXDiff % 2)) / 2);
			else
				nXCenter = ptExitPoints[i][0].x + (nXDiff / 2);
		}

		if(nYDiff > 0)
		{
			if(nYDiff % 2)
				nYCenter = ptExitPoints[i][0].y + ((nYDiff - (nYDiff % 2)) / 2);
			else
				nYCenter = ptExitPoints[i][0].y + (nYDiff / 2);
		}

		ptCenters[i].x = nXCenter ? nXCenter : ptExitPoints[i][0].x;
		ptCenters[i].y = nYCenter ? nYCenter : ptExitPoints[i][0].y;
	}

	for(Room2* pRoom = GetUnitLevel((*p_D2CLIENT_PlayerUnit))->pRoom2First; pRoom; pRoom = pRoom->pRoom2Next)
	{
		Room2* *pNear = pRoom->pRoom2Near;
		for(DWORD i = 0; i < pRoom->dwRoomsNear; i++)
		{
			if(pNear[i]->pLevel->dwLevelNo != GetUnitLevel((*p_D2CLIENT_PlayerUnit))->dwLevelNo)
			{
				INT nRoomX = pRoom->dwPosX * 5;//((pRoom->pLevel->dwPosX * 5) + pRoom->dwPosX);
				INT nRoomY = pRoom->dwPosY * 5;//((pRoom->pLevel->dwPosY * 5) + pRoom->dwPosY);

				for(INT j = 0; j < nTotalPoints; j++)
				{
					if((ptCenters[j].x + m_LevelOrigin.x) >= (WORD)nRoomX && (ptCenters[j].x + m_LevelOrigin.x) <= (WORD)(nRoomX + (pRoom->dwSizeX * 5)))
					{
						if((ptCenters[j].y + m_LevelOrigin.y) >= (WORD)nRoomY && (ptCenters[j].y + m_LevelOrigin.y) <= (WORD)(nRoomY + (pRoom->dwSizeY * 5)))
						{
							if(nCurrentExit >= nMaxExits)
								return FALSE;

							lpLevel[nCurrentExit] = new LEVELEXIT;
							lpLevel[nCurrentExit]->dwTargetLevel = pNear[i]->pLevel->dwLevelNo;
							lpLevel[nCurrentExit]->ptPos.x = ptCenters[j].x + m_LevelOrigin.x;
							lpLevel[nCurrentExit]->ptPos.y = ptCenters[j].y + m_LevelOrigin.y;
							nCurrentExit++;
						}
					}
				}

				break;
			}
		}
	}

	return TRUE;
}

WORD CMap::GetCollisionInfo(INT nX, INT nY)
{
	nX -= m_LevelOrigin.x;
	nY -= m_LevelOrigin.y;

	if(!m_Map.IsValidIndex(nX, nY))
		return NULL;

	return m_Map[nX][nY];
}

BOOL CMap::ExportCollisionMap(CMatrix<WORD, WORD>& cMatrix)
{
	m_Map.Lock();
	m_Map.ExportData(cMatrix);
	m_Map.Unlock();

	return TRUE;
}

/*bool RevealLevel(Level *pLevel)
{
	if (!pLevel)
		return false;

	//Initalize the automap layer to the level given
	if (!InitAutomapLayer(pLevel->dwLevelNo))
		return false;

	UnitAny *pUnit = D2CLIENT_GetPlayerUnit ();
	if (!pUnit)
		return false;

	//Loop each room in this level
	for (Room2 *pRoom2 = pLevel->pRoom2First; pRoom2; pRoom2 = pRoom2->pRoom2Next)
	{
		//A bool to check if we have added Room Data
		bool nAdded = false;

		//Add the room data if it is needed
		if (!pRoom2->pRoom1)
		{
			D2COMMON_AddRoomData(pLevel->pMisc->pAct,pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, pUnit->pPath->pRoom1);
			nAdded = true;
		}

		//Insure that we have a valid room before revealing it.
		if (!pRoom2->pRoom1)
			continue;
	
		//Reveal the map!
		D2CLIENT_RevealAutomapRoom(pRoom2->pRoom1, TRUE, (*p_D2CLIENT_AutomapLayer));

		DrawPresets(pRoom2);

		//Remove Room Data if we added it!
		if (nAdded)
			D2COMMON_RemoveRoomData(pLevel->pMisc->pAct, pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, D2CLIENT_GetPlayerUnit()->pPath->pRoom1);
	}

	//Reset the map layer to the current area
	InitAutomapLayer(pUnit->pPath->pRoom1->pRoom2->pLevel->dwLevelNo);

	return true;
}*/

/*BOOL RevealAct ()
{
	//Grab the player unit now, so we don't call this 100 times
	UnitAny *pUnit = D2CLIENT_GetPlayerUnit ();
	if (!pUnit)
		return false;

	//The level id's for each town and the last one is the final map
	int townLevels[6] = {1, 40, 75, 103, 109, 136 + 1}; 

	
	//We are going to loop every level in the current act.
	for (int nLevel = townLevels[pUnit->dwAct] + 1; nLevel < townLevels[pUnit->dwAct + 1]; nLevel++)
	{
		Level *pLevel = GetLevelPointer(pUnit->pAct->pMisc, nLevel);

		//Insure we have a good level struct
		if(!pLevel)
			continue;

		//Init the level so we can add map to it
		if(!pLevel->pRoom2First)
			D2COMMON_InitLevel(pLevel);

		if(!pLevel->pRoom2First)
			continue;

		//Reveal the level!
		RevealLevel(pLevel);
	}

	Print("ÿc4[xMap]ÿc0: Revealed Act %i", pUnit->dwAct + 1);
	return true;
}

//----Next functions have been taken from D2BS----

DWORD __declspec(naked) __fastcall D2CLIENT_InitAutomapLayer_STUB(DWORD nLayerNo)
{
	__asm 
	{
		push eax;
		mov eax, ecx;
		call D2CLIENT_InitAutomapLayer_I;
		pop eax;
		ret;
	}
}

AutomapLayer* InitAutomapLayer(DWORD levelno)
{
	AutomapLayer2 *pLayer = D2COMMON_GetLayer(levelno);
	if (!pLayer)
		return false;
	return D2CLIENT_InitAutomapLayer(pLayer->nLayerNo);
}*/

DWORD GetPlayerArea(VOID)
{
	if(D2CLIENT_GetPlayerUnit())
		if(D2CLIENT_GetPlayerUnit()->pPath)
			if(D2CLIENT_GetPlayerUnit()->pPath->pRoom1)
				if(D2CLIENT_GetPlayerUnit()->pPath->pRoom1->pRoom2)
					if(D2CLIENT_GetPlayerUnit()->pPath->pRoom1->pRoom2->pLevel)
						return D2CLIENT_GetPlayerUnit()->pPath->pRoom1->pRoom2->pLevel->dwLevelNo;
	return NULL;
}

BOOL GameReady(VOID)
{
	if(D2CLIENT_GetPlayerUnit())
		if(D2CLIENT_GetPlayerUnit()->pInventory)
			if(D2CLIENT_GetPlayerUnit()->pPath)
				if(D2CLIENT_GetPlayerUnit()->pPath->xPos)
					if(D2CLIENT_GetPlayerUnit()->pPath->pRoom1)
						if(D2CLIENT_GetPlayerUnit()->pPath->pRoom1->pRoom2)
							if(D2CLIENT_GetPlayerUnit()->pPath->pRoom1->pRoom2->pLevel)
								if (D2CLIENT_GetPlayerUnit()->pAct)
									if(GetPlayerArea() != NULL)
										return TRUE;
	return FALSE;
}


//From TheAce :)
unsigned long SuspendThreadsInProcess(unsigned long pid) {

  THREADENTRY32 th = { sizeof(THREADENTRY32) };
  HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);
  HANDLE hCurrentThread;
  DWORD self = GetCurrentThreadId();
  
  if (Thread32First(hThreadSnap, &th)) {

    //Loop through all the threads in the snapshot
    do {
      if (th.th32OwnerProcessID == pid) {
        if (th.th32ThreadID == self)
          continue;
        if ((hCurrentThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, th.th32ThreadID)) == NULL)
          return -1;
        if (SuspendThread(hCurrentThread) == -1)
          return -1;
      }
    } while (Thread32Next(hThreadSnap, &th));
  }

  // All threads suspended
  return 0;
}


unsigned long ResumeThreadsInProcess(unsigned long pid) {

  THREADENTRY32 th = { sizeof(THREADENTRY32) };
  HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);
  HANDLE hCurrentThread;
  DWORD self = GetCurrentThreadId();
  
  if (Thread32First(hThreadSnap, &th)) {

    //Loop through all the threads in the snapshot
    do {
      if (th.th32OwnerProcessID == pid) {
        if (th.th32ThreadID == self)
          continue;
        if ((hCurrentThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, th.th32ThreadID)) == NULL)
          return -1;
        if (ResumeThread(hCurrentThread) == -1)
          return -1;
      }
    } while (Thread32Next(hThreadSnap, &th));
  }

  // All threads resumed
  return 0;
}

/*void DrawPresets (Room2 *pRoom2)
{
	UnitAny *pPlayer = D2CLIENT_GetPlayerUnit ();

	for (PresetUnit *pUnit = pRoom2->pPreset; pUnit; pUnit = pUnit->pPresetNext)
	{
		int mCell = -1;
		if (pUnit->dwType == 1)//Special NPCs.
		{
			if (pUnit->dwTxtFileNo == 256)//Izzy
				mCell = 300;
			if (pUnit->dwTxtFileNo == 745)//Hephasto
				mCell = 745;
		} else if (pUnit->dwType == UNIT_OBJECT) { //Objects on Map
			
			//Add's a special Chest icon over the hidden uberchests in Lower Kurast
			if (pUnit->dwTxtFileNo == 580 && pRoom2->pLevel->dwLevelNo == 79)		
				mCell = 318;
			
			
			//Special Units that require special checking:)
			if (pUnit->dwTxtFileNo == 371) 
				mCell = 301; //Countess Chest
			if (pUnit->dwTxtFileNo == 152) 
				mCell = 300; //A2 Orifice
			if (pUnit->dwTxtFileNo == 460) 
				mCell = 1468; //Frozen Anya
			if ((pUnit->dwTxtFileNo == 402) && (pRoom2->pLevel->dwLevelNo == 46))
				mCell = 0; //Canyon/Arcane Waypoint
			if ((pUnit->dwTxtFileNo == 267) && (pRoom2->pLevel->dwLevelNo != 75) && (pRoom2->pLevel->dwLevelNo != 103))
				mCell = 0;
			if ((pUnit->dwTxtFileNo == 376) && (pRoom2->pLevel->dwLevelNo == 107))
				mCell = 376;

			if (mCell == -1)
			{
				//Check for stupid objects.
				if(pUnit->dwTxtFileNo > 574)
					mCell = pUnit->dwTxtFileNo - 574;
				else {
					//Get the object cell
					ObjectTxt *obj = D2COMMON_GetObjectTxt(pUnit->dwTxtFileNo);
					if (obj->nAutoMap == 310)
					{
						ShrineDesc sd = { 0, pUnit->dwPosX + (pRoom2->dwPosX * 5),
							pUnit->dwPosY + (pRoom2->dwPosY * 5), pPlayer->dwAct };
						lShr.push_back(sd);
					}

					if (mCell == -1)
					{
						//Check if it is an shrine.
						if(obj->nAutoMap == 310) {
							mCell = (obj->nSubClass & 1) ? 310 : 0;//Check to see if it is a bad shrine.
						}
						else
							if (mCell == -1)
							{
								mCell = obj->nAutoMap;//Set the cell number then.
							}
					}
				}
			}
		} else if (pUnit->dwType == UNIT_TILE) {
			LevelNameInfo *pInfo = new LevelNameInfo;
			for (RoomTile *pTile = pRoom2->pRoomTiles; pTile; pTile = pTile->pNext)
			{
				if (*(pTile->nNum) == pUnit->dwTxtFileNo)
				{
					pInfo->nLevelId = pTile->pRoom2->pLevel->dwLevelNo;
					break;
				}
			}
			pInfo->nAct = pPlayer->dwAct;
			pInfo->nX = (pUnit->dwPosX + (pRoom2->dwPosX * 5) - (8 << 1));
			pInfo->nY = (pUnit->dwPosY + (pRoom2->dwPosY * 5) - 10);
			LevelNames.Add(pInfo);
		}

		if ((mCell > 0) && (mCell < 1258))
		{
			AutomapCell *pCell = D2CLIENT_NewAutomapCell();
			pCell->nCellNo = mCell;
			int pX = (pUnit->dwPosX + (pRoom2->dwPosX * 5));
			int pY = (pUnit->dwPosY + (pRoom2->dwPosY * 5));
			pCell->xPixel = (((pX - pY) * 16) / 10) + 1;
			pCell->yPixel = (((pY + pX) * 8) / 10) - 3;

			D2CLIENT_AddAutomapCell(pCell, &((*p_D2CLIENT_AutomapLayer)->pObjects));
		}
	}
}

*/