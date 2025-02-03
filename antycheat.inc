/*
             _              _                _   
            | |            | |              | |  
  __ _ _ __ | |_ _   _  ___| |__   ___  __ _| |_ 
 / _` | '_ \| __| | | |/ __| '_ \ / _ \/ _` | __|
| (_| | | | | |_| |_| | (__| | | |  __/ (_| | |_ 
 \__,_|_| |_|\__|\__, |\___|_| |_|\___|\__,_|\__|
                  __/ |                          
                 |___/                          

Version: 2.3
Very special thanks to Pevenaider for the effort that he made for the community.
Contribuitors: sicario.dll (Everyone that contribuited this project should sign here with his/her name.)

*/

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

#define CHAIN_PUBLIC:%0(%1) %0(%1) <_ALS : _ALS_go>
#define CHAIN_FORWARD:%0_%2(%1)=%3; forward %0_%2(%1); public %0_%2(%1) <_ALS : _ALS_x0, _ALS : _ALS_x1> return (%3); public %0_%2(%1) <> return (%3);

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit(%0) CHAIN_PUBLIC:AC_OnGameModeInit(%0)
CHAIN_FORWARD:AC_OnGameModeInit() = 1;

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit(%0) CHAIN_PUBLIC:AC_OnGameModeExit(%0)
CHAIN_FORWARD:AC_OnGameModeExit() = 1;

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit(%0) CHAIN_PUBLIC:AC_OnFilterScriptInit(%0)
CHAIN_FORWARD:AC_OnFilterScriptInit() = 1;


#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit(%0) CHAIN_PUBLIC:AC_OnFilterScriptExit(%0)
CHAIN_FORWARD:AC_OnFilterScriptExit() = 1;

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect(%0) CHAIN_PUBLIC:AC_OnPlayerConnect(%0)
CHAIN_FORWARD:AC_OnPlayerConnect(playerid) = 1;

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect(%0) CHAIN_PUBLIC:AC_OnPlayerDisconnect(%0)
CHAIN_FORWARD:AC_OnPlayerDisconnect(playerid, reason) = 1;

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate(%0) CHAIN_PUBLIC:AC_OnPlayerUpdate(%0)
CHAIN_FORWARD:AC_OnPlayerUpdate(playerid) = 1;

#if defined _ALS_OnClientCheckResponse
	#undef OnClientCheckResponse
#else
	#define _ALS_OnClientCheckResponse
#endif
#define OnClientCheckResponse(%0) CHAIN_PUBLIC:AC_OnClientCheckResponse(%0)
CHAIN_FORWARD:AC_OnClientCheckResponse(playerid, actionid, memaddr, retndata) = 1;

#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot(%0) CHAIN_PUBLIC:AC_OnPlayerWeaponShot(%0)
CHAIN_FORWARD:AC_OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ) = 1;

#if defined _ALS_OnPlayerGiveDamage
	#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage(%0) CHAIN_PUBLIC:AC_OnPlayerGiveDamage(%0)
CHAIN_FORWARD:AC_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) = 1;

#define Info(%0,%1) SendClientMessage(%0, 0xFFFF00AA, "[INFO] "%1)
#define Error(%0,%1) SendClientMessage(%0, 0xFF0000FF, "[ERROR] "%1)

#define MOBILE_CLIENT "ED40ED0E8089CC44C08EE9580F4C8C44EE8EE990"

new const AC_Cheats[][] = {
	{"S0beit"},
	{"CLEO"},
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
	{"AFK-Kill"}
};

enum AC_Data = {
	AC_type,
	AC_memoryAddress,
	AC_memoryOffset,
	AC_byteCount
};

new Memory[][AC_Data] = {
	{0x47, 0, 0, 0x4},
	{0x48, 0, 0, 0x4},
	{0x5, 0x06865E, 0x0, 0x4},
	{0x5, 0xA88774, 0x0, 0x4},
	{0x5, 0xDB6746, 0x0, 0x4},
	{0x5, 0xFDB957, 0x0, 0x4},
	{0x5, 0x52D558, 0x0, 0x4},
	{0x5, 0xE4FC58, 0x0, 0x4},
	{0x5, 0x1BA246, 0x0, 0x4},
	{0x5, 0xB0C56F, 0x0, 0x4},
	{0x5, 0xF9855E, 0x0, 0x4},
	{0x5, 0xF51D54, 0x0, 0x4}
};

enum PR_Connection {
    PR_pVersion,
    PR_pByteMod,
    PR_pByteNicknameLen,
    PR_pNickName[24],
    PR_pClientChallengeResponse,
    PR_pByteAuthLen,
    PR_pAuthKey[50],
    PR_pClientVerLen,
    PR_pClientVersion[30]
};

enum AC_PlayerData {
	bool:pMobileUser,
	bool:pSuspicious,
	pLastUpdate = 0
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

public OnPlayerConnect(playerid) {
	AC_CleanPlayerData(playerid);
	for (new i; i < sizeof(Memory); i++) {
		SendClientCheck(playerid, Memory[i][AC_type], Memory[i][AC_memoryAddress], Memory[i][AC_memoryOffset], Memory[i][AC_byteCount]);
	}
	CallLocalFunction("OnClientCheckResponse", "iiii", playerid, 0x47, 0xCECECE, 256);
    CallLocalFunction("OnClientCheckResponse", "iiii", playerid, 0x48, 0xDEDEDE, 256);
	if (!Player[playerid][pMobileUser]) {
		if (!IsPlayerUsingOmp(playerid)) {
			Error(playerid, "Computer players must use open.mp launcher to play on this server.");
			return AC_Kick(playerid);
		}
		new version[24];
		GetPlayerVersion(playerid, version, sizeof(version));
		if (strcmp(version, "0.3.7") == 0) {
			Error(playerid, "You should select an higher version that 0.3.7-R1!");
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
	Player[playerid][pLastUpdate] = GetTickCount();
	if (!CA_IsPlayerInWater(playerid, 5.0, 5.0) && GetPlayerAnimationIndex(playerid) == (1538 || 1539 || 1543)) {
		return AC_DetectCheat(playerid, 10);
    }
	return AC_OnPlayerUpdate(playerid);
}

public OnPlayerSpawn(playerid) {
	Player[playerid][pLastUpdate] = GetTickCount();
	return AC_OnPlayerSpawn(playerid);
}

public OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ) {
	if (BULLET_HIT_TYPE != BULLET_HIT_TYPE:BULLET_HIT_TYPE_NONE) {
		if (!(-1000.0 <= fX <= 1000.0) || !(-1000.0 <= fY <= 1000.0) || !(-1000.0 <= fZ <= 1000.0)) {
            return AC_DetectCheat(playerid, 11);
        }
	}
	if (fX > 2140000000 || fY > 2140000000 || fZ > 2140000000) {
        return AC_DetectCheat(playerid, 11);
    }
	return AC_OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ);
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) {
	if (AC_IsPlayerPaused(playerid)) {
		return AC_DetectCheat(playerid, 12);
	}
	return AC_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);
}

static ScriptInit() {
	print("	             _              _                _   ");
	print("             | |            | |              | |  ");
	print("   __ _ _ __ | |_ _   _  ___| |__   ___  __ _| |_ ");
	print("  / _` | '_ \| __| | | |/ __| '_ \ / _ \/ _` | __|");
	print(" | (_| | | | | |_| |_| | (__| | | |  __/ (_| | |_ ");
	print("  \__,_|_| |_|\__|\__, |\___|_| |_|\___|\__,_|\__|");
	print("                   __/ |                          ");
	print("                  |___/                           ");
	print("--------------------------------------------------");
	print("------------------ Version: 2.3 ------------------");
	print("--------- Special thanks to: Pevenaider ----------");
	print("--------- Succesfully loaded the script! ---------");
}

static ScriptExit() {
	print("	             _              _                _   ");
	print("             | |            | |              | |  ");
	print("   __ _ _ __ | |_ _   _  ___| |__   ___  __ _| |_ ");
	print("  / _` | '_ \| __| | | |/ __| '_ \ / _ \/ _` | __|");
	print(" | (_| | | | | |_| |_| | (__| | | |  __/ (_| | |_ ");
	print("  \__,_|_| |_|\__|\__, |\___|_| |_|\___|\__,_|\__|");
	print("                   __/ |                          ");
	print("                  |___/                           ");
	print("--------------------------------------------------");
	print("------------------ Version: 2.3 ------------------");
	print("--------- Special thanks to: Pevenaider ----------");
	print("-------- Succesfully unloaded the script! --------");
}

public OnIncomingRPC(playerid, rpcid, BitStream:bs) {
	if (rpcid == 25) {
		BS_ReadValue(bs, 
	    	PR_INT32, data[PR_pVersion], 
	    	PR_UINT8, data[PR_pByteMod], 
	    	PR_UINT8, data[PR_pByteNicknameLen], 
	    	PR_STRING, data[PR_pNickName], data[PR_pByteNicknameLen],
	        PR_UINT32, data[PR_pClientChallengeResponse],
	        PR_UINT8, data[PR_pByteAuthLen],
	        PR_STRING, data[PR_pAuthKey], data[PR_pByteAuthKeyLen],
	        PR_UINT8, data[PR_pClientVerLen]
	    );
	    BS_ReadValue(bs, PR_STRING, data[PR_ClientVersion], (data[PR_pClientVerLen] >= 30 ? 30:data[PR_pClientVerLen]));
	    new checksum;
	    BS_ReadUint16(bs, checksum);
	    Player[playerid][pMobileUser] = (checksum == 0xBEEF) ? (true) : (false);
	}
    return true;
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
    return true;
}

public OnClientCheckResponse(playerid, actionid, memaddr, retndata) {
	switch (actionid) {
		case 0x47: {
			switch (memaddr) {
				case 0x0: if (!Player[playerid][pMobileUser] && retndata != 256) Player[playerid][pSuspicious] = false;
				case 0xCECECE: if (!Player[playerid][pMobileUser] && retndata == 256) {
					Player[playerid][pSuspicious] = true;
					SendClientCheck(playerid, 0x47, 0, 0, 0x4);
				}
			}
		}
		case 0x48: {
			if (!Player[playerid][pMobileUser]) {
				if (memaddr == 0xDEDEDE) {
					if (retndata == 256) {
						Player[playerid][pSuspicious] = true;
						SendClientCheck(playerid, 0x48, 0, 0, 0x4);
					}
				}
				else {
					if (retndata == 0) Player[playerid][pSuspicious] = false;
				}
			}
		}
		case 0x5: {
			if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 192) AC_DetectCheat(playerid, 0); // Sobeit
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 72) AC_DetectCheat(playerid, 1); // CLEO mods.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 192) AC_DetectCheat(playerid, 2); // CLEO mods.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 68) AC_DetectCheat(playerid, 3); // CLEO mods.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 196) AC_DetectCheat(playerid, 4); // CLEO mods.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 64) AC_DetectCheat(playerid, 5); // CLEO mods.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 8) AC_DetectCheat(playerid, 6); // CLEO5.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 200) AC_DetectCheat(playerid, 7); // Silentpatch.
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 200) AC_DetectCheat(playerid, 8); // Sampfuncs.asi
			else if (memaddr == Memory[0][AC_memoryAddress]) if (retndata != 129) AC_DetectCheat(playerid, 9); // SobFox.asi
		}
	}
	return AC_OnClientCheckResponse(playerid, actionid, memaddr, retndata);
}

static AC_DetectCheat(playerid, cheat = -1) {
	return CallLocalFunction("OnCheatDetected", "ii", playerid, cheat);
}

forward AC_OnCheatDetected(playerid, cheat);
forward AC_OnCheatDetected(playerid, cheat) {
	Error(playerid, "System detected that you're probably using %s on this server.", AC_Cheats[cheat]);
	Info(playerid, "If you're thinking that it's wrong, just try to contact an administrator.");
	AC_Kick(playerid);
	return true;
}

static AC_Kick(playerid) {
	return SetTimerEx("DisconnectPlayer", 500, false, "i", playerid);
}

forward DisconnectPlayer(playerid);
public DisconnectPlayer(playerid) {
	return Kick(playerid);
}

static AC_IsPlayerPaused(playerid) {
	return (GetTickCount() - Player[playerid][pLastUpdate] > 2000);
}

static AC_CleanPlayerData(playerid) {
	Player[playerid][pMobileUser] = false;
	Player[playerid][pSuspicious] = false;
	Player[playerid][pLastUpdate] = 0;
	return true;
}