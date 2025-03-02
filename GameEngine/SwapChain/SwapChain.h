#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain {
public:
    SwapChain() = default;
    ~SwapChain() = default;

    bool Init(HWND hwnd, UINT width, UINT height); // Initialize SwapChain for a window with its width and height
    bool Release(); // Release the SwapChain
    bool Present(bool vsync); // Present the SwapChain

private:
    IDXGISwapChain * m_swap_chain; // Creating pointer to the DXGI interface
    ID3D11RenderTargetView * m_render_target_view; // Creating pointer to the render target view interface

    friend class DeviceContext; // Creating DeviceContext for SwapChain
};
