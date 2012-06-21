#ifndef _MAPFUNC_H
#define _MAPFUNC_H

#include "Matrix.h"

#define CELLNO_MYSHRINES 1176
#define CELLNO_WAYPOINT 307
#define CELLNO_SHRINE 310
#define NUMOF_SHRINES 23

#define MAP_DATA_NULL       -1
#define MAP_DATA_AVOID      11115
#define MAP_DATA_FILL       11111

BOOL GameReady(VOID);
DWORD GetPlayerArea(VOID);
unsigned long SuspendThreadsInProcess(unsigned long pid);
unsigned long ResumeThreadsInProcess(unsigned long pid);

typedef struct CaveDescriptor_t
{
    CHAR szName[0x40];
    DWORD dwAct;
    POINT ptPos;
    DWORD dwLevelNo;
    DWORD dwTargetLevelNo;
} CAVEDESC, *LPCAVEDESC;

typedef struct LevelExit_t
{
    POINT ptPos;
    DWORD dwTargetLevel;
} LEVELEXIT, *LPLEVELEXIT;

DWORD __fastcall D2CLIENT_InitAutomapLayer_STUB(DWORD nLayerNo);
Level* GetLevelPointer(ActMisc *pActMisc, int nLevel);

class CMap
{
public:
    CMap();
    virtual ~CMap();

    VOID RevealAutomap();
    BOOL CreateCollisionMap();
    BOOL GetLevelExits(LPLEVELEXIT *lpLevel, INT nMaxExits);
    WORD GetCollisionInfo(INT nX, INT nY);
    BOOL ExportCollisionMap(CMatrix<WORD, WORD>& cMatrix);
    DWORD GetTileLevelNo(Room2* lpRoom2, DWORD dwTileNo);
    BOOL GetCaveExits(LPCAVEDESC *lpLevel, INT nMaxExits, DWORD dwAct);
    UCHAR m_RevealedActs[5];
    CArrayEx<ShrineDesc*, ShrineDesc*> m_Shrines;

protected:
    bool RevealLevel(Level *pLevel);
    AutomapLayer* InitAutomapLayer(DWORD levelno);
    void DrawPresets (Room2 *pRoom2);
    VOID AddAutomapRoom(Room2* pRoom2);
    VOID RemoveAutomapRoom(Room2* pRoom2);
    
    INT GetUnitCellNumber(DWORD dwClassId, DWORD dwLevelNo);

    BOOL IsGap(INT nX, INT nY);
    BOOL FillGaps();
    BOOL AddCollisionData(CollMap* pColl);
    BOOL AddCollisionData(Room2* pRoom2, CArrayEx<DWORD, DWORD>& aSkip);

    UCHAR m_ActLevels[6];
    CArrayEx<LPCAVEDESC, LPCAVEDESC> m_LevelExits;

    INT m_LastLevel;
    INT m_SizeX;
    INT m_SizeY;
    POINT m_LevelOrigin;
    CMatrix<WORD, WORD> m_Map;
};

#endif
