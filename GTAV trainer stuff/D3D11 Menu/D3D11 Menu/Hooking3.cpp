//Hooking.cpp
#include "stdafx.h"

using namespace Memory;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;

static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistration**						m_registrationTable;
static std::unordered_map<uint64_t,Hooking::NativeHandler>	m_handlerCache;

/* Start Hooking */

void Hooking::Start(HMODULE hmoduleDLL)
{
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	if (!InitializeHooks()) Cleanup();
}

/* Hooks */

// Initialization
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;


	// init minhook
	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize");
		returnVal = FALSE;
	}

	// init native hook
	if (!HookNatives()) {

		Log::Error("Failed to initialize NativeHooks");
		returnVal = FALSE;
	}

	return returnVal;
}

/* Native Hook Function  */
template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

Hooking::NativeHandler ORIG_GET_FRAME_COUNT = NULL;
void* __cdecl MY_GET_FRAME_COUNT(NativeContext *cxt)
{
	Hooking::onTickInit();
	return cxt;
}

bool Hooking::HookNatives()
{
	return true
	// native hooks	
		&& Native(0xC87A57742F7D3C06, &MY_GET_FRAME_COUNT, &ORIG_GET_FRAME_COUNT)
;
}


void ScriptMain() {
	//srand(GetTickCount());
	//if (GetAsyncKeyState(VK_F9) == 1) {
		//int amount = 750000;
		//Any idk = 1146239992;
		//UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, amount, 1);
		//UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
		Beep(1000, 1);
	//}
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();
	}
	catch (...)
	{
		Log::Fatal("Failed scriptFiber");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

/* Pattern Scanning */

void Hooking::FailPatterns(const char* name, pattern ptn)
{
	Log::Error("finding %s", name);
	Cleanup();
}

void Hooking::FindPatterns()
{
	auto p_fixVector3Result =	pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameState =			pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	auto p_worldPtr =			pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_blipList =			pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_nativeTable =		pattern("76 61 49 8B 7A 40 48 8D 0D");
	auto p_gameLogos =			pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameLegals =			pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_modelCheck =			pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	auto p_modelSpawn =			pattern("48 8B C8 FF 52 30 84 C0 74 05 48");

	char * c_location = nullptr;

	// Executable Base Address
	DEBUGMSG("baseAddr\t\t 0x%p", get_base());

	// Executable End Address
	DEBUGMSG("endAddr\t\t 0x%p", get_base() + get_size());	

	// Get game state
	c_location = p_gameState.count(1).get(0).get<char>(2);
	while (c_location == nullptr) Sleep(60);
	c_location == nullptr ? FailPatterns("gameState", p_gameState) : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	// Skip game logos
	Memory::putVP<uint8_t>(p_gameLogos.count(1).get(0).get<void>(0), 0xC3);

	// Wait for legals
	DWORD ticks = GetTickCount();
	while (*m_gameState != GameStateLicenseShit || GetTickCount() < ticks + 5000) Sleep(50);
	
	// Skip game legals
	Memory::nop(p_gameLegals.count(1).get(0).get<void>(0), 2);

	// Get vector3 result fixer function
	auto void_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (void_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(void_location);

	// Get native registration table
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration Table", p_nativeTable) : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	// Get world pointer
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer", p_worldPtr) : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;
	
	// Get blip list
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List", p_blipList) : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);

	// Bypass online model requests block
	Memory::nop(p_modelCheck.count(1).get(0).get<void>(0), 24);

	// Bypass is player model allowed to spawn checks
	Memory::nop(p_modelSpawn.count(1).get(0).get<void>(8), 2);

	DEBUGMSG("Initializing natives");
	CrossMapping::initNativeMap();

	// Check if game is ready
	Log::Msg("Checking if game is ready...");
	while (!*m_gameState == GameStatePlaying) {
		Sleep(100);
	}
	Log::Msg("Game ready");
}

static Hooking::NativeHandler _Handler(uint64_t origHash) {

	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0) {
		return nullptr;
	}

	Hooking::NativeRegistration * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->nextRegistration)
	{
		for (uint32_t i = 0; i < table->numEntries; i++)
		{
			if (newHash == table->hashes[i])
			{
				return table->handlers[i];
			}

		}
	}

	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

BlipList* Hooking::GetBlipList()
{
	return m_blipList;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}

void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

/* Clean Up */
void Hooking::Cleanup()
{
	Log::Msg("CleanUp: KEK VIP");

	MH_Uninitialize();
	FreeLibraryAndExitThread(_hmoduleDLL, 0);
}