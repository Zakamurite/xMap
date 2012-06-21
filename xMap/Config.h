#ifndef _CONFIG_H
#define _CONFIG_H

#define CONFIG_BOOL     1
#define CONFIG_INT      2
#define CONFIG_STRING   3

struct ConfigEntry
{
    char* pSection;
    char* pKey;
    char* pDefault;
    int nType;
    LPVOID nVar;
};

struct ItemColorEntry
{
    char* pCode;
    int color;
};

bool readConfig();
bool getBool(char* pRet);
VOID setConfig(char* pKey, char* pValue);
VOID getConfig(char* pKey);

int ReadColorFile();

void PrintConfigEntries();
/*void InitTCList();
void GetHighestTC(int tcno, TCTallys *tallys);*/

#endif