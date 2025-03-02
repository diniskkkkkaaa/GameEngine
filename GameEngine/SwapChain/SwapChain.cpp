#include "SwapChain.h"
#include "../GraphicsEngine/GraphicsEngine.h"

bool SwapChain::Init(HWND hwnd, UINT width, UINT height) {
    ID3D11Device* device = GraphicsEngine::Get()->m_d3d_device;

    DXGI_SWAP_CHAIN_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.BufferCount = 1;
    desc.BufferDesc.Width = width;
    desc.BufferDesc.Height = height;
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.BufferDesc.RefreshRate.Numerator = 60;
    desc.BufferDesc.RefreshRate.Denominator = 1;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.OutputWindow = hwnd;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Windowed = TRUE;

    // Create the swap chain for the window indicated by HWND parameter
    HRESULT res = GraphicsEngine::Get()->m_dxgi_factory->CreateSwapChain(device, &desc, &m_swap_chain);

    ID3D11Texture2D* back_buffer = NULL;
    if (FAILED(res))
        return false;

    res = m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&back_buffer);
    if (FAILED(res))
        return false;

    res = device->CreateRenderTargetView(back_buffer, NULL, &m_render_target_view);
    if (FAILED(res))
        return false;
    back_buffer->Release();

    return true;
}

bool SwapChain::Release() {
    m_swap_chain->Release();
    delete this;
    return true;
}

bool SwapChain::Present(bool vsync) {
    m_swap_chain->Present(vsync, NULL);
    return true;
}
