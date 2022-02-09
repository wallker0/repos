#include "JBMenu.h"

JBMenu::JBMenu(void){
	this->Visible = false;
}


void JBMenu::Init_Menu(IFW1FontWrapper *pFont, ID3D11DeviceContext *pContext, LPCWSTR Title, int x, int y){
	this->pContext = pContext;
	this->pFont = pFont;
	this->Is_Ready = true;
	this->sMenu.Title = Title;
	this->sMenu.x = x;
	this->sMenu.y = y;
}


void JBMenu::AddFolder(LPCWSTR Name, int *Pointer){
	sOptions[this->Items].Name = (LPCWSTR)Name;
	sOptions[this->Items].Function = Pointer;
	sOptions[this->Items].Type = T_FOLDER;
	this->Items++;
}

void JBMenu::AddOption(LPCWSTR Name, int *Pointer, int *Folder){
	if (*Folder == 0)
		return;
	sOptions[this->Items].Name = Name;
	sOptions[this->Items].Function = Pointer;
	sOptions[this->Items].Type = T_OPTION;
	this->Items++;
}

void JBMenu::AddSet(LPCWSTR Name, int *Pointer, int *Folder){
	if (*Folder == 0)
		return;
	sOptions[this->Items].Name = Name;
	sOptions[this->Items].Function = Pointer;
	sOptions[this->Items].Type = T_SET;
	this->Items++;
}

void JBMenu::Navigation(){

	if (GetAsyncKeyState(VK_F12) & 1)
		this->Visible = !this->Visible;

	if (!this->Visible)
		return;

	int value = 0;

	if (GetAsyncKeyState(VK_DOWN) & 1){
		this->Cur_Pos++;
		if (sOptions[this->Cur_Pos].Name == 0)
			this->Cur_Pos--;
	}

	if (GetAsyncKeyState(VK_UP) & 1){
		this->Cur_Pos--;
		if (this->Cur_Pos == -1)
			this->Cur_Pos++;
	}

	else if (GetAsyncKeyState(VK_RIGHT) & 1){
		if (sOptions[this->Cur_Pos].Type == T_OPTION || sOptions[this->Cur_Pos].Type == T_FOLDER) {
			if (*sOptions[this->Cur_Pos].Function == 0)
				value++;
		}
	}

	else if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
		if (sOptions[this->Cur_Pos].Type == T_SET){
			Beep(1000, 1);
		}
	}

	else if ((GetAsyncKeyState(VK_LEFT) & 1) && *sOptions[this->Cur_Pos].Function == 1){
		if (sOptions[this->Cur_Pos].Type == T_OPTION || sOptions[this->Cur_Pos].Type == T_FOLDER) {
				value--;
		}
	}


	if (value) {
		*sOptions[this->Cur_Pos].Function += value;
		if (sOptions[this->Cur_Pos].Type == T_FOLDER){
			memset(&sOptions, 0, sizeof(sOptions));
			this->Items = 0;
		}
	}


}



void JBMenu::Draw_Menu()
{
	if (!this->Visible)
		return;

	this->DrawText(this->sMenu.Title, 14, sMenu.x + 10, sMenu.y, this->Color_Font);
	for (int i = 0; i < this->Items; i++){
		if (this->sOptions[i].Type == T_OPTION){
			if (*this->sOptions[i].Function){
				this->DrawText(L"On", 12, sMenu.x + 150, sMenu.y + LineH*(i + 2), this->Color_On);
			}
			else {
				this->DrawText(L"Off", 12, sMenu.x + 150, sMenu.y + LineH*(i + 2), this->Color_Off);
			}
		}
		if (this->sOptions[i].Type == T_SET){
		}
		if (this->sOptions[i].Type == T_FOLDER){
			if (*this->sOptions[i].Function){
				this->DrawText(L"Open", 12, sMenu.x + 150, sMenu.y + LineH*(i + 2), this->Color_Folder);
			}
			else {
				this->DrawText(L"Closed", 12, sMenu.x + 150, sMenu.y + LineH*(i + 2), this->Color_Folder);
			}
		}
		DWORD_PTR Color = this->Color_Font;
		if (this->Cur_Pos == i)
			Color = this->Color_Current;
		this->DrawText(this->sOptions[i].Name, 12, sMenu.x + 5, sMenu.y + LineH*(i + 2), Color);

	}
}
bool JBMenu::IsReady()
{
	if (this->Items)
		return true;
	return false;
}

void JBMenu::DrawText(LPCWSTR text, int FontSize, int x, int y, DWORD_PTR Col)
{
	if (this->Is_Ready == false)
		MessageBoxA(0, "Error, you dont initialize the menu!", "Error", MB_OK);

	pFont->DrawString(pContext, text, (float)FontSize, (float)x, (float)y,
		Col, FW1_RESTORESTATE);
}
