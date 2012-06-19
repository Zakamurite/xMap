PatchHook pHooks[] = {
	{PatchJmp, GetDllOffset("D2Client.dll", 0x40609), (DWORD)GameDrawAutomapInfo_STUB, 5}, 
	{PatchJmp, GetDllOffset("D2Client.dll", 0x90524), (DWORD)GameDraw_STUB, 6}, 

	{PatchCall, GetDllOffset("D2Client.dll", 0x869B5), (DWORD)GameInput_Interception, 5},
	{PatchCall, GetDllOffset("D2Client.dll", 0xAC236), (DWORD)ItemNamePatch_ASM, 6},
	{PatchCall, GetDllOffset("D2Client.dll", 0x5F907), (DWORD)LightingPatch_ASM, 6},

	{PatchJmp, GetDllOffset("D2Common.dll", 0x73A06), (DWORD)WeatherPatch_ASM, 5},
	

	{PatchCall, GetDllOffset("D2Multi.dll", 0x1463B),   (DWORD)NextGameNamePatch, 5}, //this is on join game patch
	{PatchCall, GetDllOffset("D2Multi.dll", 0x14959),   (DWORD)NextGameNamePatch, 5},

	{PatchCall, GetDllOffset("D2Client.dll", 0xAF242),   (DWORD)ViewInventoryPatch1_ASM, 6},
	{PatchCall, GetDllOffset("D2Client.dll", 0xAE914),   (DWORD)ViewInventoryPatch2_ASM, 6},
	{PatchCall, GetDllOffset("D2Client.dll", 0xAD93F),   (DWORD)ViewInventoryPatch3_ASM, 5},
	{PatchCall, GetDllOffset("D2Client.dll", 0x7CA82),	 (DWORD)ShakeScreenPatch, 5},
	//d2client offset: 6FAB0000
	{PatchCall,	GetDllOffset("D2Client.dll", 0x81733),   (DWORD)PermShowOrbPatch_ASM, 5},
	{PatchCall,	GetDllOffset("D2Client.dll", 0x8181B),   (DWORD)PermShowOrbPatch2_ASM, 0x0B},
	{PatchCall,	GetDllOffset("D2Client.dll", 0x81826),   (DWORD)PermShowOrbPatch3_ASM, 6},
	{PatchCall, GetDllOffset("D2Client.dll", 0xB9D8E),   (DWORD)MonsterDeathPatch_ASM, 5},

	{PatchCall,	GetDllOffset("D2Client.dll", 0xBB983),	(DWORD)InfravisionPatch_ASM, 0x7}, // 5 BYTES is enough, but 7 for not disturbing orignial instruction interpretation

	{PatchCall, GetDllOffset("D2Client.dll", 0x65111), (DWORD)OnGamePacketReceived_STUB, 5},
	
	{PatchJmp, GetDllOffset("D2Client.dll", 0xD21C), (DWORD)OnGamePacketSent_STUB, 6},

	{PatchCall,   GetDllOffset("D2Client.dll", 0x3FBEB),   (DWORD)DrawPlayerBlobPatch_ASM, 5},
	{PatchCall2,	GetDllOffset("D2Client.dll", 0x3E948),   (DWORD)DrawPlayerBlobPatch2_ASM, 0x3B},
	{PatchCall,		GetDllOffset("D2Client.dll", 0x3FA73),   (DWORD)DrawObjectBlobPatch_ASM, 5},
	{PatchCall,		GetDllOffset("D2Client.dll", 0x3FA89),   (DWORD)DrawMonsterBlobPatch_ASM, 5},
	{PatchJmp,		GetDllOffset("D2Client.dll", 0x3F5C8),   (DWORD)MonsterBlobColPatch_ASM, 5},
	{PatchCall,   GetDllOffset("D2Client.dll", 0x6FAEFA04-0x6FAB0000),   (DWORD)DrawItemBlobPatch_ASM, 6},
	{PatchCall,   GetDllOffset("D2Client.dll", 0x3E14A),   (DWORD)DrawAutomapCellPatch, 5},

	{PatchCall,   GetDllOffset("D2Client.dll", 0x5CE85),   (DWORD)OutTownSelectPatch1_ASM, 6},
	{PatchCall,   GetDllOffset("D2Client.dll", 0x20071),   (DWORD)OutTownSelectPatch2_ASM, 6},
	{PatchCall,   GetDllOffset("D2Client.dll", 0x2011E),   (DWORD)OutTownSelectPatch3_ASM, 6},

	{PatchCall,	GetDllOffset("D2Client.dll", 0x86FAC),   (DWORD)InputLinePatch_ASM, 5},
	{PatchCall,	GetDllOffset("D2Client.dll", 0x86DFB),   (DWORD)InputLinePatch2_ASM, 5},
	//{PatchCall,   GetDllOffset("D2Client.dll", 0x71798),   (DWORD)MessageLogPatch1_ASM, 5},
	//{PatchCall,   GetDllOffset("D2Client.dll", 0x7150F),   (DWORD)MessageLogPatch2_ASM, 5},


	//{PatchCall,   GetDllOffset("D2Client.dll", 0x3FAAC),   (DWORD)MonsterBlobNamePatch_ASM, 5},

	//{PatchCall,   GetDllOffset("D2Win.DLL", 0xF1E0),   (DWORD)MonsterLifebarNamePatch_ASM, 6}

	//{PatchCall,	GetDllOffset("D2Client.dll", 0x327F0),   (DWORD)RButtonUpHandlerPatch_ASM, 5}
};
