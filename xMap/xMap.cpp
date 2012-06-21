// xMap v2.0 By Zakamurite
// Based ? on mMap by Mc God, first public, open source, GPL'd 1.12 Maphack
// Big thanks to:
//      Cthulhon - For all his work on structs and general help:)
//      Sheppard - For all his work on finding 1.12 pointers, and D2BS :)
//      AntiRush - For all the help he gave me to fix crashes
//      TheAce - For the help with suspending threads
//      Lord2800 - For the help and support with C++ and Injector
//      Stings/Mousepad - For things like: View Inventory, Preset Units, Auto Last Game, to name a few :P
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; version 2 of the License.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

#define _DEFINE_VARS 
#define _VARS
#include "xMap.h"

//Variables for our threads.
DWORD myThreadId;
HANDLE myThreadHandle;
DWORD apThreadId;
HANDLE apThreadHandle;
DWORD chickThreadId;
HANDLE chickThreadHandle;
DWORD enchThreadId;
HANDLE enchThreadHandle;

VOID Print(CHAR* szFormat, ...)
{
    CHAR *szString = new CHAR[8192];
    ::memset(szString, 0, 8192);
    va_list vaArgs;

    va_start(vaArgs, szFormat);
    vsprintf(szString, szFormat, vaArgs);
    va_end(vaArgs);

    if (D2CLIENT_GetPlayerUnit())
    {
        wchar_t Buffer[0x130]; //Creates a buffer to hold the new string

        MyMultiByteToWideChar(nCharTable, 1, szString, 100, Buffer, 100);
    
        D2CLIENT_PrintGameString(Buffer, 0);
    }
    else
        D2MULTI_PrintChannelText(szString, NULL);

    delete[] szString;
}

VOID PrintAtBottomLeft(CHAR* szFormat, ...)
{
    CHAR *szString = new CHAR[8192];
    ::memset(szString, 0, 8192);
    va_list vaArgs;

    va_start(vaArgs, szFormat);
    vsprintf(szString, szFormat, vaArgs);
    va_end(vaArgs);

    if (D2CLIENT_GetPlayerUnit())
    {
        wchar_t Buffer[0x130];//Creates a buffer to hold the new string

        MyMultiByteToWideChar(nCharTable, 1, szString, 100, Buffer, 100);
    
        D2CLIENT_PrintGameStringAtBottomLeft(Buffer, 0);
    }
    else
        D2MULTI_PrintChannelText(szString, NULL);

    delete[] szString;
}

/* BOOL WINAPI DllMain(HINSTANCE hDll,DWORD dwReason,LPVOID lpReserved) 
 *    The main function that gets called when the dll is injected.
 */
BOOL WINAPI DllMain(HINSTANCE hDll,DWORD dwReason,LPVOID lpReserved) 
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            DefineOffsets(); //Sets up the couple offsets we have for maphack
            InstallPatchs();
            FillBytes((void *)0x6FAED900, INST_NOP, 0x37);
            FillBytes((void *)0x6FB6B5C5, INST_NOP, 2);
            FillBytes((void *)0x6FB6B5B6, INST_NOP, 15);
            FillBytes((void *)0x6FB0DB8F, INST_NOP, 2);
            FillBytes((void *)0x6FB6B68F, INST_NOP, 2);
            GetModuleFileName(hDll,szPath,MAX_PATH);
            PathRemoveFileSpecA(szPath);
            strcat_s(szPath,sizeof(szPath),"\\");

            InitItemCodes();
            readConfig();
            ReadColorFile();
            InitBlobs();
            //InitTCList();

            if (bDisableBossDeathAnims)
                memset(cMonsterDeathAnims, 0, sizeof(cMonsterDeathAnims));
            else
                memset(cMonsterDeathAnims, 1, sizeof(cMonsterDeathAnims));

            //Taken from D2BS:P
            if (D2GFX_GetHwnd())
            {
                GetWindowText(D2GFX_GetHwnd(), szOrigWinName, sizeof(szOrigWinName));
                OldWNDPROC = (WNDPROC)GetWindowLong(D2GFX_GetHwnd(), GWL_WNDPROC);
                SetWindowLong(D2GFX_GetHwnd(), GWL_WNDPROC, (LONG)GameWindowEvent);
            }
            else 
                bPluginTrace = TRUE;

            myThreadHandle = CreateThread(0, 0, MaphackThread, 0, 0, &myThreadId);
            apThreadHandle = CreateThread(0, 0, AutoPartyThread, 0, 0, &apThreadId);
            chickThreadHandle = CreateThread(0, 0, ChickenThread, 0, 0, &chickThreadId);
            enchThreadHandle = CreateThread(0, 0, EnchantThread, 0, 0, &enchThreadId);
            break;
        case DLL_PROCESS_DETACH:
            TerminateThread(myThreadHandle, 0);//Terminates the thread on detach (Or you crash).
            TerminateThread(apThreadHandle, 0);//Terminate Auto-Party
            TerminateThread(chickThreadHandle, 0);
            TerminateThread(enchThreadHandle, 0);
            break;
    }
    return TRUE;
}

/* DWORD WINAPI MaphackThread(LPVOID lpParameter)
 *    This thread loops and waits for act change then reveals act.
 */
DWORD WINAPI MaphackThread(LPVOID lpParameter)
{
    //Declare an array of bools that will store if we have revealed map or not.
    bool hasReset = true;

    while (!GameReady())
        SleepEx(50, true);

    PrintAtBottomLeft("ÿc4xMap v2.0 By ÿc0Zakamurite ÿc4Loaded.");
    
    //Starts an infinite loop
    while(true)
    {
        SleepEx(50, true); // Delay a little to reduce CPU load

        if (GameReady() && hasReset)
        {
            nLastLevel = -1;
            if (cMap)
                delete cMap;
            cMap = new CMap();

            BnetData *pData = *p_D2LAUNCH_BnData;
            if (strlen(pData->szGameName) > 0)
                strncpy_s(szLastGameName, sizeof(szLastGameName), pData->szGameName, sizeof(pData->szGameName));

            UnitAny *pUnit = D2CLIENT_GetPlayerUnit ();

            if (bAddNameToWindow)
            {
                char nWinName[1024];
                sprintf_s(nWinName, 1024, "%s %s", szOrigWinName, pUnit->pPlayerData->szName);
                SetWindowText(D2GFX_GetHwnd(), nWinName);
            }

            nGameTimer = GetTickCount();
            hasReset = false;

            //sets exp count when joined game
            nStartExp = D2COMMON_GetUnitStat(pUnit, 13, 0);
            continue;
        }
        else if (!GameReady() && *p_D2WIN_FirstControl && !hasReset)
        {
            if (pD2WinEditBox)
            {
                *(DWORD*)p_D2CLIENT_szLastChatMessage = 0;
                wchar_t *p = wcscpy(p_D2CLIENT_szLastChatMessage, D2WIN_GetEditBoxText(pD2WinEditBox));
                *p_D2CLIENT_nTextLength = wcslen(p);
                D2WIN_DestroyEditBox(pD2WinEditBox);
                pD2WinEditBox = NULL;
                *p_D2WIN_pFocusedControl = NULL;
            }

            EnchantQueue.RemoveAll();

            if (bAddNameToWindow)
                SetWindowText(D2GFX_GetHwnd(), szOrigWinName);

            hasReset = true; // Set so we don't continously delete/declare.
            continue;
        }

        //Check to insure we are properly in game.
        if (!GameReady())
        {
            SleepEx(50, true);
            continue;
        }

        //Grab the player unit (So we can obtain act)
        UnitAny* pUnit = D2CLIENT_GetPlayerUnit();

        //Insure the unit is valid
        if (!pUnit)
            continue;
    
        if (!D2CLIENT_GetUiVar(0x01))
            uViewingUnit = NULL;

        if (uViewingUnit && uViewingUnit->dwUnitId)
        {
            if (!uViewingUnit->pInventory)
            {
                uViewingUnit = NULL;
                D2CLIENT_SetUiVar(0x01, 1, 0);            
            }
            else if (!D2CLIENT_FindUnit(uViewingUnit->dwUnitId, uViewingUnit->dwType))
            {
                uViewingUnit = NULL;
                D2CLIENT_SetUiVar(0x01, 1, 0);
            }
        }

        // Check if we have revealed the act or not.
        if (!cMap->m_RevealedActs[pUnit->dwAct] && bReveal)
        {
            Sleep(300);
            SuspendThreadsInProcess(GetCurrentProcessId()); //that's not for antidetection, thats because otherwise game freezes somehow :))
            ResumeThread(*((HANDLE*)0x6FC45348));
            cMap->RevealAutomap();
            ResumeThreadsInProcess(GetCurrentProcessId ());
        }
    }

    //unreachable :(
    //DeleteBlobs();

    return 0;
}

PLUGIN_INTERFACE     Interface;
DWORD    __stdcall     PluginEntry(DWORD dwReason, LPVOID lpData);

LPPLUGIN_INTERFACE __stdcall QueryInterface(VOID)
{
    Interface.dwMagicword = PLUGIN_MAGICWORD;
    Interface.dwVersion = PLUGIN_VERSION;
    Interface.szDescription = "xMap";
    Interface.fpEntry = PluginEntry;
    return &Interface;
}

DWORD __stdcall PluginEntry(DWORD dwReason, LPVOID lpData)
{
    if (dwReason == REASON_ENTER_MAIN_MENU && bPluginTrace)
    {
        GetWindowText(D2GFX_GetHwnd(), szOrigWinName, sizeof(szOrigWinName));
        OldWNDPROC = (WNDPROC)GetWindowLong(D2GFX_GetHwnd(), GWL_WNDPROC);
        SetWindowLong(D2GFX_GetHwnd(), GWL_WNDPROC, (LONG)GameWindowEvent);
        bPluginTrace = FALSE;
    }

    return TRUE;
}