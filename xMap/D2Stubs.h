#ifndef _D2STUBS_H
#define _D2STUBS_H

#define D2TXTCODE(x) ( ((x)&0xff)<<24 | ((x)>>8&0xff)<<16 | ((x)>>16&0xff)<<8 | ((x)>>24&0xff) )
#define STRING_EQUAL(a,b) (TrimSpaces(a).find(TrimSpaces(b)) == 0 && TrimSpaces(a).size() == TrimSpaces(b).size())

void LightingPatch_ASM();
void WeatherPatch_ASM();
DWORD __fastcall D2CLIENT_clickParty_ASM(DWORD RosterUnit, DWORD Mode);
VOID GameInput_Interception();
DWORD __fastcall GameInput(wchar_t* wMsg);
DWORD __fastcall D2DrawRectFrame_STUB(RECT* pRect);
LONG WINAPI GameWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void __fastcall NextGameNamePatch(Control* box, BOOL (__stdcall *FunCallBack)(Control*,DWORD,DWORD));
void ItemNamePatch_ASM();
void __fastcall ItemNamePatch(wchar_t *name, UnitAny *item);
DWORD __fastcall TestPvpFlag_STUB(DWORD planum1, DWORD planum2, DWORD flagmask);
DWORD __fastcall D2CLIENT_GetUIVar_STUB(DWORD varno);
DWORD __fastcall D2CLIENT_GetUnitFromId_STUB(DWORD unitid, DWORD unittype);
DWORD __fastcall D2CLIENT_GetInventoryId_STUB(UnitAny* pla, DWORD unitno, DWORD arg3);
void ViewInventoryPatch1_ASM();
void ViewInventoryPatch2_ASM();
void ViewInventoryPatch3_ASM();
UnitAny* GetViewUnit ();
UnitAny *ViewInventoryPatch1 ();
void __stdcall ShakeScreenPatch(DWORD *xpos, DWORD *ypos);
void ScrollMap(char xinc, char yinc);
struct Toggles
{
	int nKey;
	LPVOID nVar;
	char* pMsg;
};
void PermShowOrbPatch_ASM();
void PermShowOrbPatch2_ASM();
void PermShowOrbPatch3_ASM();
void MonsterDeathPatch_ASM();
BOOL PlainScreen();
BOOL Say(CHAR* lpMessage, ...);

/*InventoryLocation* GetInVentoryLocationInfo(short x, short y, int loctype);
void __stdcall RButtonUpHandlerPatch(D2MSG *pmsg);
void RButtonUpHandlerPatch_ASM();*/
////
void D2LogMessage(wchar_t** buf);
/////

void DrawPlayerBlobPatch_ASM();
void DrawAutomapBlob_ASM();
void __fastcall DrawAutomapBlob(int xpos, int ypos, DWORD col, DWORD unittype);
void DrawPlayerBlobPatch2_ASM();
void DrawObjectBlobPatch_ASM();
void DrawMonsterBlobPatch_ASM();
BYTE __fastcall MixedBlobColPatch(UnitAny *pUnit);
BYTE __fastcall MonsterBlobColPatch(UnitAny *mon);
BYTE __fastcall MonsterBlobColPatch2(UnitAny *mon);
void MonsterBlobColPatch_ASM();
void DrawItemBlobPatch_ASM();
void __stdcall DrawAutomapCellPatch(CellContext *pCellContext, DWORD xpos, DWORD ypos, RECT *cliprect, DWORD bright);

void OutTownSelectPatch1_ASM(/* four args on the stack*/);
int __fastcall OutTownSelectPatch2(UnitAny *unit);
void OutTownSelectPatch2_ASM();
void OutTownSelectPatch3_ASM();
BOOL ViewTestUnit(UnitAny *unit);
BOOL ViewingTestMonster(UnitAny *mon);

BOOL __fastcall InfravisionPatch3(UnitAny *unit);
BOOL __fastcall InfravisionPatch2(UnitAny *unit);
BOOL __fastcall InfravisionPatch(UnitAny *unit);
void InfravisionPatch_ASM();

void CheckD2WinEditBox();
BOOL __cdecl InputLinePatch(BYTE keycode);
void InputLinePatch_ASM();
BOOL __stdcall EditBoxCallBack(Control* hwnd, DWORD arg2, DWORD arg3);
BOOL __cdecl InitD2EditBox();
void InputLinePatch2_ASM();

void MessageLogPatch1_ASM();
void MessageLogPatch2_ASM();
#endif