#ifndef _ITEMS_H
#define _ITEMS_H

#define ITEM_BODYLOCATION_NONE		1
#define ITEM_BODYLOCATION_ARMOR		2
#define ITEM_BODYLOCATION_WEAPON	4

#define ITEM_RARITY_NORMAL			1
#define ITEM_RARITY_EXCEPTIONAL		2
#define ITEM_RARITY_ELITE			4
#define ITEM_RARITY_QUEST			8
#define ITEM_RARITY_MISC			16

#define ITEM_WEAPONCLASS_AXE		1
#define ITEM_WEAPONCLASS_BOW		2
#define ITEM_WEAPONCLASS_CROSSBOW	4
#define ITEM_WEAPONCLASS_DAGGER		8
#define ITEM_WEAPONCLASS_JAVELIN	16
#define ITEM_WEAPONCLASS_MACE		32
#define ITEM_WEAPONCLASS_POLEARM	64
#define ITEM_WEAPONCLASS_SCEPTER	128
#define ITEM_WEAPONCLASS_SPEAR		256
#define ITEM_WEAPONCLASS_STAFF		512
#define ITEM_WEAPONCLASS_SWORD		1024
#define ITEM_WEAPONCLASS_THROW		2048
#define ITEM_WEAPONCLASS_WAND		4096
#define ITEM_WEAPONCLASS_AMAJAVELIN	8192
#define ITEM_WEAPONCLASS_ASSAKATAR	16384
#define ITEM_WEAPONCLASS_SOSOORB	32768
#define ITEM_WEAPONCLASS_POTION		65536
#define ITEM_WEAPONCLASS_AMABOW		131072
#define ITEM_WEAPONCLASS_AMMUNITION 262144

#define ITEM_ARMORCLASS_HELM		1
#define ITEM_ARMORCLASS_BODYARMOR	2
#define ITEM_ARMORCLASS_SHIELD		4
#define ITEM_ARMORCLASS_GLOVES		8
#define ITEM_ARMORCLASS_BOOTS		16
#define ITEM_ARMORCLASS_BELT		32
#define ITEM_ARMORCLASS_BARBHELM	64
#define ITEM_ARMORCLASS_DRUIDHELM	128
#define ITEM_ARMORCLASS_PALASHIELD	256
#define ITEM_ARMORCLASS_NECROSHIELD	512
#define ITEM_ARMORCLASS_RING		1024
#define ITEM_ARMORCLASS_AMULET		2048
#define ITEM_ARMORCLASS_CIRCLET		4096

#define ITEM_MISCCLASS_GEM			1
#define ITEM_MISCCLASS_JEWEL		2
#define ITEM_MISCCLASS_RUNE			4
#define ITEM_MISCCLASS_CHARM		8
#define ITEM_MISCCLASS_MISC			16
#define ITEM_MISCCLASS_POTION		32

#define ITEM_D2QUALITY_LOW		1
#define ITEM_D2QUALITY_NORMAL	2
#define ITEM_D2QUALITY_SUPERIOR	3
#define ITEM_D2QUALITY_MAGIC	4
#define ITEM_D2QUALITY_SET		5
#define ITEM_D2QUALITY_RARE		6
#define ITEM_D2QUALITY_UNIQUE	7
#define ITEM_D2QUALITY_CRAFT	8
#define ITEM_D2QUALITY_TEMPERED	9

#define ITEM_QUALITY_LOW		1
#define ITEM_QUALITY_NORMAL		2
#define ITEM_QUALITY_SUPERIOR	4
#define ITEM_QUALITY_MAGIC		8
#define ITEM_QUALITY_SET		16
#define ITEM_QUALITY_RARE		32
#define ITEM_QUALITY_UNIQUE		64
#define ITEM_QUALITY_CRAFT		128
#define ITEM_QUALITY_TEMPERED	256
#define ITEM_QUALITY_ANY		512

#define ITEM_NUMSOCKETS_0	1
#define ITEM_NUMSOCKETS_1	2
#define ITEM_NUMSOCKETS_2	4
#define ITEM_NUMSOCKETS_3	8
#define ITEM_NUMSOCKETS_4	16
#define ITEM_NUMSOCKETS_5	32
#define ITEM_NUMSOCKETS_6	64
#define ITEM_NUMSOCKETS_ANY	128

void UseItem(UnitAny* Unit);
INT GetItemLocation(UnitAny* pItem);
BOOL GetItemCode(UnitAny* pItem, CHAR* szBuffer, DWORD dwMax);
UnitAny* FindItem(CHAR* szCode, INT nLoc);
UnitAny* FindItem(UnitAny* pUnit, CHAR* szCode, INT nLoc);
bool NoiLvl(DWORD itemcode);
bool CompareItems(DWORD itemcode, DWORD itemcode2);

String GetItemCode(UnitAny* pItem);
String GetItemCode(ItemTxt* txt);

String GetItemLocation(int itemLocation);
int GetItemLocation(String itemLocation);
String GetItemRarity(int itemRarity);
int GetItemRarity(String itemRarity);
String GetItemWeaponClass(int weaponClass);
int GetItemWeaponClass(String weaponClass);
String GetItemArmorClass(int armorClass);
int GetItemArmorClass(String armorClass);
String GetItemMiscClass(int miscClass);
int GetItemMiscClass(String miscClass);
ItemFlags* GetMyItemFlags(int itemnjipID);
bool CompareItemWithDescription(ItemDesc* item, ItemDesc* desc);
int GetItemQualityFromD2(int d2Quality);
String GetItemQuality(int quality);
int GetItemQuality(String quality);
int GetItemColor(String color);
int GetItemMapColor(String color);
int GetItemNumSockets(String sock);
int GetItemNumSocketsFromD2(int sock);
bool IsItemRune(int njipClassId);
int GetRuneNumber(int njipClassId);
int GetNumberOfTPs();

#endif