// Window.hpp

#pragma once

#include <cstdint>
#include <SDL.h>
#include <string>

class Window
{
public:
    Window(uint32_t width, uint32_t height, const std::string& title);
    ~Window();

    // poll event?
    bool IsOpen() const { return mOpen; }
    void PollEvent();

    void Begin();
    void Present();

    SDL_Renderer* GetRenderer() { return mRenderer; }
private:
    SDL_Window* mWindow = nullptr;
    SDL_Renderer* mRenderer = nullptr;

    uint32_t mWidth = 0;
    uint32_t mHeight = 0;
    bool mOpen = true;
};
