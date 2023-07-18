#include "OGL3D/Window/Owindow.h"
#include<Windows.h>
#include<assert.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {

	case WM_DESTROY: {
		break;
	}








	default:
		return DefWindowProc(hwnd, msg,wParam,lParam);
	}
	return NULL;
}


OWindow::OWindow()
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"OGL3DWindow";
	wc.lpfnWndProc = &WndProc;

	assert(RegisterClassEx(&wc));


	RECT rc = { 0,0,1025,768 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,false);

	m_handle = CreateWindowEx(NULL, L"OGL3DWindow", L"Kali-yug | OPENGL 3D FPSEngine", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

	assert(m_handle);

	ShowWindow((HWND)m_handle,SW_SHOW);
	UpdateWindow((HWND)m_handle);

}

OWindow::~OWindow()
{
	DestroyWindow((HWND)m_handle);
}
