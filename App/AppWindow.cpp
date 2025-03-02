#include "AppWindow.h"

void AppWindow::onCreate() {
    //Window::onCreate();
    GraphicsEngine::Get()->Init();
    m_swap_chain = GraphicsEngine::Get()->createSwapChain();

    RECT rc = this->getClientWindowRect();

    m_swap_chain->Init(this->m_hwnd,rc.right-rc.left,rc.bottom-rc.top);
}
void AppWindow::onUpdate() {
    //Window::onUpdate();
    GraphicsEngine::Get()->getImmediateDeviceContext()->clearRenderTargetColor(m_swap_chain, 1.0f, 0.0f, 0.0f, 1.0f);
    m_swap_chain->Present(true);
}
void AppWindow::onDestroy() {
    Window::onDestroy();
    m_swap_chain->Release();
    GraphicsEngine::Get()->Release();
}