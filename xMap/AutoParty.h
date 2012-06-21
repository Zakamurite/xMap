#ifndef _AUTOPARTY_H
#define _AUTOPARTY_H

#define PARTY_NOT_IN_PARTY      0x00
#define PARTY_IN_PARTY          0x01
#define PARTY_INVITED_YOU       0x02
#define PARTY_INVITED_BY_YOU    0x04

#define PVP_INVITED_YOU     0x01 // Invited you, but you may not have accepted
#define PVP_INVITED_BY_YOU  0x02 // Invited by you, but he may not have accepted
#define PVP_HOSTILED_YOU    0x04 // Hostiled you, but you may not have hostiled him
#define PVP_HOSTILED_BY_YOU 0x08 // Hostiled by you, but he may not have hostiled you
#define PVP_ALLIED          0x10 // Allied
#define PVP_ALLIED_WITH_YOU 0x20 // Allied with you

#define clickParty_Loot     0
#define clickParty_Accept   1
#define clickParty_Invite   2
#define clickParty_Leave    3

DWORD WINAPI AutoPartyThread(LPVOID lpParameter);
DWORD GetPvpFlags(DWORD dwPlayerId);
RosterUnit* FindPartyById(DWORD dwUnitId);

#endif