#pragma once

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#include <windows.h>

// Local Includes
#include "clock.h"

// Types

// Constants

// Prototypes
class CBackBuffer;

class CGame
{
	// Member Functions
public:
	~CGame();

	bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

	void Draw();
	void Process(float _fDeltaTick);

	void ExecuteOneFrame();

	CBackBuffer* GetBackBuffer();
	HINSTANCE GetAppInstance();
	HWND GetWindow();

	// Singleton Methods
	static CGame& GetInstance();
	static void DestroyInstance();

protected:

private:
	CGame();
	CGame(const CGame& _kr);
	CGame& operator= (const CGame& _kr);

	// Member Variables
public:

protected:
	CClock* m_pClock;

	CBackBuffer* m_pBackBuffer;

	//Application data
	HINSTANCE m_hApplicationInstance;
	HWND m_hMainWindow;

	// Singleton Instance
	static CGame* s_pGame;

private:

};

#endif    // __GAME_H__
