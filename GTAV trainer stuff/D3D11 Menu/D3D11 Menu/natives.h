#pragma once

// Generated 30 Jul 2018

#include "types.h"
#include "nativeCaller.h"

namespace PLAYER {
	static Player PLAYER_ID() { return invoke<Player>(0x4F8644AF03D0E0D6); } // 0x4F8644AF03D0E0D6 0x8AEA886C
	static Ped PLAYER_PED_ID() { return invoke<Ped>(0xD80958FC74E988A6); } // 0xD80958FC74E988A6 0xFA92E226

	static int GET_PLAYER_WANTED_LEVEL(Player player) { return invoke<int>(0xE28E54788CE8F12D, player); } // 0xE28E54788CE8F12D 0xBDCDD163
	static void REPORT_CRIME(Player player, int crimeType, int wantedLvlThresh) { invoke<Void>(0xE9B09589827545E7, player, crimeType, wantedLvlThresh); } // 0xE9B09589827545E7 0xD8EB3A44
	static int GET_WANTED_LEVEL_THRESHOLD(int wantedLevel) { return invoke<int>(0xFDD179EAF45B556C, wantedLevel); } // 0xFDD179EAF45B556C 0xD9783F6B
	static void SET_WANTED_LEVEL_DIFFICULTY(Player player, float difficulty) { invoke<Void>(0x9B0BB33B04405E7A, player, difficulty); } // 0x9B0BB33B04405E7A 0xB552626C
	static void SET_PLAYER_WANTED_CENTRE_POSITION(Player player, float x, float y, float z) { invoke<Void>(0x520E541A97A13354, player, x, y, z); } // 0x520E541A97A13354 0xF261633A
	static void SET_DISPATCH_COPS_FOR_PLAYER(Player player, BOOL toggle) { invoke<Void>(0xDB172424876553F4, player, toggle); } // 0xDB172424876553F4 0x48A18913
	static void CLEAR_PLAYER_WANTED_LEVEL(Player player) { invoke<Void>(0xB302540597885499, player); } // 0xB302540597885499 0x54EA5BCC

}

namespace UNK3 {
	static BOOL _NETWORK_SHOP_CHECKOUT_START(Any p0) { return invoke<BOOL>(0x39BE7CEA8D9CC8E6, p0); } // 0x39BE7CEA8D9CC8E6
	static BOOL _NETWORK_SHOP_BEGIN_SERVICE(int* transactionID, Hash p1, Hash transactionHash, int amount, Hash p4, int mode) { return invoke<BOOL>(0x3C5FD37B5499582E, transactionID, p1, transactionHash, amount, p4, mode); } // 0x3C5FD37B5499582E
}

namespace SCRIPT {
	static char* _GET_NAME_OF_THREAD(int threadId) { return invoke<char*>(0x05A42BA9FC8DA96B, threadId); } // 0x05A42BA9FC8DA96B 0xBE7ACD89
	static int GET_ID_OF_THIS_THREAD() { return invoke<int>(0xC30338E8088E2E21); } // 0xC30338E8088E2E21 0xDE524830
}
