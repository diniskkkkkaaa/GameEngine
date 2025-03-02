cmake_minimum_required(VERSION 3.30)
project(GameEngine)

set(CMAKE_CXX_STANDARD 20)


add_executable(GameEngine App/main.cpp
        GameEngine/WindowingSystem/Window.cpp
        GameEngine/WindowingSystem/Window.h
        App/AppWindow.cpp
        App/AppWindow.h
        GameEngine/GraphicsEngine/GraphicsEngine.cpp
        GameEngine/GraphicsEngine/GraphicsEngine.h
        GameEngine/SwapChain/SwapChain.cpp
        GameEngine/SwapChain/SwapChain.h
        GameEngine/DeviceContext/DeviceContext.cpp
        GameEngine/DeviceContext/DeviceContext.h)

target_link_libraries(GameEngine d3d11.lib)