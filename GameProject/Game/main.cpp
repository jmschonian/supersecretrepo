#include "pch.h"
#include "time.h"

bool gQuit;
HINSTANCE gInstanceHandle;
HWND gWindow;

int gWidth = 1280;
int gHeight = 720;

LRESULT WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	//ImGui_ImplDX12_WndProcHandler(hwnd, umessage, wparam, lparam);

	switch (umessage)
	{
	case WM_QUIT:
		gQuit = true;
		return 0;
	case WM_DESTROY:
		gQuit = true;
		return 0;
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
		//Input::Get().HandleInput(umessage, wparam, lparam);
		return 0;

	default:
		return DefWindowProc(hwnd, umessage, wparam, lparam); //Send to input handler
	}
}

void RegisterWindow()
{
	WNDCLASSEX window = {};

	gInstanceHandle = GetModuleHandle(nullptr);
	window.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	window.lpfnWndProc = WndProc;
	window.cbClsExtra = 0;
	window.cbWndExtra = 0;
	window.hInstance = gInstanceHandle;

	window.hCursor = LoadCursor(nullptr, IDC_ARROW);
	void* stock_object = GetStockObject(BLACK_BRUSH);
	window.hbrBackground = static_cast<HBRUSH>(stock_object);
	window.lpszMenuName = nullptr;
	window.lpszClassName = "Game";
	window.cbSize = sizeof(window);

	RegisterClassEx(&window);
}

void InitWindow()
{
	RegisterWindow();

#ifdef _DEBUG
	AllocConsole();
#endif

	FILE *f1 = stdout, *f2 = stderr;
	freopen_s(&f1, "CONOUT$", "wb", stdout);
	freopen_s(&f2, "CONOUT$", "wb", stderr);

	//Set window position
	DWORD window_style_ = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;
	RECT window_rect = { 0, 0, gWidth, gHeight };
	AdjustWindowRect(&window_rect, window_style_, false);
	int pos_x = (GetSystemMetrics(SM_CXSCREEN) - gWidth) / 2;
	int pos_y = (GetSystemMetrics(SM_CYSCREEN) - gHeight) / 2;

	//Create window
	gWindow = CreateWindowEx(WS_EX_APPWINDOW, "Game", "Game", window_style_,
		pos_x, pos_y, window_rect.right - window_rect.left, window_rect.bottom - window_rect.top,
		nullptr, nullptr, gInstanceHandle, nullptr);

	//Set focus
	ShowWindow(gWindow, SW_SHOW);
	SetForegroundWindow(gWindow);
	SetFocus(gWindow);
}

void Init()
{
	InitWindow();

	unsigned seed = (unsigned)time(nullptr);
	srand(seed);
}

int WINAPI WinMain(HINSTANCE hIstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	gQuit = false;
	MSG message;
	ZeroMemory(&message, sizeof(message));

	Init();

	while (!gQuit)
	{
		int msgCount = 0;
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE) && msgCount++ < 50000)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	return 0;
}