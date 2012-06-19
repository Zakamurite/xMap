#include "xMap.h"

void D2UnicodeFix2(LPWSTR lpText)
{
	if (lpText) {
		size_t LEN = wcslen(lpText);
		for (size_t i = 0; i < LEN; i++)
		{
			if (lpText[i] == 0xf8f5) // Unicode 'y'
				lpText[i] = 0xff; // Ansi 'y'
		}
	}
}

VOID MyMultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, INT cbMultiByte, 
						 LPWSTR lpWideCharStr, int cchWideChar)
{
	MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);

	//D2UnicodeFix2(lpWideCharStr);
	if (CodePage == CP_ACP)
	for (DWORD i = 0; i < wcslen(lpWideCharStr); i++)
		if(lpMultiByteStr[i] == 'ÿ' || lpMultiByteStr[i] == 121)
			lpWideCharStr[i] = 0xFF;
}

VOID MyWideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cmMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar)
{
	WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cmMultiByte, lpDefaultChar, lpUsedDefaultChar);

	/*if (CodePage == CP_ACP)
	for (DWORD i = 0; i < wcslen(lpWideCharStr); i++)
		if (lpWideCharStr[i] == 0xFF && lpWideCharStr[i+1] == L'c' && lpWideCharStr[i+2])
			lpMultiByteStr[i] = 'ÿ';*/
}
// returns the number of tokens made
INT StringTokenize(CHAR * input, CHAR separator, CHAR ** tokenbuf, INT maxtokens)
{
	CHAR * p = input;
	INT i = 0;
	do {
		tokenbuf[i] = p;
		p = strchr(p, separator);
		if(p)
			*(p++) = 0;
	} while (p && ++i < maxtokens);
	return ++i;
}

bool GetPlayerRoster(RosterUnit* pUnit, DWORD nUnitId)
{
	for (RosterUnit* pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
		if (pUnit->dwUnitId == nUnitId)
			return true;
	return false;
}

int GetPvPStatus(DWORD nUnitId)
{
	RosterUnit* pUnit;
	for (pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
		if (pUnit->dwUnitId == nUnitId)
			break;

	if (!pUnit)
		return PVP_HOSTILE;

	UnitAny* mypUnit = D2CLIENT_GetPlayerUnit ();
	
	RosterUnit* prPlayer;
	for (prPlayer = *p_D2CLIENT_PlayerList; prPlayer; prPlayer = prPlayer->pNext)
		if (prPlayer->dwUnitId == mypUnit->dwUnitId)
			break;
		

	if (TestPvpFlag(nUnitId, mypUnit->dwUnitId, 8) || TestPvpFlag(mypUnit->dwUnitId, nUnitId, 8))
		return PVP_HOSTILE;

	if (pUnit->dwPartyFlags & PARTY_IN_PARTY && prPlayer->wPartyId == pUnit->wPartyId)
		return PVP_FRIENDLY;

	return PVP_NEUTRAL;
}


string ToLowerCase (string s)
{
	char c[1024];
		strcpy_s(c, s.c_str());
	_strlwr_s(c);
		return c;
}

string parseStr1(char* str1)
{
	string s(str1);

	int i=0;
	do
	{
		if (((int)s.length()-i>=0))
		{
			if ((i!=0)&&(i!=s.length()))
			{
				s=s.insert(s.length()-i, ",");
				i++;
			}
		}
		else break;
		i+=3;
	}
	while(1);
	return s;
}

string TrimSpaces(string s)
{
	string tempstr = "";
	
	for (size_t i=0; i < s.size(); i++)
		if (s[i]!=' ' && s[i]!='\t')
			tempstr+=s[i];

	return ToLowerCase(tempstr);
}

int StringToInt(string s)
{
	int num=0;
	try
	{
		for(size_t i=0; i<s.size(); i++)
			if (s[s.size()-1-i]-'0' >=0 && s[s.size()-1-i]-'0'<='9')
				num+=(int)(s[s.size()-1-i]-'0')*dp(i);
			else return 0;
	}
	catch(exception &e)
	{
		//cout << e.what() << endl;
		return 0;
	}

	return num;
}

string ToString(DWORD a)
{
	char c[256];
	sprintf_s(c, sizeof(c), "%ld", a);

	return c;
}

int D2GetScreenSizeX()
{
	static int nums[2] = {640,800};
	return nums[D2GFX_GetScreenSize()/2];// ? 800 : 640;
}

int D2GetScreenSizeY()
{
	static int nums[2] = {480,600};
	return nums[D2GFX_GetScreenSize()/2];// ? 600 : 480;
}

int D2GetScreenOffsX()
{
	static int nums[2] = {0,80};
	return nums[D2GFX_GetScreenSize()/2];// ? 80 : 0;
}

int D2GetScreenOffsY()
{
	static int nums[2] = {0,60};
	return nums[D2GFX_GetScreenSize()/2];// ? 60 : 0;
}

int dp(int n)
{
	int c=1;
	for (int i=0; i<n; i++)
		c*=10;

	return c;
}

double CalculateDistance(const POINT& pt1, const POINT& pt2)
{
	return CalculateDistance(pt1.x, pt1.y, pt2.x, pt2.y);
}

double CalculateDistance(long x1, long y1, long x2, long y2)
{
	return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}



/*DWORD D2GetTextFileNo(wchar_t *str)
{
	return 0;
	DWORD width, fileno;
	D2WIN_GetTextWidthFileNo(str, &width, &fileno);
	return fileno;
}

DWORD D2GetTextWidth(wchar_t *str)
{
	DWORD width, fileno;
	D2WIN_GetTextWidthFileNo(str, &width, &fileno);
	return width;
}

wchar_t * __cdecl wsprintfW2(wchar_t *dest, char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	int len = wvsprintf((char *)dest, fmt, va);
	for (int i = len; i >= 0; i--) {
		dest[i] = ((char *)dest)[i];
	}
	return dest;
}

wchar_t * wcsrcat(wchar_t *dest, wchar_t *src)
{
	memmove(dest+wcslen(src), dest, (wcslen(dest)+1)*sizeof(wchar_t));
	memcpy(dest, src, wcslen(src)*sizeof(wchar_t));
	return dest;
}*/

