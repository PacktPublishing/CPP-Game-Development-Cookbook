//Library Includes
#include <windows.h>
#include <windowsx.h>

//Local Includes
#include "Game.h"
#include "Clock.h"
#include "Utilities.h"

#define WINDOW_CLASS_NAME L"IGFRAMEWORK"

LRESULT CALLBACK
WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_uiMsg)
	{
	case WM_DESTROY:
	{
					   PostQuitMessage(0);

					   return(0);
	}
		break;

	default:break;
	}

	return (DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam));
}

HWND
CreateAndRegisterWindow(HINSTANCE _hInstance, int _iWidth, int _iHeight, LPCWSTR _pcTitle)
{
	WNDCLASSEX winclass;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = static_cast<HBRUSH> (GetStockObject(NULL_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winclass))
	{
		// Failed to register.
		return (0);
	}

	HWND hwnd;
	hwnd = CreateWindowEx(NULL,
		WINDOW_CLASS_NAME,
		_pcTitle,
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		_iWidth, _iHeight,
		NULL,
		NULL,
		_hInstance,
		NULL);

	if (!hwnd)
	{
		// Failed to create.
		return (0);
	}

	return (hwnd);
}

int WINAPI
WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdline, int _iCmdshow)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	const int kiWidth = 400;
	const int kiHeight = 400;

	HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"My first sprite Game");

	CGame& rGame = CGame::GetInstance();

	if (!rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight))
	{
		// Failed
		return (0);
	}

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			rGame.ExecuteOneFrame();
		}
	}

	CGame::DestroyInstance();

	return (static_cast<int>(msg.wParam));
}
