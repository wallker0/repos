/*
Name: JustBasics D3D11 Menu 
Version: 0.1
Date: 01-01-14
*On/Off  (Colored)
*Folder 
*Keyboard control (Insert = Hide/Show | Arrowkeys for select)
*Using FW1FontWrapper for Font

Crediting:
*JustBasics (Menu Files)
*evolution536 (For his D3D11 Hook)
*UC-Forums 
*FW1FontWrapper
*/

#pragma once
#include <d3d11.h>
//#pragma comment(lib, "FW1FontWrapper.lib")
#include "fw1\FW1FontWrapper\Source\FW1FontWrapper.h"
//#include "natives.h"

#define MAX_ITEMS 25

#define T_FOLDER 1
#define T_OPTION 2
#define T_SET 3

#define LineH 15

/*#define IMPORT __declspec(dllimport)

IMPORT void nativeInit(UINT64 hash);
IMPORT void nativePush64(UINT64 val);
IMPORT PUINT64 nativeCall();*/

struct Options{
	LPCWSTR Name;
	int	*Function;
	BYTE Type;
};


struct Menu{
	LPCWSTR Title;
	int x;
	int y;
	int w;
};



class JBMenu
{
public:
	JBMenu(void);
	void Init_Menu(IFW1FontWrapper *pFont,ID3D11DeviceContext *pContext,LPCWSTR Title,int x,int y);
	void DrawText(LPCWSTR text,int FontSize,int x, int y,DWORD_PTR Col);


	void Draw_Menu();
	void Navigation();
	void AddFolder(LPCWSTR Name,int *Pointer);
	void AddOption(LPCWSTR Name,int *Pointer,int *Folder);
	void AddSet(LPCWSTR Name, int *Pointer, int *Folder);

	bool IsReady();

	DWORD_PTR Color_Font; 
	DWORD_PTR Color_On;
	DWORD_PTR Color_Off;
	DWORD_PTR Color_Folder;
	DWORD_PTR Color_Current;

private:
	ID3D11DeviceContext *pContext;
	IFW1FontWrapper *pFont;

	bool Is_Ready,Visible;
	int Items,Cur_Pos;


	Options sOptions[MAX_ITEMS];
	Menu sMenu;
	
};

