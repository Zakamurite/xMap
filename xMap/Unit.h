#ifndef _UNIT_H
#define _UNIT_H

BOOL IsMercClassId(DWORD dwClassID);
Level* GetUnitLevel(UnitAny* unit);
BOOL TestPlayerInTown(UnitAny *unit);
RosterUnit* FindPartyByName(CHAR* szName);
void RunToXY(WORD x, WORD y);
void RunToEntity(DWORD unitType, DWORD id);
UnitAny* FindNearestPortal(string owner);
BOOL HostilePlayer(DWORD dwUnitId);
UnitAny* D2CLIENT_FindUnit(DWORD dwId, DWORD dwType);
PresetUnit* FindPresetUnit(DWORD dwClassId, DWORD dwType, Room2** pRoom);
#endif