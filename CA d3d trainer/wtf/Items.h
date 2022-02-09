//#include "strings.h"

char *Dencrypt(const char *Plaintext)
{
	int len = strlen(Plaintext);
	char *Cyphertext = new char[len + 4];
	for (int i = 0; i < len; ++i) {
		Cyphertext[i] = Plaintext[i] - 4;
	}
	Cyphertext[len] = 0;
	return Cyphertext;
}

int save, load;

#define STRING_FONT	/*Fonte*/ Dencrypt("Q}vmeh$Tvs") //arial / myriad pro
#define STRING_TITLE /*Título*/ Dencrypt("$$$$$$$Fexexe$z9")

#define STRING_ITEM1 /*Chams*/ Dencrypt("Gleqw")
#define STRING_ITEM2 /*NoFog*/ Dencrypt("RsJsk")
#define STRING_ITEM3 /*AimCorrection*/ Dencrypt("EmqGsvvigxmsr")
#define STRING_ITEM4 /*GhostMode*/ Dencrypt("KlswxQshi")
#define STRING_ITEM5 /*SJump*/ Dencrypt("WNyqt")
#define STRING_ITEM6 /*WeaponOPK*/ Dencrypt("[ietsrSTO")
#define STRING_ITEM7 /*SSpeed*/ Dencrypt("WWtiih")
#define STRING_ITEM8 /*CharHack*/ Dencrypt("Glevegxiv$Lego")
#define STRING_ITEM9 /*WeaponSet*/ Dencrypt("[ietsrWix")
#define STRING_ITEM10 /*WeaponSet1*/ Dencrypt("Evqe$Tvmqevme")
#define STRING_ITEM11 /*WeaponSet2*/ Dencrypt("Evqe$Wigyrhevme")
#define STRING_ITEM12 /*WeaponSet3*/ Dencrypt("Kverehe")
#define STRING_ITEM13 /*WeaponSet4*/ Dencrypt("Jege")
#define STRING_ITEM14 /*CharacterSet*/ Dencrypt("Glevegxiv")
#define STRING_ITEM16 /*Exit*/ Dencrypt("I|mx")
#define STRING_ITEM20 /*Fly*/ Dencrypt("Jp}")
#define STRING_ITEM21 /*EspBox*/ Dencrypt("I|tFs|")
#define STRING_ITEM22 /*TeleKill*/ Dencrypt("XipiOmpp")
#define STRING_ITEM23 /*Save*/ Dencrypt("Wezi")
#define STRING_ITEM24 /*Load*/ Dencrypt("Pseh")
#define STRING_ITEM25 /*RapidFire*/ Dencrypt("VetmhJmvi")
#define STRING_ITEM26 /*SPickUp*/ Dencrypt("WTmgoYt")
#define STRING_ITEM27 /*InfStamina*/ Dencrypt("MrjWxeqmre")
#define STRING_ITEM28 /*ModoGM*/ Dencrypt("QshsKQ")
#define STRING_ITEM29 /*Spammer*/ Dencrypt("Wteqqiv")
#define STRING_ITEM30 /*VSpammer*/ Dencrypt("ZWteqqiv")
#define STRING_ITEM31 /*AimVisible*/ Dencrypt("EmqZmwmfpi")
#define STRING_ITEM32 /*Aimbot*/ Dencrypt("Emqfsx")
#define STRING_ITEM33 /*Angle*/ Dencrypt("Erkpi")
#define STRING_ITEM34 /*RCrasher*/ Dencrypt("VGvewliv")

#define o1 /*OPT_ON*/ Dencrypt("Sr")
#define fi /*OPT_OFF*/ Dencrypt("Sjj")
#define m3 /*M32+*/ Dencrypt("Q76/")
#define cab /*Cabin*/ Dencrypt("Gefmr")
#define spy /*superspy*/ Dencrypt("Wt}")
#define adc /*+*/ Dencrypt("/")
#define sub /*-*/ Dencrypt("1")

#define STRING_FOLDER1 /*Visual*/ Dencrypt("Zmwyep")
#define STRING_FOLDER2 /*Weapon*/ Dencrypt("[ietsr")
#define STRING_FOLDER3 /*Character*/ Dencrypt("Glevegxiv")
#define STRING_FOLDER4 /*Others*/ Dencrypt("Sxlivw")

#define STRING_D3D9	"d3dl.dll"

#define batataon /*"ChamsON"*/ Dencrypt("/WoipQshipWxirgmp$$5")
#define batataoff /*"ChamsOFF"*/ Dencrypt("/WoipQshipWxirgmp$$4")

#define batata1on /*"NoFogON"*/ Dencrypt("/JskIrefpi$$5")
#define batata1off /*"NoFogOFF"*/ Dencrypt("/JskIrefpi$$4")


