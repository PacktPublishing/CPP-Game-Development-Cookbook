#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _iCmdShow)
{
	MessageBox(NULL, L"My first message",
		L"My first Windows Program",
		MB_OK | MB_ICONEXCLAMATION);

	return (0);
}
