#include "AppWindow.h"

void AppWindow::onCreate() {
    GraphicsEngine::Get()->Init();
    m_swap_chain = GraphicsEngine::Get()->createSwapChain();

    RECT rc=this->getClientWindowRect();

    m_swap_chain->Init(this->m_hwnd,rc.right-rc.left,rc.bottom-rc.top);
}
void AppWindow::onUpdate() {

}
void AppWindow::onDestroy() {
    Window::onDestroy();
    m_swap_chain->Release();
    GraphicsEngine::Get()->Release();
}