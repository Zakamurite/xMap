#include "xMap.h"

void CastOnUnit(WORD wSpellId, UnitAny* pUnit, BOOL bLeft)
{
	UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
	if(!pPlayer) return;
	if(!GetSkill(wSpellId)) return;

	SetSkill(wSpellId, bLeft);

	BYTE *aPacket = new BYTE[9];
	aPacket[0] = bLeft ? 0x06 : 0x0D;
	*(DWORD*)&aPacket[1] = pUnit->dwType;
	*(DWORD*)&aPacket[5] = pUnit->dwUnitId;
	D2NET_SendPacket(9, 1, aPacket);
	delete aPacket;
}

BOOL SetSkill(WORD wSkillId, BOOL bLeft)
{
	UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
	if(!pPlayer) 
		return FALSE;

	BYTE aPacket[9];

	aPacket[0] = 0x3C;
	*(WORD*)&aPacket[1] = wSkillId;
	aPacket[3] = 0;
	aPacket[4] = (bLeft) ? 0x80 : 0;
	*(DWORD*)&aPacket[5] = 0xFFFFFFFF;

	D2NET_SendPacket(9, 1, aPacket);
	return TRUE;
}

INT GetSkill(WORD wSkillId)
{
	UnitAny* pPlayer = D2CLIENT_GetPlayerUnit();
	if(!pPlayer) 
		return 0;

	for(Skill* pSkill = pPlayer->pInfo->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
		if(pSkill->pSkillInfo->wSkillId == wSkillId)
			return pSkill->dwSkillLevel ? pSkill->dwSkillLevel : 1;

	return 0;
}

BOOL CastSkillXY(WORD wSpellId, DWORD x, DWORD y)
{
//0c   5   Right skill         0c [WORD x] [WORD y] 
	if(!GetSkill(wSpellId)) 
		return FALSE;

	SetSkill(wSpellId, FALSE);

	BYTE *aPacket = new BYTE[5];
	aPacket[0] = 0x0C;
	*(WORD*)&aPacket[1] = x;
	*(WORD*)&aPacket[3] = y;
	D2NET_SendPacket(5, 1, aPacket);
	delete aPacket;

	return TRUE;
}

void CastXY(DWORD x, DWORD y, BOOL bLeft)
{
	BYTE *aPacket = new BYTE[5];
		
	aPacket[0] = bLeft ? 0x05 : 0x0C;
	*(WORD*)&aPacket[1] = x;
	*(WORD*)&aPacket[3] = y;
	D2NET_SendPacket(5, 1, aPacket);
	delete aPacket;
}