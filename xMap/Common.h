#include <iostream>
using namespace std;

#ifndef _COMMON_H
#define _COMMON_H

#define PVP_HOSTILE 1
#define PVP_FRIENDLY 2
#define PVP_NEUTRAL 3

VOID MyMultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, INT cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
VOID MyWideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cmMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar);

INT StringTokenize(CHAR * input, CHAR separator, CHAR ** tokenbuf, INT maxtokens);
int GetPvPStatus(DWORD nUnitId);
bool GetPlayerRoster(RosterUnit* pUnit, DWORD nUnitId);

int D2GetScreenSizeX();
int D2GetScreenSizeY();
int D2GetScreenOffsX();
int D2GetScreenOffsY();

int dp(int n);
string ToLowerCase (string s);
string parseStr1(char* str1);
string TrimSpaces(string s);
int StringToInt(string s);
string ToString(DWORD a);

double CalculateDistance(const POINT& pt1, const POINT& pt2);
double CalculateDistance(long x1, long y1, long x2, long y2);
//
/*DWORD D2GetTextFileNo(wchar_t *str);
DWORD D2GetTextWidth(wchar_t *str);
wchar_t * __cdecl wsprintfW2(wchar_t *dest, char *fmt, ...);
wchar_t * wcsrcat(wchar_t *dest, wchar_t *src);*/

#endif