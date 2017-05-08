// A lot of this is copied from http://www.directxtutorial.com/

#include <Windows.h>
#include <windowsx.h>
#include <d3d9.h>

#pragma comment (lib, "d3d9.lib")

LPDIRECT3D9 d3d;
LPDIRECT3DDEVICE9 d3ddev;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void InitD3D(HWND hWnd);
void RenderFrame();
void CleanD3D();

static const int WINDOW_X = 200;
static const int WINDOW_Y = 200;
static const int WINDOW_WIDTH = 960;
static const int WINDOW_HEIGHT = 720;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass1";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(NULL, L"WindowClass1", L"MapViewer", WS_OVERLAPPEDWINDOW, WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	InitD3D(hWnd);

	ShowWindow(hWnd, nCmdShow);

	MSG msg;

	while (TRUE) {
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT) {
			break;
		}

		RenderFrame();
	}

	CleanD3D();

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void InitD3D(HWND hWnd) {
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;

	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
}

void RenderFrame() {
	static int currentValue = 0;
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(currentValue * 2 % 256, currentValue * 3 % 256, currentValue * 5 % 256), 1.0f, 0);

	++currentValue;

	d3ddev->BeginScene();

	d3ddev->EndScene();

	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void CleanD3D() {
	d3ddev->Release();
	d3d->Release();
}