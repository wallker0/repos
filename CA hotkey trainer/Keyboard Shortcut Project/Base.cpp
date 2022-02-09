#include <windows.h>
#include <d3d9.h>
#include "Header.h"


//Address Combat Arms Brazil
#define ADDR_D3D					0x95E8D0
#define ADDR_MTBWCRET				0x3737FDE9
#define ADDR_SHOWFPS				0x379B6E30
//Endereços CABR
#define ADDR_GAMESTATUS				0x379ECCD0
#define ADDR_LTCLIENTEXE 			0x491E20
#define ADDR_PLAYERSTATUS 			0x379F1D34
#define ADDR_DEVICEGAME				0x95E8D0
#define ADDR_WEAPONMGR			    0x37A3BAD4
#define ADDR_WEAPONSET				0x37A41C78
#define ADDR_FRunVel				0x379BBCBC
#define Ponteiro					0x008EFD14
#define Addr_Consoles				0x379B6E28
#define ArmaInformacao				0x379F1D14


//Variaveis
INT ModoFantasma, WeaponSet, iSuperVelocidade, nxchams, rapidfire, actdist, WeaponSetCabin, FPS, Fly, SemNeblina;

//Metodo ativar/desativar
VOID CheckKey(INT &variavel, INT teclax)
{
	if (GetAsyncKeyState(teclax) & 1)
		variavel = !variavel;
}

//Metodo de Console
VOID PushToConsole(int variavel, const char *ativado, const char *desativado, bool &zsFlag)
{
	typedef void(__cdecl*RunConsoleCommandFn)(const char*);
	RunConsoleCommandFn PtcStatus = (RunConsoleCommandFn)ADDR_LTCLIENTEXE;

	if (variavel == 1 && zsFlag == false)
	{
		PtcStatus(ativado);
		zsFlag = true;
	}

	if (variavel == 0 && zsFlag == true)
	{
		PtcStatus(desativado);
		zsFlag = false;
	}
}


//aimcorrection
bool bSetWepData = 1, bStoreWepData = 0, bAimCorrection = 0;
float OgAwepData[20][2000];

DWORD dwOffSets[20] = {
	0x2BC, 0x2C0, 0x2C4, 0x2C8, 0x2CC, 0x2D0, 0x310, 0x314, 0x31C, 0x320,
	0x328, 0x32C, 0x354, 0x358, 0x364, 0x368, 0x36C, 0x370, 0x3FC, 0x400
};

void vAimCorrection(int Correct)
{
	DWORD WepMgr = *(DWORD *)ADDR_WEAPONMGR;

	if (!bStoreWepData)
	{
		for (int i = 0; i < *((__int32 *)(WepMgr + 0x15E4)) && WepMgr; i++)
		{
			DWORD Wep = *(DWORD *)(*(DWORD *)(WepMgr + 0x15E0) + 4 * i);
			for (int j = 0; j < (sizeof(dwOffSets) / 4) && Wep; j++)
				OgAwepData[j][i] = *(float *)(Wep + dwOffSets[j]);
		}
		bStoreWepData = 1;
	}

	if (Correct && bSetWepData)
	{
		for (int i = 0; i < *((__int32 *)(WepMgr + 0x15E4)) && WepMgr; i++)
		{
			DWORD Wep = *(DWORD *)(*(DWORD *)(WepMgr + 0x15E0) + 4 * i);
			for (int j = 0; j < (sizeof(dwOffSets) / 4) && Wep; j++)
				*(float *)(Wep + dwOffSets[j]) = 0.0;
		}
		bSetWepData = 0;
	}
	else if (!Correct && !bSetWepData)
	{
		for (int i = 0; i < *((__int32 *)(WepMgr + 0x15E4)) && WepMgr; i++)
		{
			DWORD Wep = *(DWORD *)(*(DWORD *)(WepMgr + 0x15E0) + 4 * i);
			for (int j = 0; j < (sizeof(dwOffSets) / 4) && Wep; j++)
				*(float *)(Wep + dwOffSets[j]) = OgAwepData[j][i];
		}
		bSetWepData = 1;
	}
}

void RenderBackend(void)
{
	static LPDIRECT3DDEVICE9 pDevice;

	if (!pDevice)
		pDevice = **(LPDIRECT3DDEVICE9 **)ADDR_D3D;
	else
	{
		CheckKey(ModoFantasma, VK_NUMPAD8);
		CheckKey(WeaponSet, VK_INSERT);
		CheckKey(WeaponSetCabin, VK_DELETE);
		CheckKey(SemNeblina, VK_END);
		CheckKey(iSuperVelocidade, VK_NUMPAD9);
		CheckKey(nxchams, VK_HOME);
		

		//Weapon Set
		if (WeaponSet)
		{
			DWORD dwWeaponSet = *(DWORD *)(ADDR_WEAPONSET + 0x1EC);
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x0) + 0x14) = 49; // substitui sua arma primária padrão
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x4) + 0x14) = 224; // substitui sua arma secundária padrão
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x8) + 0x14) = 291; // substitui sua faca padrão
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0xC) + 0x14) = 171; // substitui sua granada padrão
			for (int x = 0; (x < 12) && (*(DWORD *)(ADDR_WEAPONSET + 0xC4) != NULL); x++)
			*(WCHAR *)(*(DWORD *)(ADDR_WEAPONSET + 0xC4) + x * 2) = 56;
		}

		//Weapon Set
		if (WeaponSetCabin)
		{
			DWORD dwWeaponSet = *(DWORD *)(ADDR_WEAPONSET + 0x1EC);
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x0) + 0x14) = 49; // substitui sua arma primária padrão
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x4) + 0x14) = 291; // substitui sua arma secundária padrão
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x8) + 0x14) = 291; // substitui sua faca padrão
			*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0xC) + 0x14) = 191; // substitui sua granada padrão
			for (int x = 0; (x < 12) && (*(DWORD *)(ADDR_WEAPONSET + 0xC4) != NULL); x++)
				*(WCHAR *)(*(DWORD *)(ADDR_WEAPONSET + 0xC4) + x * 2) = 58;
		}


		   //Ghost Mod
			if (ModoFantasma)		
			{
				if (*(long*)ADDR_PLAYERSTATUS == 1)
					*(long*)ADDR_PLAYERSTATUS = -5;
			}
				else
			{
				if (*(long*)ADDR_PLAYERSTATUS == -5)
					*(long*)ADDR_PLAYERSTATUS = 1;
			}


			//aimcorrection
			if (GetAsyncKeyState(VK_NUMPAD0) & 1)
				bAimCorrection = !bAimCorrection;
			if (*(PBYTE)ADDR_GAMESTATUS == 1)
				vAimCorrection(bAimCorrection);


			//SkelModelStencil 
			bool bnxchams;
			PushToConsole(nxchams, " +SkelModelStencil  1 ", " +SkelModelStencil  0 ", bnxchams);

			//no fog
			bool bSemNeblina;
			PushToConsole(SemNeblina, " +FogEnable  0 ", " +FogEnable  1 ", bSemNeblina);

			//SuperSpeed
			if (iSuperVelocidade)
				*(float*)ADDR_FRunVel = 285.0f * 5;
			else
				*(float*)ADDR_FRunVel = 285.0f;

	}
}


static DWORD dwMTBWCRet = NULL;

typedef int(WINAPI* MultiByteToWideChar_t)(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
MultiByteToWideChar_t pMultiByte;

int WINAPI nMultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
	_asm pushad;

	_asm
	{
		MOV EAX, [EBP + 0x4]
			MOV dwMTBWCRet, EAX
	}

	if (dwMTBWCRet == ADDR_MTBWCRET)
	{
		lpMultiByteStr = ""; // null multi byte string, hide fraps actived and show render for menu and hacks

		RenderBackend();
	}

	_asm popad;

	return pMultiByte(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
}

void *DetourCreateE9(BYTE *src, const BYTE *dst, const int len)
{
	DWORD dwBack;
	BYTE *jmp = (BYTE*)malloc(len + 5);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &dwBack);
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwBack, &dwBack);
	FlushInstructionCache(GetCurrentProcess(), src, 0x10);

	return(jmp - len);
}

DWORD WINAPI dwMain(LPVOID lpArg)
{
	while ((GetModuleHandleA("ClientFX.fxd") == NULL))
		Sleep(25);

	*(FLOAT*)(ADDR_SHOWFPS) = 1.f; // Hook using show fraps actived

	return EXIT_SUCCESS;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DWORD MBTWCAddr = (DWORD)GetProcAddress(GetModuleHandleA("Kernel32.dll"), "MultiByteToWideChar");
		pMultiByte = (MultiByteToWideChar_t)DetourCreateE9((PBYTE)MBTWCAddr, (PBYTE)nMultiByteToWideChar, 5);
		CreateThread(NULL, NULL, dwMain, NULL, NULL, NULL);
	}
	return TRUE;
}