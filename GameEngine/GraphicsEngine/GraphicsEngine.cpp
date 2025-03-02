#include "GraphicsEngine.h"
#include "../SwapChain/SwapChain.h"

bool GraphicsEngine::Init() {
    D3D_DRIVER_TYPE driverTypes[] = {
    D3D_DRIVER_TYPE_HARDWARE,
    D3D_DRIVER_TYPE_WARP,
    D3D_DRIVER_TYPE_REFERENCE
    }; // GPU driver, CPU driver, Bad driver

    D3D_FEATURE_LEVEL featureLevel[] = {
        D3D_FEATURE_LEVEL_11_0
    };

    UINT num_driver_types = ARRAYSIZE(driverTypes);
    UINT num_features = ARRAYSIZE(featureLevel);
    HRESULT res=0;

    for (UINT driver_type_index = 0; driver_type_index < num_driver_types; driver_type_index++) {
        res = D3D11CreateDevice(NULL, driverTypes[driver_type_index], NULL, NULL, featureLevel, num_features,
                                D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_inn_context);
        if (SUCCEEDED(res))
            break;
    }
    if (FAILED(res))
        return false;

    m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
    m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
    m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);



    return true;
}

bool GraphicsEngine::Release() {

    m_dxgi_device->Release();
    m_dxgi_adapter->Release();
    m_dxgi_factory->Release();


    m_inn_context->Release();
    m_d3d_device->Release();
    return true;
}

GraphicsEngine * GraphicsEngine::Get() {
    static GraphicsEngine engine;
    return &engine;
}

SwapChain * GraphicsEngine::createSwapChain() {
    return new SwapChain();
}
