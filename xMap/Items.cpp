#include "xMap.h"

void UseItem(UnitAny* Unit)
{
    UnitAny* pUnit = D2CLIENT_GetPlayerUnit();
    if (!Unit || !pUnit) 
        return;

    BYTE aPacket[13] = {0};
    switch (GetItemLocation(Unit))
    {
        case STORAGE_INVENTORY:
            aPacket[0] = 0x20;
            *(DWORD*)&aPacket[1] = Unit->dwUnitId;
            *(DWORD*)&aPacket[5] = pUnit->pPath->xPos;
            *(DWORD*)&aPacket[9] = pUnit->pPath->yPos;
            break;
        case STORAGE_BELT:
            aPacket[0] = 0x26;
            *(DWORD*)&aPacket[1] = Unit->dwUnitId;
            *(DWORD*)&aPacket[5] = 0;
            *(DWORD*)&aPacket[9] = 0;
            break;
    }

    if (aPacket[0])
        D2NET_SendPacket(13, 1, aPacket);
}

UnitAny* FindItem(CHAR* szCode, INT nLoc)
{
    return FindItem((*p_D2CLIENT_PlayerUnit), szCode, nLoc);
}

UnitAny* FindItem(UnitAny* pUnit, CHAR* szCode, INT nLoc)
{
    //Loop the items in inventory.
    for (UnitAny* pItem = pUnit->pInventory->pFirstItem; pItem; pItem = pItem->pItemData->pNextInvItem)
    {
        //Compare Locations
        if (pItem->pItemData->ItemLocation != nLoc && nLoc != -1)
            continue;

        //Compare Item Codes
        ItemTxt* pTxt = D2COMMON_GetItemTxt(pItem->dwTxtFileNo);

        char c[1024];
        strcpy_s(c, sizeof(c), pTxt->szCode);
        if (!_strcmpi(szCode, strtok(c, " ")))
            return pItem;
    }
    return false;
} 

INT GetItemLocation(UnitAny* pItem)
{
    if (!pItem || !pItem->pItemData)
        return -1;

    switch (pItem->pItemData->ItemLocation)
    {
        case STORAGE_INVENTORY:
            return STORAGE_INVENTORY;
        case STORAGE_TRADE:
            if(pItem->pItemData->NodePage == NODEPAGE_STORAGE)
                return STORAGE_TRADE;
        case STORAGE_CUBE:
            return STORAGE_CUBE;    
        case STORAGE_STASH:
            return STORAGE_STASH;
        case STORAGE_NULL:
            switch(pItem->pItemData->NodePage)
            {
                case NODEPAGE_EQUIP:
                    return STORAGE_EQUIP;
                case NODEPAGE_BELTSLOTS:
                    return STORAGE_BELT;
            }
            break;
    }

    return STORAGE_NULL;
}

BOOL GetItemCode(UnitAny* pItem, CHAR* szBuffer, DWORD dwMax)
{
    if (!pItem)
        return FALSE;

    ItemTxt* pTxt = D2COMMON_GetItemTxt(pItem->dwUnitId);
    ::memcpy(szBuffer, pTxt->szCode, min(3, dwMax));
    return (int)strlen(szBuffer);
}

bool NoiLvl(DWORD itemcode)
{
    return 
        //gems, pots, exlixirs
        CompareItems(itemcode, 'gcv ') || CompareItems(itemcode, 'gfv ') || CompareItems(itemcode, 'gsv ') || CompareItems(itemcode, 'gzv ') || CompareItems(itemcode, 'gpv ') ||
        CompareItems(itemcode, 'gcy ') || CompareItems(itemcode, 'gfy ') || CompareItems(itemcode, 'gsy ') || CompareItems(itemcode, 'gly ') || CompareItems(itemcode, 'gpy ') || 
        CompareItems(itemcode, 'gcb ') || CompareItems(itemcode, 'gfb ') || CompareItems(itemcode, 'gsb ') || CompareItems(itemcode, 'glb ') ||    CompareItems(itemcode, 'gpb ') ||
        CompareItems(itemcode, 'gcg ') || CompareItems(itemcode, 'gfg ') || CompareItems(itemcode, 'gsg ') || CompareItems(itemcode, 'glg ') || CompareItems(itemcode, 'gpg ') ||
        CompareItems(itemcode, 'gcr ') || CompareItems(itemcode, 'gfr ') || CompareItems(itemcode, 'gsr ') || CompareItems(itemcode, 'glr ') || CompareItems(itemcode, 'gpr ') ||
        CompareItems(itemcode, 'gcw ') || CompareItems(itemcode, 'gfw ') || CompareItems(itemcode, 'gsw ') || CompareItems(itemcode, 'glw ') || CompareItems(itemcode, 'gpw ') ||
        CompareItems(itemcode, 'hp1 ') || CompareItems(itemcode, 'hp2 ') || CompareItems(itemcode, 'hp3 ') ||
        CompareItems(itemcode, 'hp4 ') || CompareItems(itemcode, 'hp5 ') ||
        CompareItems(itemcode, 'mp1 ') || CompareItems(itemcode, 'mp2 ') || CompareItems(itemcode, 'mp3 ') ||
        CompareItems(itemcode, 'mp4 ') || CompareItems(itemcode, 'mp5 ') || 
        CompareItems(itemcode, 'skc ') || CompareItems(itemcode, 'skf ') || CompareItems(itemcode, 'sku ') || CompareItems(itemcode, 'skl ') || CompareItems(itemcode, 'skz ') ||
        CompareItems(itemcode, 'elx ') || 
        //some unknown shit
        CompareItems(itemcode, 'hpo ') ||  CompareItems(itemcode, 'mpo ') ||  CompareItems(itemcode, 'hpf ') ||  CompareItems(itemcode, 'mpf ') || 
        //antidote  stamina antifreeze
        CompareItems(itemcode, 'vps ') || CompareItems(itemcode, 'yps ') || CompareItems(itemcode, 'wms ') || 
        //rejuvs
        CompareItems(itemcode, 'rvs ') || CompareItems(itemcode, 'rvl ') ||     
        //scrolls and boks
        CompareItems(itemcode, 'tbk ') || CompareItems(itemcode, 'ibk ') ||
        CompareItems(itemcode, 'tsc ') || CompareItems(itemcode, 'isc ') ||
        //runes
        CompareItems(itemcode, 'r01 ') || CompareItems(itemcode, 'r02 ') || CompareItems(itemcode, 'r03 ') || 
        CompareItems(itemcode, 'r04 ') || CompareItems(itemcode, 'r05 ') || CompareItems(itemcode, 'r06 ') ||
        CompareItems(itemcode, 'r07 ') || CompareItems(itemcode, 'r08 ') || CompareItems(itemcode, 'r09 ') ||
        CompareItems(itemcode, 'r10 ') || CompareItems(itemcode, 'r11 ') ||    CompareItems(itemcode, 'r12 ') ||
        CompareItems(itemcode, 'r13 ') || CompareItems(itemcode, 'r14 ') ||    CompareItems(itemcode, 'r15 ') ||
        CompareItems(itemcode, 'r16 ') || CompareItems(itemcode, 'r17 ') ||    CompareItems(itemcode, 'r18 ') ||
        CompareItems(itemcode, 'r19 ') || CompareItems(itemcode, 'r20 ') ||    CompareItems(itemcode, 'r21 ') ||
        CompareItems(itemcode, 'r22 ') || CompareItems(itemcode, 'r23 ') ||    CompareItems(itemcode, 'r24 ') ||
        CompareItems(itemcode, 'r25 ') || CompareItems(itemcode, 'r26 ') ||    CompareItems(itemcode, 'r27 ') ||
        CompareItems(itemcode, 'r28 ') || CompareItems(itemcode, 'r29 ') ||    CompareItems(itemcode, 'r30 ') ||
        CompareItems(itemcode, 'r31 ') || CompareItems(itemcode, 'r32 ') ||    CompareItems(itemcode, 'r33 ') ||
        //arrows and bolt and crap potions
        CompareItems(itemcode, 'aqv ') || CompareItems(itemcode, 'cqv ') ||
        CompareItems(itemcode, 'gps ') || CompareItems(itemcode, 'ops ') ||    CompareItems(itemcode, 'gpm ') ||
        CompareItems(itemcode, 'opm ') || CompareItems(itemcode, 'gpl ') ||    CompareItems(itemcode, 'opl ');
}

bool CompareItems(DWORD itemcode, DWORD itemcode2)
{
    return itemcode == D2TXTCODE(itemcode2);
}

String GetItemCode(UnitAny* pItem)
{
    if (!pItem)
        return "null";

    if (pItem->dwType == UNIT_ITEM)
    {
        if (ItemTxt* txt = D2COMMON_GetItemTxt(pItem->dwTxtFileNo))
        {
            string code=txt->szCode;
            return code.substr(0, code.find_first_of(' '));
        }
    }

    return "null";
}

String GetItemCode(ItemTxt* txt)
{
    if (!txt)
        return "null";

    string code = txt->szCode;
    return code.substr(0, code.find_first_of(' '));
}

String GetItemLocation(int itemLocation)
{
    switch(itemLocation)
    {
        case ITEM_BODYLOCATION_NONE:
            return "Inventory";
        case ITEM_BODYLOCATION_ARMOR:
            return "Armor";
        case ITEM_BODYLOCATION_WEAPON:
            return "Weapon";
        default:
            return "Unknown";
    }
}

int GetItemLocation(String itemLocation)
{
    String i = itemLocation.Trim();
    if (i == "inventory")
        return ITEM_BODYLOCATION_NONE;
    else if (i == "armor")        
        return ITEM_BODYLOCATION_ARMOR;
    else if (i == "weapon")
        return ITEM_BODYLOCATION_WEAPON;
    else
        return 0;    
}

String GetItemRarity(int itemRarity)
{
    switch(itemRarity)
    {
        case ITEM_RARITY_NORMAL:
            return "Normal";
        case ITEM_RARITY_EXCEPTIONAL:
            return "Exceptional";
        case ITEM_RARITY_ELITE:
            return "Elite";
        case ITEM_RARITY_QUEST:
            return "Quest";
        case ITEM_RARITY_MISC:
            return "Misc";
        default:
            return "Unknown";
    }
}

int GetItemRarity(String itemRarity)
{
    String i = itemRarity.Trim();

    if (i == "normal")
        return ITEM_RARITY_NORMAL;
    else if (i == "exceptional" || i == "exc")
        return ITEM_RARITY_EXCEPTIONAL;
    else if (i == "elite")        
        return ITEM_RARITY_ELITE;
    else if (i == "quest")
        return ITEM_RARITY_QUEST;
    else if (i == "misc")
        return ITEM_RARITY_MISC;
    else
        return 0;
}

String GetItemWeaponClass(int weaponClass)
{
    switch(weaponClass)
    {
        case ITEM_WEAPONCLASS_AXE:
            return "Axe";
        case ITEM_WEAPONCLASS_BOW:
            return "Bow";
        case ITEM_WEAPONCLASS_CROSSBOW:
            return "Crossbow";
        case ITEM_WEAPONCLASS_DAGGER:
            return "Dagger";
        case ITEM_WEAPONCLASS_JAVELIN:
            return "Javelin";
        case ITEM_WEAPONCLASS_MACE:
            return "Mace";
        case ITEM_WEAPONCLASS_POLEARM:
            return "Polearm";
        case ITEM_WEAPONCLASS_SCEPTER:
            return "Scepter";
        case ITEM_WEAPONCLASS_SPEAR:
            return "Spear";
        case ITEM_WEAPONCLASS_STAFF:
            return "Staff";
        case ITEM_WEAPONCLASS_SWORD:
            return "Sword";
        case ITEM_WEAPONCLASS_THROW:
            return "Throwing Weapon";
        case ITEM_WEAPONCLASS_WAND:
            return "Wand";
        case ITEM_WEAPONCLASS_AMAJAVELIN:
            return "Amazon Javelin";
        case ITEM_WEAPONCLASS_ASSAKATAR:
            return "Assassin Katar";
        case ITEM_WEAPONCLASS_SOSOORB:
            return "Sorceress Orb";
        case ITEM_WEAPONCLASS_POTION:
            return "Throwing Potion";
            break;
        case ITEM_WEAPONCLASS_AMABOW:
            return "Amazon Bow";
        default:
            return "Unknown";
    }
}

int GetItemWeaponClass(String weaponClass)
{
    String w = weaponClass.Trim();

    if (w == "axe")
        return ITEM_WEAPONCLASS_AXE;
    else if (w == "bow")
        return ITEM_WEAPONCLASS_BOW;
    else if (w == "crossbow")
        return ITEM_WEAPONCLASS_CROSSBOW;
    else if (w == "dagger")
        return ITEM_WEAPONCLASS_DAGGER;
    else if (w == "javelin")
        return ITEM_WEAPONCLASS_JAVELIN;
    else if (w == "mace")
        return ITEM_WEAPONCLASS_MACE;
    else if (w == "polearm")
        return ITEM_WEAPONCLASS_POLEARM;
    else if (w == "scepter")
        return ITEM_WEAPONCLASS_SCEPTER;
    else if (w == "spear")
        return ITEM_WEAPONCLASS_SPEAR;
    else if (w == "staff")
        return ITEM_WEAPONCLASS_STAFF;
    else if (w == "sword")
        return ITEM_WEAPONCLASS_SWORD;
    else if (w == "throwingweapon")
        return ITEM_WEAPONCLASS_THROW;
    else if (w == "wand")
        return ITEM_WEAPONCLASS_WAND;
    else if (w == "amazonjavelin")
        return ITEM_WEAPONCLASS_AMAJAVELIN;
    else if (w == "assassinkatar")
        return ITEM_WEAPONCLASS_ASSAKATAR;
    else if (w == "sorceressorb")
        return ITEM_WEAPONCLASS_SOSOORB;
    else if (w == "throwingpotion")
        return ITEM_WEAPONCLASS_POTION;
    else if (w == "amazonbow")
        return ITEM_WEAPONCLASS_AMABOW;
    else if (w == "ammunition")
        return ITEM_WEAPONCLASS_AMMUNITION;    
    else
        return 0;
}

String GetItemArmorClass(int armorClass)
{
    switch (armorClass)
    {
        case ITEM_ARMORCLASS_HELM:
            return "Helm";
        case ITEM_ARMORCLASS_BODYARMOR:
            return "Body Armor";
        case ITEM_ARMORCLASS_SHIELD:
            return "Shield";
        case ITEM_ARMORCLASS_GLOVES:
            return "Gloves";
        case ITEM_ARMORCLASS_BOOTS:
            return "Boots";
        case ITEM_ARMORCLASS_BELT:
            return "Belt";
        case ITEM_ARMORCLASS_BARBHELM:
            return "Barbarian Helm";
        case ITEM_ARMORCLASS_DRUIDHELM:
            return "Druid Pelt";
        case ITEM_ARMORCLASS_PALASHIELD:
            return "Paladin Shield";
        case ITEM_ARMORCLASS_NECROSHIELD:
            return "Necromancer Shield";
        case ITEM_ARMORCLASS_RING:
            return "Ring";
        case ITEM_ARMORCLASS_AMULET:
            return "Amulet";
        case ITEM_ARMORCLASS_CIRCLET:
            return "Circlet";
        default:
            return "Unknown";
    }
}

int GetItemArmorClass(String armorClass)
{
    String a = armorClass.Trim();
    if (a == "helm")
        return ITEM_ARMORCLASS_HELM;
    else if (a == "bodyarmor")
        return ITEM_ARMORCLASS_BODYARMOR;
    else if (a == "shield") 
        return ITEM_ARMORCLASS_SHIELD;
    else if (a == "gloves") 
        return ITEM_ARMORCLASS_GLOVES;
    else if (a == "boots")
        return ITEM_ARMORCLASS_BOOTS;
    else if (a == "belt") 
        return ITEM_ARMORCLASS_BELT;
    else if (a == "barbarianhelm") 
        return ITEM_ARMORCLASS_BARBHELM;
    else if (a == "druidpelt") 
        return ITEM_ARMORCLASS_DRUIDHELM;
    else if (a == "paladinshield") 
        return ITEM_ARMORCLASS_PALASHIELD;
    else if (a == "necromancershield") 
        return ITEM_ARMORCLASS_NECROSHIELD;
    else if (a == "ring") 
        return ITEM_ARMORCLASS_RING;
    else if (a == "amulet") 
        return ITEM_ARMORCLASS_AMULET;
    else if (a == "circlet") 
        return ITEM_ARMORCLASS_CIRCLET;
    else
        return 0;
}

String GetItemMiscClass(int miscClass)
{
    switch (miscClass)
    {
        case ITEM_MISCCLASS_GEM:
            return "Gem";
        case ITEM_MISCCLASS_JEWEL:
            return "Jewel";
        case ITEM_MISCCLASS_RUNE:
            return "Rune";
        case ITEM_MISCCLASS_CHARM:
            return "Charm";
        case ITEM_MISCCLASS_MISC:
            return "Misc";
        case ITEM_MISCCLASS_POTION:
            return "Potion";
        default:
            return "Unknown";
    }
}

int GetItemMiscClass(String miscClass)
{
    String m = miscClass.Trim();

    if (m == "gem")
        return ITEM_MISCCLASS_GEM;
    else if (m == "jewel")
        return ITEM_MISCCLASS_JEWEL;
    else if (m == "rune")        
        return ITEM_MISCCLASS_RUNE;
    else if (m == "charm")
        return ITEM_MISCCLASS_CHARM;
    else if (m == "misc")
        return ITEM_MISCCLASS_MISC;
    else if (m == "potion")
        return ITEM_MISCCLASS_POTION;    
    else
        return 0;
}

ItemFlags* GetMyItemFlags(int itemnjipID)
{
    ItemFlags* flags = new ItemFlags;
    memset(flags, 0, sizeof(ItemFlags));

    if (!itemnjipID)
        return flags;
    //cout << flags->bodyLocation << endl;

    //int ret = 0;

    /*************
     Body location
     *************/
    if (itemnjipID >= 1 && itemnjipID <= 86 || //normal weapons
        //itemnjipID >= 89 && itemnjipID <= 92 || //quest weapons
        itemnjipID >= 94 && itemnjipID <= 173 || //exc weapons
        //itemnjipID == 174 || itemnjipID == 175 || //khalim's crap
        itemnjipID >= 176 && itemnjipID <= 196 || //katars
        itemnjipID >= 197 && itemnjipID <= 276 || //elite weapons
        itemnjipID >= 277 && itemnjipID <= 306 || //soso and ama weapons
        itemnjipID == 527 || itemnjipID == 529 || //arrows and bolts
        itemnjipID >= 81 && itemnjipID <= 86 ) //potions
        flags->bodyLocation |= ITEM_BODYLOCATION_WEAPON;
    else if (itemnjipID >= 307 && itemnjipID <= 352 || //normal armor
        itemnjipID >= 353 && itemnjipID <= 398 || //exc armor
        itemnjipID >= 399 && itemnjipID <= 418 || //normal dudu baba pala necro njip-specific
        itemnjipID >= 419 && itemnjipID <= 422 || //circlets
        itemnjipID >= 423 && itemnjipID <= 468 || //elite armors
        itemnjipID >= 469 && itemnjipID <= 508 || //exc and elite dudu baba pala necro class-specific
        itemnjipID == 521 || itemnjipID == 522 ) //amulet and ring
        flags->bodyLocation |= ITEM_BODYLOCATION_ARMOR;
    else
        flags->bodyLocation |= ITEM_BODYLOCATION_NONE;

     /******
     Rarity
     ******/
    if (itemnjipID >= 1 && itemnjipID <= 80 || //normal weapons
        itemnjipID >= 176 && itemnjipID <= 182 || //normal katars
        itemnjipID >= 307 && itemnjipID <= 352 || //normal armor
        itemnjipID >= 399 && itemnjipID <= 418 || //normal class-specific
        itemnjipID == 419 || itemnjipID == 420) //circlet and coronet
        flags->rarity |= ITEM_RARITY_NORMAL;
    else if (itemnjipID >= 94 && itemnjipID <= 173 || //exc weapons
        itemnjipID >= 287 && itemnjipID <= 296 || //exc soso and ama weap
        itemnjipID >= 353 && itemnjipID <= 398 || //exc armor
        itemnjipID >= 469 && itemnjipID <= 488 || //exc dudu baba pala necro class-specific
        itemnjipID == 421 ) //tiara
        flags->rarity |= ITEM_RARITY_EXCEPTIONAL;
    else if (itemnjipID >= 190 && itemnjipID <= 196 || //elite katars
        itemnjipID >= 197 && itemnjipID <= 276 || //elite weap
        itemnjipID >= 297 && itemnjipID <= 306 || //elite soso and ama weap
        itemnjipID == 422 || //diadem
        itemnjipID >= 423 && itemnjipID <= 468 || //elite armor
        itemnjipID >= 489 && itemnjipID <= 508) //elite dudu baba pala necro class-specific
        flags->rarity |= ITEM_RARITY_ELITE;
    else if (itemnjipID >= 87 && itemnjipID <= 93 || //
        itemnjipID == 174 || itemnjipID == 175 || //khalim's crap
        itemnjipID == 522 || //top of the staff
        itemnjipID == 525 || itemnjipID == 526 || //infus, key to stones
        itemnjipID >= 546 && itemnjipID <= 556 || //
        itemnjipID == 645 || //malahs potion
        itemnjipID >= 648 && itemnjipID <= 654) //pandemonium items
        flags->rarity |= ITEM_RARITY_QUEST;
    else
        flags->rarity |= ITEM_RARITY_MISC;

     /*****
     TYPES
     *****/
    if (flags->bodyLocation & ITEM_BODYLOCATION_WEAPON)
    {
        if (itemnjipID >= 1 && itemnjipID <= 10 ||
            itemnjipID >= 94 && itemnjipID <= 103 ||
            itemnjipID >= 197 && itemnjipID <= 206)
            flags->itemClass |= ITEM_WEAPONCLASS_AXE;
        else if (itemnjipID >= 11 && itemnjipID <= 14 || 
            itemnjipID >= 104 && itemnjipID <= 107 || //+93
            itemnjipID >= 207 && itemnjipID <= 210) //+103
            flags->itemClass |= ITEM_WEAPONCLASS_WAND;
        else if (itemnjipID >= 15 && itemnjipID <= 25 ||
            itemnjipID >= 108 && itemnjipID <= 118 ||
            itemnjipID >= 211 && itemnjipID <= 221)
            flags->itemClass |= ITEM_WEAPONCLASS_MACE;
        else if (itemnjipID >= 26 && itemnjipID <= 39 ||
            itemnjipID >= 119 && itemnjipID <= 132 ||
            itemnjipID >= 222 && itemnjipID <= 235)
            flags->itemClass |= ITEM_WEAPONCLASS_SWORD;
        else if (itemnjipID >= 40 && itemnjipID <= 43 ||
            itemnjipID >= 133 && itemnjipID <= 136 ||
            itemnjipID >= 236 && itemnjipID <= 239)
            flags->itemClass |= ITEM_WEAPONCLASS_DAGGER;
        else if (itemnjipID >= 44 && itemnjipID <= 47 ||
            itemnjipID >= 137 && itemnjipID <= 140 ||
            itemnjipID >= 240 && itemnjipID <= 243)
            flags->itemClass |= ITEM_WEAPONCLASS_THROW;
        else if (itemnjipID >= 48 && itemnjipID <= 52 ||
            itemnjipID >= 141 && itemnjipID <= 145 ||
            itemnjipID >= 244 && itemnjipID <= 248)
            flags->itemClass |= ITEM_WEAPONCLASS_JAVELIN;
        else if (itemnjipID >= 53 && itemnjipID <= 57 || //+93
            itemnjipID >= 146 && itemnjipID <= 150 || //+103
            itemnjipID >= 249 && itemnjipID <= 253)
            flags->itemClass |= ITEM_WEAPONCLASS_SPEAR;
        else if (itemnjipID >= 58 && itemnjipID <= 63 ||
            itemnjipID >= 151 && itemnjipID <= 156 ||
            itemnjipID >= 254 && itemnjipID <= 259)
            flags->itemClass |= ITEM_WEAPONCLASS_POLEARM;
        else if (itemnjipID >= 64 && itemnjipID <= 68 ||
            itemnjipID >= 157 && itemnjipID <= 161 ||
            itemnjipID >= 260 && itemnjipID <= 264)
            flags->itemClass |= ITEM_WEAPONCLASS_STAFF;
        else if (itemnjipID >= 69 && itemnjipID <= 76 ||
            itemnjipID >= 162 && itemnjipID <= 169 ||
            itemnjipID >= 265 && itemnjipID <= 272)
            flags->itemClass |= ITEM_WEAPONCLASS_BOW;
        else if (itemnjipID >= 77 && itemnjipID <= 80 ||
            itemnjipID >= 170 && itemnjipID <= 173 ||
            itemnjipID >= 273 && itemnjipID <= 276)
            flags->itemClass |= ITEM_WEAPONCLASS_CROSSBOW;
        else if (itemnjipID >= 176 && itemnjipID <= 196)
            flags->itemClass |= ITEM_WEAPONCLASS_ASSAKATAR;
        else if (itemnjipID >= 277 && itemnjipID <= 281 ||
            itemnjipID >= 287 && itemnjipID <= 291 ||
            itemnjipID >= 297 && itemnjipID <= 301)
            flags->itemClass |= ITEM_WEAPONCLASS_SOSOORB;
        else if (itemnjipID == 282 || itemnjipID == 283 ||
            itemnjipID == 292 || itemnjipID == 293 ||
            itemnjipID == 302 || itemnjipID == 303)
            flags->itemClass |= ITEM_WEAPONCLASS_AMABOW;
        else if (itemnjipID >= 284 && itemnjipID <= 286 ||
            itemnjipID >= 294 && itemnjipID <= 296 ||
            itemnjipID >= 304 && itemnjipID <= 306)
            flags->itemClass |= ITEM_WEAPONCLASS_AMAJAVELIN;
        else if (itemnjipID >= 81 && itemnjipID <= 86)
            flags->itemClass |= ITEM_WEAPONCLASS_POTION;
        else if (itemnjipID == 527 || itemnjipID == 529) //bolts and arrows
            flags->itemClass |= ITEM_WEAPONCLASS_AMMUNITION; 
    }
    else if (flags->bodyLocation & ITEM_BODYLOCATION_ARMOR)
    {
         if (itemnjipID >= 307 && itemnjipID <= 313 || //+46
            itemnjipID >= 353 && itemnjipID <= 359 || //+70
            itemnjipID >= 423 && itemnjipID <= 429 ||
            itemnjipID == 350 || itemnjipID == 396 ||
            itemnjipID == 466)
            flags->itemClass |= ITEM_ARMORCLASS_HELM;
         else if (itemnjipID >= 314 && itemnjipID <= 328 ||
            itemnjipID >= 360 && itemnjipID <= 374 ||
            itemnjipID >= 430 && itemnjipID <= 444)
            flags->itemClass |= ITEM_ARMORCLASS_BODYARMOR;
         else if (itemnjipID >= 329 && itemnjipID <= 334 ||
            itemnjipID == 351 || itemnjipID == 352 ||
            itemnjipID >= 375 && itemnjipID <= 380 ||
            itemnjipID == 397 || itemnjipID == 398 ||
            itemnjipID >= 445 && itemnjipID <= 450 ||
            itemnjipID == 467 || itemnjipID == 468)
            flags->itemClass |= ITEM_ARMORCLASS_SHIELD;
         else if (itemnjipID >= 335 && itemnjipID <= 339 ||
            itemnjipID >= 381 && itemnjipID <= 385 ||
            itemnjipID >= 451 && itemnjipID <= 455 )
            flags->itemClass |= ITEM_ARMORCLASS_GLOVES;
         else if (itemnjipID >= 340 && itemnjipID <= 344 ||
            itemnjipID >= 386 && itemnjipID <= 390 ||
             itemnjipID >= 456 && itemnjipID <= 460 )
            flags->itemClass |= ITEM_ARMORCLASS_BOOTS;
         else if (itemnjipID >= 345 && itemnjipID <= 349 ||
            itemnjipID >= 391 && itemnjipID <= 395 ||
            itemnjipID >= 461 && itemnjipID <= 465 )
            flags->itemClass |= ITEM_ARMORCLASS_BELT;
         else if (itemnjipID >= 399 && itemnjipID <= 403 || //+70
            itemnjipID >= 469 && itemnjipID <= 473 || //+20
            itemnjipID >= 489 && itemnjipID <= 493 )
            flags->itemClass |= ITEM_ARMORCLASS_DRUIDHELM;
         else if (itemnjipID >= 404 && itemnjipID <= 408 ||
            itemnjipID >= 474 && itemnjipID <= 478 ||
            itemnjipID >= 494 && itemnjipID <= 498 )
            flags->itemClass |= ITEM_ARMORCLASS_BARBHELM;
         else if (itemnjipID >= 409 && itemnjipID <= 413 ||
            itemnjipID >= 479 && itemnjipID <= 483 ||
            itemnjipID >= 499 && itemnjipID <= 503 )
            flags->itemClass |= ITEM_ARMORCLASS_PALASHIELD;
         else if (itemnjipID >= 414 && itemnjipID <= 418 ||
            itemnjipID >= 484 && itemnjipID <= 488 ||
            itemnjipID >= 504 && itemnjipID <= 508 )
            flags->itemClass |= ITEM_ARMORCLASS_NECROSHIELD;

         if (itemnjipID >= 419 && itemnjipID <= 422 )
            flags->itemClass |= ITEM_ARMORCLASS_CIRCLET;
         else if (itemnjipID == 521)
            flags->itemClass |= ITEM_ARMORCLASS_AMULET;
         else if (itemnjipID == 523)
            flags->itemClass |= ITEM_ARMORCLASS_RING;
    }
    else if (flags->bodyLocation & ITEM_BODYLOCATION_NONE)
    {
        if (itemnjipID >= 514 && itemnjipID <= 518 ||
            itemnjipID >= 588 && itemnjipID <= 597)
            flags->itemClass |= ITEM_MISCCLASS_POTION;
        else if (itemnjipID >= 558 && itemnjipID <= 587 ||
            itemnjipID >= 598 && itemnjipID <= 602)
            flags->itemClass |= ITEM_MISCCLASS_GEM;
        else if (itemnjipID >= 604 && itemnjipID <= 606)
            flags->itemClass |= ITEM_MISCCLASS_CHARM;
        else if (itemnjipID >= 611 && itemnjipID <= 643)
            flags->itemClass |= ITEM_MISCCLASS_RUNE;
        else if (itemnjipID == 644)
            flags->itemClass |= ITEM_MISCCLASS_JEWEL;
        else
            flags->itemClass |= ITEM_MISCCLASS_MISC;
    }
    else
        flags->itemClass |= ITEM_MISCCLASS_MISC;

    return flags;
}

bool CompareItemWithDescription(ItemDesc* item, ItemDesc* desc)
{
    if (!item || !desc)
        return false;
    if (item->itemCode.empty() || !item->flags || !desc->flags)
        return false;

    int eth = item->isEthereal;
    //String name = *item->itemCode.begin();
    int code = *item->itemCode.begin();
    /*int quality = *item->itemQuality.begin();
    int sock = *item->numSockets.begin();*/

    bool flag = desc->isEthereal == -1 ? true : (eth && desc->isEthereal);
    if (!flag)
        return false;

    flag = desc->itemCode.empty();
    //for (list<String>::iterator i = desc->itemCode.begin(); i != desc->itemCode.end(); i++)
    for (list<int>::iterator i = desc->itemCode.begin(); i != desc->itemCode.end(); i++)
        //if ( *i == name )
        //if ( njipClassId[*i] == njipClassId[name.ToLowerCase()] )
        if ( *i == code )
        {
            flag = true;
            break;
        }
    if (!flag)
        return false;

    flag = desc->itemQuality & ITEM_QUALITY_ANY;
    if (!flag)
        flag = item->itemQuality & desc->itemQuality;
    /*for (list<int>::iterator i = desc->itemQuality.begin(); i !=desc->itemQuality.end(); i++)
    {
        if (*i == quality || *i == 0)
        {
            flag= true;
            break;
        }
    }*/
    if (!flag)
        return false;

    flag = desc->numSockets & ITEM_NUMSOCKETS_ANY;
    if (!flag)
        flag = item->numSockets & desc->numSockets;
    /*for (list<int>::iterator i = desc->numSockets.begin(); i != desc->numSockets.end(); i++)
    {
        if (*i == sock || *i == -1)
        {
            flag = true;
            break;
        }
    }*/
    if (!flag)
        return false;

    flag = true;
    if (desc->flags->bodyLocation)
        if (! (desc->flags->bodyLocation & item->flags->bodyLocation))
            return false;

    if (desc->flags->itemClass)
        if (! (desc->flags->itemClass & item->flags->itemClass))
            return false;

    if (desc->flags->rarity)
        if (! (desc->flags->rarity & item->flags->rarity))
            return false;

    return flag;
}

////////////////////////

int GetItemQualityFromD2(int d2Quality)
{
    switch (d2Quality)
    {
        case ITEM_D2QUALITY_LOW:
            return ITEM_QUALITY_LOW;
        case ITEM_D2QUALITY_NORMAL:
            return ITEM_QUALITY_NORMAL;
        case ITEM_D2QUALITY_SUPERIOR:
            return ITEM_QUALITY_SUPERIOR;
        case ITEM_D2QUALITY_MAGIC:
            return ITEM_QUALITY_MAGIC;
        case ITEM_D2QUALITY_SET:
            return ITEM_QUALITY_SET;
        case ITEM_D2QUALITY_RARE:
            return ITEM_QUALITY_RARE;
        case ITEM_D2QUALITY_UNIQUE:
            return ITEM_QUALITY_UNIQUE;
        case ITEM_D2QUALITY_CRAFT:
            return ITEM_QUALITY_CRAFT;
        case ITEM_D2QUALITY_TEMPERED:
            return ITEM_QUALITY_TEMPERED;
        default:
            return ITEM_QUALITY_ANY;
    }
}

String GetItemQuality(int quality)
{
    switch (quality)
    {
        case ITEM_QUALITY_LOW:
            return "Low";
        case ITEM_QUALITY_NORMAL:
            return "Normal";
        case ITEM_QUALITY_SUPERIOR:
            return "Superior";
        case ITEM_QUALITY_MAGIC:
            return "Magic";
        case ITEM_QUALITY_SET:
            return "Set";
        case ITEM_QUALITY_RARE:
            return "Rare";
        case ITEM_QUALITY_UNIQUE:
            return "Unique";
        case ITEM_QUALITY_CRAFT:
            return "Craft";
        case ITEM_QUALITY_TEMPERED:
            return "Tempered";
        default:
            return "Any";
    }
}

int GetItemQuality(String quality)
{
    String q = quality.Trim();

    if (q == "any")
        return ITEM_QUALITY_ANY;
    else if (q == "low" || q == "crude")
        return ITEM_QUALITY_LOW;
    else if (q == "norm" || q == "normal")
        return ITEM_QUALITY_NORMAL;
    else if (q == "sup" || q == "hiq" || q == "superior")
        return ITEM_QUALITY_SUPERIOR;
    else if (q == "mag" || q == "magic")
        return ITEM_QUALITY_MAGIC;
    else if (q == "set")
        return ITEM_QUALITY_SET;
    else if (q == "rare")
        return ITEM_QUALITY_RARE;
    else if (q == "uni" || q == "unique")
        return ITEM_QUALITY_UNIQUE;
    else if (q == "craft")
        return ITEM_QUALITY_CRAFT;
    else if (q == "tempered")
        return ITEM_QUALITY_TEMPERED;
    else if (q == "white")
        return ITEM_QUALITY_LOW + ITEM_QUALITY_NORMAL + ITEM_QUALITY_SUPERIOR;
    else
        return 0;    
}

int GetItemColor(String color)
{
    String c = color.Trim();

    if (c == "default" || c == "white")
        return '0';
    else if (c == "purple")
        return ';';
    else if (c == "red")
        return '1';
    else if (c == "green")
        return '2';
    else if (c == "blue")
        return '3';
    else if (c == "tan")
        return '4';
    else if (c == "gray")
        return '5';
    else if (c == "black")
        return '6';
    else if (c == "gold")
        return '7';
    else if (c == "orange")
        return '8';
    else if (c == "yellow")
        return '9';
    else if (c == "gold")
        return '=';
    else if (c == "boldwhite")
        return '-';
    else if (c == "boldwhite2")
        return '+';
    else if (c == "darkgreen")
        return '<';
    else if (c == "darkgreen2")
        return ';';
    //else
    //if (c == "hide")
    //    return 254;
    else
        return 255;
}

int GetItemMapColor(String color)
{
    String c = color.Trim();

    if (c == "default")
        return -1;
    else if (c == "orange")
        return 0x68;
    else if (c == "white")
        return 0x20;
    else if (c == "red")
        return 0x62;
    else if (c == "green")
        return 0x84;
    else if (c == "purple")
        return 0x9B;
    else if (c == "blue")
        return 0x97;
    else if (c == "skyblue")
        return 0x9E;
    else if (c == "lightgreen")
        return 0x87;
    else if (c == "pink")
        return 0x70;
    else if (c == "yellow")
        return 0xA8;
    else
        return -2;
}

int GetItemNumSockets(String sock)
{
    String s = sock.Trim();

    if (s == "any")
        return ITEM_NUMSOCKETS_ANY;
    else if (s == "0")
        return ITEM_NUMSOCKETS_0;
    else if (s == "1")
        return ITEM_NUMSOCKETS_1;
    else if (s == "2")
        return ITEM_NUMSOCKETS_2;
    else if (s == "3")
        return ITEM_NUMSOCKETS_3;
    else if (s == "4")
        return ITEM_NUMSOCKETS_4;
    else if (s == "5")
        return ITEM_NUMSOCKETS_5;
    else if (s == "6")
        return ITEM_NUMSOCKETS_6;
    else
        return 0;
}

int GetItemNumSocketsFromD2(int sock)
{
    switch(sock)
    {
        case 0:
            return ITEM_NUMSOCKETS_0;
        case 1:
            return ITEM_NUMSOCKETS_1;
        case 2:
            return ITEM_NUMSOCKETS_2;
        case 3:
            return ITEM_NUMSOCKETS_3;
        case 4:
            return ITEM_NUMSOCKETS_4;
        case 5:
            return ITEM_NUMSOCKETS_5;
        case 6:
            return ITEM_NUMSOCKETS_6;
        default:
            return 0;
    }
}

bool IsItemRune(int njipClassId)
{
    return (njipClassId >= 611 && njipClassId <= 643);    
}

int GetRuneNumber(int njipClassId)
{
    return njipClassId - 611 + 1;
}

int GetNumberOfTPs()
{
    UnitAny* pUnit = FindItem("tbk", STORAGE_INVENTORY);
    if (!pUnit)
        return -1;

    return GetUnitStat(pUnit, STAT_AMMOQUANTITY);
}