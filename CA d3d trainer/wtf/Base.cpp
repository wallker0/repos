#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Menu.h"
#include "Classes.h"
#include "Limpador.h"
#include "Header.h"
#include "Header1.h"
#include "message.h"
#include "LTClient.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")


BOOL bFont;

INT primaria, secundaria, faca, nade;
INT Names, Lines, Distances, Boxes; 


INT PosX = 30; //Menu Position
INT PosY = 70; //Menu Position
INT Posy = 60; //Menu Position


//Metodo de Console

typedef UINT(WINAPI *tSendToServer)(ILTMessage_Read *pMsg, UINT Flags);
tSendToServer oSendToServer;

typedef void(__cdecl*RunConsoleCommandFn)(const char*);
RunConsoleCommandFn PtcStatus = (RunConsoleCommandFn)ADDR_LTCLIENTEXE;

CHAR Timestruct[MAX_PATH] = { "hh':'mm':'ss tt" }; //Estrutura do relógio.
CHAR TimeString[MAX_PATH];
INT charid;

void RenderBackend(void)
{
	LPDIRECT3DDEVICE9 pDevice = **(LPDIRECT3DDEVICE9 **)ADDR_DEVICEGAME;

	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);

	D3DXCreateFont(pDevice, 14, 0, 400, 1, 0, 1, 0, 4, 0 | (0 << 4), STRING_FONT, &pFont);

	MenuSettings();

	if (GetAsyncKeyState(VK_F12) & 1) Menu = !Menu;

	if (Menu && pFont)
	{
		GetTimeFormatA(0, 0, 0, 0, Timestruct, 15);
		sprintf_s(TimeString, "%s", Timestruct);

		//[Draw Box]
		Degrade(PosX + 5, PosY - 20, 350, 200, Cinza, Cinza2, Cinza, gr_orientation::vertical, pDevice);
		DrawBox(PosX + 5, PosY - 20, 350, 20, Cinza, Menu, pDevice);
		Degrade(PosX - 13, 80, 15, 135, Cinza, Cinza2, Cinza, gr_orientation::vertical, pDevice);
		//End of [Draw Box]

		//[Name And Timer]
		PrintShadowedText(pFont, 339, 230, Green, Black, 1, 1, Timestruct);
		PrintShadowedText(pFont, PosX - 10, 95, Green, Black, 2, 2, Dencrypt("F"));
		PrintShadowedText(pFont, PosX - 9, 105, Green, Black, 2, 2, Dencrypt("e"));
		PrintShadowedText(pFont, PosX - 9, 115, Green, Black, 2, 2, Dencrypt("x"));
		PrintShadowedText(pFont, PosX - 9, 125, Green, Black, 2, 2, Dencrypt("e"));
		PrintShadowedText(pFont, PosX - 9, 135, Green, Black, 2, 2, Dencrypt("x"));
		PrintShadowedText(pFont, PosX - 9, 145, Green, Black, 2, 2, Dencrypt("e"));
		//End of [Name And Timer]

		//[Version]
		PrintShadowedText(pFont, PosX - 9, 165, Green, Black, 2, 2, "V");
		PrintShadowedText(pFont, PosX - 9, 175, Green, Black, 2, 2, "5");
		//End of [Version]

		//[Tab Buttons]
		DrawTabButton(35, 31, Tab[1], Dencrypt("$Emqfsx"), pDevice);

		DrawTabButton(90, 31, Tab[2], Dencrypt("$$Zmwyep"), pDevice);

		DrawTabButton(144, 31, Tab[3], Dencrypt("[ietsr"), pDevice);
		
		DrawTabButton(198, 31, Tab[4], Dencrypt("$$$Glev"), pDevice);

		DrawTabButton(253, 31, Tab[5], Dencrypt("$$$$W6W"), pDevice);

		DrawTabButton(303, 31, Tab[6], Dencrypt("$$W1Zmt+w"), pDevice);

		DrawTabButton2(356, 31, Tab[7], Dencrypt("Syx"), pDevice);
		//End of [Tab Buttons]

		if (Tab[1])//Aimbot
		{
			DoubleCheck(10, 60, MenuItem[32], STRING_ITEM32, Menu, Menu, pDevice); 
			Degrade(35, 240, 175, 80, Cinza, Cinza2, Black, gr_orientation::vertical, pDevice);
			DrawBorder(menux + 19, menuy + 225 + (MenuSelection * 15), 165, 15, 1, bBlue, pDevice);
			Item(STRING_ITEM33, Opt_ang, AngleCheck, 4);
		}
		if (Tab[2])//Visuals
		{
			DoubleCheck(10, 60, MenuItem[1], STRING_ITEM1, Menu, Menu, pDevice);
			DoubleCheck(10, 80, MenuItem[2], STRING_ITEM2, Menu, Menu, pDevice);
			DoubleCheck(10, 100, MenuItem[4], STRING_ITEM4, Menu, Menu, pDevice);
			DoubleCheck(10, 120, MenuItem[5], STRING_ITEM5, Menu, Menu, pDevice);
			DoubleCheck(10, 140, MenuItem[7], STRING_ITEM7, Menu, Menu, pDevice);
			DoubleCheck(10, 160, MenuItem[20], STRING_ITEM20, Menu, Menu, pDevice);
			DoubleCheck(10, 180, MenuItem[21], STRING_ITEM21, Menu, Menu, pDevice);
		}
		if (Tab[3])//Weapon
		{
			DoubleCheck(10, 60, MenuItem[3], STRING_ITEM3, Menu, Menu, pDevice);
			DoubleCheck(10, 80, MenuItem[6], STRING_ITEM6, Menu, Menu, pDevice);
			DoubleCheck(10, 100, MenuItem[25], STRING_ITEM25, Menu, Menu, pDevice);
			DoubleCheck(10, 120, MenuItem[26], STRING_ITEM26, Menu, Menu, pDevice);
			DoubleCheck(10, 140, MenuItem[10], STRING_ITEM9, Menu, Menu, pDevice);
			Degrade(35, 240, 175, 80, Cinza, Cinza2, Black, gr_orientation::vertical, pDevice);
			DrawBorder(menux + 19, menuy + 225 + (MenuSelection * 15), 165, 15, 1, bBlue, pDevice);
			Item(STRING_ITEM10, Opt_Armas, MenuItem[11], 23);
			Item(STRING_ITEM11, Opt_Armas, MenuItem[12], 23);
			Item(STRING_ITEM12, Opt_Armas, MenuItem[13], 23);
			Item(STRING_ITEM13, Opt_Armas, MenuItem[14], 23);
		}
		if (Tab[4])//Character
		{
			DoubleCheck(10, 60, MenuItem[27], STRING_ITEM27, Menu, Menu, pDevice);
			DoubleCheck(10, 80, MenuItem[8], STRING_ITEM8, Menu, Menu, pDevice);
			Degrade(35, 240, 175, 80, Cinza, Cinza2, Black, gr_orientation::vertical, pDevice);
			DrawBorder(menux + 19, menuy + 225 + (MenuSelection * 15), 165, 15, 1, bBlue, pDevice);
			Item(STRING_ITEM14, Opt_Char, MenuItem[15], 10);
			Item(STRING_ITEM28, Opt_nome, MenuItem[28], 3);
		}
		if (Tab[5])//Func. S2S
		{
			DoubleCheck(10, 60, MenuItem[30], STRING_ITEM30, Menu, Menu, pDevice);
			DoubleCheck(10, 80, MenuItem[29], STRING_ITEM29, Menu, Menu, pDevice);
		}
		if (Tab[6])//Semi-Vips
		{
			DoubleCheck(10, 60, MenuItem[22], STRING_ITEM22, Menu, Menu, pDevice);
			DoubleCheck(10, 80, MenuItem[34], STRING_ITEM34, Menu, Menu, pDevice);
		}
		if (Tab[7])//Outros
		{
			DoubleCheck(10, 60, save, STRING_ITEM23, Menu, Menu, pDevice);
			DoubleCheck(10, 80, load, STRING_ITEM24, Menu, Menu, pDevice);
			DoubleCheck(10, 100, MenuItem[17], STRING_ITEM16, Menu, Menu, pDevice);
			DrawText(pDevice, 84, 100, bBlue, Dencrypt("$>$Xigpe$B$Irh"));
		}
		SetDrawColors(pDevice);
		DrawMouse(pDevice);
	}

	Navigation();

	//chams
	if (*(BYTE*)ADDR_GAMESTATUS == 5) // Se GameStatus estiver com o valor de 5(Que eu defini como NoLobby  )
	{
		PtcStatus("+SkelModelStencil 0"); // A função vai desativar
	}
	else if (*(BYTE*)ADDR_GAMESTATUS == 1) // Dai se GameStatus estiver com valor de 1(Que eu defini como Jogando)
	{
		PtcStatus("+SkelModelStencil 1"); // A função vai Ativar 
	}

	//no fog
	if (*(BYTE*)ADDR_GAMESTATUS == 5) // Se GameStatus estiver com o valor de 5(Que eu defini como NoLobby  )
	{
		PtcStatus("+FogEnable 1"); // A função vai desativar
	}
	else if (*(BYTE*)ADDR_GAMESTATUS == 1) // Dai se GameStatus estiver com valor de 1(Que eu defini como Jogando)
	{
		PtcStatus("+FogEnable 0"); // A função vai Ativar 
	}

	//aimcorrection
	if (MenuItem[3] == 1)
	{
		bAimCorrection = !bAimCorrection;
		vAimCorrection();
	}

	//gamestatus check(aimbot/aimvisible)
	if ((*(BYTE *)ADDR_GAMESTATUS == 5))
	{
		MenuItem[31] = 0;
		MenuItem[32] = 0;
	}

	//aimbot
	if (MenuItem[32])
	{
		DoAimbot(MenuItem[32]);
	}


	//Ghost Mod
	if (MenuItem[4])
	{
		if (*(long*)ADDR_PLAYERSTATUS == 1)
			*(long*)ADDR_PLAYERSTATUS = -5;
	}
	else
	{
		if (*(long*)ADDR_PLAYERSTATUS == -5)
			*(long*)ADDR_PLAYERSTATUS = 1;
	}

	//save e load
	if (save){

		Save("Zmwyep1", "KlswxQshi1", MenuItem[3], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep2", "KlswxQshi2", MenuItem[4], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep3", "KlswxQshi3", MenuItem[5], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep4", "KlswxQshi4", MenuItem[6], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep5", "KlswxQshi5", MenuItem[7], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep6", "KlswxQshi6", MenuItem[20], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep7", "KlswxQshi7", MenuItem[21], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep8", "KlswxQshi8", MenuItem[22], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep9", "KlswxQshi9", MenuItem[23], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep10", "KlswxQshi10", MenuItem[24], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep11", "KlswxQshi11", MenuItem[25], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep12", "KlswxQshi12", MenuItem[26], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep13", "KlswxQshi13", MenuItem[10], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep14", "KlswxQshi14", MenuItem[11], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep15", "KlswxQshi15", MenuItem[12], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep16", "KlswxQshi16", MenuItem[13], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep17", "KlswxQshi17", MenuItem[14], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep18", "KlswxQshi18", MenuItem[8], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep19", "KlswxQshi19", MenuItem[15], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep20", "KlswxQshi20", MenuItem[27], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep21", "KlswxQshi21", MenuItem[28], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep22", "KlswxQshi22", MenuItem[17], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep23", "KlswxQshi23", MenuItem[29], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep24", "KlswxQshi24", MenuItem[30], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep25", "KlswxQshi25", MenuItem[31], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep26", "KlswxQshi26", MenuItem[32], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep27", "KlswxQshi27", MenuItem[33], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep28", "KlswxQshi28", MenuItem[34], GetFile("D:\\SaveName.ini"));
		Save("Zmwyep29", "KlswxQshi29", MenuItem[35], GetFile("D:\\SaveName.ini"));
		//Deixe o save recebendo zero sempre no final, para que não fique salvando em loop		
		save = 0;
	}
	if (load){
		MenuItem[3] = Load("Zmwyep1", "KlswxQshi1", MenuItem[3], GetFile("D:\\SaveName.ini"));
		MenuItem[4] = Load("Zmwyep2", "KlswxQshi2", MenuItem[4], GetFile("D:\\SaveName.ini"));
		MenuItem[5] = Load("Zmwyep3", "KlswxQshi3", MenuItem[5], GetFile("D:\\SaveName.ini"));
		MenuItem[6] = Load("Zmwyep4", "KlswxQshi4", MenuItem[6], GetFile("D:\\SaveName.ini"));
		MenuItem[7] = Load("Zmwyep5", "KlswxQshi5", MenuItem[7], GetFile("D:\\SaveName.ini"));
		MenuItem[20] = Load("Zmwyep6", "KlswxQshi6", MenuItem[20], GetFile("D:\\SaveName.ini"));
		MenuItem[21] = Load("Zmwyep7", "KlswxQshi7", MenuItem[21], GetFile("D:\\SaveName.ini"));
		MenuItem[22] = Load("Zmwyep8", "KlswxQshi8", MenuItem[22], GetFile("D:\\SaveName.ini"));
		MenuItem[23] = Load("Zmwyep9", "KlswxQshi9", MenuItem[23], GetFile("D:\\SaveName.ini"));
		MenuItem[24] = Load("Zmwyep10", "KlswxQshi10", MenuItem[24], GetFile("D:\\SaveName.ini"));
		MenuItem[25] = Load("Zmwyep11", "KlswxQshi11", MenuItem[25], GetFile("D:\\SaveName.ini"));
		MenuItem[26] = Load("Zmwyep12", "KlswxQshi12", MenuItem[26], GetFile("D:\\SaveName.ini"));
		MenuItem[10] = Load("Zmwyep13", "KlswxQshi13", MenuItem[10], GetFile("D:\\SaveName.ini"));
		MenuItem[11] = Load("Zmwyep14", "KlswxQshi14", MenuItem[11], GetFile("D:\\SaveName.ini"));
		MenuItem[12] = Load("Zmwyep15", "KlswxQshi15", MenuItem[12], GetFile("D:\\SaveName.ini"));
		MenuItem[13] = Load("Zmwyep16", "KlswxQshi16", MenuItem[13], GetFile("D:\\SaveName.ini"));
		MenuItem[14] = Load("Zmwyep17", "KlswxQshi17", MenuItem[14], GetFile("D:\\SaveName.ini"));
		MenuItem[8] = Load("Zmwyep18", "KlswxQshi18", MenuItem[8], GetFile("D:\\SaveName.ini"));
		MenuItem[15] = Load("Zmwyep19", "KlswxQshi19", MenuItem[15], GetFile("D:\\SaveName.ini"));
		MenuItem[27] = Load("Zmwyep20", "KlswxQshi20", MenuItem[27], GetFile("D:\\SaveName.ini"));
		MenuItem[28] = Load("Zmwyep21", "KlswxQshi21", MenuItem[28], GetFile("D:\\SaveName.ini"));
		MenuItem[17] = Load("Zmwyep22", "KlswxQshi22", MenuItem[17], GetFile("D:\\SaveName.ini"));
		MenuItem[29] = Load("Zmwyep23", "KlswxQshi23", MenuItem[29], GetFile("D:\\SaveName.ini"));
		MenuItem[30] = Load("Zmwyep24", "KlswxQshi24", MenuItem[30], GetFile("D:\\SaveName.ini"));
		MenuItem[31] = Load("Zmwyep25", "KlswxQshi25", MenuItem[31], GetFile("D:\\SaveName.ini"));
		MenuItem[32] = Load("Zmwyep26", "KlswxQshi26", MenuItem[32], GetFile("D:\\SaveName.ini"));
		MenuItem[33] = Load("Zmwyep27", "KlswxQshi27", MenuItem[33], GetFile("D:\\SaveName.ini"));
		MenuItem[34] = Load("Zmwyep28", "KlswxQshi28", MenuItem[34], GetFile("D:\\SaveName.ini"));
		MenuItem[35] = Load("Zmwyep29", "KlswxQshi29", MenuItem[35], GetFile("D:\\SaveName.ini"));
		//Deixe o load sempre no final para que não trave as funções ligadas		
		load = 0;
	}


	//spammer de texto
	if (MenuItem[29])
	{
		oSendToServer = (tSendToServer)ADDR_SendToServer;
		g_LTClient = *(CLTClient**)LTClientDLL;
		g_CommonLT = g_LTClient->Common();
		if (ValidPointer(g_LTClient))
		{
			CAutoMessage Msg;
			Msg.Writeuint8(104);
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			Msg.WriteWString(PTSpammer(L"LUG-Queremos O Servidor Para Iniciantes", 2));
			oSendToServer(Msg.Read(), (1 << 7)); //1<<7
		}
	}

	//voice spammer
	if (MenuItem[30])
	{
		oSendToServer = (tSendToServer)ADDR_SendToServer;
		g_LTClient = *(CLTClient**)LTClientDLL;
		g_CommonLT = g_LTClient->Common();
		if (ValidPointer(g_LTClient))
		{
			CAutoMessage Msg;
			Msg.Writeuint8(702);//ID_1
			Msg.Writeuint8(703);//ID_2
			Msg.Writeuint8(704);//ID_3
			Msg.Writeuint8(705);//ID_3
			oSendToServer(Msg.Read(), (1 << 7));
		}
	}


	//gamestatus check(EspBoxes)
	if ((*(BYTE *)ADDR_GAMESTATUS == 5))
	{
		MenuItem[21] = 0;}
	else if ((*(BYTE *)ADDR_GAMESTATUS == 1))
	{
		MenuItem[21] = 1;}

	//esp boxes
	if (MenuItem[21])
	{
		CHAR CName[50];
		GetPlayerByIndex = (lpGetPlayerByIndex)PlayerByIndex;
		unsigned long ulThis = *(unsigned long *)ADDR_CLIENTINFOMGR;
		GetLocalPlayer = (lpGetLocalPlayer)ADDR_LOCALPLAYER;
		cGameClientShell *pGameClientShell = *(cGameClientShell **)GCS;
		for (INT i = 0; i < 24; i++)
		{
			pPlayerInfo *pLocal = GetLocalPlayer(ulThis);
			pPlayerInfo *pPlayer = GetPlayerByIndex(ulThis, i, 0);
			cCharacterFX *PlayerFX = (cCharacterFX *)pGameClientShell->GetSFXMgr()->SFXList[0x18].List[i];
			if (pPlayer != 0 && pPlayer->Object != 0 && pPlayer->IsDead == 0)
			{
				D3DXVECTOR3 HeadPos, FootPos, HeadScreen, FootScreen;
				if (!pPlayer->IsDead) // se nao estiver morto..
				{
					D3DXVECTOR3 vPos, vFootScreen, vScreen;
					vPos.x = pPlayer->Object->Pos.x;
					vPos.y = pPlayer->Object->yBound2;
					vPos.z = pPlayer->Object->Pos.z;
					if (W2S(pDevice, vPos, &vScreen))
					{
						vPos.x = pPlayer->Object->Pos.x;
						vPos.y = pPlayer->Object->yBound1;
						vPos.z = pPlayer->Object->Pos.z;
						vPos.x = pPlayer->Object->Pos.x;
						vPos.y = pPlayer->Object->yBound1;
						vPos.z = pPlayer->Object->Pos.z;
						if (pPlayer != 0 && pPlayer->Object != 0 && pPlayer->IsDead == 0 && pLocal->IsDead == 0)
						{
							D3DXVECTOR3 vPos, vFootScreen, vScreen;
							vPos.x = pPlayer->Object->Pos.x;
							vPos.y = pPlayer->Object->yBound2;
							vPos.z = pPlayer->Object->Pos.z;
							if (W2S(pDevice, vPos, &vScreen))
							{
								if (pPlayer->Team != pLocal->Team)
								{
										sprintf(CName, "%s", pPlayer->Name);
										Texto(vScreen.x, vScreen.y, Red, TCenter, pFont, CName);

										vPos.x = pPlayer->Object->Pos.x;
										vPos.y = pPlayer->Object->yBound1;
										vPos.z = pPlayer->Object->Pos.z;
										if (W2S(pDevice, vPos, &vFootScreen))
										{
											INT BoxDist = INT(0.2f * (vFootScreen.y - vScreen.y));
											#pragma warning(push)
											D3DRECT rectBoxes[10] =
											{
												{ vScreen.x - BoxDist, vScreen.y, vScreen.x - BoxDist + 2, vFootScreen.y },
												{ vScreen.x - BoxDist, vFootScreen.y, vScreen.x + BoxDist + 2, vFootScreen.y + 1 },
												{ vScreen.x + BoxDist, vScreen.y, vScreen.x + BoxDist + 2, vFootScreen.y },
												{ vScreen.x - BoxDist, vScreen.y, vScreen.x + BoxDist, vScreen.y + 1 }
											};
											#pragma warning(pop)
											pDevice->Clear(10, rectBoxes, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, Red, 1.0f, 0);
										}
									}
								}
								if (pPlayer->Team == pLocal->Team && pPlayer->index != pLocal->index)
								{
										//sprintf(CName, "%s", pPlayer->Name);
										//Texto(vScreen.x, vScreen.y, Green, TCenter, pFont, CName);

										vPos.x = pPlayer->Object->Pos.x;
										vPos.y = pPlayer->Object->yBound1;
										vPos.z = pPlayer->Object->Pos.z;
										if (W2S(pDevice, vPos, &vFootScreen))
										{
											INT BoxDist = INT(0.2f * (vFootScreen.y - vScreen.y));
											#pragma warning(push)
											D3DRECT rectBoxes[10] =

											{
												{ vScreen.x - BoxDist, vScreen.y, vScreen.x - BoxDist + 2, vFootScreen.y },
												{ vScreen.x - BoxDist, vFootScreen.y, vScreen.x + BoxDist + 2, vFootScreen.y + 1 },
												{ vScreen.x + BoxDist, vScreen.y, vScreen.x + BoxDist + 2, vFootScreen.y },
												{ vScreen.x - BoxDist, vScreen.y, vScreen.x + BoxDist, vScreen.y + 1 }
											};
											#pragma warning(pop)
											pDevice->Clear(10, rectBoxes, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, bBlue, 1.0f, 0);

										}
									}
								}
							}
						}
					}
				}
			}


	/*Char hack bugadão*/
	if (MenuItem[8] == 1)
	{
		cLoadGamePacketClass *pLoadGame = (cLoadGamePacketClass*)/*Endereço =>*/ADDR_WEAPONSET;
		pLoadGame->pInvintoryData->Personagem = charid;
		pLoadGame->pInvintoryData->Uniforme = 2;
		pLoadGame->pInvintoryData->Mochila = 0;
		pLoadGame->pInvintoryData->CosmeticoMochila = 7103;
		pLoadGame->pInvintoryData->CosmeticoPersonagem = 10072;
		pLoadGame->pInvintoryData->Cabeça = 4135;
		pLoadGame->pInvintoryData->Rosto = 5085;
		//Traje Guillie = 10072;
		//Traje EOD = 10073;
		//Transparencia Total = 10074;
		//Uniforme De Prisão = 10076;
		//Traje JSF = 10086;
	}


	//charset
	if (MenuItem[15] == 1)
	{charid = 1;}
	else if (MenuItem[15] == 2)
	{charid = 23;}
	else if (MenuItem[15] == 3)
	{charid = 27;}
	else if (MenuItem[15] == 4)
	{charid = 15;}
	else if (MenuItem[15] == 5)
	{charid = 10;}
	else if (MenuItem[15] == 6)
	{charid = 57;}
	else if (MenuItem[15] == 7)
	{charid = 56;}
	else if (MenuItem[15] == 8)
	{charid = 81;} //42 /62
	else if (MenuItem[15] == 9)
	{charid = 71;} //42 /62 /73(astronauta)


	//SuperJump
	if (MenuItem[5])
	{
		*(float*)Jump = 300.0f * 3;}
	else
	{
		*(float*)Jump = 350.0f;}

	//SuperPickUp
	if (MenuItem[26])
	{
		*(float*)PickUP = 1000.0f * 100000000;}
	else
	{
		*(float*)PickUP = 1000.0f;}

	//Fly
	if (MenuItem[20] && GetAsyncKeyState(VK_SPACE))
		*(FLOAT*)(*(DWORD*)(*(DWORD*)(PlayerManager)+0x10) + 0xD0) = 1100.0f;
	else
		*(FLOAT*)(*(DWORD*)(*(DWORD*)(PlayerManager)+0x10) + 0xD0) = -1100.0f;

	//WeaponOPK
	if (MenuItem[6])
	{
		WeaponOPK();
	}

	//NpcOPK
	if (MenuItem[22])
	{
		TeleKillFull();
	}

	Crosshair(pDevice);

	//rapidfire && gamestatus check
	if ((*(BYTE *)ADDR_GAMESTATUS == 5))
		MenuItem[25] = 0;

	//rapidfire
	cArmaMGR  *pMGR = (cArmaMGR *)ADDR_WEAPONINFO; // definir a classe 
	if ((*(BYTE *)ADDR_GAMESTATUS ) && MenuItem[25] == 1)
	{
		if (GetAsyncKeyState(VK_LBUTTON)<0)
			*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerManager)+0x18) + 0x0C) + 0xE0) = 1;
		else if (GetAsyncKeyState(VK_LBUTTON)<0)
			*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerManager)+0x18) + 0x0C) + 0xE0) = 0;
	}


	//superstamina
	if (MenuItem[27])
	{
		if (pMGR->Stamina < 100)
		{
			pMGR->Stamina = 5000;}
		else
		{
			pMGR->Stamina = 5000;}
	}

 
	//modogm
	if (MenuItem[28] == 1)
	{
		funcaoGM(L"iTzWallkerII");}
	else if (MenuItem[28] == 2)
	{
		funcaoGM(L"GM-Wallker");}


	//superspeed
	if (MenuItem[7])
		*(float*)ADDR_FRunVel = 285.0f * 6;
	else
		*(float*)ADDR_FRunVel = 285.0f;

	//rcrasher
	if (MenuItem[34] == 1)
	{
		*(DWORD *)(*(DWORD *)(ADDR_WEAPONSET + 0x1EC) + 0xB4) = 170;
	}

	//WeaponSet1
	if (MenuItem[10] == 1)
	{
		DWORD dwWeaponSet = *(DWORD *)(ADDR_WEAPONSET + 0x1EC);
		*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x0) + 0x14) = primaria; // substitui sua arma primária padrão
		*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x4) + 0x14) = secundaria; // substitui sua arma secundária padrão
		*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0x8) + 0x14) = faca; // substitui sua faca padrão
		*(DWORD *)(*(DWORD *)(*(DWORD *)(dwWeaponSet + 0x48) + 0xC) + 0x14) = nade; // substitui sua granada padrão
		*(DWORD *)(ADDR_WEAPONSET + 0x488) = 37; // Germany / Alemanha
		*(DWORD *)(ADDR_WEAPONSET + 0x474) = 0xFF800080; // Roxo
	}

	//weaponset->primaria 
	if (MenuItem[11] == 1)
	{primaria = 330;}
	else if (MenuItem[11] == 2)
	{primaria = 280;}
	else if (MenuItem[11] == 3)
	{primaria = 291;}
	else if (MenuItem[11] == 4)
	{primaria = 461;} //461
	else if (MenuItem[11] == 5)
	{primaria = 49;}
	else if (MenuItem[11] == 6)
	{primaria = 344;}
	else if (MenuItem[11] == 7)
	{primaria = 56;}
	else if (MenuItem[11] == 8)
	{primaria = 256;}
	else if (MenuItem[11] == 9)
	{primaria = 527;}
	else if (MenuItem[11] == 10)
	{primaria = 99;}
	else if (MenuItem[11] == 11)
	{primaria = 190;}
	else if (MenuItem[11] == 12)
	{primaria = 148;}
	else if (MenuItem[11] == 13)
	{primaria = 113;}
	else if (MenuItem[11] == 14)
	{primaria = 143;}
	else if (MenuItem[11] == 15)
	{primaria = 247;}
	else if (MenuItem[11] == 16)
	{primaria = 294;}
	else if (MenuItem[11] == 17)
	{primaria = 410;}
	else if (MenuItem[11] == 18)
	{primaria = 331;}
	else if (MenuItem[11] == 19)
	{primaria = 562;}
	else if (MenuItem[11] == 20)
	{primaria = 558;} 
	else if (MenuItem[11] == 21)
	{primaria = 66;}
	else if (MenuItem[11] == 22)
	{primaria = 419;}

	//weaponset->secundaria
	if (MenuItem[12] == 1)
	{secundaria = 330;}
	else if (MenuItem[12] == 2)
	{secundaria = 280;}
	else if (MenuItem[12] == 3)
	{secundaria = 291;}
	else if (MenuItem[12] == 4)
	{secundaria = 461;} //461
	else if (MenuItem[12] == 5)
	{secundaria = 49;}
	else if (MenuItem[12] == 6)
	{secundaria = 344;}
	else if (MenuItem[12] == 7)
	{secundaria = 56;}
	else if (MenuItem[12] == 8)
	{secundaria = 256;}
	else if (MenuItem[12] == 9)
	{secundaria = 527;}
	else if (MenuItem[12] == 10)
	{secundaria = 99;}
	else if (MenuItem[12] == 11)
	{secundaria = 190;}
	else if (MenuItem[12] == 12)
	{secundaria = 148;}
	else if (MenuItem[12] == 13)
	{secundaria = 113;}
	else if (MenuItem[12] == 14)
	{secundaria = 143;}
	else if (MenuItem[12] == 15)
	{secundaria = 247;}
	else if (MenuItem[12] == 16)
	{secundaria = 294;}
	else if (MenuItem[12] == 17)
	{secundaria = 410;}
	else if (MenuItem[12] == 18)
	{secundaria = 331;}
	else if (MenuItem[12] == 19)
	{secundaria = 562;}
	else if (MenuItem[12] == 20)
	{secundaria = 558;}
	else if (MenuItem[12] == 21)
	{secundaria = 66;}
	else if (MenuItem[12] == 22)
	{secundaria = 419;}

	//weaponset->faca
	if (MenuItem[13] == 1)
	{faca = 330;}
	else if (MenuItem[13] == 2)
	{faca = 280;}
	else if (MenuItem[13] == 3)
	{faca = 291;}
	else if (MenuItem[13] == 4)
	{faca = 461;} //461
	else if (MenuItem[13] == 5)
	{faca = 49;}
	else if (MenuItem[13] == 6)
	{faca = 344;}
	else if (MenuItem[13] == 7)
	{faca = 56;}
	else if (MenuItem[13] == 8)
	{faca = 256;}
	else if (MenuItem[13] == 9)
	{faca = 527;}
	else if (MenuItem[13] == 10)
	{faca = 99;}
	else if (MenuItem[13] == 11)
	{faca = 190;}
	else if (MenuItem[13] == 12)
	{faca = 148;}
	else if (MenuItem[13] == 13)
	{faca = 113;}
	else if (MenuItem[13] == 14)
	{faca = 143;}
	else if (MenuItem[13] == 15)
	{faca = 247;}
	else if (MenuItem[13] == 16)
	{faca = 294;}
	else if (MenuItem[13] == 17)
	{faca = 410;}
	else if (MenuItem[13] == 18)
	{faca = 331;}
	else if (MenuItem[13] == 19)
	{faca = 562;}
	else if (MenuItem[13] == 20)
	{faca = 558;}
	else if (MenuItem[13] == 21)
	{faca = 66;}
	else if (MenuItem[13] == 22)
	{faca = 419;}

	//weaponset->nade
	if (MenuItem[14] == 1)
	{nade = 330;}
	else if (MenuItem[14] == 2)
	{nade = 280;}
	else if (MenuItem[14] == 3)
	{nade = 291;}
	else if (MenuItem[14] == 4)
	{nade = 461;} //461
	else if (MenuItem[14] == 5)
	{nade = 49;}
	else if (MenuItem[14] == 6)
	{nade = 344;}
	else if (MenuItem[14] == 7)
	{nade = 56;}
	else if (MenuItem[14] == 8)
	{nade = 256;}
	else if (MenuItem[14] == 9)
	{nade = 527;}
	else if (MenuItem[14] == 10)
	{nade = 99;}
	else if (MenuItem[14] == 11)
	{nade = 190;}
	else if (MenuItem[14] == 12)
	{nade = 148;}
	else if (MenuItem[14] == 13)
	{nade = 113;}
	else if (MenuItem[14] == 14)
	{nade = 143;}
	else if (MenuItem[14] == 15)
	{nade = 247;}
	else if (MenuItem[14] == 16)
	{nade = 294;}
	else if (MenuItem[14] == 17)
	{nade = 410;}
	else if (MenuItem[14] == 18)
	{nade = 331;}
	else if (MenuItem[14] == 19)
	{nade = 562;}
	else if (MenuItem[14] == 20)
	{nade = 558;}
	else if (MenuItem[14] == 21)
	{nade = 66;}
	else if (MenuItem[14] == 22)
	{nade = 419;}

	//exit
	if (MenuItem[17])
	{
		if (GetAsyncKeyState(VK_END)&1)
		TerminateProcess(GetCurrentProcess(), 0);
		Sleep(10);
	}

	// Se fonte e release, anula
	if (pFont)
	{
		if (pFont->Release())
			pFont = NULL;
	}

	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
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
		lpMultiByteStr = "";

		static LPDIRECT3DDEVICE9 pDevice;

		if (!pDevice)
			pDevice = **(LPDIRECT3DDEVICE9 **)ADDR_D3D;
		else
		{
			RenderBackend();
		}
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

	*(FLOAT*)(ADDR_SHOWFPS) = 1.0f;

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
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) LimparLogs, NULL, NULL, NULL);
		//MessageBox(NULL, "Could not allocate dll pathname in target process.", "Error", MB_OK);
	}
	return TRUE;
}