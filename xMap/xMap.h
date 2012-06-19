#pragma comment(lib, "shlwapi.lib")

#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <shlwapi.h>
#include <ctime>
#include <math.h>
#include <direct.h>
#include <stdlib.h>
#include <errno.h>
#include <io.h>
#include <string.h>
#include <iostream>
#include <list>
#include <map>

#include "D2Ptrs.h"
#include "D2Stubs.h"
#include "Vars.h"
#include "Config.h"
#include "Offset.h"
#include "MapFunc.h"
#include "plugin.h"
#include "d2param.h"
#include "Monsters.h"
#include "Screenhooks.h"
#include "AutoParty.h"
#include "Common.h"
#include "File.h"
#include "FileReader.cpp"
#include "ItemCodes.h"
#include "Chicken.h"
#include "Enchant.h"
#include "Skills.h"
#include "Unit.h"
#include "Packet.h"
#include "Items.h"
#include "Bmp.h"
#include "String2.h"
#include "Levels.h"

using namespace std;

//																here russian windows support
#define CToW(szString, wString)				(MyMultiByteToWideChar(nCharTable, MB_PRECOMPOSED, szString, (int)strlen(szString), wString, (int)strlen(szString)+1))
#define	WToC(wString, szString)				(MyWideCharToMultiByte(nCharTable, 0, wString, -1, szString, (int)sizeof(szString), 0, 0));

#define ArraySize(x) (sizeof(x) / sizeof(x[0]))

DWORD WINAPI MaphackThread(LPVOID lpParameter);
VOID Print(CHAR* szFormat, ...);
VOID PrintAtBottomLeft(CHAR* szFormat, ...);