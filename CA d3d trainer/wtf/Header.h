//Generated using ReClass 2013 Mod by CypherPresents

class cLoadGamePacketClass;
class cInvintoryData;
class cWeaponInvintory;
class cSlot;
class cName;

class cLoadGamePacketClass
{
public:
	byte _0x0000[196];
	cName* pName; //0x00C4 by NeoStryker
	byte _0x00C8[292];
	cInvintoryData* pInvintoryData; //0x01EC 

};//Size=0x01F0

class cWeaponSetClass
{
public:
	char _0x0000[168];
	wchar_t UserNameHack[15]; //0x00A8 
	char _0x00B7[13];
	wchar_t GMHack[21]; //0x00C4 
	char _0x00D9[79];
	DWORD Eliminaçoes; //0x0128 
	DWORD Mortes; //0x012C 
	DWORD GP; //0x0130 
	DWORD NxCredit; //0x0134 
	char _0x0138[16];
	DWORD NxPrepaid; //0x0148 
	char _0x014C[40];
	DWORD Experiencia; //0x0174 
	char _0x0178[116];
	cInvintoryData* pInvintoryData; //0x01EC 
	char _0x01F0[24];
	char VersaoGame[14]; //0x0208 
	char _0x0216[554];

};//Size=0x0440

class cInvintoryData
{
public:
	char _0x0000[72];
	cWeaponInvintory* pWeaponInvintory; //0x0048 
	char _0x004C[72];
	__int32 Cabeça; //0x0094 
	char _0x0098[4];
	__int32 Cranio; //0x009C 
	char _0x00A0[4];
	__int32 Rosto; //0x00A4 
	char _0x00A8[4];
	__int32 Uniforme; //0x00AC 
	char _0x00B0[4];
	__int32 Personagem; //0x00B4 
	char _0x00B8[4];
	__int32 Mochila; //0x00BC 
	char _0x00C0[44];
	__int32 CosmeticoPersonagem; //0x00EC 
	char _0x00F0[4];
	__int32 CosmeticoCabeça; //0x00F4 
	char _0x00F8[4];
	__int32 CosmeticoRosto; //0x00FC 
	char _0x0100[4];
	__int32 CosmeticoColete; //0x0104 
	char _0x0108[4];
	__int32 CosmeticoMochila; //0x010C 
	char _0x0110[108];
	__int32 HabA; //0x017C 
	char _0x0180[4];
	__int32 HabB; //0x0184 
	char _0x0188[4];
	__int32 HabC; //0x018C 
	char _0x0190[4];
	__int32 HabD; //0x0194 
	char _0x0198[1704];
};//Size=0x0284

class cWeaponInvintory
{
public:
	cSlot* pPrimary; //0x0000 
	cSlot* pPistol; //0x0004 
	cSlot* pKnife; //0x0008 
	cSlot* pNade; //0x000C 
	cSlot* pBackPackA; //0x0010 
	cSlot* pBackPackB; //0x0014 
	cSlot* pBackPackC; //0x0018 
	cSlot* pBackPackD; //0x001C 

};//Size=0x0020

class cSlot
{
public:
	byte _0x0000[20];
	__int32 WeaponId; //0x0014 

};//Size=0x0018

class cName
{
public:
	wchar_t Name[8]; //0x0000 by NeoStryker

};//Size=0x0040

cLoadGamePacketClass * pLoadGame;




struct __Object
{
public:
	DWORD Unknown;				//0x0000
	float xBound1;				//0x0004
	float yBound1;				//0x0008
	float zBound1;				//0x000C
	float xBound2;				//0x0010
	float yBound2;				//0x0014
	float zBound2;				//0x0018
	char unknown28[172];		//0x001C
	D3DXVECTOR3 Pos;			//0x00C8
	//LTRotation Rot;				//0x00D4
	char unknown228[180];		//0x00E4
	//LTVector Vel;				//0x0198
	CHAR Pad[4];
	D3DXVECTOR3 origin;
};

class pPlayerInfo
{
public:
	__int32 pPing; //0x0000  
	__int32 index; //0x0004  
	__int32 ID; //0x0008  
	char unknown2[8]; //0x000C  
	char Name[20]; //0x0014  
	char unknown3[4]; //0x0028  
	__Object *Object;  //0x002C  
	__int32 Kills; //0x0030  
	__int32 Deaths; //0x0034  
	char unknown4[44]; //0x0038  
	__int32 HeadShots; //0x0064  
	char unknown5[12]; //0x0068  
	__int32 Team; //0x0074  
	char unknown6[4]; //0x0078  
	BYTE IsDead; //0x007C  
	char unknown7[659];
	pPlayerInfo* PlayerPrev; //0x0310
	pPlayerInfo* PlayerNext; //0x0314 
};


typedef pPlayerInfo *(__thiscall *lpGetLocalPlayer)(unsigned long ulThis);
lpGetLocalPlayer GetLocalPlayer;

typedef pPlayerInfo *(__thiscall *lpGetPlayerByIndex)(unsigned long ulThis, INT index, INT unk);
lpGetPlayerByIndex GetPlayerByIndex;

class cBackPackA3;
class cBackPackB3;
class cBackPackC3;
class cBackPackD3;

class cWeaponsClass
{
public:
	char _0x0000[20]; //0x0000 
	union {
		__int32 PrimaryID1; //0x0014 
		__int32 PistolID1; //0x0014 
		__int32 KnifeID1; //0x0014 
		__int32 NadeID1; //0x0014 
	};
	union {
		__int32 PrimaryID2; //0x0018 
		__int32 PistolID2; //0x0018 
		__int32 KnifeID2; //0x0018 
		__int32 NadeID2; //0x0018 
		cBackPackA3* pBackPackA; //0x0010 
		cBackPackB3* pBackPackB; //0x0014 
		cBackPackC3* pBackPackC; //0x0018 
		cBackPackD3* pBackPackD; //0x001C 
	};
};//Size=0x001C

class cSlots
{
public:
	cWeaponsClass *Primary; //0x0000 
	cWeaponsClass *Pistol; //0x0004 
	cWeaponsClass *Knife; //0x0008 
	cWeaponsClass *Nade; //0x000C 
};//Size=0x0010

class cWeaponSetSlot
{
public:
	char _0x0000[8]; //0x0000 
	cSlots *Slots; //0x0008 
};//Size=0x000C

class cWeaponSet
{
public:
	char _0x0000[492]; //0x0000 
	cWeaponSetSlot *WeaponSet; //0x01EC 
};//Size=0x01F0

class cBackPackA3
{
public:
	char _0x0000[20];
	__int32 WeaponID; //0x0014 

};//Size=0x0080

class cBackPackB3
{
public:
	char _0x0000[20];
	__int32 WeaponID; //0x0014 


};//Size=0x0080

class cBackPackC3
{
public:
	char _0x0000[20];
	__int32 WeaponID; //0x0014 

};//Size=0x0080

class cBackPackD3
{
public:
	char _0x0000[20];
	__int32 WeaponID; //0x0014 


};//Size=0x0080

cWeaponSet *pWeaponSet;


class cCharacterFX2
{
public:
	char unknown1[16];
	__Object* Object; //0x0010
	char unknown2[44];
	__int32 IsPlayer; //0x0040
};//Size=0x05C8
