#pragma once
#include <d3d11.h>
#include "../SwapChain/SwapChain.h"

class GraphicsEngine {
public:
    GraphicsEngine() = default;
    ~GraphicsEngine() = default;

    bool Init(); // Initializing the GraphicsEngine and DirectX 11 device
    bool Release(); // Release all the resource loaded

    static GraphicsEngine* Get(); // Creating pointer to engine
    SwapChain* createSwapChain(); // Creating pointer to SwapChain

private:
    ID3D11Device * m_d3d_device; // Pointer to the main device interface
    D3D_FEATURE_LEVEL m_feature_level; // Definition of the supported feature level of a Direct3D device.
    ID3D11DeviceContext * m_inn_context; // Pointer to the device context

    IDXGIDevice * m_dxgi_device; // Pointer to the DXGI device interface
    IDXGIAdapter * m_dxgi_adapter; // Pointer to the graphics adapter interface
    IDXGIFactory * m_dxgi_factory; // Pointer to the DXGI factory interface

    friend class SwapChain; // Creating SwapChain for engine
};