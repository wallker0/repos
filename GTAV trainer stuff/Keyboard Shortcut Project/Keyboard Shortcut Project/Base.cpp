// Authored by Tristan aka HylianTimelord
// Posted for my dudes @ unknowncheats.me
// Creds to IAmDaz for suggesting memcpy & void*

#pragma once

#include <Windows.h>
#include <map>

using namespace std;



class VMTHook
{
public:

	void** vmt = nullptr; // Pointer to the VMT, we're using it more as an array of void*

	VMTHook(void* vmt); // Hook original VMT by it's address
	VMTHook(DWORD64* vmt_ptr); // Create Shadow VMT from VMT pointer ( Not implemented here )
	~VMTHook(); // Destructor, removes all hooks

	void* Hook(int index, void* hk);
	void ClearHooks();
private:
	map<int, void*>::iterator func_iterator; // Iterator so we can iterate the map below
	map<int, void*> hooked_funcs; // std::map which holds the index hooked and the original function's address
};

VMTHook::VMTHook(void* vmt_addy)
{
	vmt = (void**)vmt_addy;
}

void* VMTHook::Hook(int index, void* hk)
{
	// Store the index and original function address
	hooked_funcs.insert(make_pair(index, vmt[index]));

	// Change the memory's access rights, patch the address to our hook, restore original rights
	DWORD old;
	VirtualProtect(&vmt[index], sizeof(void*), PAGE_EXECUTE_READWRITE, &old);
	vmt[index] = hk;
	VirtualProtect(&vmt[index], sizeof(void*), old, NULL);

	return hooked_funcs[index];
}

void VMTHook::ClearHooks()
{
	for (func_iterator = hooked_funcs.begin(); func_iterator != hooked_funcs.end(); func_iterator++)
	{
		DWORD old;
		VirtualProtect(&vmt[func_iterator->first], sizeof(void*), PAGE_EXECUTE_READWRITE, &old);
		vmt[func_iterator->first] = func_iterator->second;
		VirtualProtect(&vmt[func_iterator->first], sizeof(void*), old, NULL);
	}
	hooked_funcs.clear();
	vmt = nullptr;
}

VMTHook dx_hook((void*)Renderer->GetVMTAddy());
oPresent = (D3D11PresentHook)dx_hook.Hook(8, hk_Present);

for (;; ) { /* Do thread stuff */ }

dx_hook.ClearHooks();

return EXIT_SUCCESS;

VMTHook::~VMTHook() {}