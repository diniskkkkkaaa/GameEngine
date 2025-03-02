#pragma once
#include <d3d11.h>

class SwapChain {
public:
    SwapChain() = default;
    ~SwapChain() = default;

    bool Init(HWND hwnd, UINT width, UINT height); // Initialize SwapChain for a window with its width and height
    bool Release(); // Release the SwapChain

private:
    IDXGISwapChain * m_swap_chain; // Creating pointer to the DXGI interface
};
