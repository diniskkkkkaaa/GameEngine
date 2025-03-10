#include "DeviceContext.h"
#include "../SwapChain/SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* device_context):m_device_context(device_context)
{
}

bool DeviceContext::clearRenderTargetColor(SwapChain* swap_chain, float red, float green, float blue, float alpha)
{
    FLOAT clear_color[] = {red,green,blue,alpha};
    m_device_context->ClearRenderTargetView(swap_chain->m_render_target_view, clear_color);


    return true;
}


bool DeviceContext::Release()
{
    m_device_context->Release();
    delete this;
    return true;
}
