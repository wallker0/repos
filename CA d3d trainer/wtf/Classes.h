// VER_BR_1410.04


class cLTCientShellBase;
class cLTDrawPrim;
struct Transform;


class cSFXList
{
public:
	DWORD unknown1;
	DWORD* List; //0x0004
	DWORD unknown2;
	__int32 Num; //0x000C
};//Size=0x0010

class cSFXMgr
{
public:
	cSFXList SFXList[0x3D]; //0x0000
};//Size=0x00F4

class cGameClientShell
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual void Function41();
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
	virtual void Function52();
	virtual void Function53();
	virtual void Function54();
	virtual void Function55();
	virtual void Function56();
	virtual DWORD GetClientInfoMgr(); //0x00E4
	virtual DWORD GetInterfaceManager(); //0x00E8
	virtual DWORD GetPlayerManager(); //0x00EC
	virtual void Function60();
	virtual void Function61();
	virtual void Function62();
	virtual void Function63();
	virtual void Function64();
	virtual void Function65();
	virtual cSFXMgr* GetSFXMgr(); //0x0108
	virtual void Function67();
	virtual void Function68();
	virtual void Function69();
};


struct Transform
{
public:
	D3DXVECTOR3 Pos;
	unsigned char Space[0x100];
};

Transform Transformado;
Transform NodeFX;

class cLTModel
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual unsigned int GetBoneNode(int* Obj, char* nodeName, unsigned int &Node); //0x0038
	virtual unsigned int GetNodeName(int* Obj, unsigned int Node, char* name, int maxlen); //0x003C
	virtual unsigned int GetNodeTransform(int* Obj, unsigned int hNode, Transform* trans, char bWorldSpace);
	virtual unsigned int GetModelNextNode(int* Obj, unsigned int Node, unsigned int &Next); //0x0044
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual unsigned int GetNumNodes(int* Obj, unsigned int &num); //0x0058
};

//cLTBase* ILTBase; //0x0000

class cLTClientShellBase
{
public:
	char unknown1[16];
	__int32 ILTDrawPrim; //0x0014
	char unknown2[12];
	cLTModel** ILTModel; //0x0024
	char unknown3[144];
	cGameClientShell* ILTGameClientShell; //0x00B8
};//Size=0x00BC

class IntersectQueryCA
{
public:
	D3DXVECTOR3 Start; //0x0000
	D3DXVECTOR3 End; //0x000C
	char unknown1[12];
	unsigned int Flags; //0x0024
	//ObjectFilterFn FilterFn; //0x0028
	void* FilterIntersectParam; //0x002C
	//ObjectFilterFn FilterIntersectFn; //0x0030
	void* FilterParam; //0x0034
	void* PolyFilterParam; //0x0038
};//Size=0x003C

class IntersectInfoCA
{
public:
	D3DXVECTOR3 vImpactPos; //0x0000
	char unknown1[16];
	int* hObjImpact; //0x001C
	DWORD nSomething1; //0x0020
	DWORD nSomething2; //0x0024
	DWORD nSomething3; //0x0028
};//Size=0x002C

class cLTBase
{
public:
	__int32 ILTClient; //0x0000
	char unknown1[96];
	bool(WINAPIV* IntersectSegment)(IntersectQueryCA& Query, IntersectInfoCA* pInfo); //0x0064
	char unknown2[28];
	unsigned int (WINAPIV* GetLocalClientID)(unsigned int* pIDOut); //0x0084
	char unknown3[412];
	unsigned int(WINAPIV* RunConsoleCommand)(const char* szCommand); //0x0224
	int*(WINAPIV* GetClientObject)(); //0x0228
	char unknown4[16];
	unsigned int(WINAPIV* GetObjectScale)(int* pObject, float* scale); //0x023C
	unsigned int(WINAPIV* SetObjectScale)(int* pObject, float scale); //0x0240
	char unknown5[4];
	unsigned int(WINAPIV* GetObjectColor)(int* pObject, float* r, float* g, float* b, float* a); //0x0248
	unsigned int(WINAPIV* SetObjectColor)(int* pObject, float r, float g, float b, float a); //0x024C
};
class cClientWeapon
{
public:
	char unknown1[0xE0];
	__int32 fireWeapon; //0x00E0

};//Size=0x00E4

cClientWeapon* pClientWeapon;


class cClientWeaponMgr
{
public:
	cClientWeapon** WeaponList; //0x0000
	__int32 MaxWeapons; //0x0004
	__int32 WeapIndex; //0x0008
	cClientWeapon* CurrentWeapon; //0x000C
	BYTE WeaponsEnabled; //0x0010
	BYTE WeaponsVisible; //0x0011
	char unknown1[16];
	__int32 nCurrentWeaponID; //0x0020
};//Size=0x0024

class cPlayerMgr
{
public:
	char unknown1[24];
	cClientWeaponMgr* WeaponMgr; //0x0018
	char unknown2[56];
	float Pitch; //0x0054
	float Yaw; //0x0058
	float Roll; //0x005C
	char unknown3[220];
	__int32* CameraObject; //0x013C

	__inline cClientWeapon* GetCurrentWeapon()
	{
		if (WeaponMgr && WeaponMgr->CurrentWeapon)
			return WeaponMgr->CurrentWeapon;

		return NULL;
	}
};//Size=0x0138

cPlayerMgr * pPlayerManager;

class PlayerInfo
{
public:
	__int32 pPing; //0x0000
	__int32 index; //0x0004
	__int32 ID; //0x0008
	char unknown1[8];
	char pName[20]; //0x0014
	char unknown2[4];
	__int32* Object; //0x002C
	__int32 Kills; //0x0030
	__int32 Deaths; //0x0034
	char unknown3[44];
	__int32 HeadShots; //0x0064
	char unknown4[12];
	__int32 pTeam; //0x0074
	char unknown5[4];
	bool pIsDead; //0x007C
	char unknown6[655];
	PlayerInfo* PlayerPrev; //0x030C
	PlayerInfo* PlayerNext; //0x0310
};//Size=0x0314

class ClienteInfo
{
public:
	DWORD unknown1;
	PlayerInfo* Primeiro; //0x0004 
	unsigned int LocalIndex; //0x0008 

	inline PlayerInfo* JogadorIndex(int id)
	{
		PlayerInfo* ptr = Primeiro;

		while (ptr)
		{
			if (ptr->index == id)
				return ptr;

			ptr = ptr->PlayerNext;
		}
		return NULL;
	}
};//Size=0x000C

class Info
{
public:
	char unknown1[12];
	__int32 iHP; //0x000C
	__int32 iAP; //0x0010
	__int32 iMaxHP; //0x0014
	__int32 iMaxAP; //0x0018
	__int32 gotoWepInfo; //0x001C
	__int32 goToSomething; //0x0020
	char unknown2[388];
	float fStamina; //0x01A8
	__int32 iIsRunning; //0x01AC
	__int32 iIsJumping; //0x01B0
	__int32 iWeaponSlotInUse; //0x01B4
	char unknown3[44];
	PlayerInfo* goToPlayers; //0x01E4
};//Size=0x01E8

class LocalInfo
{
public:
	Info* goToInfoClass; //0x0000 
};//Size=0x0004

class cCharacterFX
{
public:
	char unknown1[16];
	__int32* Object; //0x0010
	char unknown2[44];
	__int32 IsPlayer; //0x0040
	char unknown3[52];
	BYTE index; //0x0078
	char unknown4[1240];
	BYTE IsDead; //0x0551
	bool bVisPlayer; //0x0552
	char unknown5[9];
	__int32* hHitbox; //0x055C
	char unknown6[92];
	WORD wHealth; //0x05BC
	WORD wArmor; //0x05BE
	char unknown7[4];
	__int32 Index2; //0x05C4
};//Size=0x05C8

class cWeaponInfo
{
public:
	char unknown1[12];
	DWORD dwClientWeaponType; //0x000C
	char unknown2[16];
	DWORD dwAlt_InstDamage; //0x0020
	DWORD dwInstDamage; //0x0024
	char unknown3[108];
	DWORD dwFireSnd; //0x0094
	char unknown4[108];
	float fFireDelay1; //0x0104
	float ffiredelay1; //0x0108
	DWORD dwMaxAmmo3; //0x010C
	DWORD dwMaxAmmo2; //0x0110
	char unknown5[316];
	BYTE TripleShotMode; //0x0250
	char unknown6[3];
	DWORD dwTripleShotRoundNum; //0x0254
	float fDamageRFacter; //0x0258
	char unknown7[20];
	DWORD dwInfiAmmo2; //0x0270
	DWORD dwInfiniteAmmo; //0x0274
	DWORD dwHideWhenEmpty; //0x0278
	char unknown8[4];
	DWORD dwShotsPerClip; //0x0280
	char unknown9[52];
	float fZoomTime; //0x02B8
	DWORD dwMinPerturb; //0x02BC
	DWORD dwMaxPerturb; //0x02C0
	float fDuckPerturb; //0x02C4
	float fMoveDuckPerturb; //0x02C8
	DWORD dwZoomedMinPerturb; //0x02CC
	DWORD dwZoomedMaxPerturb; //0x02D0
	DWORD dwRange; //0x02D4
	char unknown10[12];
	DWORD VectorsPerRound; //0x02E4
	char unknown11[40];
	float fPerturbIncSpeed; //0x0310
	float fPerturbDecSpeed; //0x0314
	char unknown12[4];
	float fZoomedPerturbIncSpeed; //0x031C
	float fZoomedPerturbDecSpeed; //0x0320
	char unknown13[4];
	float fBaseCamRecoilPitch; //0x0328
	float fBaseCamRecoilAccelPitch; //0x032C
	char unknown14[36];
	float fTripleShotMaxCamRecoilPitch; //0x0354
	float fTripleShotBaseCamRecoilPitch; //0x0358
	char unknown15[8];
	DWORD dwTripleShotMinPerturb; //0x0364
	DWORD dwTripleShotMaxPerturb; //0x0368
	float fTripleShotPerturbIncSpeed; //0x036C
	float fTripleShotPerturbDecSpeed; //0x0370
	char unknown16[108];
	BYTE DisableCrosshair; //0x03E0
	char unknown17[27];
	float fCameraSwayXFreq; //0x03FC
	float fCameraSwayYFreq; //0x0400
	char unknown18[8];
	DWORD dwEffectRange; //0x040C
};//Size=0x0410(1040)

class cWeaponMgr
{
public:
	char unknown1[5600];
	cWeaponInfo** Weapons; //0x15E0
	__int32 WeaponCount; //0x15E4
};//Size=0x15E8

class CILTDrawPrim
{
public:
	char unknown1[16184];
	D3DVIEWPORT9 ViewPort; //0x3F38
	D3DXMATRIX World; //0x3F50
	D3DXMATRIX View; //0x3F90
	D3DXMATRIX Projection; //0x3FD0
};//Size=0x4010

class cObjName
{
public:
	char unknown1[4];
	char Name[28]; //0x0004
};//Size=0x0008

class cBaseFX
{
public:
	char unknown1[16];
	int* Object; //0x0010
	D3DXVECTOR3 Pos; //0x0014
	char unknown2[28];
	cObjName* gotoObjName; //0x0034
	char unknown3[8];
	int NaoArma; //0x0040
	char unknown4[4];
	BYTE Unknown5;
	BYTE OwnerID; //0x004C
	char unknown6[40];
};//Size=0x0054

//typedef bool (*ObjectFilterFnCA)(int* hObj, void* pUserData);


class cArmaMGR;
class cChamarArma;
class cArmaJogador;
class cInformacaoArma;
class cArmaNome;

class cArmaMGR
{
public:
	cChamarArma* pChamar; //0x0000  
	char _0x0004[56];
	float ArmaPosY; //0x003C  
	float ArmaPosX; //0x0040  
	char _0x0044[660];
	__int32 Vida; //0x02D8  
	__int32 AP; //0x02DC  
	__int32 VidaMaxima; //0x02E0  
	__int32 APMaximo; //0x02E4  
	char _0x02E8[396];
	float Stamina; //0x0474  
	char _0x0478[72];

};//Size=0x04C0 

class cChamarArma
{
public:
	char _0x0000[12];
	cArmaJogador* pArma; //0x000C  
	char _0x0010[48];

};//Size=0x0040 

class cArmaJogador
{
public:
	char _0x0000[152];
	DWORD ArmaID; //0x0098  
	char _0x009C[8];
	cInformacaoArma* pArmaInfo; //0x00A4  
	char _0x00A8[36];
	float TamanhoMira; //0x00CC  
	float TiroEspalhado; //0x00D0  
	char _0x00D4[12];
	__int32 FogoRapido; //0x00E0  
	__int32 Muniçao; //0x00E4  
	__int32 CartuchoHacker; //0x00E8  
	__int32 SemSelecionar; //0x00EC  
	char _0x00F0[912];

};//Size=0x0480 

cChamarArma * pChamarArma;

class cInformacaoArma
{
public:
	char _0x0000[20];
	cArmaNome* pArmaNome; //0x0014  
	__int32 MunicaoTotal; //0x0018  
	char _0x001C[4];
	__int32 DanoArma; //0x0020  
	__int32 DanoFaca; //0x0024  
	__int32 DanoBomba; //0x0028  
	char _0x002C[1044];

};//Size=0x0440 

class cArmaNome
{
public:
	char ArmaNome[20]; //0x0000  
	char _0x0014[44];

};//Size=0x0040


LocalInfo *pLocal;

VOID Texto(INT x, INT y, DWORD color, DWORD Flags, LPD3DXFONT g_pFont, CONST CHAR *fmt, ...)
{
	RECT FontPos = { x, y, x, y };
	CHAR buf[256] = { '\0' };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	g_pFont->DrawText(NULL, buf, -1, &FontPos, Flags, color);
}

float PegarDistancia(D3DXVECTOR3 Camera, D3DXVECTOR3 Jogador)
{
	return sqrt((Camera.x - Jogador.x) * (Camera.x - Jogador.x) +
		(Camera.y - Jogador.y) * (Camera.y - Jogador.y) +
		(Camera.z - Jogador.z) * (Camera.z - Jogador.z));
}


cLTModel*			pLTModel;
cGameClientShell*  pGameClientShell;