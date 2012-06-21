#include "xMap.h"


ConfigEntry pEntries[] =
{
    {"Maphack", "AutoReveal",               "false",        CONFIG_BOOL,    &bReveal},
    {"Maphack", "NoWeather",                "false",        CONFIG_BOOL,    &bNoWeather},
    {"Maphack", "Infravision",              "false",        CONFIG_BOOL,    &bInfravision},
    {"Maphack", "FullLOS",                  "false",        CONFIG_BOOL,    &bFullLoS},
    {"Maphack", "AutoLastGameName",         "false",        CONFIG_BOOL,    &bAutoLastGameName},
    {"Maphack", "ShowItemSockets",          "false",        CONFIG_BOOL,    &bShowItemSockets},
    {"Maphack", "ShowItemEthereal",         "false",        CONFIG_BOOL,    &bShowItemEthereal},
    {"Maphack", "ShowItemiLvl",             "false",        CONFIG_BOOL,    &bShowItemiLvl},
    {"Maphack", "ShowRuneNumbers",          "false",        CONFIG_BOOL,    &bShowRuneNumbers},
    {"Maphack", "ShowItemValues",           "false",        CONFIG_BOOL,    &bShowItemValues},
    {"Maphack", "AddCharNameToWindow",      "false",        CONFIG_BOOL,    &bAddNameToWindow},
    {"Maphack", "CommandPrefix",            ".",            CONFIG_STRING,  &cCommandPrefix},
    {"Maphack", "ShowInventoryKey",         "48",           CONFIG_INT,     &nShowInvKey},
    {"Maphack", "HideItemsKey",             "101",          CONFIG_INT,     &nHideItemsKey},    

    {"Maphack", "ShowPercents",             "false",        CONFIG_BOOL,    &bShowPercents},
    {"Maphack", "ToggleOrbsText",           "false",        CONFIG_BOOL,    &bTogglePermShowOrbsText},
    {"Maphack", "LifePercentToggle",        "111",          CONFIG_INT,     &nLifePercentToggle},
    {"Maphack", "StatsToggleKey",           "108",          CONFIG_INT,     &nShowStatsToggle},
    {"Maphack", "ScrollMapToggle",          "145",          CONFIG_INT,     &nScrollMapToggle},

    {"Maphack", "DisableBossDeathAnims",    "false",        CONFIG_BOOL,    &bDisableBossDeathAnims},
    {"Maphack", "DisableMonsterDeathAnims", "false",        CONFIG_BOOL,    &bDisableMonsterDeathAnims},
    {"Maphack", "HideCorpses",              "false",        CONFIG_BOOL,    &bHideCorpses},

    {"Maphack", "ChangeItemColors",         "false",        CONFIG_BOOL,    &bChangeItemColors},
    {"Maphack", "DrawAutomapItems",         "false",        CONFIG_BOOL,    &bDrawAutomapItems},
    {"Maphack", "RevealMapKey",             "106",          CONFIG_INT,     &nRevealMapKey},
    {"Maphack", "FastExitKey",              "53",           CONFIG_INT,     &nFastExitKey},
    {"Maphack", "FastToTownKey",            "88",           CONFIG_INT,     &nFastToTownKey},
    {"Maphack", "DangerousPingValue",       "150",          CONFIG_INT,     &nDangerousPing},
    {"Maphack", "ActiveRoomsToggle",        "109",          CONFIG_INT,     &nActiveRoomsToggle},
    {"Maphack", "ActiveRoomsColor",         "29",           CONFIG_INT,     &nActiveRoomsColor},

    {"Maphack", "ShowAutomapChests",        "true",         CONFIG_BOOL,    &bShowAutomapChests},
    {"Maphack", "OpenChestColor",           "115",          CONFIG_INT,     &nOpenChestColor},
    {"Maphack", "LockedChestColor",         "117",          CONFIG_INT,     &nLockedChestColor},
    {"Maphack", "GoodGoldCount",            "1000",         CONFIG_INT,     &nGoodGoldCount},
    
    //blobs
    {"Maphack", "PlayerBlobFile",           "blobcircle",   CONFIG_STRING,  &cUnitBlobFiles[UNIT_PLAYER]},
    {"Maphack", "ObjectBlobFile",           "blobcross",    CONFIG_STRING,  &cUnitBlobFiles[UNIT_OBJECT]},
    {"Maphack", "MissileBlobFile",          "blobdot",      CONFIG_STRING,  &cUnitBlobFiles[UNIT_MISSILE]},
    {"Maphack", "MonsterBlobFile",          "blobcross",    CONFIG_STRING,  &cUnitBlobFiles[UNIT_MONSTER]},
    {"Maphack", "ItemBlobFile",             "blobitem",     CONFIG_STRING,  &cUnitBlobFiles[UNIT_ITEM]},
    {"Maphack", "WaypointBlobFile",         "wp",           CONFIG_STRING,  &cWaypointBlobFile},
    {"Maphack", "AggroRadiusBlobFile",      "radius",       CONFIG_STRING,  &cRadiusBlobFile},

    
    {"Auto Party", "UseAutoParty",          "false",        CONFIG_BOOL,    &bUseAutoParty},
    {"Auto Party", "AutoPartyToggle",       "107",          CONFIG_INT,     &nAutoPartyToggle},
    {"Auto Party", "PartyOnlyInPrivate",    "false",        CONFIG_BOOL,    &bPOIP},

    {"Missiles", "ShowMissiles",            "true",         CONFIG_BOOL,    &bShowMissiles},
    {"Missiles", "YourMissileColor",        "200",          CONFIG_INT,     &nYourMissileColor},
    {"Missiles", "HostileMissileColor",     "100",          CONFIG_INT,     &nHostileMissileColor},
    {"Missiles", "NeutralMissileColor",     "153",          CONFIG_INT,     &nNeutralMissileColor},
    {"Missiles", "PartyMissileColor",       "30",           CONFIG_INT,     &nPartyMissileColor},

    {"Monsters", "ShowMonsters",            "false",        CONFIG_BOOL,    &bShowMonsters},
    {"Monsters", "NormalMonsterColor",      "98",           CONFIG_INT,     &nNormalMonsterColor},
    {"Monsters", "ChampionMonsterColor",    "255",          CONFIG_INT,     &nChampionMonsterColor},
    {"Monsters", "MinionMonsterColor",      "102",          CONFIG_INT,     &nMinionMonsterColor},
    {"Monsters", "BossMonsterColor",        "255",          CONFIG_INT,     &nBossMonsterColor},
    {"Monsters", "MonsterImmunitySymbol",   "*",            CONFIG_STRING,  &cMonsterImmunitySymbol},
    {"Monsters", "ShowMonsterEnchantments", "false",        CONFIG_BOOL,    &bShowEnchantments},
    {"Monsters", "ShowMonsterBarResists",   "true",         CONFIG_BOOL,    &bShowMonsterBarResists},

    {"Monsters", "ExtraStrongDescr",        "ÿc1Strong",    CONFIG_STRING,  &cEnchDescSymbols[5]},
    {"Monsters", "ExtraFastDesc",           "ÿc1Fast",      CONFIG_STRING,  &cEnchDescSymbols[6]},
    {"Monsters", "CursedDesc",              "ÿc8Cursed",    CONFIG_STRING,  &cEnchDescSymbols[7]},
    {"Monsters", "MagicResistantDesc",      "ÿc8MagRs",     CONFIG_STRING,  &cEnchDescSymbols[8]},
    {"Monsters", "FireEnchantedDesc",       "ÿc1FireEnc",   CONFIG_STRING,  &cEnchDescSymbols[9]},
    {"Monsters", "ChampionDesc",            "ÿc4Champ",     CONFIG_STRING,  &cEnchDescSymbols[16]},
    {"Monsters", "LightEnchantedDesc",      "ÿc9LightEnc",  CONFIG_STRING,  &cEnchDescSymbols[17]},
    {"Monsters", "ColdEnchantedDesc",       "ÿc3ColdEnc",   CONFIG_STRING,  &cEnchDescSymbols[18]},
    {"Monsters", "ThiefDesc",               "ÿc0Thief",     CONFIG_STRING,  &cEnchDescSymbols[24]},
    {"Monsters", "ManaBurnDesc",            "ÿc3Mana",      CONFIG_STRING,  &cEnchDescSymbols[25]},
    {"Monsters", "TeleportationDesc",       "ÿc3Tport",     CONFIG_STRING,  &cEnchDescSymbols[26]},
    {"Monsters", "SpectralHitDesc",         "ÿc2Spectral",  CONFIG_STRING,  &cEnchDescSymbols[27]},
    {"Monsters", "StoneSkinDesc",           "ÿc7SSkin",     CONFIG_STRING,  &cEnchDescSymbols[28]},
    {"Monsters", "MultipleShotsDesc",       "ÿc1MltiSht",   CONFIG_STRING,  &cEnchDescSymbols[29]},
    {"Monsters", "GhostlyDesc",             "ÿc4Ghost",     CONFIG_STRING,  &cEnchDescSymbols[36]},
    {"Monsters", "FanaticDesc",             "ÿc4Fana",      CONFIG_STRING,  &cEnchDescSymbols[37]},
    {"Monsters", "PossessedDesc",           "ÿc4Poss",      CONFIG_STRING,  &cEnchDescSymbols[38]},
    {"Monsters", "BerserkerDesc",           "ÿc4Bers",      CONFIG_STRING,  &cEnchDescSymbols[39]},

    {"Monsters", "MightAuraDesc",           "ÿc1Might",     CONFIG_STRING,  &cAuraDescSymbols[0]},
    {"Monsters", "HolyFireAuraDesc",        "ÿc1HFire",     CONFIG_STRING,  &cAuraDescSymbols[1]},
    {"Monsters", "BlessedAimAuraDesc",      "ÿc3Blessed",   CONFIG_STRING,  &cAuraDescSymbols[2]},
    {"Monsters", "HolyFreezeAuraDesc",      "ÿc3Freeze",    CONFIG_STRING,  &cAuraDescSymbols[3]},
    {"Monsters", "HolyShockAuraDesc",       "ÿc9Shock",     CONFIG_STRING,  &cAuraDescSymbols[4]},
    {"Monsters", "ConvictionAuraDesc",      "ÿc2Convic",    CONFIG_STRING,  &cAuraDescSymbols[5]},
    {"Monsters", "FanaticismAuraDesc",      "ÿc1Fana",      CONFIG_STRING,  &cAuraDescSymbols[6]},

    {"Chicken", "ToggleChicken",            "false",        CONFIG_BOOL,    &bToggleChicken},
    {"Chicken", "ToggleChickenHostile",     "false",        CONFIG_BOOL,    &bToggleChickenHostile},    
    {"Chicken", "ChikenLife",               "0",            CONFIG_INT,     &nChickenLife},
    {"Chicken", "ChickenLifePercent",       "20",           CONFIG_INT,     &nChickenLifePercent},
    {"Chicken", "ChickenPing",              "600",          CONFIG_INT,     &nChickenPing},
    {"Chicken", "ChickenToTown",            "true",         CONFIG_BOOL,    &bChickenToTown},
    {"Chicken", "ChickenToTownOnHostile",   "false",        CONFIG_BOOL,    &bChickenToTownOnHostile},

    {"Misc", "OpenStashKey",                "45",           CONFIG_INT,     &nOpenStashKey},
    {"Misc", "OpenCubeKey",                 "36",           CONFIG_INT,     &nOpenCubeKey},    
    {"Misc", "ResyncKey",                   "46",           CONFIG_INT,     &nResynchKey},
    {"Misc", "CharTable",                   "0",            CONFIG_INT,     &nCharTable},
    {"Misc", "FastTeleport",                "true",         CONFIG_BOOL,    &bFastTeleport},
    {"Misc", "OpenPortalKey",               "90",           CONFIG_INT,     &nOpenPortalKey},
    {"Misc", "ShowTauntMessages",           "false",        CONFIG_BOOL,    &bShowTauntMessages},
    {"Misc", "DeathMessage",                "pwned!",       CONFIG_STRING,  &cDeathMessage},
    {"Misc", "DropMessage",                 "tt",           CONFIG_STRING,  &cDropMessage},
    {"Misc", "SojsSoldMessage",             "",             CONFIG_STRING,  &cSojsSoldMessage},
    {"Misc", "DiCloneMessage",              "",             CONFIG_STRING,  &cDiCloneMessage},
    {"Misc", "SilentBots",                  "true",         CONFIG_BOOL,    &bSilentBots},

    {"Misc", "SocketProtectKey",            "102",          CONFIG_INT,     &nSocketProtectKey},
    {"Misc", "ShowTPsLeft",                 "false",        CONFIG_BOOL,    &bShowTPsLeft},    
    
    {"Misc", "EnableTPPK",                  "false",        CONFIG_BOOL,    &bEnableTPPK},
    {"Misc", "TPPKKey",                     "8",            CONFIG_INT,     &nTPPKKey},
    
    {"Misc", "OutOfTownSelectToggleKey",    "35",           CONFIG_INT,     &nOutOfTownSelectKey},
    {"Misc", "InputLinePatch",              "false",        CONFIG_BOOL,    &bInputLinePatch},
    {"Misc", "ShowWardenNotifications",     "false",        CONFIG_BOOL,    &bShowWardenNotifications},
    {"Misc", "NoQuestBox",                  "false",        CONFIG_BOOL,    &bNoQuestBox},
    {"Misc", "AntiFlash",                   "false",        CONFIG_BOOL,    &bAntiFlash},    

    {"EnchantBot", "EnchantBotToggleKey",   "103",          CONFIG_INT,     &nEnchantBotToggleKey},
    {"EnchantBot", "EnchantMeCommand",      "chant",        CONFIG_STRING,  &cEnchantMe},
    {"EnchantBot", "EnchantMercCommand",    "chantmerc",    CONFIG_STRING,  &cEnchantMerc},
    {"EnchantBot", "EnchantAllCommand",     "chantall",     CONFIG_STRING,  &cEnchantAll},

    {"FollowBot", "LeaderName",             "",             CONFIG_STRING,  &cFollowBotLeaderName},
    {"FollowBot", "FollowBotToggleKey",     "104",          CONFIG_INT,     &nFollowBotToggleKey},
    {"FollowBot", "WaitCommand",            "w8",           CONFIG_STRING,  &cWaitCommand},
    {"FollowBot", "GoCommand",              "go",           CONFIG_STRING,  &cGoCommand},
    {"FollowBot", "TakeMyTpCommand",        "taketp",       CONFIG_STRING,  &cTakeMyTpCommand},
    {"FollowBot", "TakeOwnTpCommand",       "yourtp",       CONFIG_STRING,  &cTakeOwnTpCommand},
    {"FollowBot", "MakeTpCommand",          "maketp",       CONFIG_STRING,  &cOpenTpCommand},
    {"FollowBot", "TownCommand",            "town",         CONFIG_STRING,  &cTownCommand},
    {"FollowBot", "ExitGameCommand",        "fu",           CONFIG_STRING,  &cExitGameCommand},
    {"FollowBot", "BoCommand",              "bo",           CONFIG_STRING,  &cBoCommand},


    {"MoveNPC", "BindNPCKey",               "74",           CONFIG_INT,     &nBindNPCKey},
    {"MoveNPC", "PullNPCKey",               "75",           CONFIG_INT,     &nPullNPCKey},
    {"MoveNPC", "InteractNPCKey",           "76",           CONFIG_INT,     &nInteractNPCKey},
    
    //{"FollowBot", "FollowBotXOffset", "5", CONFIG_INT, &cFollowBotXOffset},
    //{"FollowBot", "FollowBotYOffset", "5", CONFIG_INT, &cFollowBotYOffset}    
};

bool readConfig()
{
    char pFile[65535];
    strncpy_s(pFile, sizeof(pFile), szPath, sizeof(pFile));
    strcat_s(pFile, "\\xMap.ini");
    
    char nRet[65535];
    for (int i = 0; i < ArraySize(pEntries); ++i)
    {
        GetPrivateProfileString(pEntries[i].pSection, pEntries[i].pKey, pEntries[i].pDefault, nRet, sizeof(nRet), pFile);
        if (pEntries[i].nType == CONFIG_BOOL)
            *(PBOOL)pEntries[i].nVar = getBool(nRet);
        else if (pEntries[i].nType == CONFIG_INT)
            *(PINT)pEntries[i].nVar = atoi(nRet);
        else if (pEntries[i].nType == CONFIG_STRING)
            *(string*)pEntries[i].nVar = nRet;
    }
    return true;
}

bool getBool(char* pLower)
{
    if (_stricmp(pLower, "1") == 0 || _stricmp(pLower, "y") == 0 || _stricmp(pLower, "yes") == 0 || _stricmp(pLower, "true") == 0)
        return true;

    return false;
}

VOID setConfig(char* pKey, char* pValue)
{
    if (strlen(pKey) == 0 || strlen(pValue) == 0)
        return;

    for (int i = 0; i < ArraySize(pEntries); ++i)
    {
        if (_strcmpi(pKey, pEntries[i].pKey) == 0)
        {
            if (pEntries[i].nType == CONFIG_BOOL)
            {
                *(BOOL*)pEntries[i].nVar = getBool(pValue);
                PrintAtBottomLeft("ÿc4[xMap]ÿc0: %s is now set to %s", pEntries[i].pKey, *(BOOL*)pEntries[i].nVar ? "true" : "false");
            }
            else if (pEntries[i].nType == CONFIG_INT)
            {
                *(INT*)pEntries[i].nVar = atoi(pValue);
                PrintAtBottomLeft("ÿc4[xMap]ÿc0: %s is now set to %d", pEntries[i].pKey, *(INT*)pEntries[i].nVar);
            }
            else if (pEntries[i].nType == CONFIG_STRING) 
            {
                *(string*)pEntries[i].nVar = pValue;
                PrintAtBottomLeft("ÿc4[xMap]ÿc0: %s is now set to %s", pEntries[i].pKey, ((string*)pEntries[i].nVar)->c_str());
            }                
        }
    }
}

VOID getConfig(char* pKey)
{
    if (strlen(pKey) == 0 )
        return;

    for (int i = 0; i < ArraySize(pEntries); ++i)
    {
        if (_strcmpi(pKey, pEntries[i].pKey) == 0)
        {
            if (pEntries[i].nType == CONFIG_BOOL)
                Print("ÿc4[xMap]ÿc0: %s is %s", pEntries[i].pKey, *(BOOL*)pEntries[i].nVar ? "true" : "false");
            else if (pEntries[i].nType == CONFIG_INT) 
                Print("ÿc4[xMap]ÿc0: %s is %d", pEntries[i].pKey, *(PINT)pEntries[i].nVar);
            else if (pEntries[i].nType == CONFIG_STRING) 
                Print("ÿc4[xMap]ÿc0: %s is %s", pEntries[i].pKey, ((string*)pEntries[i].nVar)->c_str());
        }
    }
}

void PrintConfigEntries()
{

    for (int i = 0; i < ArraySize(pEntries); ++i)
    {
        if (pEntries[i].nType == CONFIG_BOOL)
            Print("ÿc4[xMap]ÿc0: [%s] %s = %s", pEntries[i].pSection, pEntries[i].pKey, *(BOOL*)pEntries[i].nVar ? "true" : "false");
        else if (pEntries[i].nType == CONFIG_INT) 
            Print("ÿc4[xMap]ÿc0: [%s] %s = %d", pEntries[i].pSection, pEntries[i].pKey, *(PINT)pEntries[i].nVar);
        else if (pEntries[i].nType == CONFIG_STRING) 
            Print("ÿc4[xMap]ÿc0: [%s] %s = %s", pEntries[i].pSection, pEntries[i].pKey, ((string*)pEntries[i].nVar)->c_str());
    }
}


int ReadColorFile()
{
    //clearing previous data
    /*for (ItemDescList::iterator i = itemCol.begin(); i != itemCol.end(); i++)
    {
        delete (*i)->flags;
        delete *i;    
    }*/
    for (int i = 0; i < itemCol.GetSize(); ++i)
    {
        delete itemCol[i]->flags;
        delete itemCol[i];
    }

    itemCol.RemoveAll();

    int line = 0;
    try
    {
        string path = szPath;
        path += "\\xColor.ini";
        FileReader f(path.c_str());

        String attr, val;
        CHAR* values[0x30];
        
        ItemDesc* tempDesc;
        bool justStarted = true;

        while(!f.Eof())
        {
            line++;
            attr = f.ReadLine().Trim();
            if (attr.length() == 0)
                continue;
            if (attr[0] == '/')
                continue;
            if (attr == "---eof---")
                break;

            if (attr[0] == '[')
            {
                if (!justStarted)
                    itemCol.Add(tempDesc);

                tempDesc = new ItemDesc;
                tempDesc->flags = new ItemFlags;
                memset(tempDesc->flags, 0, sizeof(ItemFlags));

                tempDesc->itemColor = '\0';
                tempDesc->isEthereal = -1;
                tempDesc->showOnMap = false;
                tempDesc->onMapColor = -1;
                tempDesc->itemQuality = ITEM_QUALITY_ANY;
                tempDesc->numSockets = ITEM_NUMSOCKETS_ANY;
                tempDesc->hide = false;
                justStarted = false;

                continue;
            }            
            
            val = attr.substr(attr.find_first_of('=') + 1, attr.length() - attr.find_first_of('=') - 1);
            if (val == attr)
                continue;

            attr = attr.substr(0, attr.find_first_of('='));

            char c[0x400];
            strcpy_s(c, sizeof(c), val.c_str());
            int argc = StringTokenize(c, '|', values, 0x30);

            if (attr == "name")
            {
                for (int i = 0; i < argc; ++i)
                    tempDesc->itemCode.push_back(njipClassId[String(values[i])]);
            }
            else if (attr == "color")
            {
                if (argc > 0)
                {
                    char color = GetItemColor(values[0]);
                    if (color != 255)
                        tempDesc->itemColor = color;
                }
            }
            else if (attr == "showonmap")
            {
                if (argc > 0)
                    tempDesc->showOnMap = getBool(values[0]);
            }
            else if (attr == "eth")
            {
                if (argc > 0)
                {
                    if (String(values[0]) == "any")
                        tempDesc->isEthereal = -1;
                    else
                        tempDesc->isEthereal = getBool(values[0]);
                }
            }
            else if (attr == "sock")
            {
                tempDesc->numSockets = 0;

                for (int i = 0; i < argc; ++i)
                    tempDesc->numSockets |= GetItemNumSockets(values[i]);
            }
            else if (attr == "quality")     // new
            {
                tempDesc->itemQuality = 0;
                for (int i = 0; i < argc; ++i)
                    tempDesc->itemQuality |= GetItemQuality(values[i]);
            }
            else if (attr == "location")    // new
            {
                for (int i = 0; i < argc; ++i)
                    tempDesc->flags->bodyLocation |= GetItemLocation(values[i]);
            }            
            else if (attr == "type")        // new
            {
                for (int i = 0; i < argc; ++i)
                {
                    if (GetItemArmorClass(values[i]))
                    {
                        tempDesc->flags->itemClass |= GetItemArmorClass(values[i]);
                        tempDesc->flags->bodyLocation |= ITEM_BODYLOCATION_ARMOR;
                    }
                    else if (GetItemWeaponClass(values[i]))
                    {
                        tempDesc->flags->itemClass |= GetItemWeaponClass(values[i]);
                        tempDesc->flags->bodyLocation |= ITEM_BODYLOCATION_WEAPON;
                    }
                    else if (GetItemMiscClass(values[i]))
                    {
                        tempDesc->flags->itemClass |= GetItemMiscClass(values[i]);
                        tempDesc->flags->bodyLocation |= ITEM_BODYLOCATION_NONE;
                    }
                }
            }            
            else if (attr == "rarity")
            {
                for (int i = 0; i < argc; ++i)
                    tempDesc->flags->rarity |= GetItemRarity(values[i]);
            }
            else if (attr == "mapcolor")
            {
                if (argc > 0)
                {
                    int color = GetItemMapColor(values[0]);
                    if (color == -2)
                    {
                        color = StringToInt(values[0]);
                        if (color != -2)
                            tempDesc->onMapColor = color;
                    }
                    else
                        tempDesc->onMapColor = color;
                }
            }
            else if (attr == "hide")
            {
                if (argc > 0)
                    tempDesc->hide = getBool(values[0]);
            }
            else
            {
                if (GameReady())
                    Print("Unknown parameter at line %d of xColor.ini : \"%s\"", line, attr.c_str());
            }
        }
        
        //if (tempDesc->itemColor != 254)
            itemCol.Add(tempDesc);
        //else
        //    itemHide.push_back(tempDesc);

        f.Close();
    }
    catch(exception &e)
    {
        //cout << "Exception occured at line " << (line-1) << " of ColorConfig.ini: " << e.what() << endl;
        if (GameReady())
            Print("ÿc1[xMap]ÿc0: Exception occured at line %d of %s: \"%s\"", line, "xColor.ini", e.what());

        return 0;
    }

    return 1;
}

/*void GetHighestTC(int tcno, TCTallys *tallys)
{
    TreasureClass *tc = D2COMMON_GetTreasureClasses(tcno, 0);
    if (!tc) return;

    for (int i = 0; i < (int)tc->numitems; i++) {
        if (tc->items[i].tcflag) {
            if (tc->items[i].thingno <= 160) {
                int groupno = (tc->items[i].thingno-1)/32;
                int levno = (((tc->items[i].thingno-1)%32)+1)*3;
                if (levno > tallys->groupnos[groupno]) tallys->groupnos[groupno] = levno;
            } else {
                GetHighestTC(tc->items[i].thingno, tallys);
            }
        } else {
            ItemTxt *itemtxt = D2COMMON_GetItemTxt(tc->items[i].thingno);
            if (itemtxt && itemtxt->nType == 74) {
                int runeno = (itemtxt->szCode[1]-'0')*10+(itemtxt->szCode[2]-'0');
                if (runeno > tallys->runeno) tallys->runeno = runeno;
            }
        }
    }
}

void InitTCList()
{
    MonsterTxt *mon;
    // i < ARRAYSIZE(anMonsterTCs)
    for (int i = 0; mon = D2CLIENT_GetMonsterTxt(i); i++) {
        TCTallys tallys;
        memset(&tallys, 0, sizeof(tallys));
        for (int j = 0; j < 4; j++) {
            int tcno = mon->tcs[D2CLIENT_GetDifficulty()][j];
            GetHighestTC(tcno, &tallys);
        }
        anMonsterTCs[i] = tallys.groupnos[1];
    }
    SuperuniqueTxt *sup;
    // j < ARRAYSIZE(anSuperuniqueTCs)
    for (int j = 0; sup = D2COMMON_GetSuperuniqueTxt(j); j++) {
        TCTallys tallys;
        memset(&tallys, 0, sizeof(tallys));
        int tcno = sup->tcs[D2CLIENT_GetDifficulty()];
        GetHighestTC(tcno, &tallys);
        anSuperuniqueTCs[j] = tallys.groupnos[1];
    }
    //numMonsterTC = i;
    //numSuperuniqueTC = j;
}*/