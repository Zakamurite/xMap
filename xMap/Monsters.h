#ifndef _MAPMON_H
#define _MAPMON_H

enum 
{  
	NPC_MODE_DEATH = 0,		// NPC death
	NPC_MODE_STAND,			// NPC standing still
	NPC_MODE_WALK,			// NPC walking
	NPC_MODE_BEING_HIT,		// NPC getting hit
	NPC_MODE_ATTACK1,		// NPC attacking 1
	NPC_MODE_ATTACK2,		// NPC attacking 2
	NPC_MODE_BLOCK,			// NPC blocking
	NPC_MODE_CAST,			// NPC casting spell skill
	NPC_MODE_USESKILL1,		// NPC using skill 1
	NPC_MODE_USESKILL2,		// NPC using skill 2
	NPC_MODE_USESKILL3,		// NPC using skill 3
	NPC_MODE_USESKILL4,		// NPC using skill 4
	NPC_MODE_DEAD,			// NPC dead
	NPC_MODE_BEING_KNOCKBACK,	// NPC being knocked back
	NPC_MODE_SEQUENCE,		// NPC sequence
	NPC_MODE_RUN			// NPC running
};

void DrawActiveRooms ();
//BOOL IsValidMonster(UnitAny *pUnit);
VOID DrawAutomapText ();
DWORD __fastcall D2CLIENT_GetUnitName_STUB(DWORD UnitAny);

int IsObjectChest(int objno);

struct AutomapInfo
{
	char* Message;
	char* Data;
};

string GetMonsterResists(UnitAny *unit);
void GetHighestTC(int tcno, TCTallys *tallys);
void InitTCList();
//void GetMonsterLevelTC(wchar_t *str, UnitAny *unit, DWORD no);
int GetMonsterLvl(UnitAny *unit);
int GetMonsterTC(UnitAny *unit);
int GetSTC(int no);
int GetMTC(int no);
#endif