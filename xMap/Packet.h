#ifndef _PACKET_H
#define _PACKET_H

BOOL Interact(DWORD dwUnitId, DWORD dwType, BOOL bCheckOverride);
void OnGamePacketSent_STUB();
BOOL __fastcall OnGamePacketSent(LPBYTE aPacket, DWORD aLen);
VOID OnGamePacketReceived_STUB();
BOOL __fastcall OnGamePacketReceived(LPBYTE aPacket, DWORD aLen);

void OpenStash();
void OpenCube();
void Resynch();
void MoveNPC(DWORD npcId);
void LogPacket(LPBYTE aPacket, DWORD aLen, bool in);

#endif