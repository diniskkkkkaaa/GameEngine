cmake_minimum_required(VERSION 3.30)
project(GameEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameEngine App/main.cpp
        Engine/Window.cpp
        Engine/Window.h
        App/AppWindow.cpp
        App/AppWindow.h)
