#ifndef _ENCHANT_H
#define _ENCHANT_H

#define ENCHANT_ME		1
#define ENCHANT_MERC	2
#define ENCHANT_ALL		3

//#define cEnchantMe "chant"
//#define cEnchantMerc "chantmerc"
//#define cEnchantAll "chantall"

BOOL ExecuteEnchantQueue(LPENCHANTINFO EnchInfo);

DWORD WINAPI EnchantThread(LPVOID lpParameter);

#endif