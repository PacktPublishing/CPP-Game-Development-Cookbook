// Library Includes

// Local Includes
#include "Clock.h"
#include "BackBuffer.h"
#include "Utilities.h"

// This Include
#include "Game.h"

// Static Variables
CGame* CGame::s_pGame = 0;

// Static Function Prototypes

// Implementation

CGame::CGame()
: m_pClock(0)
, m_hApplicationInstance(0)
, m_hMainWindow(0)
, m_pBackBuffer(0)
{

}

CGame::~CGame()
{
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

	ShowCursor(false);

	return (true);
}

void
CGame::Draw()
{
	m_pBackBuffer->Clear();

	// Do all the game’s drawing here...

	m_pBackBuffer->Present();
}

void
CGame::Process(float _fDeltaTick)
{
	// Process all the game’s logic here.
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
