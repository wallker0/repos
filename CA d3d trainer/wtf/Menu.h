#pragma once

#include "Items.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#pragma warning(disable : 4996)

#pragma once
#ifndef WINVER
#define WINVER 0x0600
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0700
#endif


LPD3DXFONT pFont;
LPD3DXLINE pLine;
LPDIRECT3DDEVICE9 pDevice;
INT Tab[40];

#define Red       D3DCOLOR_ARGB(255, 255, 000, 000)
#define Green     D3DCOLOR_ARGB(255, 127, 255, 000)
#define Orange    D3DCOLOR_ARGB(255, 255, 140, 000)
#define Blue      D3DCOLOR_ARGB(255, 000, 000, 255)
#define Yellow    D3DCOLOR_ARGB(255, 255, 255, 51)
#define Black     D3DCOLOR_ARGB(255, 000, 000, 000)
#define Grey      D3DCOLOR_ARGB(255, 27,  27,  27)
#define Gold      D3DCOLOR_ARGB(255, 255, 215, 000)
#define Pink      D3DCOLOR_ARGB(255, 255, 192, 203)
#define Purple    D3DCOLOR_ARGB(255, 128, 000, 128)
#define White     D3DCOLOR_ARGB(255, 255, 255, 249)
#define Cyan      D3DCOLOR_ARGB(255, 000, 255, 255)
#define Magenta   D3DCOLOR_ARGB(255, 255, 000, 255)
#define TBlack    D3DCOLOR_ARGB(128, 000, 000, 000)
#define Cinza2    D3DCOLOR_ARGB(225, 26,  26,  26)
#define Cinza     D3DCOLOR_ARGB(255, 35,  35,  35)
#define bBlue     D3DCOLOR_ARGB(255, 0,   134, 230)
#define nBlue     D3DCOLOR_ARGB(255, 56,  90,  113)//(255, 48,  77,  98)

#define TNormal DT_NOCLIP
#define TLeft	DT_NOCLIP | DT_LEFT
#define TRight	DT_NOCLIP | DT_RIGHT
#define TCenter DT_NOCLIP | DT_CENTER

void DrawText(LPDIRECT3DDEVICE9 pDevice, int x, int y, DWORD Color, char *Text)
{
	RECT rect;
	SetRect(&rect, x, y, x, y);
	pFont->DrawText(NULL, Text, -1, &rect, DT_LEFT | DT_NOCLIP, Color);
}

void FillRGB(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}

void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{
	FillRGB(x, (y + h - px), w, px, BorderColor, pDevice);
	FillRGB(x, y, px, h, BorderColor, pDevice);
	FillRGB(x, y, w, px, BorderColor, pDevice);
	FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
}

void DrawBox(int x, int y, int w, int h, D3DCOLOR Color, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{

	DrawBorder(x, y, w, h, 2, BorderColor, pDevice);

	const DWORD D3D_FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	struct Vertex {
		float x, y, w, h;
		D3DCOLOR Color;
	}
	V[4] = { { (float)x, (float)(y + h), 0.0f, 0.0f, Color },
	{ (float)x, (float)y, 0.0f, 0.0f, Color },
	{ (float)(x + w), (float)(y + h), 0.0f, 0.0f, Color },
	{ (float)(x + w), (float)y, 0.0f, 0.0f, Color }
	};
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, D3DZB_TRUE);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	pDevice->SetRenderState(D3DRS_FOGENABLE, D3DZB_FALSE);

	pDevice->SetFVF(D3D_FVF);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
}

void FazerESPCaixa(D3DXVECTOR3 Head, D3DXVECTOR3 Foot, DWORD dwColor, LPDIRECT3DDEVICE9 pDevice)
{

	D3DXVECTOR3 Box = Head - Foot;

	if (Box.y  < 0)
		Box.y *= -1;

	int BoxWidth = (int)Box.y / 2;
	int DrawX = (int)Head.x - (BoxWidth / 2);
	int DrawY = (int)Head.y;

	DrawBox(DrawX, DrawY, BoxWidth, (int)Box.y, 2, dwColor, pDevice);
	DrawBox(DrawX, DrawY, BoxWidth, (int)Box.y, 1, 0xFF000000, pDevice);
}

int qntHacks = 0;
int frame;
int menux, menuy, mxofs;
int MenuSelection;
bool Menu = true;

void PrintText(LPD3DXFONT g_pFont, INT x, INT y, DWORD Flags, DWORD Color, CHAR *text, ...)
{
	RECT rec;
	SetRect(&rec, x, y, x, y);
	CHAR logbuf[512] = { 0 };

	va_list va_alist;
	va_start(va_alist, text);
	vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);

	va_end(va_alist);
	g_pFont->DrawTextA(NULL, logbuf, -1, &rec, Flags, Color);
}

int Current = true;

void Item(CHAR *text, CHAR **opt, INT &val, INT maxvalue)
{
	DWORD Color1, Color2;
	INT bVar = (val) ? (val) : 0;
	extern INT Current;
	if (Menu && pFont)
	{
		if (MenuSelection == qntHacks)
		{
			if (GetAsyncKeyState(VK_RIGHT) & 1)
				if (val < maxvalue - 1)
					val++;
			if (GetAsyncKeyState(VK_LEFT) & 1)
				if (val > 0)
					val--;
		}

		Color1 = White;
		Color2 = (bVar) ? White : White;

		PrintText(pFont, menux + 25, menuy + 225 + (qntHacks * 15), TLeft, Color1, text);
		PrintText(pFont, menux - 5 + mxofs, menuy + 225 + (qntHacks * 15), TRight, Color2, opt[bVar]);

		qntHacks++;
		frame = (qntHacks * 15 + 20);
	}
	Current++;
}

void Folder(CHAR *text, CHAR **opt, INT &val, INT maxvalue)
{
	DWORD Color1, Color2;
	int bVar = (val) ? (val) : 0;
	extern int Current;
	if (Menu && pFont)
	{
		if (MenuSelection == qntHacks)
		{
			if (GetAsyncKeyState(VK_RIGHT) & 1)
				if (val < maxvalue - 1)
					val++;
			if (GetAsyncKeyState(VK_LEFT) & 1)
				if (val > 0)
					val--;
		}

		Color1 = nBlue;
		Color2 = (bVar) ? nBlue : nBlue;

		PrintText(pFont, menux - 20, menuy + 380 + (qntHacks * 15), TLeft, Color1, text);
		PrintText(pFont, menux + 20 + mxofs, menuy + 380 + (qntHacks * 15), TRight, Color2, opt[bVar]);

		qntHacks++;

		frame = (qntHacks * 15 + 20);
	}
	Current++;
}

bool IsInBox(int x, int y, int w, int h)
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return (MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}

void PrintShadowedText(LPD3DXFONT Font, int x, int y, D3DCOLOR ColorFont, D3DCOLOR ColorShadow, int xDisplacement, int YDisplacement, const char *text, ...)
{
	D3DCOLOR fontColor = ColorFont;
	D3DCOLOR fontColorShadow = ColorShadow;

	RECT rctA;
	rctA.left = x;
	rctA.top = y;
	rctA.right = rctA.left + 1000;
	rctA.bottom = rctA.top + 1000;
	RECT rctB; rctB.left = x + xDisplacement;
	rctB.top = y + YDisplacement;
	rctB.right = rctB.left + 1000;
	rctB.bottom = rctB.top + 1000;

	va_list va_alist;
	char logbuf[256] = { 0 };
	va_start(va_alist, text);
	_vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
	va_end(va_alist);

	Font->DrawTextA(NULL, logbuf, -1, &rctB, 0, fontColorShadow);
	Font->DrawTextA(NULL, logbuf, -1, &rctA, 0, fontColor);
}

int CheckTabs(int x, int y, int w, int h)
{
	if (IsInBox(x, y, w, h))
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 1)
		{
			return 1;
		}
		return 2;
	}
	return 0;
}

enum gr_orientation
{
	horizontal,
	vertical
};

void Degrade(float x, float y, float width, float height, D3DCOLOR startCol, D3DCOLOR endCol, D3DCOLOR BorderColor, gr_orientation orientation, LPDIRECT3DDEVICE9 pDevice)
{
	static struct D3DVERTEX
	{
		float x, y, z, rhw; DWORD color;
	}
	vertices[4] = { { 0, 0, 0, 1.0f, 0 }, { 0, 0, 0, 1.0f, 0 }, { 0, 0, 0, 1.0f, 0 }, { 0, 0, 0, 1.0f, 0 } };
	vertices[0].x = x;
	vertices[0].y = y;
	vertices[0].color = startCol;

	vertices[1].x = x + width;
	vertices[1].y = y;
	vertices[1].color = orientation == horizontal ? endCol : startCol;

	vertices[2].x = x;
	vertices[2].y = y + height;
	vertices[2].color = orientation == horizontal ? startCol : endCol;

	vertices[3].x = x + width;
	vertices[3].y = y + height;
	vertices[3].color = endCol;

	static LPDIRECT3DVERTEXBUFFER9 pVertexObject = NULL;
	static void *pVertexBuffer = NULL;

	if (FAILED(pDevice->CreateVertexBuffer(sizeof(vertices), 0,
		D3DFVF_XYZRHW | D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &pVertexObject, NULL)))
		return;

	if (FAILED(pVertexObject->Lock(0, sizeof(vertices), &pVertexBuffer, 0)))
		return;

	memcpy(pVertexBuffer, vertices, sizeof(vertices));
	pVertexObject->Unlock();

	pDevice->SetStreamSource(0, pVertexObject, 0, sizeof(D3DVERTEX));
	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	FillRGB(x - 1, y - 1, width + 1, 1, Black, pDevice);
	FillRGB(x - 1, y + height, width + 1, 1, Black, pDevice);

	FillRGB(x - 1, y - 1, 1, height + 1, Black, pDevice);
	FillRGB(x + width, y - 1, 1, height + 1, Black, pDevice);
}


void DrawTabButton(int x, int y, int &var, char* text, LPDIRECT3DDEVICE9 pDevice)
{
	INT Check = CheckTabs(x, y, 55, 18);
	DWORD ColorText = White;
	DWORD ColorBox;

	Degrade(x, y, 55, 18, Cinza, Cinza2, Black, gr_orientation::vertical, pDevice);

	if (Check == 1)
	{
		Beep(3, 5);
		Tab[1] = Tab[2] = Tab[3] = Tab[4] = Tab[5] = Tab[6] = Tab[7] = Tab[8] = 0;
		var = !var;
	}

	if (var)
	{
		ColorBox = bBlue;
	}
	else
	{
		ColorBox = Black;
	}

	DrawBox(x, y - 3, 55, 3, ColorBox, Menu, pDevice);
	PrintShadowedText(pFont, x + 5, y + 2, ColorText, Cinza, 1, 1, text);
}

void DrawTabButton2(int x, int y, int &var, char* text, LPDIRECT3DDEVICE9 pDevice)
{
	INT Check = CheckTabs(x, y, 28, 18);
	DWORD ColorText = White;
	DWORD ColorBox;

	Degrade(x, y, 28, 18, Cinza, Cinza2, Black, gr_orientation::vertical, pDevice);

	if (Check == 1)
	{
		Beep(3, 5);
		Tab[1] = Tab[2] = Tab[3] = Tab[4] = Tab[5] = Tab[6] = Tab[7] = Tab[8] = 0;
		var = !var;
	}

	if (var)
	{
		ColorBox = bBlue;
	}
	else
	{
		ColorBox = Black;
	}

	DrawBox(x, y - 3, 29, 3, ColorBox, Menu, pDevice);
	PrintShadowedText(pFont, x + 5, y + 2, ColorText, Cinza, 1, 1, text);
}

void DoubleCheck(int x, int y, int &Var, char* BText, D3DCOLOR Button, D3DCOLOR Text, LPDIRECT3DDEVICE9 pDevice)
{
	if (IsInBox(x, y, 150, 14))
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 1)
		{
			Var = !Var;
			Beep(3, 5);
		}
	}
	if (Var == 0)
	{
		//Button = Red;
		Text = bBlue;
	}

	if (Var == 1)
	{
		Button = bBlue;
		Text = bBlue;
	}

	if (Var>0)
	{
		FillRGB(x + 36, y + 4, 6, 6, Button, pDevice);
	}
	else
	{
		//FillRGB(x + 3, y + 3, 6, 6, Button, pDevice);
	}
	DrawBorder(x + 33, y + 1, 12, 12, 1, White, pDevice);
	PrintShadowedText(pFont, x + 50, y, Text, Cinza, 1, 1, BText);
}



#define c1 /*Padrao*/ Dencrypt("Tehves")
#define c2 /*Viper*/ Dencrypt("Zmtiv")
#define c3 /*Hawk*/ Dencrypt("Le{o")
#define c4 /*Deckland*/ Dencrypt("Higoperh")
#define c6 /*Crusher*/ Dencrypt("Gvywliv")
#define c7 /*Striker*/ Dencrypt("Wxvmoiv")
#define c8 /*N500AP*/ Dencrypt("R944ET")
#define c9 /*Astronauta*/ Dencrypt("Ewxvsreyxe")

#define w1 /*ATurret*/ Dencrypt("EXyvvix")
#define w2 /*FirstAid*/ Dencrypt("JmvwxEmh")
#define w3 /*Minigun*/ Dencrypt("Qmrmkyr")
#define w4 /*LChamas*/ Dencrypt("PGleqew")
#define w5 /*ScarLB*/ Dencrypt("WgevPF")
#define w6 /*LifeTaker*/ Dencrypt("PmjiXeoiv")
#define w7 /*AK-103*/ Dencrypt("EO1547")
#define w8 /*M417*/ Dencrypt("Q85;")
#define w9 /*UNK_SMG*/ Dencrypt("YROcWQK")
#define w10 /*ScarLT*/ Dencrypt("WgevPX")
#define w11 /*HostHands*/ Dencrypt("LswxLerhw")
#define w12 /*L96A1*/ Dencrypt("P=:E5")
#define w13 /*M69HE_NL*/ Dencrypt("Q:=LI")
#define w14 /*M67_Pack*/ Dencrypt("Q:;cTego")
#define w15 /*DScorpion*/ Dencrypt("HWgsvtmsr")
#define w16 /*Napalm*/ Dencrypt("Retepq")
#define w17 /*P90CBS*/ Dencrypt("T=4GFW")
#define w18 /*Hornet*/ Dencrypt("Lsvrix")
#define w19 /*PP19-S*/ Dencrypt("TT5=1W")
#define w20 /*GTurret*/ Dencrypt("KXyvvix")
#define w21 /*LAW*/ Dencrypt("PE[")
#define w22 /*M416*/ Dencrypt("Q85:")
#define n1 /*itz*/ Dencrypt("mx~")
#define n2 /*GM*/ Dencrypt("KQ")

int MenuItem[100];
int MenuFolder[100];
char * Opt_OnOff[] = { fi, o1 };
char * Opt_WeaponSet[] = { fi, m3, cab };
char * Opt_Char[] = { fi, c1, c2, c3, c4, spy, c6, c7, c8, c9 };
char * Opt_Folder[] = { adc, sub }; 
char * Opt_Armas[] = { fi, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16, w17, w18, w19, w20, w21, w22 };
char * Opt_nome[] = { fi, n1, n2 };
char * Opt_ang[] = { fi, "35", "65", "95"  };

void Itens()
{
	/*Current = 1;
	Folder(STRING_FOLDER1, Opt_Folder, MenuFolder[0], 2);
	if (MenuFolder[0])
	{
		Item(STRING_ITEM3,  Opt_OnOff, MenuItem[3], 2);
		Item(STRING_ITEM4,  Opt_OnOff, MenuItem[4], 2);
		Item(STRING_ITEM5,  Opt_OnOff, MenuItem[5], 2);
		Item(STRING_ITEM6,  Opt_OnOff, MenuItem[6], 2);
		Item(STRING_ITEM7,  Opt_OnOff, MenuItem[7], 2);
		Item(STRING_ITEM20, Opt_OnOff, MenuItem[20], 2);
		Item(STRING_ITEM21, Opt_OnOff, MenuItem[21], 2);
		Item(STRING_ITEM22, Opt_OnOff, MenuItem[22], 2);
		Item(STRING_ITEM25, Opt_OnOff, MenuItem[25], 2);
		Item(STRING_ITEM26, Opt_OnOff, MenuItem[26], 2);
		Item(STRING_ITEM29, Opt_OnOff, MenuItem[29], 2);
		Item(STRING_ITEM30, Opt_OnOff, MenuItem[30], 2);
	}

	Folder(STRING_FOLDER2, Opt_Folder, MenuFolder[1], 2);
	if (MenuFolder[1])
	{
		Item(STRING_ITEM9,  Opt_OnOff, MenuItem[10], 2);
		Item(STRING_ITEM10, Opt_Armas, MenuItem[11], 15);
		Item(STRING_ITEM11, Opt_Armas, MenuItem[12], 15);
		Item(STRING_ITEM12, Opt_Armas, MenuItem[13], 15);
		Item(STRING_ITEM13, Opt_Armas, MenuItem[14], 15);
	}

	Folder(STRING_FOLDER3, Opt_Folder, MenuFolder[2], 2);
	if (MenuFolder[2])
	{
	Item(STRING_ITEM8,  Opt_OnOff, MenuItem[8],  2);
	Item(STRING_ITEM14, Opt_Char,  MenuItem[15], 9);
	Item(STRING_ITEM27, Opt_OnOff, MenuItem[27], 2);
	Item(STRING_ITEM28, Opt_nome,  MenuItem[28], 3);
	}

	Folder(STRING_FOLDER4, Opt_Folder, MenuFolder[3], 2);
	if (MenuFolder[3])
	{
		Item(STRING_ITEM23, Opt_OnOff, save, 2);
		Item(STRING_ITEM24, Opt_OnOff, load, 2);
		Item(STRING_ITEM16, Opt_OnOff, MenuItem[17], 2);
	}*/

}


void Navigation()
{

	if (Menu && pFont)
	{
		if (GetAsyncKeyState(VK_DOWN) & 1)
			MenuSelection++;
		if (GetAsyncKeyState(VK_UP) & 1)
			MenuSelection--;

		Itens();

		if (MenuSelection >qntHacks - 1)
			MenuSelection = 0;
		if (MenuSelection < 0)
			MenuSelection = qntHacks - 1;
	}
}

void MenuSettings()
{
	menux = 20;
	menuy = 25;
	mxofs = 180;
	qntHacks = 0;
}


