#pragma once
#include "Windows.h"

class Window {
public:
    Window() = default;

    bool Init(); // Initialize the window
    bool Broadcast(); // Updating window
    bool isRunning(); // Check is window running
    bool Release(); //Release the window
    RECT getClientWindowRect(); // Gets the coordinates of the window
    void setHWND(HWND hwnd); // Setting window

    virtual void onCreate()=0; //Event after window creation
    virtual void onUpdate()=0; //Event after window update
    virtual void onDestroy(); //Event after window release

    ~Window() = default;
protected:
    HWND m_hwnd; // Window object
    bool m_isRunning; // The flag is window is running and doesn't release
};