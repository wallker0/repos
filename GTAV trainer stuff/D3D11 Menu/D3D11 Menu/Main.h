#include <Windows.h> 
#include <d3d11.h> 

#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "FW1FontWrapper.lib")
#include "BeaEngine\Include\BeaEngine.h"

//#pragma comment(lib, "BeaEngine64.lib")
#include "fw1\FW1FontWrapper\Source\FW1FontWrapper.h"


ID3D11Device *pDevice;
IFW1Factory *pFW1Factory;
IFW1FontWrapper *pFont;
ID3D11DeviceContext *pContext;


DWORD_PTR* pSwapChainVtable;
DWORD_PTR* pDeviceContextVTable;


void* detourBuffer[3];
struct HookContext
{
	BYTE original_code[64];
	SIZE_T dst_ptr;
	BYTE far_jmp[6];
};

HookContext* presenthook64;

const unsigned int DisasmLengthCheck(const SIZE_T address, const unsigned int jumplength)
{
	DISASM disasm;
	memset(&disasm, 0, sizeof(DISASM));

	disasm.EIP = (UIntPtr)address;
	disasm.Archi = 0x40;

	unsigned int processed = 0;
	while (processed < jumplength)
	{
		const int len = Disasm(&disasm);
		if (len == UNKNOWN_OPCODE)
		{
			++disasm.EIP;
		}
		else
		{
			processed += len;
			disasm.EIP += len;
		}
	}

	return processed;
}

const void* DetourFunc64(BYTE* const src, const BYTE* dest, const unsigned int jumplength)
{
	// Allocate a memory page that is going to contain executable code.
	MEMORY_BASIC_INFORMATION mbi;
	for (SIZE_T addr = (SIZE_T)src; addr > (SIZE_T)src - 0x80000000; addr = (SIZE_T)mbi.BaseAddress - 1)
	{
		if (!VirtualQuery((LPCVOID)addr, &mbi, sizeof(mbi)))
		{
			break;
		}

		if (mbi.State == MEM_FREE)
		{
			if (presenthook64 = (HookContext*)VirtualAlloc(mbi.BaseAddress, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE))
			{
				break;
			}
		}
	}

	// If allocating a memory page failed, the function failed.
	if (!presenthook64)
	{
		return NULL;
	}

	// Select a pointer slot for the memory page to be freed on unload.
	for (int i = 0; i < sizeof(detourBuffer) / sizeof(void*); ++i)
	{
		if (!detourBuffer[i])
		{
			detourBuffer[i] = presenthook64;
			break;
		}
	}

	// Save original code and apply detour. The detour code is:
	// push rax
	// movabs rax, 0xCCCCCCCCCCCCCCCC
	// xchg rax, [rsp]
	// ret
	BYTE detour[] = { 0x50, 0x48, 0xB8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x87, 0x04, 0x24, 0xC3 };
	const unsigned int length = DisasmLengthCheck((SIZE_T)src, jumplength);
	memcpy(presenthook64->original_code, src, length);
	memcpy(&presenthook64->original_code[length], detour, sizeof(detour));
	*(SIZE_T*)&presenthook64->original_code[length + 3] = (SIZE_T)src + length;

	// Build a far jump to the destination function.
	*(WORD*)&presenthook64->far_jmp = 0x25FF;
	*(DWORD*)(presenthook64->far_jmp + 2) = (DWORD)((SIZE_T)presenthook64 - (SIZE_T)src + FIELD_OFFSET(HookContext, dst_ptr) - 6);
	presenthook64->dst_ptr = (SIZE_T)dest;

	// Write the hook to the original function.
	DWORD flOld = 0;
	VirtualProtect(src, 6, PAGE_EXECUTE_READWRITE, &flOld);
	memcpy(src, presenthook64->far_jmp, sizeof(presenthook64->far_jmp));
	VirtualProtect(src, 6, flOld, &flOld);

	// Return a pointer to the original code.
	return presenthook64->original_code;
}



typedef HRESULT (__stdcall *D3D11PresentHook) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags); 
typedef void (__stdcall *D3D11DrawIndexedHook) (ID3D11DeviceContext* pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
typedef void (__stdcall *D3D11ClearRenderTargetViewHook) (ID3D11DeviceContext* pContext, ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4]);



D3D11PresentHook phookD3D11Present = NULL;
D3D11DrawIndexedHook phookD3D11DrawIndexed = NULL;
D3D11ClearRenderTargetViewHook phookD3D11ClearRenderTargetView = NULL;