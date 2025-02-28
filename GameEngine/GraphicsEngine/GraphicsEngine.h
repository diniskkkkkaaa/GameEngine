#pragma once
#include <d3d11.h>

class GraphicsEngine {
public:
    GraphicsEngine();
    // Initializing the GraphicsEngine and DirectX 11 device
    bool Init();
    // Release all the resource loaded
    bool Release();
    ~GraphicsEngine();

    static GraphicsEngine* Get();

private:
    ID3D11Device * m_d3d_device;
    D3D_FEATURE_LEVEL m_feature_level;
    ID3D11DeviceContext * m_inn_context;
};