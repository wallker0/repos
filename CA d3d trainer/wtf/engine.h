#ifndef _ENGINE_
#define _ENGINE_

#pragma once

#include "Classes.h"

bool MyFilterObjects( int* hObj, void* pUser );
bool IntersectAndPenetrateSegment( IntersectQuery* iQuery, IntersectInfo* qInfo );

class cEngine
{
public:
	cEngine();

	bool ValidPointer( void* p )
	{ 
		return !IsBadReadPtr( p, 4 ) && p;
	}

	D3DXVECTOR3 MyGetObjectMaxPos( int* obj )
	{
		return *(D3DXVECTOR3*)( obj + 0x4 );
	}

	D3DXVECTOR3 MyGetObjectMinPos( int* obj )
	{
		return *(D3DXVECTOR3*)( obj + 0x10 );
	}

	D3DXVECTOR3 MyGetObjectRootPos( int* obj )
	{
		return *(D3DXVECTOR3*)( obj + 0xC8 );
	}

	DWORD MyGetObjectColorRGBA( int* obj )
	{
		return *(DWORD*)( obj + 0x94 );
	}

	DWORD MySetObjectColorRGBA( int* obj, DWORD dwColorRGBA )
	{
		*(DWORD*)( obj + 0x94 ) = dwColorRGBA;
	}

	c_player* GetPlayerByIndex( unsigned char index )
	{
		if( !ValidPointer( this ) || !ValidPointer( GetClientInfoMgr() ) )
			return NULL;

		c_player* player = GetClientInfoMgr()->GetClientByID( (int)index );

		if( !ValidPointer( player ) )
			return NULL;

		return player;
	}

	void InitFonts( void );

	bool ValidGamePointers( void );

	void InitEnginePointers( void );
	int GetFontHandle( int index );
	void WriteChat( const wchar_t* message );
	int GetConsoleInt( char* cmd, int value );
	bool __cdecl IsVisible( D3DXVECTOR3 Point );
	void SetCvar( DWORD CVarBase, float Value );
	void SetLocalPlayerPosition( D3DXVECTOR3 pos );
	DWORD BuildFontByFontIndex( int index, int FontSize );
	bool WorldToScreen( D3DXVECTOR3 Pos, D3DXVECTOR3 *Screen );
	void RenderString( int x, int y, CHAR* text, DWORD color );
	bool WINAPIV Original_IntersectSegment( IntersectQuery& iQuery, IntersectInfo *iInfo );

	//////////////////////////////////////////////////////////////////////////
	//							Class Pointers								//
	//////////////////////////////////////////////////////////////////////////

	cLTClientShellBase* GetClientShellBase()
	{
		return pClientShellBase;
	}

	cGameClientShell* GetGameClientShell()
	{
		return pGameClientShell;
	}

	cClientInfoMgr* GetClientInfoMgr()
	{
		return pClientInfoMgr;
	}

	cPlayerMgr* GetPlayerMgr()
	{
		return pPlayerManager;
	}

	cLTBase* GetLTBase()
	{
		return pLTBase;
	}

	cLTModel* GetLTModel()
	{
		return pLTModel;
	}

	cLTClient* GetLTClient()
	{
		return pLTClient;
	}

	cLTDrawPrim* GetLTDrawPrim()
	{
		return pLTDrawPrim;
	}

	LocalInfo* GetLocal()
	{
		return pLocal;
	}

	//////////////////////////////////////////////////////////////////////////
	//								Font Pointers							//
	//////////////////////////////////////////////////////////////////////////

 	cFont* GetSmallFont()
 	{
 		return pSmallFont;
 	}

	cFont* GetWarningFont()
	{
		return pWarningFont;
	}

	cFont* GetMenuFont()
	{
		return pMenuFont;
	}

private:

	//////////////////////////////////////////////////////////////////////////
	//																		//
	//////////////////////////////////////////////////////////////////////////

	cLTClientShellBase*	pClientShellBase;
	cGameClientShell*	pGameClientShell;
	cClientInfoMgr*		pClientInfoMgr;
	cPlayerMgr*			pPlayerManager;
	cLTDrawPrim*		pLTDrawPrim;
	cLTClient*			pLTClient;
	cLTModel*			pLTModel;
	cLTBase*			pLTBase;
	LocalInfo*			pLocal;

	cFont*				pWarningFont;
	cFont*				pSmallFont;
	cFont*				pMenuFont;

	DWORD				dwClientFxEntry;
};

extern class cEngine* engine;

#endif