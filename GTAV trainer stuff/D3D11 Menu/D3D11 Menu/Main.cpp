
#include "Main.h"
#include "JBMenu.h"
#include "stdafx.h"


JBMenu Menu;



#define ORANGE 0xFF00BFFF
#define BLACK 0xFF000000
#define WHITE 0xFFFFFFFF
#define GREEN 0xFF00FF00 
#define RED  0x22FF3030
#define GRAY 0xFF383838

int Folder1 = 0;
int Item[100];

void Do_Menu(){
	Menu.AddFolder(L"CHEETOS",&Folder1);
	Menu.AddSet(L"$$$",&Item[1],&Folder1);
	Menu.AddOption(L"LEIA",&Item[2],&Folder1);	
}



HRESULT __stdcall hookD3D11Present(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags){

    if (!pFW1Factory){
        pSwapChain->GetDevice(__uuidof(pDevice), (void**)&pDevice);
        pDevice->GetImmediateContext(&pContext);
        FW1CreateFactory(FW1_VERSION, &pFW1Factory);
        pFW1Factory->CreateFontWrapper(pDevice, L"Arial", &pFont);
        pFW1Factory->Release();	
    }

	if(Menu.IsReady() == false){
		Menu.Init_Menu(pFont,pContext,L"KEK VIP",25,100);
		Do_Menu();
		Menu.Color_Font = WHITE;
		Menu.Color_Off = RED;
		Menu.Color_On = RED;
		Menu.Color_Folder = GRAY;
		Menu.Color_Current = RED;
	}

	Menu.Draw_Menu();
	Menu.Navigation();

	if (Item[1]) {
		//int amount = 1500000;
		//Any idk = 1146239992;
		//UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, amount, 1);
		//UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
		Item[1] = 0;
		//Beep(1000, 1);
	}

	if(Item[2])
		Menu.DrawTextW(L"aproveitem, keks [1B MAX]- wallker",17,30,200,GREEN);


    return phookD3D11Present(pSwapChain, SyncInterval, Flags);
}

void __stdcall hookD3D11DrawIndexed(ID3D11DeviceContext* pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation)
{
    return phookD3D11DrawIndexed(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
}

void __stdcall hookD3D11ClearRenderTargetView(ID3D11DeviceContext* pContext, ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4])
{
    return phookD3D11ClearRenderTargetView(pContext, pRenderTargetView, ColorRGBA);
}

const void* DetourFuncVTable(SIZE_T* src, const BYTE* dest, const DWORD index)
{
	DWORD dwVirtualProtectBackup;
	SIZE_T* const indexPtr = &src[index];
	const void* origFunc = (void*)*indexPtr;
	VirtualProtect(indexPtr, sizeof(SIZE_T), PAGE_EXECUTE_READWRITE, &dwVirtualProtectBackup);
	*indexPtr = (SIZE_T)dest;
	VirtualProtect(indexPtr, sizeof(SIZE_T), dwVirtualProtectBackup, &dwVirtualProtectBackup);
	return origFunc;
}

DWORD __stdcall InitializeHook(LPVOID)
{

    HWND hWnd = GetForegroundWindow();
    IDXGISwapChain* pSwapChain;

    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
    swapChainDesc.BufferCount = 1;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.OutputWindow = hWnd;
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.Windowed = (GetWindowLong(hWnd, GWL_STYLE) & (WS_POPUP != 0)) ? false : true;
    swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, &featureLevel, 1
        , D3D11_SDK_VERSION, &swapChainDesc, &pSwapChain, &pDevice, NULL, &pContext)))
    {
        MessageBoxA(hWnd, "Failed to create directX device and swapchain!", "uBoos?", MB_ICONERROR);
        return NULL;
    }

    pSwapChainVtable = (DWORD_PTR*)pSwapChain;
    pSwapChainVtable = (DWORD_PTR*)pSwapChainVtable[0];

    pDeviceContextVTable = (DWORD_PTR*)pContext;
    pDeviceContextVTable = (DWORD_PTR*)pDeviceContextVTable[0];

    phookD3D11Present = (D3D11PresentHook)DetourFunc64((BYTE*)pSwapChainVtable[8], (BYTE*)hookD3D11Present, 16);
    phookD3D11DrawIndexed = (D3D11DrawIndexedHook)DetourFunc64((BYTE*)pDeviceContextVTable[12], (BYTE*)hookD3D11DrawIndexed, 16);
    phookD3D11ClearRenderTargetView = (D3D11ClearRenderTargetViewHook)DetourFunc64((BYTE*)pDeviceContextVTable[50], (BYTE*)hookD3D11ClearRenderTargetView, 16);

	DWORD dwOld;
    VirtualProtect(phookD3D11Present, 2, PAGE_EXECUTE_READWRITE, &dwOld);

    pDevice->Release();
    pContext->Release();
    pSwapChain->Release();

    return NULL;
}

DWORD WINAPI ControlThread(LPVOID lpParam)
{
	Hooking::Start((HMODULE)lpParam);
	return 0;
}

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved){
	if (dwReason == DLL_PROCESS_ATTACH){
		memset(detourBuffer, 0, sizeof(detourBuffer) * sizeof(void*));
		//CreateThread(NULL, 0, InitializeHook, NULL, 0, NULL);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
	}
	else if (dwReason == DLL_PROCESS_DETACH){
		if (pFW1Factory){
			pFW1Factory->Release();
		}

		for (int i = 0; i < sizeof(detourBuffer) / sizeof(void*); ++i){
			if (detourBuffer[i]){
				VirtualFree(detourBuffer[i], 0, MEM_RELEASE);

			}
		}
		Hooking::Cleanup();
	}

	return TRUE;
}