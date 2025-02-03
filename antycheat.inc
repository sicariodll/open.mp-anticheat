/*
                       __                          __                              __     
                      /  |                        /  |                            /  |    
  ______   _______   _$$ |_    __    __   _______ $$ |____    ______    ______   _$$ |_   
 /      \ /       \ / $$   |  /  |  /  | /       |$$      \  /      \  /      \ / $$   |  
 $$$$$$  |$$$$$$$  |$$$$$$/   $$ |  $$ |/$$$$$$$/ $$$$$$$  |/$$$$$$  | $$$$$$  |$$$$$$/   
 /    $$ |$$ |  $$ |  $$ | __ $$ |  $$ |$$ |      $$ |  $$ |$$    $$ | /    $$ |  $$ | __ 
/$$$$$$$ |$$ |  $$ |  $$ |/  |$$ \__$$ |$$ \_____ $$ |  $$ |$$$$$$$$/ /$$$$$$$ |  $$ |/  |
$$    $$ |$$ |  $$ |  $$  $$/ $$    $$ |$$       |$$ |  $$ |$$       |$$    $$ |  $$  $$/ 
 $$$$$$$/ $$/   $$/    $$$$/   $$$$$$$ | $$$$$$$/ $$/   $$/  $$$$$$$/  $$$$$$$/    $$$$/  
                              /  \__$$ |                                                  
                              $$    $$/                                                   
                               $$$$$$/                                                                            

Version: 2.3
Very special thanks to Pevenaider for the effort that he made for the community.
Contributors: Pevenaider, sicario.dll, devbluen 

(Everyone who contributes this project should sign here with his/her name.)

*/

#if defined _INC_antycheat
	#endinput
#endif
#define _INC_antycheat

#define ANTYCHEAT_VERSION (2.3 R-2)

#tryinclude <open.mp>

#if !defined _INC_open_mp
	#error open.mp.inc is required. (You must include it to use this include as well.)
#endif

#tryinclude <Pawn.RakNet>

#if !defined PAWNRAKNET_INC_
	#error Pawn.RakNet.inc is required. (You must include it to use this include as well.)
#endif

#tryinclude <colandreas>

#if !defined _colandreas_included
	#error colandreas.inc is required. (You must include it to use this include as well.)
#endif

#if !defined AC_CHAIN_ORDER
	#define AC_CHAIN_ORDER() 0
#endif

#define AC_CHAIN_HOOK(%0) forward @ACCO_%0();public @ACCO_%0(){return AC_CHAIN_ORDER()+1;}
#define AC_CHAIN_NEXT(%0) @ACCO_%0

#define AC_CHAIN_PUBLIC:%0(%1) %0(%1) <_ALS : _ALS_go>
#define AC_CHAIN_FORWARD:%0_%2(%1)=%3; forward %0_%2(%1); public %0_%2(%1) <_ALS : _ALS_x0, _ALS : _ALS_x1> return (%3); public %0_%2(%1) <> return (%3);

AC_CHAIN_HOOK(AC)
#undef AC_CHAIN_ORDER
#define AC_CHAIN_ORDER AC_CHAIN_NEXT(AC)

static stock _AC_IncludeStates() <_ALS : _ALS_x0, _ALS : _ALS_x1, _ALS : _ALS_x2, _ALS : _ALS_x3> {}
static stock _AC_IncludeStates() <_ALS : _ALS_go> {}

#define InfoMessage(%0,%1) SendClientMessage(%0, 0xFFFF00AA, "[INFO] "%1)
#define ErrorMessage(%0,%1) SendClientMessage(%0, 0xFF0000FF, "[ERROR] "%1)

new Float:AC_Paynsprays[10][3] = {
	{1025.05, -1024.23, 32.1},	// LS Temple
	{487.68, -1740.87, 11.13},	// LS Santa Maria
	{-1420.73, 2583.37, 55.56},	// El Quebrados
	{-1904.39, 284.97, 40.75},	// Wang Cars
	{-2425.91, 1022.33, 50.10},	// Juniper Hill
	{1975.60, 2162.16, 10.77},	// LV Redsands
	{2065.38, -1831.51, 13.25},	// Idlewood
	{-99.55, 1118.36, 19.44},	// Fort Carson
	{721.07, -455.94, 16.04},	// Dillimore
	{2393.74, 1493.01, 10.52} 	// LV Unused (Pyramid)
};

new Float:AC_Modgarages[3][3] = {
	{611.35, -77.55, 997.99},	// Loco Low Co.
	{612.21, -123.90, 997.99},	// Wheel Arch Angels.
	{621.45, -23.72, 1000.92} 	// TransFender
};

new const AC_Cheats[][] = {
	{"S0beit"},
	{"S0beit"},
	{"S0beit"},
	{"S0beit"},
	{"S0beit"},
	{"CLEO"},
	{"CLEO"},
	{"CLEO"},
	{"CLEO"},
	{"CLEO"},
	{"CLEO5"},
	{"Silentpatch"},
	{"SAMPFUNCS"},
	{"SobFox"},
	{"Airbreak"},
	{"Aimbot"},
	{"AFK-Kill"},
	{"Vehicle repair"},
	{"Teleport"}
};

enum AC_Data {
	AC_type,
	AC_memoryAddress,
	AC_memoryOffset,
	AC_byteCount,
	AC_retndata
};

new Memory[][AC_Data] = {
	{0x47, 0x0, 0, 0x4, 0},
	{0x48, 0, 0, 0x4, 0},
	{0x5, 0x06865E, 0x0, 0x4, 192},
	{0x5, 0x5242CD, 0x0, 0x4, 204},
	{0x5, 0x6EFBC7, 0x0, 0x4, 196},
	{0x5, 0xA88774, 0x0, 0x4, 72},
	{0x5, 0xDB6746, 0x0, 0x4, 192},
	{0x5, 0xFDB957, 0x0, 0x4, 68},
	{0x5, 0x52D558, 0x0, 0x4, 196},
	{0x5, 0xE4FC58, 0x0, 0x4, 64},
	{0x5, 0x1BA246, 0x0, 0x4, 8},
	{0x5, 0xB0C56F, 0x0, 0x4, 200},
	{0x5, 0xF9855E, 0x0, 0x4, 200},
	{0x5, 0xF51D54, 0x0, 0x4, 128}
};

enum PR_Connection {
    PR_pVersion,
    PR_pByteMod,
    PR_pByteNicknameLen,
    PR_pNickName[24],
    PR_pClientChallengeResponse,
    PR_pByteAuthKeyLen,
    PR_pAuthKey[50],
    PR_pClientVerLen,
    PR_pClientVersion[30]
};

enum AC_PlayerData {
	bool:pMobileUser,
	bool:pSuspicious,
	pLastUpdate,
	pCheckStep,
	pGarageTick
};

new AC_Player[MAX_PLAYERS][AC_PlayerData];

public OnGameModeInit() {
	state _ALS : _ALS_go;
	ScriptInit();
	return AC_OnGameModeInit();
}

public OnGameModeExit() {
	ScriptExit();
	return AC_OnGameModeExit();
}

public OnFilterScriptInit() {
	state _ALS : _ALS_go;
	ScriptInit();
	return AC_OnFilterScriptInit();
}

public OnFilterScriptExit() {
	ScriptExit();
	return AC_OnFilterScriptExit();
}

static ScriptInit() {
	print("                       __                          __                              __     	");
	print("                      /  |                        /  |                            /  |    	");
	print("  ______   _______   _$$ |_    __    __   _______ $$ |____    ______    ______   _$$ |_   	");
	print(" /      \\ /       \\ / $$   |  /  |  /  | /       |$$      \\  /      \\  /      \\ / $$   |");
	print(" $$$$$$  |$$$$$$$  |$$$$$$/   $$ |  $$ |/$$$$$$$/ $$$$$$$  |/$$$$$$  | $$$$$$  |$$$$$$/   	");
	print(" /    $$ |$$ |  $$ |  $$ | __ $$ |  $$ |$$ |      $$ |  $$ |$$    $$ | /    $$ |  $$ | __ 	");
	print("/$$$$$$$ |$$ |  $$ |  $$ |/  |$$ \\__$$ |$$ \\_____ $$ |  $$ |$$$$$$$$/ /$$$$$$$ |  $$ |/  |	");
	print("$$    $$ |$$ |  $$ |  $$  $$/ $$    $$ |$$       |$$ |  $$ |$$       |$$    $$ |  $$  $$/ 	");
	print(" $$$$$$$/ $$/   $$/    $$$$/   $$$$$$$ | $$$$$$$/ $$/   $$/  $$$$$$$/  $$$$$$$/    $$$$/  	");
	print("                              /  \\__$$ |                                                  	");
	print("                              $$    $$/                                                   	");
	print("                               $$$$$$/                                                    	");
	print("	             	   																			");
}

static ScriptExit() {
	print("Script unloaded successfully!");
}

public OnPlayerConnect(playerid) {
	AC_CleanPlayerData(playerid);
	for (new i; i < sizeof(Memory); i++) {
		SendClientCheck(playerid, Memory[i][AC_type], AC_AnotherForm(Memory[i][AC_memoryAddress]), Memory[i][AC_memoryOffset], Memory[i][AC_byteCount]);
	}
	if (!AC_Player[playerid][pMobileUser]) {
		if (!IsPlayerUsingOmp(playerid)) {
			ErrorMessage(playerid, "Computer players must use open.mp launcher to play on this server!");
			return AC_Kick(playerid);
		}
		new version[24];
		GetPlayerVersion(playerid, version, sizeof(version));
		if (!strcmp(version, "0.3.7", true)) {
			ErrorMessage(playerid, "You should select an higher version than 0.3.7-R1!");
			return AC_Kick(playerid);
		}
	}
	return AC_OnPlayerConnect(playerid);
}

public OnPlayerDisconnect(playerid, reason) {
	AC_CleanPlayerData(playerid);
	return AC_OnPlayerDisconnect(playerid, reason);
}

public OnPlayerUpdate(playerid) {
	AC_Player[playerid][pLastUpdate] = GetTickCount();
	new Float:depth = 5.0, Float:playerdepth = 5.0;
	if (!CA_IsPlayerInWater(playerid, depth, playerdepth) && (GetPlayerAnimationIndex(playerid) == 1538 || GetPlayerAnimationIndex(playerid) == 1539 || GetPlayerAnimationIndex(playerid) == 1543)) {
		return AC_DetectCheat(playerid, 14);
    }
    if (IsPlayerSpawned(playerid)) {
        new Float:AC_Pos[3];
        GetPlayerPos(playerid, AC_Pos[0], AC_Pos[1], AC_Pos[2]);
        if (!IsPlayerInRangeOfPoint(playerid, 50.0, AC_Pos[0], AC_Pos[1], AC_Pos[2])) {
            if (!GetPVarInt(playerid, "Check_Teleport")) {
                return AC_DetectCheat(playerid, 18);
            }
            else DeletePVar(playerid, "Check_Teleport");
        }
    }
    if (GetPlayerState(playerid) == PLAYER_STATE:PLAYER_STATE_DRIVER) {
    	new vehicleid = GetPlayerVehicleID(playerid), Float:health;
    	GetVehicleHealth(vehicleid, health);
    	if (health > 999.9 && (gettime() - AC_Player[playerid][pGarageTick])) {
    		SetVehicleHealth(vehicleid, 999.9);
    		AC_Player[playerid][pGarageTick] = gettime();
    		if (!IsPlayerInsidePaySpray(playerid) && !IsPlayerInsideModGarage(playerid)) {
    			return AC_DetectCheat(playerid, 17);
    		}
    	}
    }
	return AC_OnPlayerUpdate(playerid);
}

public OnPlayerSpawn(playerid) {
	AC_Player[playerid][pLastUpdate] = GetTickCount();
	return AC_OnPlayerSpawn(playerid);
}

public OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ) {
	if (hittype != BULLET_HIT_TYPE:BULLET_HIT_TYPE_NONE) {
		if (!(-1000.0 <= fX <= 1000.0) || !(-1000.0 <= fY <= 1000.0) || !(-1000.0 <= fZ <= 1000.0)) {
            return AC_DetectCheat(playerid, 15);
        }
	}
	if (fX > 2140000000 || fY > 2140000000 || fZ > 2140000000) {
        return AC_DetectCheat(playerid, 15);
    }
	return AC_OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ);
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart) {
	if (AC_IsPlayerPaused(playerid)) {
		return AC_DetectCheat(playerid, 16);
	}
	return AC_OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart);
}

public OnIncomingRPC(playerid, rpcid, BitStream:bs) {
	if (rpcid == 25) {
		new data[PR_Connection];
		BS_ReadValue(bs, 
	    	PR_INT32, data[PR_pVersion], 
	    	PR_UINT8, data[PR_pByteMod], 
	    	PR_UINT8, data[PR_pByteNicknameLen], 
	    	PR_STRING, data[PR_pNickName], data[PR_pByteNicknameLen],
	        PR_UINT32, data[PR_pClientChallengeResponse],
	        PR_UINT8, data[PR_pByteAuthKeyLen],
	        PR_STRING, data[PR_pAuthKey], data[PR_pByteAuthKeyLen],
	        PR_UINT8, data[PR_pClientVerLen]
	    );
	    BS_ReadValue(bs, PR_STRING, data[PR_pClientVersion], (data[PR_pClientVerLen] >= 30 ? 30:data[PR_pClientVerLen]));
	    new checksum;
	    BS_ReadUint16(bs, checksum);
	    AC_Player[playerid][pMobileUser] = (checksum == 0xBEEF) ? (true) : (false);
	}
    return AC_OnIncomingRPC(playerid, rpcid, BitStream:bs);
}

public OnIncomingPacket(playerid, packetid, BitStream:bs) {
    switch (packetid) {
        case 207: {
            new Float:OPTUD_w, Float:OPTUD_x, Float:OPTUD_y, Float:OPTUD_z;
            BS_SetReadOffset(bs, 0x98);
            BS_ReadValue(bs, PR_FLOAT, OPTUD_w, PR_FLOAT, OPTUD_x, PR_FLOAT, OPTUD_y, PR_FLOAT, OPTUD_z);
            BS_ResetReadPointer(bs);
            new const Float:OPTUD_angle = atan2(2 * ((OPTUD_y * OPTUD_z) + (OPTUD_w * OPTUD_x)), (OPTUD_w * OPTUD_w) - (OPTUD_x * OPTUD_x) - (OPTUD_y * OPTUD_y) + (OPTUD_z * OPTUD_z));
            if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION:SPECIAL_ACTION_NONE) {
                if ((OPTUD_angle > 85.0 || OPTUD_angle < -85.0) && OPTUD_angle == OPTUD_angle) {
                    return AC_DetectCheat(playerid, 0);
                }
            }
            new BWH_OnFootData[PR_OnFootSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadOnFootSync(bs, BWH_OnFootData);
            BS_ResetReadPointer(bs);
            if(BWH_OnFootData[PR_weaponId] == 4) {
                BWH_OnFootData[PR_weaponId] = 0;
                BS_SetWriteOffset(bs, 8);
                BS_WriteOnFootSync(bs, BWH_OnFootData);
            }
            if(BWH_OnFootData[PR_weaponId] == 40) {
                return AC_DetectCheat(playerid, 0);
            }
        }
        case 209: {
            new unoccupiedData[PR_UnoccupiedSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadUnoccupiedSync(bs, unoccupiedData);
            if (floatcmp(floatabs(unoccupiedData[PR_roll][0]), 1.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_roll][1]), 1.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_roll][2]), 1.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_direction][0]), 1.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_direction][1]), 1.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_direction][2]), 1.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_position][0]), 20000.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_position][1]), 20000.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_position][2]), 20000.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_angularVelocity][0]), 1.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_angularVelocity][1]), 1.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_angularVelocity][2]), 1.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_velocity][0]), 100.00000) == 1 || floatcmp(floatabs(unoccupiedData[PR_velocity][1]), 100.00000) == 1 || 
                floatcmp(floatabs(unoccupiedData[PR_velocity][2]), 100.00000) == 1) {
                return false;
            }
        }
        case 203: {
            new aimData[PR_AimSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadAimSync(bs, aimData);
            if (aimData[PR_camMode] == 45 || aimData[PR_camMode] == 49) {
                return AC_DetectCheat(playerid, 0);
            }
        }
    }
    return AC_OnIncomingPacket(playerid, packetid, BitStream:bs);
}

public OnClientCheckResponse(playerid, actionid, memaddr, retndata) {
	if (actionid == 0x47) {
		if (!AC_Player[playerid][pMobileUser]) {
			if (memaddr == 0x0 && retndata != 256) AC_Player[playerid][pSuspicious] = false;
			else if (memaddr == 0xCECECE && retndata == 256) {
				AC_Player[playerid][pSuspicious] = true;
				SendClientCheck(playerid, 0x47, 0x0, 0, 0x4);
			}
		}
	}
	else if (actionid == 0x48) {
		if (!AC_Player[playerid][pMobileUser]) {
			if (memaddr == 0xDEDEDE) {
				if (retndata == 256) {
					AC_Player[playerid][pSuspicious] = true;
					SendClientCheck(playerid, 0x48, 0, 0, 0x4);
				}
			}
			else {
				if (retndata == 0) AC_Player[playerid][pSuspicious] = false;
			}
		}
	}
	else if (actionid == 0x5) {
    for (new i = AC_Player[playerid][pCheckStep]; i < sizeof(Memory); i++) {
			AC_Player[playerid][pCheckStep]++;
			if (memaddr == AC_AnotherForm(Memory[i][AC_memoryAddress]) && retndata != Memory[i][AC_retndata]) {
				AC_DetectCheat(playerid, i);
				break;
			}
    	}
	}
	return AC_OnClientCheckResponse(playerid, actionid, memaddr, retndata);
}

stock AC_SetPlayerPos(playerid, Float:x, Float:y, Float:z) {
	SetPVarInt(playerid, "Check_Teleport", 1);
	return SetPlayerPos(playerid, x, y, z);
}

static AC_DetectCheat(playerid, cheat = -1) {
	return CallLocalFunction("AC_OnCheatDetected", "ii", playerid, cheat);
}

forward AC_OnCheatDetected(playerid, cheat);
public AC_OnCheatDetected(playerid, cheat) {
	ErrorMessage(playerid, "System detected that you're probably using %s on this server.", AC_Cheats[cheat]);
	InfoMessage(playerid, "If you're thinking that it's wrong, just try to contact an administrator.");
	AC_Kick(playerid);
	return true;
}

static AC_Kick(playerid) {
	return SetTimerEx("AC_DisconnectPlayer", 1000, false, "i", playerid);
}

forward AC_DisconnectPlayer(playerid);
public AC_DisconnectPlayer(playerid) {
	return Kick(playerid);
}

static AC_IsPlayerPaused(playerid) {
	return (GetTickCount() - AC_Player[playerid][pLastUpdate] > 2000);
}

static AC_CleanPlayerData(playerid) {
	AC_Player[playerid][pMobileUser] = false;
	AC_Player[playerid][pSuspicious] = false;
	AC_Player[playerid][pLastUpdate] = 0;
	AC_Player[playerid][pCheckStep] = 0;
	AC_Player[playerid][pGarageTick] = 0;
	return true;
}

static IsPlayerInsidePaySpray(playerid) {
	for (new i; i < sizeof(AC_Paynsprays); i++) if (IsPlayerInRangeOfPoint(playerid, 10.0, AC_Paynsprays[i][0], AC_Paynsprays[i][1], AC_Paynsprays[i][2])) {
		return true;
	}
	return false;
}

static IsPlayerInsideModGarage(playerid) {
	for (new i; i < sizeof(AC_Modgarages); i++) if (IsPlayerInRangeOfPoint(playerid, 10.0, AC_Modgarages[i][0], AC_Modgarages[i][1], AC_Modgarages[i][2])) {
		return true;
	}
	return false;
}

static AC_AnotherForm(input) {
    new result;
 
    #emit LOAD.S.pri input
    #emit CONST.alt 0xFF
    #emit AND
    #emit CONST.alt 16
    #emit SHL
    #emit STOR.S.pri result
 
    #emit LOAD.S.pri input
    #emit CONST.alt 0xFF00
    #emit AND
    #emit LOAD.S.alt result
    #emit ADD
    #emit STOR.S.pri result
 
    #emit LOAD.S.pri input
    #emit CONST.alt 0xFF0000
    #emit AND
    #emit CONST.alt 16
    #emit SHR
    #emit LOAD.S.alt result
    #emit ADD
    #emit STOR.S.pri result

    return result;
}

#if defined _ALS_OnIncomingRPC
	#undef OnIncomingRPC
#else
	#define _ALS_OnIncomingRPC
#endif
#define OnIncomingRPC(%0) AC_CHAIN_PUBLIC:AC_OnIncomingRPC(%0)
AC_CHAIN_FORWARD:AC_OnIncomingRPC(playerid, rpcid, BitStream:bs) = 1;

#if defined _ALS_OnIncomingPacket
	#undef OnIncomingPacket
#else
	#define _ALS_OnIncomingPacket
#endif
#define OnIncomingPacket(%0) AC_CHAIN_PUBLIC:AC_OnIncomingPacket(%0)
AC_CHAIN_FORWARD:AC_OnIncomingPacket(playerid, packetid, BitStream:bs) = 1;

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit(%0) AC_CHAIN_PUBLIC:AC_OnGameModeInit(%0)
AC_CHAIN_FORWARD:AC_OnGameModeInit() = 1;

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit(%0) AC_CHAIN_PUBLIC:AC_OnGameModeExit(%0)
AC_CHAIN_FORWARD:AC_OnGameModeExit() = 1;

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit(%0) AC_CHAIN_PUBLIC:AC_OnFilterScriptInit(%0)
AC_CHAIN_FORWARD:AC_OnFilterScriptInit() = 1;

#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit(%0) AC_CHAIN_PUBLIC:AC_OnFilterScriptExit(%0)
AC_CHAIN_FORWARD:AC_OnFilterScriptExit() = 1;

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect(%0) AC_CHAIN_PUBLIC:AC_OnPlayerConnect(%0)
AC_CHAIN_FORWARD:AC_OnPlayerConnect(playerid) = 1;

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect(%0) AC_CHAIN_PUBLIC:AC_OnPlayerDisconnect(%0)
AC_CHAIN_FORWARD:AC_OnPlayerDisconnect(playerid, reason) = 1;

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate(%0) AC_CHAIN_PUBLIC:AC_OnPlayerUpdate(%0)
AC_CHAIN_FORWARD:AC_OnPlayerUpdate(playerid) = 1;

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn(%0) AC_CHAIN_PUBLIC:AC_OnPlayerSpawn(%0)
AC_CHAIN_FORWARD:AC_OnPlayerSpawn(playerid) = 1;

#if defined _ALS_OnClientCheckResponse
	#undef OnClientCheckResponse
#else
	#define _ALS_OnClientCheckResponse
#endif
#define OnClientCheckResponse(%0) AC_CHAIN_PUBLIC:AC_OnClientCheckResponse(%0)
AC_CHAIN_FORWARD:AC_OnClientCheckResponse(playerid, actionid, memaddr, retndata) = 1;

#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot(%0) AC_CHAIN_PUBLIC:AC_OnPlayerWeaponShot(%0)
AC_CHAIN_FORWARD:AC_OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ) = 1;

#if defined _ALS_OnPlayerGiveDamage
	#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage(%0) AC_CHAIN_PUBLIC:AC_OnPlayerGiveDamage(%0)
AC_CHAIN_FORWARD:AC_OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart) = 1;
