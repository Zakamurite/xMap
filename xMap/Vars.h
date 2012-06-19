#ifdef _VARS
#define DEFINEVAR(type, name)		type name;
#define CARRAY(type, name)		CArrayEx<type, type> name;
#else
#define DEFINEVAR(type, name)		extern type name;
#define CARRAY(type, name)		extern CArrayEx<type, type> name;
#endif

#include "MapFunc.h"

CARRAY(LPENCHANTINFO, EnchantQueue)
//CARRAY(LevelNameInfo*, LevelNames)

DEFINEVAR(CMap*, cMap)
DEFINEVAR(INT, nLastLevel)
CARRAY(LPVECTOR, v_CurrentVectors[0x100])


DEFINEVAR(Control*, pD2WinEditBox)

DEFINEVAR(njipMap, njipClassId)

//DEFINEVAR(ItemDescList, itemCol)
CARRAY(ItemDesc*, itemCol)
//DEFINEVAR(CritSection, itemColCS)

DEFINEVAR(String, cUnitBlobFiles[6])
DEFINEVAR(String, cWaypointBlobFile)
DEFINEVAR(String, cRadiusBlobFile)

DEFINEVAR(CellFile*, cUnitBlobCells[6])
DEFINEVAR(CellFile*, cShrineBlobCells[24])
DEFINEVAR(CellFile*, cWaypointCell)
DEFINEVAR(CellFile*, cRadiusCell)

//DEFINEVAR(list<ShrineDesc>, lShr)
//DEFINEVAR(CritSection, lShrCS)
DEFINEVAR(BOOL, bOutOfTownSelect)
DEFINEVAR(INT, nOutOfTownSelectKey)

/*DEFINEVAR(BYTE, anMonsterTCs[1000])
DEFINEVAR(BYTE, anSuperuniqueTCs[100])*/

//DEFINEVAR(ItemIDs, njipClassId)

DEFINEVAR(INT, nLockedChestColor)
DEFINEVAR(INT, nOpenChestColor)
DEFINEVAR(BOOL, bShowAutomapChests)
DEFINEVAR(INT, nDangerousPing)
//DEFINEVAR(BOOL, nRevealedActs[5])
DEFINEVAR(BOOL, bShowItemValues)
DEFINEVAR(unsigned long int, nStartExp)
DEFINEVAR(BOOL, bReveal)

//MoveNPC
DEFINEVAR(INT, nBindNPCKey)
DEFINEVAR(INT, nPullNPCKey)
DEFINEVAR(INT, nInteractNPCKey)

//Misc
DEFINEVAR(INT, nOpenStashKey)
DEFINEVAR(INT, nOpenCubeKey)
DEFINEVAR(INT, nResynchKey)
DEFINEVAR(INT, nCharTable)
DEFINEVAR(BOOL, bFastTeleport)
DEFINEVAR(INT, nOpenPortalKey)
DEFINEVAR(String, cDeathMessage)
DEFINEVAR(String, cDropMessage)
DEFINEVAR(String, cSojsSoldMessage)
DEFINEVAR(String, cDiCloneMessage)
DEFINEVAR(BOOL, bHostilePlayers)
DEFINEVAR(BOOL, bSilentBots)
DEFINEVAR(INT, nFastExitKey)
DEFINEVAR(BOOL, bBackToTown)
DEFINEVAR(INT, nFastToTownKey)
DEFINEVAR(BOOL, bShowTauntMessages)
DEFINEVAR(INT, nTPPKKey)
DEFINEVAR(BOOL, bEnableTPPK)
DEFINEVAR(BOOL, bInputLinePatch)
DEFINEVAR(INT, nGoodGoldCount)
DEFINEVAR(BOOL, bShowWardenNotifications)
DEFINEVAR(BOOL, bSocketProtect)
DEFINEVAR(INT, nSocketProtectKey)
DEFINEVAR(BOOL, bShowTPsLeft)
DEFINEVAR(BOOL, bNoQuestBox)
DEFINEVAR(BOOL, bAntiFlash)


//Follow bot
DEFINEVAR(string, cFollowBotLeaderName)
DEFINEVAR(BOOL, bFollowBotToggle)
DEFINEVAR(INT, nFollowBotToggleKey)
DEFINEVAR(BOOL, bFollowBotWaiting)
DEFINEVAR(String, cWaitCommand)
DEFINEVAR(String, cTakeMyTpCommand)
DEFINEVAR(String, cTakeOwnTpCommand)
DEFINEVAR(String, cBoCommand)
DEFINEVAR(String, cGoCommand)
//DEFINEVAR(INT, cFollowBotXOffset)
//DEFINEVAR(INT, cFollowBotYOffset)

DEFINEVAR(String, cTownCommand)
DEFINEVAR(String, cOpenTpCommand)
DEFINEVAR(String, cExitGameCommand)

//Chant bot
DEFINEVAR(String, cEnchantMe)
DEFINEVAR(String, cEnchantMerc)
DEFINEVAR(String, cEnchantAll)
DEFINEVAR(INT, nEnchantBotToggleKey)
DEFINEVAR(BOOL, cEnchantBotToggle)

//Chicken
DEFINEVAR(DWORD, nChickenLifePercent)
DEFINEVAR(DWORD, nChickenLife)
DEFINEVAR(BOOL, bToggleChickenHostile)
DEFINEVAR(BOOL, bToggleChicken)
DEFINEVAR(INT, nChickenPing)
DEFINEVAR(BOOL, bChickenToTown)
DEFINEVAR(BOOL, bChickenToTownOnHostile)

//Visuals
DEFINEVAR(BOOL, bFullLoS)
DEFINEVAR(BOOL, bNoWeather)
DEFINEVAR(BOOL, bDisableBossDeathAnims)
DEFINEVAR(BOOL, bInfravision)
DEFINEVAR(BOOL, bChangeItemColors)
DEFINEVAR(BOOL, cHideItems)
DEFINEVAR(INT,	nHideItemsKey)
DEFINEVAR(BOOL, bDrawAutomapItems)
DEFINEVAR(BYTE, cMonsterDeathAnims[1000])
DEFINEVAR(BOOL, bDisableMonsterDeathAnims)
DEFINEVAR(BOOL, bHideCorpses)

DEFINEVAR(BOOL, bAutoLastGameName)
DEFINEVAR(BOOL, bShowItemSockets)
DEFINEVAR(BOOL, bShowItemEthereal)
DEFINEVAR(BOOL, bShowItemiLvl)
DEFINEVAR(BOOL, bAddNameToWindow)
DEFINEVAR(String, cCommandPrefix)
DEFINEVAR(INT, nShowInvKey)
DEFINEVAR(INT, nRevealMapKey)
DEFINEVAR(BOOL, bShowRuneNumbers)

DEFINEVAR(BOOL, bShowActiveRooms)
DEFINEVAR(INT, nActiveRoomsToggle)
DEFINEVAR(INT, nActiveRoomsColor)

//Life Percent Settings
DEFINEVAR(BOOL, bShowPercents)
DEFINEVAR(INT, nLifePercentToggle)
DEFINEVAR(BOOL, bTogglePermShowOrbsText)

//Stat Settings
DEFINEVAR(BOOL, bShowStats)
DEFINEVAR(INT, nShowStatsToggle)

//Scroll Map Settings
DEFINEVAR(BOOL, bScrollMap)
DEFINEVAR(INT, nScrollMapToggle)

//Auto Party Settings
DEFINEVAR(BOOL, bUseAutoParty)
DEFINEVAR(INT, nAutoPartyToggle)
DEFINEVAR(BOOL, bPOIP)

//Missile Settings
DEFINEVAR(BOOL, bShowMissiles)
DEFINEVAR(INT, nYourMissileColor)
DEFINEVAR(INT, nHostileMissileColor)
DEFINEVAR(INT, nNeutralMissileColor)
DEFINEVAR(INT, nPartyMissileColor)

//Monster Settings
DEFINEVAR(BOOL, bShowMonsters)
DEFINEVAR(INT, nNormalMonsterColor)
DEFINEVAR(INT, nChampionMonsterColor)
DEFINEVAR(INT, nMinionMonsterColor)
DEFINEVAR(INT, nBossMonsterColor)
DEFINEVAR(BOOL, bShowMonsterBarResists)
DEFINEVAR(String, cEnchDescSymbols[50])
DEFINEVAR(String, cAuraDescSymbols[7])
DEFINEVAR(BOOL, bShowEnchantments)
DEFINEVAR(String, cMonsterImmunitySymbol)


DEFINEVAR(CHAR, szOrigWinName[1024])
DEFINEVAR(CHAR, szPath[65535])
DEFINEVAR(CHAR, szLastGameName[1024])
DEFINEVAR(INT, nGameTimer)
DEFINEVAR(WNDPROC,OldWNDPROC)
DEFINEVAR(BOOL, bPluginTrace)
DEFINEVAR(UnitAny*, uViewingUnit)
DEFINEVAR(INT, xMapShake)
DEFINEVAR(INT, yMapShake)
#undef _VARS


