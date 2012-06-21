#pragma once
#include "xMap.h"

//int AreaLocaleIds[] = {0, 5055, 5054, 5053, 5052, 5051, 5050, 5049, 3714, 5047, 5046, 5045, 5044, 5043, 5042, 5041, 5040, 5039, 5038, 5037, 5036, 5035, 5034, 5033, 5032, 5031, 5030, 5029, 5028, 5027, 5026, 5025, 5024, 5023, 5022, 5021, 5020, 5019, 5018, 788, 852, 851, 850, 849, 848, 847, 846, 845, 844, 843, 842, 841, 840, 839, 838, 837, 836, 835, 834, 833, 832, 831, 830, 829, 828, 827, 826, 826, 826, 826, 826, 826, 826, 825, 824, 820, 819, 818, 817, 816, 815, 814, 813, 812, 810, 811, 809, 808, 806, 805, 807, 804, 845, 844, 803, 802, 801, 800, 799, 798, 797, 796, 795, 790, 792, 793, 794, 791, 789, 22646, 22647, 22648, 22649, 22650, 22651, 22652, 22653, 22654, 22655, 22656, 22657, 22660, 21865, 21866, 21867, 22658, 22659, 22662, 22663, 22664, 22665, 22667, 22666, 11155, 11156, 11157, 5018};

unsigned long int nLevelExp[] = {0, 500, 1500, 3750, 7875, 14175, 22680, 32886, 44396, 57715, 72144, 90180, 112725, 140906, 176132, 220165, 275207, 344008, 
        430010, 537513, 671891, 839864, 1049830, 1312287, 1640359, 2050449, 2563061, 3203826, 3902260, 4663553, 5493363, 
        6397855, 7383752, 8458379, 9629723, 10906488, 12298162, 13815086, 15468534, 17270791, 19235252, 21376515, 23710491, 
        26254525, 29027522, 32050088, 35344686, 38935798, 42850109, 47116709, 51767302, 56836449, 62361819, 68384473, 74949165, 
        82104680, 89904191, 98405658, 107672256, 117772849, 128782495, 140783010, 153863570, 168121381, 183662396, 200602101, 
        219066380, 239192444, 261129853, 285041630, 311105466, 339515048, 370481492, 404234916, 441026148, 481128591, 524840254, 
        572485967, 624419793, 681027665, 742730244, 809986056, 883294891, 963201521, 1050299747, 1145236814, 1248718217, 
        1361512946, 1484459201, 1618470619, 1764543065, 1923762030, 2097310703, 2286478756, 2492671933, 2717422497, 2962400612, 
        3229426756, 3520485254, 0};

void DrawActiveRooms ()
{
    UnitAny* pUnit = D2CLIENT_GetPlayerUnit();
    if (!pUnit)
        return;
    
    Room2* pRoom = pUnit->pPath->pRoom1->pRoom2;

    for (int i = 0; i < pRoom->dwRoomsNear; ++i)
    {
        Room2* pRoom2 = pRoom->pRoom2Near[i];
        POINT topLeft, topRight, bottomLeft, bottomRight;
        ScreenToAutomap(&topLeft, pRoom2->dwPosX * 160, pRoom2->dwPosY * 160);
        ScreenToAutomap(&topRight, (pRoom2->dwPosX + pRoom2->dwSizeX) * 160, pRoom2->dwPosY * 160);
        ScreenToAutomap(&bottomLeft, pRoom2->dwPosX * 160, (pRoom2->dwPosY + pRoom2->dwSizeY) * 160);
        ScreenToAutomap(&bottomRight, (pRoom2->dwPosX + pRoom2->dwSizeX) * 160, (pRoom2->dwPosY + pRoom2->dwSizeY) * 160);
        LineHook(topLeft.x, topLeft.y, topRight.x, topRight.y, nActiveRoomsColor, FALSE);
        LineHook(topLeft.x, topLeft.y, bottomLeft.x, bottomLeft.y, nActiveRoomsColor, FALSE);
        LineHook(bottomLeft.x, bottomLeft.y, bottomRight.x, bottomRight.y, nActiveRoomsColor, FALSE);
        LineHook(bottomRight.x, bottomRight.y, topRight.x, topRight.y, nActiveRoomsColor, FALSE);
    }

    myDrawAutomapCell(cRadiusCell, pUnit->pPath->xPos, pUnit->pPath->yPos, nActiveRoomsColor, TRUE);
}

VOID DrawAutomapText ()
{
    //Grab some required info
    GameStructInfo* pInfo = D2CLIENT_GetGameInfo();
    BnetData* pInfo2 = *p_D2LAUNCH_BnData;
    UnitAny* pUnit = D2CLIENT_GetPlayerUnit ();
    wchar_t* pLocaleText;

    //Calculate your Experience Percent
    //char nExpPercent[50];
    char nExpStr[50];
    char nExpLvlStr[50];
    char nExpPercent[50];
    int nLevel = D2COMMON_GetUnitStat(pUnit, 12, 0);
    unsigned long int nExp = D2COMMON_GetUnitStat(pUnit, 13, 0);
    sprintf_s(nExpStr, sizeof(nExpStr), "%d", nExp - nStartExp);
    sprintf_s(nExpStr, sizeof(nExpStr), "%s", parseStr1(nExpStr).c_str());
    
    int nExpPer = (int)abs((float)((double)(nExp - nLevelExp[nLevel - 1]) / (double)(nLevelExp[nLevel] - nLevelExp[nLevel - 1])) * 100);
    sprintf_s(nExpPercent, sizeof(nExpPercent), "%i", nExpPer);

    sprintf_s(nExpLvlStr, sizeof(nExpLvlStr), "%d", nLevelExp[nLevel] - nExp);
    sprintf_s(nExpLvlStr, sizeof(nExpLvlStr), "%s", parseStr1(nExpLvlStr).c_str());

    //Array of info to be pasted.

    /*//Convert the level name from wchar_t to char.
    char nLevelName[50];
    pLocaleText = D2LANG_GetLocaleText(AreaLocaleIds[pUnit->pPath->pRoom1->pRoom2->pLevel->dwLevelNo]);
    WToC(pLocaleText, nLevelName);*/

    //Convert Automap Game from wchar_t to char.
    char nGame[15];
    pLocaleText = D2LANG_GetLocaleText(4181);
    WToC(pLocaleText, nGame);
    strcat_s(nGame, "%s");

    //Convert Automap Pass from wchar_t to char.
    char nPass[15];
    pLocaleText = D2LANG_GetLocaleText(4182);
    WToC(pLocaleText, nPass);
    strcat_s(nPass, "%s");

    //Convert Automap Difficulty from wchar_t to char.
    char nDiffName[25];
    pLocaleText = D2LANG_GetLocaleText(4183);
    WToC(pLocaleText, nDiffName);

    //Convert the difficulty from wchar_t to char.
    int DiffIds[] = {5156, 5155, 5154};
    char nDiff[25];
    pLocaleText = D2LANG_GetLocaleText(DiffIds[D2CLIENT_GetDifficulty()]);
    WToC(pLocaleText, nDiff);

    char szTime[200];
    int nTime = ((GetTickCount () - nGameTimer) / 1000);
    sprintf_s(szTime, 200, "%.2d:%.2d:%.2d", nTime/3600, (nTime/60)%60, nTime%60);

    char ping[32];
    DWORD p = *p_D2CLIENT_Ping;
    if (p > nDangerousPing && nDangerousPing)
        sprintf_s(ping, sizeof(ping), "ÿc1%d", p);
    else
        sprintf_s(ping, sizeof(ping), "%d", p);

    char fps[32];
    sprintf_s(fps, sizeof(fps), "%d", *p_D2CLIENT_FPS);

    char areaName[0x400];
    strcpy_s(areaName, sizeof(areaName), D2GetMapName(pUnit->pPath->pRoom1->pRoom2->pLevel->dwLevelNo).c_str());
    AutomapInfo Automap[] =
    {
        { nGame, pInfo->szGameName },
        { nPass, pInfo->szGamePassword },
        { "%s", areaName },
        { nDiffName, nDiff },
        { "", "" },
        { "Exp Percent: %s%%", nExpPercent },
        { "Exp gained: %s", nExpStr },
        { "Exp to level: %s", nExpLvlStr },
        { "", "" },
        { "%s", szTime },
        { "IP: %s", pInfo->szGameServerIp },
        { "", "" },
        { "FPS: %s", fps },
        { "Ping: %s", ping }
    };

    int yLen = 0;
    
    for (int i = 0; i < ArraySize(Automap); ++i)
    {
        if ((strlen(Automap[i].Message) == 0) && (strlen(Automap[i].Message) == 0))
            yLen += 16;

        if (strlen(Automap[i].Data) == 0)
            continue;

        yLen += 16;
        TextHook(790, yLen, 4, false, 1, 0, Automap[i].Message, Automap[i].Data);
    }

    LPCAVEDESC LevelDesc[0x40];
    INT nTotal = 0;

    nTotal = cMap->GetCaveExits(LevelDesc, 0x40, D2CLIENT_GetPlayerUnit()->dwAct);

    POINT ptPos;

    for (INT i = 0; i < nTotal; i++)
    {
        ScreenToAutomap(&ptPos, LevelDesc[i]->ptPos.x * 32, LevelDesc[i]->ptPos.y * 32);
        TextHook(ptPos.x, ptPos.y, 0, 0, 4, 1, "%s", LevelDesc[i]->szName);
    }
    
    /*if (!LevelNames.IsEmpty ())
    {
        int townLevels[6] = {1, 40, 75, 103, 109, 132};

        for (int i = 0; i < LevelNames.GetSize(); i++)
        {
            LevelNameInfo* pInfo = LevelNames.ElementAt(i);

            if (pInfo->nAct != pUnit->dwAct)
                continue;

            char nLevelName[70];
            pLocaleText = D2LANG_GetLocaleText(AreaLocaleIds[pInfo->nLevelId]);
            WToC(pLocaleText, nLevelName);

            if (pInfo->nLevelId == pUnit->pAct->pMisc->dwStaffTombLevel)
                strcat_s(nLevelName, sizeof(nLevelName), "ÿc2*");
            
            TextHook(pInfo->nX, pInfo->nY, 0, true, 4, 1, "%s", nLevelName);
        }
    }*/
}

/*BOOL IsValidMonster(UnitAny *pUnit)
{
    if (!pUnit)
        return false;

    //Check to see if unit is dead.
    if ((pUnit->dwMode == 0) || (pUnit->dwMode == 12))
        return false;

    if ((pUnit->dwTxtFileNo >= 110) && (pUnit->dwTxtFileNo <= 113) || (pUnit->dwTxtFileNo == 608) && (pUnit->dwMode == 8))
        return false;
    
    //if ((pUnit->dwTxtFileNo == 68) && (pUnit->dwMode == 14))// Ignore burrowing maggots
    //s    return false;

    if (((pUnit->dwTxtFileNo == 258) || (pUnit->dwTxtFileNo == 261)) && (pUnit->dwMode == 14))
        return false;

    DWORD badMonIds[] = {326, 327, 328, 329, 330, 410, 411, 412, 413, 414, 415, 416, 366, 406,
    351, 352, 353, 266, 408, 516, 517, 518, 519, 522, 523, 543, 543, 545};

    for (DWORD n = 0; n < ArraySize(badMonIds) - 1; n++)
    {
        if (pUnit->dwTxtFileNo == badMonIds[n])
            return false;
    }

    if (D2COMMON_GetUnitStat(pUnit, 172, 0) == 2) 
        return false;

    wchar_t* name = D2CLIENT_GetUnitName(pUnit);
    char tmp[52];
    WToC(name, tmp);

    if ((strcmp(tmp,"an evil force") == 0) || (strcmp(tmp, "dummy") == 0))
        return false;

    return true;
}*/

DWORD __declspec(naked) __fastcall D2CLIENT_GetUnitName_STUB(DWORD UnitAny)
{
    __asm
    {
        mov eax, ecx
        jmp D2CLIENT_GetUnitName_I
    }
}

int IsObjectChest(int objno)
{
    ObjectTxt *obj = D2COMMON_GetObjectTxt(objno);
    return obj->nSelectable0 && (
        obj->nOperateFn == 1 || //bed, undef grave, casket, sarc
        obj->nOperateFn == 3 || //basket, urn, rockpile, trapped soul
        obj->nOperateFn == 4 || //chest, corpse, wooden chest, buriel chest, skull and rocks, dead barb
        obj->nOperateFn == 5 || //barrel
        obj->nOperateFn == 7 || //exploding barrel
        obj->nOperateFn == 14 || //loose bolder etc....*
        obj->nOperateFn == 19 || //armor stand
        obj->nOperateFn == 20 || //weapon rack
        obj->nOperateFn == 33 || //writ
        obj->nOperateFn == 48 || //trapped soul
        obj->nOperateFn == 51 || //stash
        obj->nOperateFn == 68    //evil urn
        );
}


/*#define    ExtraStrongDesc        "ÿc1Strong" 
#define    ExtraFastDesc        "ÿc1Fast"        
#define CursedDesc            "ÿc8Cursed"    
#define    MagicResistantDesc    "ÿc8MagRs"        
#define    FireEnchantedDesc    "ÿc1FireEnc"    
#define    ChampionDesc        "ÿc4Champ"        
#define    LightEnchantedDesc    "ÿc9LightEnc"    
#define    ColdEnchantedDesc    "ÿc3ColdEnc"    
#define    ThiefDesc            "ÿc0Thief"        
#define    ManaBurnDesc        "ÿc3Mana"        
#define    TeleportationDesc    "ÿc3Tport"        
#define    SpectralHitDesc        "ÿc2Spectral"    
#define    StoneSkinDesc        "ÿc7SSkin"        
#define    MultipleShotsDesc    "ÿc1MltiSht"    
#define    GhostlyDesc            "ÿc4Ghost"    
#define    FanaticDesc            "ÿc4Fana"    
#define    PossessedDesc        "ÿc4Poss"        
#define    BerserkerDesc        "ÿc4Bers"        

#define    MightAuraDesc        "ÿc1Might"        
#define    HolyFireAuraDesc    "ÿc1HFire"        
#define    BlessedAimAuraDesc    "ÿc3Blessed"    
#define    HolyFreezeAuraDesc    "ÿc3Freeze"        
#define    HolyShockAuraDesc    "ÿc9Shock"        
#define    ConvictionAuraDesc    "ÿc2Convic"    
#define FanaticismAuraDesc    "ÿc1Fana"    */

string GetMonsterResists(UnitAny* unit)
{
    if (!unit)
        return "";

    string s="";
    if (bShowMonsterBarResists)
    {
        if (int dr = D2COMMON_GetUnitStat(unit, STAT_DAMAGE_REDUCED, 0))
        {
            s+=" ÿc7"; s+=ToString(dr); s += "% Physical";
        }
        if (int mr = D2COMMON_GetUnitStat(unit, STAT_MAGIC_RESIST, 0))
        {
            s+=" ÿc8"; s+=ToString(mr); s += "% Magic";
        }
        if (int fr = D2COMMON_GetUnitStat(unit, STAT_FIRE_RESIST, 0))
        {
            s+=" ÿc1"; s+=ToString(fr); s += "% Fire";
        }
        if (int lr = D2COMMON_GetUnitStat(unit, STAT_LIGHTING_RESIST, 0))
        {
            s+=" ÿc9"; s+=ToString(lr); s += "% Lightning";
        }
        if (int cr = D2COMMON_GetUnitStat(unit, STAT_COLD_RESIST, 0))
        {
            s+=" ÿc3"; s+=ToString(cr); s += "% Cold";
        }
        if (int pr = D2COMMON_GetUnitStat(unit, STAT_POSION_RESIST, 0))
        {
            s+=" ÿc2"; s+=ToString(pr); s += "% Poison";
        }
    }

    return s;
}

/*****
 *****
 *****
 *****
 *****/

BYTE anMonsterTCs[1000];
BYTE anSuperuniqueTCs[100];
int numMonsterTC;
int numSuperuniqueTC;

void GetHighestTC(int tcno, TCTallys *tallys)
{
    TreasureClass *tc = D2COMMON_GetTreasureClasses(tcno, 0);
    if (!tc)
        return;

    for (int i = 0; i < (int)tc->numitems; i++) {
        if (tc->items[i].tcflag)
        {
            if (tc->items[i].thingno <= 160)
            {
                int groupno = (tc->items[i].thingno-1) / 32;
                int levno = (((tc->items[i].thingno-1)%32)+1) * 3;
                if (levno > tallys->groupnos[groupno])
                    tallys->groupnos[groupno] = levno;
            }
            else 
                GetHighestTC(tc->items[i].thingno, tallys);
        } 
        else 
        {
            ItemTxt *itemtxt = D2COMMON_GetItemTxt(tc->items[i].thingno);
            if (itemtxt && itemtxt->nType == 74)
            {
                int runeno = (itemtxt->szCode[1]-'0')*10+(itemtxt->szCode[2]-'0');
                if (runeno > tallys->runeno) 
                    tallys->runeno = runeno;
            }
        }
    }
}

void InitTCList()
{
    memset(anMonsterTCs, 0, sizeof(anMonsterTCs));
    memset(anSuperuniqueTCs, 0, sizeof(anSuperuniqueTCs));

    MonsterTxt* mon;
    // i < ARRAYSIZE(anMonsterTCs)
    int i = 0, j = 0;
    //for (i = 0; mon = D2CLIENT_GetMonsterTxt(i); i++)
    for (i = 0; i < 1000; ++i)
    {
        mon = D2CLIENT_GetMonsterTxt(i);
        if (!mon)
            continue;

        TCTallys tallys;
        memset(&tallys, 0, sizeof(tallys));
        for (int j = 0; j < 4; ++j)
        {
            int tcno = mon->tcs[D2CLIENT_GetDifficulty()][j];
            GetHighestTC(tcno, &tallys);
        }
        anMonsterTCs[i] = tallys.groupnos[1];
    }
    SuperuniqueTxt *sup;
    // j < ARRAYSIZE(anSuperuniqueTCs)
    //for (j = 0; sup = D2COMMON_GetSuperuniqueTxt(j); j++)
    for (j = 0; j < 100; ++j)
    {
        sup = D2COMMON_GetSuperuniqueTxt(j);
        if (!sup)
            continue;
        if (GameReady())
            Print("%d", j);
        TCTallys tallys;
        memset(&tallys, 0, sizeof(tallys));
        int tcno = sup->tcs[D2CLIENT_GetDifficulty()];
        GetHighestTC(tcno, &tallys);
        anSuperuniqueTCs[j] = tallys.groupnos[1];
    }
    numMonsterTC = i;
    numSuperuniqueTC = j;
}

int GetMonsterLvl(UnitAny *unit)
{
    int lvl = D2COMMON_GetUnitStat(unit, STAT_LEVEL, 0);
    /*if (unit->pMonsterData->fBoss & 1)
    {
        lvl += 3;
        //DWORD* p = unit->pMonsterData->pEnchants->anEnchants;
        //for (int i = 0; *p && i < ArraySize(unit->pMonsterData->pEnchants->anEnchants); ++i, ++p)
            if (*p == 16 || *p >= 36 && *p <= 38)
        //        --lvl;
        for (int i = 0; i < 9; i++)
        {
            if (unit->pMonsterData->anEnchants[i] == 16 || 
                unit->pMonsterData->anEnchants[i] >= 36 && unit->pMonsterData->anEnchants[i] <= 38)
                --lvl;
        }
    }*/

    return lvl;
}

int GetMonsterTC(UnitAny *unit)
{
    BYTE tc;
    if (unit->pMonsterData->fNormal & 1)
    {
        //Print("1");
        tc = anSuperuniqueTCs[unit->pMonsterData->wUniqueNo];
    }
    else
    {
        //Print("2");
        tc = anMonsterTCs[unit->dwTxtFileNo];
    }

    return tc;
}

int GetSTC(int no)
{
    if (no == 100)
        return numMonsterTC;
    else if (no == 101)
        return numSuperuniqueTC;

    return anSuperuniqueTCs[no];
}
int GetMTC(int no)
{
    return anMonsterTCs[no];
}
/*void GetMonsterLevelTC(wchar_t *str, UnitAny *unit, DWORD no)
{
    //if (tToggleMonsterLevel.flag) {
    if (1) {
        int lvl = D2COMMON_GetUnitStat(unit, STAT_LEVEL, 0);
        if (unit->pMonsterData->fBoss & 1) {
            lvl += 3;
            PBYTE p = unit->pMonsterData->anEnchants;
            for (int i = 0; *p && i < ARRAYSIZE(unit->pMonsterData->anEnchants); ++i, ++p) {
                if (*p == 16 || (*p >= 36 && *p <= 38)) {
                    --lvl;
                }
            }
        }
        if (lvl > 99) lvl = 99; // nah?!
        //wsprintfW2(str+wcslen(str), " (l%d)", lvl);
    }
    //if (tToggleMonsterTC.flag) {
    if (1) {
        BYTE tc;
        if (unit->pMonsterData->fNormal & 1) {
            tc = anSuperuniqueTCs[unit->pMonsterData->wUniqueNo];
        } else {
            tc = anMonsterTCs[unit->dwTxtFileNo];
        }
        //if (tc)    wsprintfW2(str+wcslen(str), " (tc%d)", tc);
    }
}*/