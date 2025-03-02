#pragma once
#include "../GameEngine/WindowingSystem/Window.h"
#include "../GameEngine/GraphicsEngine/GraphicsEngine.h"
#include "../GameEngine/SwapChain/SwapChain.h"

class AppWindow: public Window{
public:
    AppWindow() = default;
    ~AppWindow() = default;

    virtual void onCreate() override; //Event after window creation
    virtual void onUpdate() override; //Event after window update
    virtual void onDestroy() override; //Event after window release
private:
    SwapChain * m_swap_chain; // SwapChain object
};
