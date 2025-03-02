#include "Window.h"

Window* window=nullptr;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
           // Event fired when the window will be created
           window->setHWND(hwnd);
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
    WNDCLASSEX wc; // Setting up WNDCLASSEX object
    wc.cbClsExtra = NULL; // Additional memory space for the class
    wc.cbSize = sizeof(WNDCLASSEX); // Size of the structure
    wc.cbWndExtra = NULL; // Additional memory space for the window
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND; // Specifies the background brush (set to a system color)
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Defines the cursor style (set to an arrow cursor).
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Specifies icons for the window (set to default application icon).
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // Specifies icons for the window (set to default application icon).
    wc.hInstance = NULL; // IDK
    wc.lpszClassName = "WindowClass"; // Name of the window class "WindowClass"
    wc.lpszMenuName = ""; // Specifies the menu name (set to an empty string, meaning no menu)
    wc.style = NULL; // IDK
    wc.lpfnWndProc = &WndProc; // Pointer to the window procedure function (WndProc) to handle window messages

    // Registering the window class
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

RECT Window::getClientWindowRect() {
    RECT rc;
    GetClientRect(this->m_hwnd, &rc);
    return rc;
}

void Window::setHWND(HWND hwnd) {
    this->m_hwnd=hwnd;
}

bool Window::isRunning() {
    // Returning status of the window
    return m_isRunning;
}

void Window::onDestroy() {
    // Set this flag to false to indicate that the window is not running
    m_isRunning =false;
}