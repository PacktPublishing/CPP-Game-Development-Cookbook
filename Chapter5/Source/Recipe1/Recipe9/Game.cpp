// Library Includes

// Local Includes
#include "Clock.h"
#include "Level.h"
#include "BackBuffer.h"
#include "Utilities.h"

// This Include
#include "Game.h"

// Static Variables
CGame* CGame::s_pGame = 0;

// Static Function Prototypes

// Implementation

CGame::CGame()
: m_pLevel(0)
, m_pClock(0)
, m_hApplicationInstance(0)
, m_hMainWindow(0)
, m_pBackBuffer(0)
{

}

CGame::~CGame()
{
	delete m_pLevel;
	m_pLevel = 0;

	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pClock;
	m_pClock = 0;
}

bool
CGame::Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight)
{
	m_hApplicationInstance = _hInstance;
	m_hMainWindow = _hWnd;

	m_pClock = new CClock();
	VALIDATE(m_pClock->Initialise());
	m_pClock->Process();

	m_pBackBuffer = new CBackBuffer();
	VALIDATE(m_pBackBuffer->Initialise(_hWnd, _iWidth, _iHeight));

	m_pLevel = new CLevel();
	VALIDATE(m_pLevel->Initialise(_iWidth, _iHeight));

	ShowCursor(false);

	return (true);
}

void
CGame::Draw()
{
	m_pBackBuffer->Clear();

	m_pLevel->Draw();

	m_pBackBuffer->Present();
}

void
CGame::Process(float _fDeltaTick)
{
	m_pLevel->Process(_fDeltaTick);
}

void
CGame::ExecuteOneFrame()
{
	float fDT = m_pClock->GetDeltaTick();

	Process(fDT);
	Draw();

	m_pClock->Process();

	Sleep(1);
}

CGame&
CGame::GetInstance()
{
	if (s_pGame == 0)
	{
		s_pGame = new CGame();
	}

	return (*s_pGame);
}

void
CGame::GameOverWon()
{
	MessageBox(m_hMainWindow, L"Winner!", L"Game Over", MB_OK);
	PostQuitMessage(0);
}

void
CGame::GameOverLost()
{
	MessageBox(m_hMainWindow, "Loser!", "Game Over", MB_OK);
	PostQuitMessage(0);
}

void
CGame::DestroyInstance()
{
	delete s_pGame;
	s_pGame = 0;
}

CBackBuffer*
CGame::GetBackBuffer()
{
	return (m_pBackBuffer);
}

CLevel*
CGame::GetLevel()
{
	return (m_pLevel);
}

HINSTANCE
CGame::GetAppInstance()
{
	return (m_hApplicationInstance);
}

HWND
CGame::GetWindow()
{
	return (m_hMainWindow);
}

