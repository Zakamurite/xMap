#include "ArrayEx.h"
//#include "String2.h"
#include "D2Structs.h"

/*enum DllBase
{
    DLLBASE_D2CLIENT    = 0x6FAB0000,
    DLLBASE_D2COMMON    = 0x6FD50000,
    DLLBASE_D2GFX       = 0x6FA80000,
    DLLBASE_D2WIN       = 0x6F8E0000,
    DLLBASE_D2LANG      = 0x6FC00000,
    DLLBASE_D2CMP       = 0x6FE10000,
    DLLBASE_D2MULTI     = 0x6F9D0000,
    DLLBASE_BNCLIENT    = 0x6FF20000,
    DLLBASE_D2NET       = 0x6FFB0000,   // conflict with STORM.DLL
    DLLBASE_STORM       = 0x6FBF0000,
    DLLBASE_FOG         = 0x6FF50000
};*/
#ifdef _DEFINE_VARS

enum {DLLNO_D2CLIENT, DLLNO_D2COMMON, DLLNO_D2GFX, DLLNO_D2LANG, DLLNO_D2WIN, DLLNO_D2NET, DLLNO_D2GAME, DLLNO_D2LAUNCH, DLLNO_FOG, DLLNO_BNCLIENT, DLLNO_STORM, DLLNO_D2CMP, DLLNO_D2MULTI};

#define DLLOFFSET(a1,b1)            ((DLLNO_##a1)|((b1)<<8))
#define FUNCPTR(d1,v1,t1,t2,o1)     typedef t1 d1##_##v1##_t t2; d1##_##v1##_t *d1##_##v1 = (d1##_##v1##_t *)DLLOFFSET(d1,o1);
#define VARPTR(d1,v1,t1,o1)         typedef t1 d1##_##v1##_t;    d1##_##v1##_t *p_##d1##_##v1 = (d1##_##v1##_t *)DLLOFFSET(d1,o1);
#define ASMPTR(d1,v1,o1)            DWORD d1##_##v1 = DLLOFFSET(d1,o1);

#else

#define FUNCPTR(d1,v1,t1,t2,o1)     typedef t1 d1##_##v1##_t t2;    extern d1##_##v1##_t *d1##_##v1;
#define VARPTR(d1,v1,t1,o1)         typedef t1 d1##_##v1##_t;       extern d1##_##v1##_t *p_##d1##_##v1;
#define ASMPTR(d1,v1,o1)            extern DWORD d1##_##v1;

#endif
#define _D2PTRS_START   D2CLIENT_RevealAutomapRoom

FUNCPTR(D2CLIENT, RevealAutomapRoom, void __stdcall, (Room1 *pRoom1, DWORD dwClipFlag, AutomapLayer *aLayer), 0x404C0)

FUNCPTR(D2CLIENT, GetCurrentInteractingNPC, UnitAny* __fastcall, (VOID), 0x18450)
VARPTR(D2CLIENT, FPS, DWORD, 0x11C388) // Updated 

FUNCPTR(D2WIN, TakeScreenshot, void __fastcall, (void), -10196)
FUNCPTR(D2WIN, GetEditBoxText, wchar_t* __fastcall, (Control* box), -10075) //updated by me
FUNCPTR(D2WIN, CreateEditBox, Control* __fastcall, (DWORD style, int ypos, int xpos, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD size, void* buf), -10115)  //updated by hz
VARPTR(D2CLIENT, szLastChatMessage, wchar_t, 0x11FC40) // updated by zak. 0x6FBCFC40-d2cl
VARPTR(D2WIN, pFocusedControl, Control*, 0x5C728) //UPDATED by me 0x6F93C728-d2win
FUNCPTR(D2WIN, SetEditBoxProc, void __fastcall, (Control* box, BOOL (__stdcall *FunCallBack)(Control*,DWORD,DWORD)), -10113) //updated
FUNCPTR(D2WIN, SetControlText, void* __fastcall, (Control* box, wchar_t* txt), -10095) // Updated 
FUNCPTR(D2WIN, DestroyEditBox, DWORD __fastcall, (Control* box), -10155) //updated by me
VARPTR(D2CLIENT, nTextLength, int, 0x11BF48) //UPDATED by me

FUNCPTR(D2COMMON, GetItemValue, int __stdcall, (UnitAny * player, UnitAny * item, DWORD difficulty, void* questinfo, int value, DWORD flag), -10122) 
VARPTR(D2CLIENT, Ping, DWORD, 0x1032BC) // Updated 6FBB32BC id d2

FUNCPTR(D2MULTI, SayInChannel, bool __stdcall, (char *szMessage), 0xFE50)

FUNCPTR(D2CLIENT, clickMap, VOID __stdcall, (DWORD MouseFlag, DWORD x, DWORD y, DWORD Type), 0x5CE80) // Updated 
                                                                                                    //6FB0CE80
FUNCPTR(D2NET, SendPacket, void __stdcall, (size_t aLen, DWORD arg1, BYTE* aPacket), -10036) 
FUNCPTR(D2NET, ReceivePacket, void __stdcall, (BYTE *aPacket, DWORD aLen), 0x6510) // Updated
FUNCPTR(D2NET, ReceivePacket_I, void __stdcall, (BYTE *aPacket, DWORD aLen), -10002) // Updated 

FUNCPTR(D2COMMON, GetItemFromInventory, UnitAny *__stdcall, (Inventory* inv),-11151) // Updated
FUNCPTR(D2COMMON, GetNextItemFromInventory, UnitAny *__stdcall, (UnitAny *pItem), -10770)// Updated

FUNCPTR(D2GFX, DrawAutomapCell, void __stdcall, (CellContext *context, DWORD xpos, DWORD ypos, RECT *cliprect, DWORD bright), -10061) //updated
FUNCPTR(D2GFX, DrawAutomapCell2, void __stdcall, (CellContext *context, DWORD xpos, DWORD ypos, DWORD bright2, DWORD bright, BYTE *coltab), -10024) 
ASMPTR(D2CLIENT, LoadUIImage_I, 0xBEED0) // Updated

FUNCPTR(D2CMP, InitCellFile, void __stdcall, (void *cellfile, CellFile **outptr, char *srcfile, DWORD lineno, DWORD filever, char *filename), -10006)
FUNCPTR(D2CMP, DeleteCellFile, void __stdcall, (CellFile *cellfile), -10106) 

FUNCPTR(D2CLIENT, GetMouseXOffset, DWORD __fastcall, (VOID), 0x5D670) // Updated
FUNCPTR(D2CLIENT, GetMouseYOffset, DWORD __fastcall, (VOID), 0x5D680) // Updated
FUNCPTR(D2COMMON, MapToAbsScreen, void __stdcall, (long *pX, long *pY), -10912)// Updated

FUNCPTR(D2COMMON, GetBaseStat, DWORD __stdcall, (UnitAny *Unit, DWORD dwStat, DWORD dwUkn), -10494) // Updated

FUNCPTR(D2COMMON, GetMonsterColorIndex, int __stdcall, (UnitAny *mon, int no), -10675)

ASMPTR(D2CLIENT, GetMonsterTxt_I2, 0x1670) //6FAB1630

//FUNCPTR(D2COMMON, GetSuperuniqueTxt, SuperuniqueTxt * __stdcall, (DWORD monno), -10162) 
//FUNCPTR(D2COMMON, GetTreasureClasses, TreasureClass * __stdcall, (DWORD tcno, DWORD lvlno), -10909) 

//right click handler concerned
//D2FUNCPTR(D2COMMON, GetCursorItem, UnitAny * __stdcall, (UnitInventory * ptInventory), -10078) 
/*FUNCPTR(D2COMMON, GetCursorItem, UnitAny * __stdcall, (Inventory * ptInventory), -10078) 
FUNCPTR(D2COMMON, 10409, DWORD __stdcall, (UnitAny * pla, int invlocation, DWORD unk), -10301)
FUNCPTR(D2COMMON, 10247, int __stdcall, (Inventory* inventory, UnitAny *item, DWORD u3, DWORD u4, DWORD u5, int* u6, int* ItemCount, int invlocation), -10448)
VARPTR(D2CLIENT, UnkU3, DWORD, 0xECD14)
VARPTR(D2CLIENT, UnkU4, DWORD, 0xECD18)
VARPTR(D2CLIENT, UnkU6, DWORD, 0x11C2B8)*/

FUNCPTR(D2COMMON, GetFunUnk_5, DWORD __stdcall, (DWORD nLevelNo), -10698) 
FUNCPTR(D2COMMON, TestFunUnk_6, DWORD __stdcall, (UnitAny *unit1, UnitAny *unit2, DWORD arg3), -10233) 


FUNCPTR(D2CLIENT, InitAutomapLayer_I, AutomapLayer* __fastcall, (DWORD nLayerNo), 0x40650)
FUNCPTR(D2CLIENT, GetAutomapSize, DWORD __stdcall, (), 0x3CFC0)
FUNCPTR(D2CLIENT, NewAutomapCell, AutomapCell * __fastcall, (), 0x3D5B0 )
FUNCPTR(D2CLIENT, AddAutomapCell, void __fastcall, (AutomapCell *cell, AutomapCell **node), 0x3F090 ) 
FUNCPTR(D2CLIENT, GetUiVar_I, DWORD __fastcall, (DWORD dwVarNo), 0x8AA90) // Updated 
FUNCPTR(D2CLIENT, FindServerSideUnit, UnitAny * __fastcall, (DWORD id, DWORD type), 0x1F1C0) 
FUNCPTR(D2CLIENT, FindClientSideUnit, UnitAny* __fastcall, (DWORD dwId, DWORD dwType), 0x1F1A0) // Updated
FUNCPTR(D2CLIENT, DrawRectFrame, VOID __fastcall, (RECT *pRect), 0x8AB50)
FUNCPTR(D2CLIENT, GetMonsterOwner, DWORD __fastcall, (DWORD nMonsterId), 0xC3160) // Updated 
FUNCPTR(D2CLIENT, PrintGameString, void __stdcall, (wchar_t *wMessage, int nColor), 0x71740)
FUNCPTR(D2CLIENT, PrintGameStringAtBottomLeft, void __stdcall, (wchar_t* wMessage, int nColor), 0x71500) //Updated
FUNCPTR(D2CLIENT, GetDifficulty, BYTE __stdcall, (), 0x79CD0)
FUNCPTR(D2CLIENT, SetUiVar, DWORD __fastcall, (DWORD varno, DWORD howset, DWORD unknown1), 0x8EF00) // Updated 
FUNCPTR(D2CLIENT, GetMonsterTxt, MonsterTxt * __fastcall, (DWORD monno), 0x1390) // Updated+
FUNCPTR(D2CLIENT, GetUnitNoFromId, DWORD __fastcall, (DWORD unitid), 0xC31C0)
FUNCPTR(D2CLIENT, GetPlayerUnit, UnitAny*  __stdcall,(),0x1e490)
FUNCPTR(D2CLIENT, GetGameInfo, GameStructInfo *__stdcall, (), 0x120F0)
FUNCPTR(D2CLIENT, GetSelectedUnit, UnitAny * __stdcall, (), 0x6ECA0) 
FUNCPTR(D2CLIENT, CalcShake, void __stdcall, (DWORD *xpos, DWORD *ypos), 0xBB4F0) 
FUNCPTR(D2COMMON, GetQuestFlag, INT __stdcall, (VOID* QuestInfo, DWORD dwQuest, DWORD dwFlag), -10600)
FUNCPTR(D2CLIENT, GetQuestInfo, void* __stdcall, (), 0x17D00) 
FUNCPTR(D2CLIENT, GetUnknownFlag, DWORD __fastcall, (), 0x30080);

VARPTR(D2CLIENT, pUnitTable, POINT, 0x6FBCA960) 

VARPTR(D2CLIENT, PlayerUnit, UnitAny*, 0x11C3D0) 
VARPTR(D2CLIENT, PlayerList, RosterUnit *, 0x11C080)
VARPTR(D2CLIENT, AutomapLayer, AutomapLayer *, 0x11C2B4)
VARPTR(D2CLIENT, AutomapOn, DWORD, 0x102B80) 
VARPTR(D2CLIENT, Divisor, int, 0xF3B98)
VARPTR(D2CLIENT, Offset, POINT, 0x11C2E8)
VARPTR(D2CLIENT, UnitListHdr, UnitAny*, 0x11B97C) 
VARPTR(D2CLIENT, MouseX, DWORD, 0x101638)// Updated
VARPTR(D2CLIENT, MouseY, DWORD, 0x101638-4) // Updated 
VARPTR(D2CLIENT, xMapShake, int, 0x11B9B4)
VARPTR(D2CLIENT, yMapShake, int, 0xFD114) 
VARPTR(D2CLIENT, ptAutomap, POINT, 0x11C2D8)

ASMPTR(D2CLIENT, TestPvpFlag_I, 0x30DD0) // Updated 
ASMPTR(D2CLIENT, clickParty_I, 0x78D10)
ASMPTR(D2CLIENT, GetUnitName_I, 0x1F3D0)
ASMPTR(D2CLIENT, InputCall_I, 0x79670) // Updated 
ASMPTR(D2CLIENT, GetUnitFromId_I, 0x1E550) 

FUNCPTR(D2COMMON, AddRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1 * pRoom), 0x568F0)
FUNCPTR(D2COMMON, RemoveRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1 * pRoom), 0x56830)
FUNCPTR(D2COMMON, GetUnitStat, DWORD __stdcall, (UnitAny* pUnit, DWORD dwStat, DWORD dwStat2), -10658)
FUNCPTR(D2COMMON, GetObjectTxt, ObjectTxt * __stdcall, (DWORD objno), -10670) 
FUNCPTR(D2COMMON, GetUnitState, int __stdcall, (UnitAny *unit, DWORD stateno), -10295)
FUNCPTR(D2COMMON, GetItemTxt, ItemTxt * __stdcall, (DWORD itemno), -10887)
FUNCPTR(D2COMMON, GetLayer, AutomapLayer2* __fastcall, (DWORD dwLevelNo), -10301)
FUNCPTR(D2COMMON, GetLevel, Level * __fastcall, (ActMisc *pMisc, DWORD dwLevelNo), -11020)
FUNCPTR(D2COMMON, GetLevelTxt, LevelTxt * __stdcall, (DWORD levelno), -11102)
FUNCPTR(D2COMMON, InitLevel, void __stdcall, (Level *pLevel), -10721)
FUNCPTR(D2COMMON, GetItemFlag, DWORD __stdcall, (UnitAny *Item, DWORD dwFlagMask, DWORD dwLineNo, char *szFileName), -10554) // Updated 

ASMPTR(D2COMMON, GetLevelIdFromRoom_I, 0x55250)

FUNCPTR(D2GFX, DrawRectangle, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwTrans), -10062)
FUNCPTR(D2GFX, DrawLine, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwUnk), -10031)
FUNCPTR(D2GFX, GetScreenSize, DWORD __stdcall, (), -10043)
FUNCPTR(D2GFX, GetHwnd, HWND __stdcall, (), -10078) // Updated 

FUNCPTR(D2WIN, DrawText, void __fastcall, (wchar_t *wStr, int xPos, int yPos, DWORD dwColor, DWORD dwUnk), -10001) 
FUNCPTR(D2WIN, GetTextWidthFileNo, DWORD __fastcall, (wchar_t *wStr, DWORD* dwWidth, DWORD* dwFileNo), -10096)
FUNCPTR(D2WIN, SetTextSize, DWORD __fastcall, (DWORD dwSize), -10010)
FUNCPTR(D2WIN, SelectEditBoxText, void __fastcall, (Control* box, wchar_t* txt), -10035) // Updated 

FUNCPTR(D2MULTI, PrintChannelText, void __stdcall, (char *szText, DWORD dwColor), 0xF770)

VARPTR(D2LAUNCH, BnData, BnetData *, 0x25ACC);
VARPTR(D2WIN, FirstControl, Control *, 0x5C718)
//to update

FUNCPTR(D2COMMON, GetTreasureClasses, TreasureClass * __stdcall, (DWORD tcno, DWORD lvlno), -10909) //UPDATED
FUNCPTR(D2COMMON, GetSuperuniqueTxt, SuperuniqueTxt * __stdcall, (DWORD monno), -10162) //UPDATED

//
FUNCPTR(D2LANG, GetLocaleText, wchar_t* __fastcall, (WORD nLocaleTxtNo), -10005)
#define _D2PTRS_END    D2LANG_GetLocaleText

#undef FUNCPTR
#undef VARPTR
#undef ASMPTR

#define D2CLIENT_GetInventoryId        D2CLIENT_GetInventoryId_STUB
#define D2CLIENT_GetUiVar(dwVarNo)        (D2CLIENT_GetUIVar_STUB(dwVarNo))
#define D2CLIENT_GetUnitName(x)                (wchar_t*)D2CLIENT_GetUnitName_STUB((DWORD)x)
#define D2CLIENT_InitAutomapLayer(layerlvl)    ((AutomapLayer*)D2CLIENT_InitAutomapLayer_STUB(layerlvl))
#define D2CLIENT_clickParty(x,y)            (D2CLIENT_clickParty_ASM((DWORD)x, (DWORD)y))
#define D2CLIENT_DrawRectBox(x)                (D2DrawRectFrame_STUB((DWORD)x))
#define TestPvpFlag(dwId1, dwId2, dwFlag)    (TestPvpFlag_STUB(dwId1, dwId2, dwFlag))
#define D2CLIENT_GetUnitFromId(unitid, unittype)        ((UnitAny *)D2CLIENT_GetUnitFromId_STUB(unitid, unittype))
#define GetPlayerStat(nStat, nExtra)                (D2COMMON_GetUnitStat(*p_D2CLIENT_PlayerUnit, nStat, nExtra))
#define GetUnitStat(unit, stat)                (D2COMMON_GetUnitStat(unit, stat, 0))
