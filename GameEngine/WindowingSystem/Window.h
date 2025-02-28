#pragma once
#include "Windows.h"

class Window {
public:
    Window();
    //Intialize the window
    bool Init();
    bool Broadcast();
    bool isRunning();
    //Release the window
    bool Release();

    //Events
    virtual void onCreate()=0;
    virtual void onUpdate()=0;
    virtual void onDestroy();

    ~Window();
protected:
    HWND m_hwnd;
    bool m_isRunning;
};