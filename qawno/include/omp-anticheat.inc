/*
open.mp anticheat
Version: 2.5-RC3
Very special thanks to Pevenaider for the memory codes that he shared with us.
Contributors: Pevenaider, sicario.dll, devbluen 

(Everyone who contributes this project should sign here with his/her name.)
*/

#if defined _INC_anticheat
	#endinput
#endif
#define _INC_anticheat

#define VERSION (2.5-RC3)

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

#if !defined CHAIN_ORDER
	#define CHAIN_ORDER() 0
#endif

#define CHAIN_HOOK(%0) forward @ACCO_%0();public @ACCO_%0(){return CHAIN_ORDER()+1;}
#define CHAIN_NEXT(%0) @ACCO_%0

#define CHAIN_PUBLIC:%0(%1) %0(%1) <_ALS : _ALS_go>
#define CHAIN_FORWARD:%0_%2(%1)=%3; forward %0_%2(%1); public %0_%2(%1) <_ALS : _ALS_x0, _ALS : _ALS_x1> {return (%3);} public %0_%2(%1) <> {return (%3);}

CHAIN_HOOK(AC)
#undef CHAIN_ORDER
#define CHAIN_ORDER CHAIN_NEXT(AC)

static stock _IncludeStates() <_ALS : _ALS_x0, _ALS : _ALS_x1, _ALS : _ALS_x2, _ALS : _ALS_x3> {}
static stock _IncludeStates() <_ALS : _ALS_go> {}

#define InfoMessage(%0,%1) SendClientMessage(%0, 0xFFFF00AA, "[i] "%1)
#define ErrorMessage(%0,%1) SendClientMessage(%0, 0xFF0000FF, "[!] "%1)

new Float:Sprays[10][3] = {
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

new Float:Garages[3][3] = {
	{611.35, -77.55, 997.99},	// Loco Low Co.
	{612.21, -123.90, 997.99},	// Wheel Arch Angels.
	{621.45, -23.72, 1000.92} 	// TransFender
};

new const Cheats[][] = {
	{"S0beit"},
	{"CLEO"},
	{"Silentpatch"},
	{"SAMPFUNCS"},
	{"VorbisFile.dll"},
	{"UltraWH"},
	{"Airbreak"},
	{"Aimbot"},
	{"AFK-Kill"},
	{"Vehicle repair"},
	{"Teleport"}
};

enum {
	CHEAT_SOBEIT,
	CHEAT_CLEO,
	CHEAT_SILENT,
	CHEAT_SAMPFUNCS,
	CHEAT_ULTRAWH,
	CHEAT_AIRBREAK,
	CHEAT_TELEPORT,
	CHEAT_SPEED,
	CHEAT_WEAPON,
	CHEAT_AMMO,
	CHEAT_AIMBOT,
	CHEAT_JETPACK,
	CHEAT_AFKILL,
	CHEAT_RAKSAMP,
	CHEAT_MINING,
	CHEAT_SLAPPER,
	CHEAT_BADPACK,
	CHEAT_EXPLOIT
};

enum Data {
	type,
	memoryAddress,
	memoryOffset,
	byteCount,
	retndata
};

new Memory[][Data] = {
	{0x45, 0x3A9EB, 0, 0x4, 0},
	{0x45, 0x3AEB9, 0, 0x4, 0},
	{0x45, 0x3AD8D, 0, 0x4, 0},
	{0x45, 0x3A7F2, 0, 0x4, 0},
	{0x47, 0, 0, 0x4, 0},
	{0x48, 0, 0, 0x4, 0},
	{0x5, 0x06865E, 0x0, 0x4, 192},
	{0x5, 0xA88774, 0x0, 0x4, 72},
	{0x5, 0xDB6746, 0x0, 0x4, 192},
	{0x5, 0xFDB957, 0x0, 0x4, 68},
	{0x5, 0x52D558, 0x0, 0x4, 196},
	{0x5, 0xE4FC58, 0x0, 0x4, 64},
	{0x5, 0x1BA246, 0x0, 0x4, 8},
	{0x5, 0xB0C56F, 0x0, 0x4, 200},
	{0x5, 0xF9855E, 0x0, 0x4, 200},
	{0x5, 0xF51D54, 0x0, 0x4, 128},
	{0x5, 0xF4C853, 0x0, 0x4, 132},
	{0x5, 0xB47E74, 0x0, 0x4, 132}
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

enum PlayerData {
	bool:pMobileUser,
	bool:pSuspicious,
	Float:pLastPos,
	pLastUpdate,
	pGarageTick,
	pLastData,
	pCooldown
};

new Player[MAX_PLAYERS][PlayerData];

public OnGameModeInit() {
	state _ALS : _ALS_go;
	ScriptInit();
	return OnGameModeInit();
}

public OnGameModeExit() {
	ScriptExit();
	return OnGameModeExit();
}

public OnFilterScriptInit() {
	state _ALS : _ALS_go;
	ScriptInit();
	return OnFilterScriptInit();
}

public OnFilterScriptExit() {
	ScriptExit();
	return OnFilterScriptExit();
}

static ScriptInit() {
	print("open.mp anticheat");
	printf("Version %s", VERSION);
	print("Script loaded successfully!");
}

static ScriptExit() {
	print("Script unloaded successfully!");
}

public OnPlayerConnect(playerid) {
	CleanPlayerData(playerid);
	for (new i; i < sizeof(Memory); i++) {
		if (Memory[i][type] == 0x5)
			SendClientCheck(playerid, Memory[i][type], Encode(Memory[i][memoryAddress]), Memory[i][memoryOffset], Memory[i][byteCount]);
		}
		else {
			SendClientCheck(playerid, Memory[i][type], Memory[i][memoryAddress], Memory[i][memoryOffset], Memory[i][byteCount]);
		}
	}
	if (!Player[playerid][pMobileUser]) {
		if (!IsPlayerUsingOmp(playerid)) {
			ErrorMessage(playerid, "Computer players must use open.mp launcher to play on this server!");
			return KickEx(playerid);
		}
		new version[24];
		GetPlayerVersion(playerid, version, sizeof(version));
		if (!strcmp(version, "0.3.7", true)) {
			ErrorMessage(playerid, "You should select an higher version than 0.3.7-R1!");
			return KickEx(playerid);
		}
	}
	return OnPlayerConnect(playerid);
}

public OnPlayerDisconnect(playerid, reason) {
	CleanPlayerData(playerid);
	return OnPlayerDisconnect(playerid, reason);
}

public OnPlayerUpdate(playerid) {
	Player[playerid][pLastUpdate] = GetTickCount();
	if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
        if (GetPlayerSpeed(playerid) > 185)
            return DetectCheat(playerid, CHEAT_SLAPPER);

        if (GetPlayerSpeed(playerid) > 10 && (GetPlayerAnimationIndex(playerid) == 1130 || GetPlayerAnimationIndex(playerid) == 1189) && GetPlayerDistanceFromPoint(playerid, Player[playerid][pLastPos][0], Player[playerid][pLastPos][1], Player[playerid][pLastPos][2]) > 30.0)
            return DetectCheat(playerid, CHEAT_AIRBREAK);
    }
    if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
        new vehicleid = GetPlayerVehicleID(playerid);
        if (GetVehicleSpeed(playerid) > 310)
            return DetectCheat(playerid, CHEAT_SLAPPER);

        if (GetVehicleSpeed(vehicleid) > 10 && GetPlayerDistanceFromPoint(playerid, Player[playerid][pLastPos][0], Player[playerid][pLastPos][1], Player[playerid][pLastPos][2]) > 30.0)
            return DetectCheat(playerid, CHEAT_AIRBREAK);
    }
	new Float:depth = 5.0, Float:playerdepth = 5.0;
	if (!CA_IsPlayerInWater(playerid, depth, playerdepth) && (GetPlayerAnimationIndex(playerid) == 1538 || GetPlayerAnimationIndex(playerid) == 1539 || GetPlayerAnimationIndex(playerid) == 1543))
		return DetectCheat(playerid, CHEAT_AIRBREAK);

    if (IsPlayerSpawned(playerid)) {
        if (GetPlayerDistanceFromPoint(playerid, Player[playerid][pLastPos][0], Player[playerid][pLastPos][1], Player[playerid][pLastPos][2]) > 10.0) {
            if (!GetPVarInt(playerid, "Check_Teleport"))
                return DetectCheat(playerid, CHEAT_TELEPORT);

            else DeletePVar(playerid, "Check_Teleport");
        }
        GetPlayerPos(playerid, Player[playerid][pLastPos][0], Player[playerid][pLastPos][1], Player[playerid][pLastPos][2]);
    }
    if (GetPlayerState(playerid) == PLAYER_STATE:PLAYER_STATE_DRIVER) {
    	new vehicleid = GetPlayerVehicleID(playerid), Float:health;
    	GetVehicleHealth(vehicleid, health);
    	if (health > 999.9 && (gettime() - Player[playerid][pGarageTick])) {
    		SetVehicleHealth(vehicleid, 999.9);
    		Player[playerid][pGarageTick] = gettime();
    		if (!IsPlayerInsidePaySpray(playerid) && !IsPlayerInsideModGarage(playerid))
    			return DetectCheat(playerid, CHEAT_REPAIR);
    	}
    }
	return OnPlayerUpdate(playerid);
}

public OnPlayerSpawn(playerid) {
	for (new i; i < sizeof(Memory); i++) if (Memory[i][type] == 0x45)
		SendClientCheck(playerid, Memory[i][type], Memory[i][memoryAddress], Memory[i][memoryOffset], Memory[i][byteCount]);

	Player[playerid][pLastUpdate] = GetTickCount();
	return OnPlayerSpawn(playerid);
}

public OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ) {
	if (hittype != BULLET_HIT_TYPE:BULLET_HIT_TYPE_NONE) {
		if ((fX < -1000.0 || fX > 1000.0) || (fY < -1000.0 || fY > 1000.0) || (fZ < -1000.0 || fZ > 1000.0))
            return DetectCheat(playerid, CHEAT_AIMBOT);
	}
	if (fX > 2140000000 || fY > 2140000000 || fZ > 2140000000)
        return DetectCheat(playerid, CHEAT_AIMBOT);

	return OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ);
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart) {
	if (IsPlayerPaused(playerid))
		return DetectCheat(playerid, CHEAT_AFKILL);

	return OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart);
}

public OnPlayerRequestClass(playerid, classid) {
	SendClientCheck(playerid, 0x45, 0x3A9EB, 0, 0x4);
	return OnPlayerRequestClass(playerid, classid);
}

public OnIncomingRPC(playerid, rpcid, BitStream:bs) {
	if (IsPlayerNPC(playerid))
        return true;

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
	    Player[playerid][pMobileUser] = (checksum == 0xBEEF) ? (true) : (false);
	}
    return OnIncomingRPC(playerid, rpcid, BitStream:bs);
}

public OnIncomingPacket(playerid, packetid, BitStream:bs) {
    if (IsPlayerNPC(playerid))
        return true;

    switch (packetid) {
        case 20: {
            new pkt_id, rpc_id, bits;
            BS_ReadValue(bs, PR_UINT8, pkt_id, PR_UINT8, rpc_id, PR_CUINT32, bits);
            if (pkt_id == 40 || bits >= 0x1FFFFF || bits <= 0x80000000 || bits < 0) {
                DetectCheat(playerid, CHEAT_EXPLOIT);
                return false;
            }
        }
        case PLAYER_SYNC: {
            new Float:qw, Float:qx, Float:qy, Float:qz;
            BS_SetReadOffset(bs, 0x98);
            BS_ReadValue(bs, PR_FLOAT, qw, PR_FLOAT, qx, PR_FLOAT, qy, PR_FLOAT, qz);
            BS_ResetReadPointer(bs);
            new const Float:angle = atan2(2 * ((qy * qz) + (qw * qx)), (qw * qw) - (qx * qx) - (qy * qy) + (qz * qz));
            if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_NONE && (angle > 85.0 || angle < -85.0) && angle == angle) {
                DetectCheat(playerid, CHEAT_AIMBOT);
                return false;
            }
            new onFootData[PR_OnFootSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadOnFootSync(bs, onFootData);
            switch (onFootData[PR_weaponId]) {
                case WEAPON_BOMB: {
                    onFootData[PR_keys] &= ~_:KEY_HANDBRAKE;
                }
                case WEAPON_SPRAYCAN, WEAPON_FIREEXTINGUISHER, WEAPON_FLAMETHROWER: {
                    if (!(1160 <= onFootData[PR_animationId] <= 1167)) {
                        if (onFootData[PR_keys] & _:KEY_HANDBRAKE) {
                            onFootData[PR_keys] &= ~_:KEY_ACTION;
                        }
                        onFootData[PR_keys] &= ~(_:KEY_FIRE | _:KEY_HANDBRAKE);
                    }
                }
                case WEAPON_GRENADE: {
                    if (!(644 <= onFootData[PR_animationId] <= 646)) {
                        onFootData[PR_keys] &= ~_:KEY_ACTION;
                    }
                }
                default: {
                    if (GetWeaponType(WEAPON:onFootData[PR_weaponId]) == WEAPON_TYPE_BULLET) {
                        if (1222 <= onFootData[PR_animationId] <= 1236 ||
                            onFootData[PR_animationId] == 1249 ||
                            1275 <= onFootData[PR_animationId] <= 1287 ||
                            onFootData[PR_animationId] == 459 ||
                            908 <= onFootData[PR_animationId] <= 909 ||
                            onFootData[PR_animationId] == 1274 ||
                            onFootData[PR_animationId] == 1266 ||
                            1241 <= onFootData[PR_animationId] <= 1242 ||
                            17   <= onFootData[PR_animationId] <= 27 ||
                            745  <= onFootData[PR_animationId] <= 760 ||
                            1545 <= onFootData[PR_animationId] <= 1554 ||
                            471  <= onFootData[PR_animationId] <= 507 ||
                            1135 <= onFootData[PR_animationId] <= 1151) {
                            if (onFootData[PR_keys] & _:KEY_HANDBRAKE) {
                                onFootData[PR_keys] &= ~_:KEY_ACTION;
                            }
                            onFootData[PR_keys] &= ~(_:KEY_FIRE | _:KEY_HANDBRAKE);
                        }
                    }
                }
            }
            BS_SetWriteOffset(bs, 8);
            BS_WriteOnFootSync(bs, onFootData);
        }
        case VEHICLE_SYNC: {
            new inCarData[PR_InCarSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadInCarSync(bs, inCarData);
            BS_SetWriteOffset(bs, 8);
            BS_WriteInCarSync(bs, inCarData);
        }
        case PASSENGER_SYNC: {
            new passengerData[PR_PassengerSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadPassengerSync(bs, passengerData);
            BS_SetWriteOffset(bs, 8);
            BS_WritePassengerSync(bs, passengerData);
        }
        case AIM_SYNC: {
            new aimData[PR_AimSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadAimSync(bs, aimData);
            BS_SetWriteOffset(bs, 8);
            BS_WriteAimSync(bs, aimData);
        }
        case UNOCCUPIED_SYNC: {
            new unoccupiedData[PR_UnoccupiedSync];
            BS_IgnoreBits(bs, 8);
            BS_ReadUnoccupiedSync(bs, unoccupiedData);
            if (floatcmp(floatabs(unoccupiedData[PR_roll][0]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_roll][1]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_roll][2]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_direction][0]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_direction][1]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_direction][2]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_position][0]), 20000.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_position][1]), 20000.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_position][2]), 20000.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_angularVelocity][0]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_angularVelocity][1]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_angularVelocity][2]), 1.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_velocity][0]), 100.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_velocity][1]), 100.0) == 1 ||
                floatcmp(floatabs(unoccupiedData[PR_velocity][2]), 100.0) == 1) {
                return false;
            }
        }
    }
    return true;
}

public OnClientCheckResponse(playerid, actionid, memaddr, retndata) {
    if (IsPlayerNPC(playerid))
        return true;

    if (actionid == 0x45) {
        for (new i; i < sizeof(Memory); i++) {
            if (memaddr == Memory[i][memoryAddress]) {
                Player[playerid][pLastData] = retndata;
                if (retndata != Player[playerid][pLastData]) {
                    DetectCheat(playerid, CHEAT_SOBEIT);
                    break;
                }
            }
        }
    }
    else if (actionid == 0x47) {
        if (memaddr == 0xCECECE && retndata == 256) {
            DetectCheat(playerid, CHEAT_BADPACK);
            return false;
        }
    }
    else if (actionid == 0x48) {
        if (memaddr == 0xDEDEDE && retndata == 256) {
            DetectCheat(playerid, CHEAT_BADPACK);
            return false;
        }
    }
    else if (actionid == 0x5) {
        for (new i; i < sizeof(Memory); i++) {
            if (memaddr == EncodeMemory(Memory[i][memoryAddress]) && retndata != Memory[i][retndata]) {
                new cheat;
                switch (i) {
                    case 6, 15, 17: cheat = CHEAT_SOBEIT;
                    case 7..12: cheat = CHEAT_CLEO;
                    case 13: cheat = CHEAT_SILENT;
                    case 14: cheat = CHEAT_SAMPFUNCS;
                    case 16: cheat = CHEAT_ULTRAWH;
                }
                DetectCheat(playerid, cheat);
                break;
            }
        }
    }
    return OnClientCheckResponse(playerid, actionid, memaddr, retndata);
}

stock SetPlayerPos(playerid, Float:x, Float:y, Float:z) {
	SetPVarInt(playerid, "Check_Teleport", 1);
	return SetPlayerPos(playerid, x, y, z);
}

static DetectCheat(playerid, cheat = -1) {
	return CallLocalFunction("OnCheatDetected", "ii", playerid, cheat);
}

forward OnCheatDetected(playerid, cheat);
public OnCheatDetected(playerid, cheat) {
	if (Player[playerid][pCooldown] < gettime()) {
		ErrorMessage(playerid, "System detected that you're probably using %s on this server.", Cheats[cheat]);
		InfoMessage(playerid, "If you're thinking that it's a mistake, just try to contact an administrator.");
		Player[playerid][pCooldown] = gettime() + 100;
	}
	KickEx(playerid);
	return true;
}

static KickEx(playerid) {
	return SetTimerEx("DisconnectPlayer", 500, false, "i", playerid);
}

forward DisconnectPlayer(playerid);
public DisconnectPlayer(playerid) {
	return KickEx(playerid);
}

static IsPlayerPaused(playerid) {
	return (GetTickCount() - Player[playerid][pLastUpdate] > 2000);
}

static CleanPlayerData(playerid) {
	Player[playerid][pMobileUser] = false;
	Player[playerid][pSuspicious] = false;
	Player[playerid][pLastUpdate] = 0;
	Player[playerid][pGarageTick] = 0;
	Player[playerid][pLastData] = 0;
	Player[playerid][pLastData] = 0;
	Player[playerid][pCooldown] += 10;
	for (new i; i < 3; i++) {
		Player[playerid][pLastPos][i] = 0.0;
	}
	return true;
}

static GetPlayerSpeed(playerid) {
    new Float:vel[3], Float:rtn;
    GetPlayerVelocity(playerid, vel[0], vel[1], vel[2]);
    rtn = floatsqroot(floatabs(floatpower(vel[0] + vel[1] + vel[2], 2)));
    return floatround(rtn * 100 * 1.61 * 0.621371);
}

static GetVehicleSpeed(vehicleid) {
	new Float:speed[3];
	GetVehicleVelocity(vehicleid, speed[0], speed[1], speed[2]);
	return floatround(floatsqroot((speed[0] * speed[0]) + (speed[1] * speed[1]) + (speed[2] * speed[2])) * 111.846814);
}

static IsPlayerInsidePaySpray(playerid) {
	for (new i; i < sizeof(Sprays); i++) if (IsPlayerInRangeOfPoint(playerid, 10.0, Sprays[i][0], Sprays[i][1], Sprays[i][2])) {
		return true;
	}
	return false;
}

static IsPlayerInsideModGarage(playerid) {
	for (new i; i < sizeof(Garages); i++) if (IsPlayerInRangeOfPoint(playerid, 10.0, Garages[i][0], Garages[i][1], Garages[i][2])) {
		return true;
	}
	return false;
}

static Encode(input) {
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

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos(%0) CHAIN_PUBLIC:SetPlayerPos(%0)
CHAIN_FORWARD:SetPlayerPos(playerid, Float:x, Float:y, Float:z) = 1;

#if defined _ALS_OnIncomingRPC
	#undef OnIncomingRPC
#else
	#define _ALS_OnIncomingRPC
#endif
#define OnIncomingRPC(%0) CHAIN_PUBLIC:OnIncomingRPC(%0)
CHAIN_FORWARD:OnIncomingRPC(playerid, rpcid, BitStream:bs) = 1;

#if defined _ALS_OnIncomingPacket
	#undef OnIncomingPacket
#else
	#define _ALS_OnIncomingPacket
#endif
#define OnIncomingPacket(%0) CHAIN_PUBLIC:OnIncomingPacket(%0)
CHAIN_FORWARD:OnIncomingPacket(playerid, packetid, BitStream:bs) = 1;

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit(%0) CHAIN_PUBLIC:OnGameModeInit(%0)
CHAIN_FORWARD:OnGameModeInit() = 1;

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit(%0) CHAIN_PUBLIC:OnGameModeExit(%0)
CHAIN_FORWARD:OnGameModeExit() = 1;

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit(%0) CHAIN_PUBLIC:OnFilterScriptInit(%0)
CHAIN_FORWARD:OnFilterScriptInit() = 1;

#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit(%0) CHAIN_PUBLIC:OnFilterScriptExit(%0)
CHAIN_FORWARD:OnFilterScriptExit() = 1;

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect(%0) CHAIN_PUBLIC:OnPlayerConnect(%0)
CHAIN_FORWARD:OnPlayerConnect(playerid) = 1;

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect(%0) CHAIN_PUBLIC:OnPlayerDisconnect(%0)
CHAIN_FORWARD:OnPlayerDisconnect(playerid, reason) = 1;

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate(%0) CHAIN_PUBLIC:OnPlayerUpdate(%0)
CHAIN_FORWARD:OnPlayerUpdate(playerid) = 1;

#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass(%0) CHAIN_PUBLIC:OnPlayerRequestClass(%0)
CHAIN_FORWARD:OnPlayerRequestClass(playerid, classid) = 1;

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn(%0) CHAIN_PUBLIC:OnPlayerSpawn(%0)
CHAIN_FORWARD:OnPlayerSpawn(playerid) = 1;

#if defined _ALS_OnClientCheckResponse
	#undef OnClientCheckResponse
#else
	#define _ALS_OnClientCheckResponse
#endif
#define OnClientCheckResponse(%0) CHAIN_PUBLIC:OnClientCheckResponse(%0)
CHAIN_FORWARD:OnClientCheckResponse(playerid, actionid, memaddr, retndata) = 1;

#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot(%0) CHAIN_PUBLIC:OnPlayerWeaponShot(%0)
CHAIN_FORWARD:OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ) = 1;

#if defined _ALS_OnPlayerGiveDamage
	#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage(%0) CHAIN_PUBLIC:OnPlayerGiveDamage(%0)
CHAIN_FORWARD:OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart) = 1;

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos(%0) CHAIN_PUBLIC:SetPlayerPos(%0)
CHAIN_FORWARD:SetPlayerPos(playerid, Float:x, Float:y, Float:z) = 1;
