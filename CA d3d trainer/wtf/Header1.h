#define ADDR_D3D					0x538E3F
#define ADDR_MTBWCRET				0x373B5549
#define ADDR_SHOWFPS				0x37C1DED0
#define ADDR_LTCLIENTEXE			0x48EAE0
#define ADDR_GAMESTATUS				0x37C534C4
//Endereços CABR
#define ADDR_PLAYERSTATUS 			0x38
#define ADDR_DEVICEGAME				0x7DB480
#define ADDR_WEAPONMGR			    0x37CAD08C
#define ADDR_WEAPONSET				0x37CACA40
#define ADDR_FRunVel				0x37C2384C
#define Ponteiro					0x008EFD14 //
#define Jump						0x37C238B8
#define PickUP						0x37C2B7CC
#define ADDR_PLAYERGRAVITY			0x379C5B78
#define PlayerManager				0x37C7CAB4
#define PlayerByIndex				0x371AAA90
#define ADDR_CLIENTINFOMGR			0x379D9A9C
#define ADDR_LOCALPLAYER			0x371B44E0
#define ADDR_WORLDTOSCREEN			0x49ABC0
#define GCS							0x37C7C9D0
#define ADDR_DRAWPRIMITIVE			0x754E30
#define ADDR_WEAPONINFO				0x37C585F8
#define LTClientDLL					0x37C3C378
#define ADDR_SendToServer			0x47D8E0
#define UnlimitedAmmo				0x374BFE27
#define CursorCenter				0x75B574

//CCommonLT* g_CommonLT;

unsigned int ValidPointer(void* p)
{
	return (p != 0) ? 1 : 0;
}

int cor1;
int AngleCheck;

unsigned long ulThis;

//aimcorrection
bool bSetWepData = 1, bStoreWepData = 0, bAimCorrection = 0;
float OgAwepData[20][2000];

DWORD dwOffSets[20] = {
	0x2BC, 0x2C0, 0x2C4, 0x2C8, 0x2CC, 0x2D0, 0x310, 0x314, 0x31C, 0x320,
	0x328, 0x32C, 0x354, 0x358, 0x364, 0x368, 0x36C, 0x370, 0x3FC, 0x400
};

void vAimCorrection()
{
	DWORD WepMgr = *(DWORD *)ADDR_WEAPONMGR;

	if (MenuItem[3] == 1)
	{
		for (int i = 0; i < *((__int32 *)(WepMgr + 0x15E4)) && WepMgr; i++)
		{
			DWORD Wep = *(DWORD *)(*(DWORD *)(WepMgr + 0x15E0) + 4 * i);
			for (int j = 0; j < (sizeof(dwOffSets) / 4) && Wep; j++)
				*(float *)(Wep + dwOffSets[j]) = 0.0;
		}
		bSetWepData = 0;
	}
	else
	{
		for (int i = 0; i < *((__int32 *)(WepMgr + 0x15E4)) && WepMgr; i++)
		{
			DWORD Wep = *(DWORD *)(*(DWORD *)(WepMgr + 0x15E0) + 4 * i);
			for (int j = 0; j < (sizeof(dwOffSets) / 4) && Wep; j++)
				OgAwepData[j][i] = *(float *)(Wep + dwOffSets[j]);
		}
		bSetWepData = 1;
	}
}

#define PI 3.14159265//Defining what PI is. PI is a Circle 
int CenterX = GetSystemMetrics(0) / 2 - 1;//Gets screen X resolution then cutting it in half to get the center.
int CenterY = GetSystemMetrics(1) / 2 - 1;//Gets screen Y resolution then cutting it in half to get the center.
//LPDIRECT3DDEVICE9 pDevice;
//ID3DXLine *pLine;

D3DXVECTOR3 MyGetObjectMaxPos(int* obj)
{
	return *(D3DXVECTOR3*)(obj + 0x4);
}


int color, OptsCor;

VOID SetDrawColors(LPDIRECT3DDEVICE9 pDevice)
{
	if (OptsCor < 1)
		color = Purple;
	else if (OptsCor > 2)
		color = Pink;
	else if (OptsCor < 3)
		color = Magenta;
	if (OptsCor >= 4)
		OptsCor = 0;
	OptsCor++;
}

void DrawMouse(LPDIRECT3DDEVICE9 pDevice)
{
	POINT myCursor;
	*(INT *)CursorCenter = 0;
	GetCursorPos(&myCursor);
	FillRGB(myCursor.x + 1, myCursor.y + 1, 5, 5, color, pDevice);
}

bool W2S(LPDIRECT3DDEVICE9 pDevice, CONST D3DXVECTOR3 &vWorld, D3DXVECTOR3 *pScreen)
{
	CILTDrawPrim *pDrawPrimitive = *(CILTDrawPrim **)ADDR_DRAWPRIMITIVE;
	D3DVIEWPORT9 D3DViewport = { 0 };
	D3DXMATRIX matrixProjection, matrixView, matrixWorld;
	pDevice->GetTransform(D3DTS_VIEW, &matrixView);
	pDevice->GetTransform(D3DTS_PROJECTION, &matrixProjection);
	pDevice->GetTransform(D3DTS_WORLD, &matrixWorld);
	pDevice->GetViewport(&D3DViewport);
	D3DXVec3Project(pScreen, &vWorld, &D3DViewport, &pDrawPrimitive->Projection, &pDrawPrimitive->View, &pDrawPrimitive->World);

	return(pScreen->z < 1.0f);
}

void WeaponOPK()
{
	cGameClientShell *pGameClientShell = *(cGameClientShell **)GCS;
	cSFXMgr* SFXMgr = pGameClientShell->GetSFXMgr();

	DWORD posptr, PositionY, dwBack;

	posptr = (DWORD)GetModuleHandle("ClientFX.fxd");
	posptr += 0x6CF34;

	VirtualProtect(&PositionY, 4, PAGE_EXECUTE_READWRITE, &dwBack);
	memcpy(&PositionY, (VOID *)(posptr), 4);
	VirtualProtect(&PositionY, 4, dwBack, &dwBack);

	if (SFXMgr)
	{
		for (int i = 0; i < SFXMgr->SFXList[0x17].Num; i++)
		{
			cBaseFX* Pickup = (cBaseFX*)SFXMgr->SFXList[0x17].List[i];
			if ((Pickup) && (Pickup->Object))
			{
				if (MenuItem[6])
				{
					if (*(long*)ADDR_PLAYERSTATUS == 1)
						*(long*)ADDR_PLAYERSTATUS = -5;
					else if
						(*(long*)ADDR_PLAYERSTATUS == -5)
						*(long*)ADDR_PLAYERSTATUS = 1;

					*(FLOAT *)(PositionY + 0xC8) = Pickup->Pos.x + 25.0f;
					*(FLOAT *)(PositionY + 0xCC) = Pickup->Pos.y + 25.0f;
					*(FLOAT *)(PositionY + 0xD0) = Pickup->Pos.z;
				}
			}
		}
	}
}


void TeleKillFull()
{
	DWORD posptr, PositionY;
	GetPlayerByIndex = (lpGetPlayerByIndex)PlayerByIndex;
	unsigned long ulThis = *(unsigned long *)ADDR_CLIENTINFOMGR;
	GetLocalPlayer = (lpGetLocalPlayer)ADDR_LOCALPLAYER;
	posptr = (DWORD)GetModuleHandle("ClientFX.fxd");
	posptr += 0x6CF34;
	memcpy(&PositionY, (VOID *)(posptr), 4);
	for (int i = 0; i < 16; i++)
	{
		pPlayerInfo *pPlayer = GetPlayerByIndex(ulThis, i, 0);
		pPlayerInfo *pLocal = GetLocalPlayer(ulThis);
		if (pPlayer != 0 && pPlayer->Object != 0 && pPlayer->IsDead == 0)
		{
			if (MenuItem[22])
			{
				if (pPlayer->Team != pLocal->Team) {
					Sleep(1);
					*(FLOAT *)(PositionY + 0xC8) = (pPlayer->Object->Pos.x + 25.0f);
					*(FLOAT *)(PositionY + 0xCC) = (pPlayer->Object->yBound2);
					*(FLOAT *)(PositionY + 0xD0) = (pPlayer->Object->Pos.z);
				}
			}
		}
	}
}

void funcaoGM(CONST WCHAR GM[20])
{
	for (int x = 0; (x < 20) && (*(DWORD *)(ADDR_WEAPONSET + 0xC4) != NULL); x++)
		*(WCHAR *)(*(DWORD *)(ADDR_WEAPONSET + 0xC4) + x * 2) = GM[x];
}


void Crosshair(LPDIRECT3DDEVICE9 pDevice)
{

	//D3DCOLOR Color;
	D3DVIEWPORT9 Viewport;
	pDevice->GetViewport(&Viewport);
	DWORD CenterX = Viewport.Width / 2;
	DWORD CenterY = Viewport.Height / 2;
	//Ponto
	FillRGB(CenterX - 1.5, CenterY - 1.5, 5, 5, bBlue, pDevice);
}

void DrawPoint(int x, int y, int w, int h, DWORD color)
{
	FillRGB((int)x, (int)y, (int)w, (int)h, color, pDevice);
}


//Funções de save, load e diretório
char dllpath[255];

char* GetFile(char *file)
{
	static char path[320];
	for (int i = 0; i<strlen(path); i++)
		path[i] = 0;
	strcpy(path, dllpath);
	strcat(path, file);
	return path;
}

void Save(char* szSection, char* szKey, int iValue, LPCSTR file)
{
	char szValue[1524];
	sprintf(szValue, "%d", iValue);
	WritePrivateProfileStringA(szSection, szKey, szValue, file);
}

int Load(char* szSection, char* szKey, int iDefaultValue, LPCSTR file)
{
	int iResult = GetPrivateProfileIntA(szSection, szKey, iDefaultValue, file);
	return iResult;
}

wchar_t* PTSpammer(const wchar_t *PTBR, int len)
{
	int size = wcslen(PTBR);
	wchar_t* txtbr = new wchar_t[size + 1];
	for (int i = 0; i < size; i++)
		txtbr[i] = PTBR[i] * len;
	txtbr[size] = 0;
	return txtbr;
}

#define M_PI				3.14159265358979323846f
#define DegToRad(degree)	((degree) * (M_PI / 180.0f))
#define PITCH				0
#define YAW					1
#define ROLL				2

#define SubtractVector(v1, v2, v3) ((v3[0] = v1[0] - v2[0]), (v3[1] = v1[1] - v2[1]), (v3[2] = v1[2] - v2[2]))

FLOAT GetDistance(D3DXVECTOR3 Local, D3DXVECTOR3 Target)
{
	FLOAT fResult[3];
	SubtractVector(Target, Local, fResult);
	return (sqrt((fResult[0] * fResult[0]) + (fResult[1] * fResult[1]) + (fResult[2] * fResult[2])) / 100);
}

VOID VectorAngles(CONST FLOAT *fForward, FLOAT *fAngles)
{
	FLOAT fTmp, fYaw, fPitch;

	if (fForward[2] == 0 && fForward[0] == 0)
	{
		fYaw = 0;

		if (fForward[2] > 0)
			fPitch = 90;
		else
			fPitch = 270;
	}
	else {
		fYaw = (atan2(fForward[2], -fForward[0]) * 180.0f / M_PI) - 90;

		if (fYaw < 0)
			fYaw += 360.0f;

		fTmp = sqrt(fForward[0] * fForward[0] + fForward[2] * fForward[2]);
		fPitch = (atan2(fForward[1], fTmp) * 180.0f / M_PI);

		if (fPitch < 0)
			fPitch += 360.0f;
	}

	fAngles[PITCH] = -fPitch;
	fAngles[YAW] = fYaw;
	fAngles[ROLL] = 0;
}

VOID GetAngleToTarget(D3DXVECTOR3 vTargetPos, D3DXVECTOR3 vCameraPos, D3DXVECTOR3 &vFinalVector)
{
	D3DXVECTOR3 vMidVector(vTargetPos.x - vCameraPos.x, vTargetPos.y - vCameraPos.y, vTargetPos.z - vCameraPos.z);

	VectorAngles((FLOAT *)&vMidVector, (FLOAT *)&vFinalVector);

	if (vFinalVector.x > 180.0f)
		vFinalVector.x -= 360.0f;
	else if (vFinalVector.x < -180.0f)
		vFinalVector.x += 360.0f;

	if (vFinalVector.y > 180.0f)
		vFinalVector.y -= 360.0f;
	else if (vFinalVector.y < -180.0f)
		vFinalVector.y += 360.0f;
}


INT iGetBestPlayer()
{
	FLOAT fNearest = (FLOAT)INT_MAX;
	INT iAimAt = -1;
	GetPlayerByIndex = (lpGetPlayerByIndex)PlayerByIndex;
	unsigned long ulThis = *(unsigned long *)ADDR_CLIENTINFOMGR;
	GetLocalPlayer = (lpGetLocalPlayer)ADDR_LOCALPLAYER;

	for (INT i = 0; i < 16; i++)
	{
		D3DXVECTOR3 localPos, targetPos;
		pPlayerInfo *pLocal = GetLocalPlayer(ulThis);
		pPlayerInfo *pPlayer = GetPlayerByIndex(ulThis, i, 0);

		if (pLocal != 0 && pPlayer != 0 && pLocal->Object != 0 && pPlayer->Object != 0 && pPlayer->IsDead == 0 && pPlayer->index != pLocal->index)
		{
			if (pPlayer->Team != pLocal->Team)
			{
				localPos = pLocal->Object->Pos;
				targetPos = pPlayer->Object->Pos;
				if ((GetDistance(localPos, targetPos) < fNearest))
				{
					iAimAt = i;
					fNearest = (GetDistance(localPos, targetPos));
				}
			}
		}
	}
	return iAimAt;
}


VOID DoAimbot(INT &var)
{
	if ((*(BYTE *)ADDR_GAMESTATUS == 1) && var && GetAsyncKeyState(VK_RBUTTON) < 0)
	{
		GetPlayerByIndex = (lpGetPlayerByIndex)PlayerByIndex;
		unsigned long ulThis = *(unsigned long *)ADDR_CLIENTINFOMGR;
		GetLocalPlayer = (lpGetLocalPlayer)ADDR_LOCALPLAYER;

		cPlayerMgr *pPlayerManager = *(cPlayerMgr **)PlayerManager;
		INT i = iGetBestPlayer();

		if (i != -1)
		{
			pPlayerInfo *pLocal = GetLocalPlayer(ulThis);
			pPlayerInfo *pPlayer = GetPlayerByIndex(ulThis, i, 0);

			D3DXVECTOR3 enemyPos = pPlayer->Object->Pos, localPos = pLocal->Object->Pos, AimAngle;

			GetAngleToTarget(enemyPos, localPos, AimAngle);
			if (pLocal->Team != pPlayer->Team)
			{
				pPlayerManager->Yaw = DegToRad(AimAngle[YAW]);
				pPlayerManager->Pitch = DegToRad(AimAngle[PITCH] + 2.5f);
			}
		}
	}
}