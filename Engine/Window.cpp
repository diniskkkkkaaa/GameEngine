#include "Window.h"

Window* window=nullptr;

Window::Window() {}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
           // Event fired when the window will be created
           window->onCreate();
           break;

        case WM_DESTROY:
            // Event fired when the window will be destroyed
            window->onDestroy();
            ::PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return NULL;
}
bool Window::Init() {
    // Setting up WNDCLASSEX object
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = "WindowClass";
    wc.lpszMenuName = "";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;

    if(!::RegisterClassEx(&wc))
        return false;

    if (!window)
        window = this;

    // Creating of the window
    m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "WindowClass", "Game", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

    // If the creating fail return false
    if (!m_hwnd)
        return false;

    // Show up the window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    // Set this flag to true to indicate that the window is initialized and running
    m_isRunning = true;
    return true;
}

bool Window::Broadcast() {
    MSG msg;

    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)>0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    window->onUpdate();
    Sleep(0);

    return true;
}


bool Window::Release() {
    // Destroy the window
    if (!::DestroyWindow(m_hwnd))
        return false;
    return true;
}

bool Window::isRunning() {
    return m_isRunning;
}

void Window::onDestroy() {
    // Set this flag to false to indicate that the window is not running
    m_isRunning =false;
}

Window::~Window() {}
