// Window.cpp^

#include "Window.hpp"

#include <iostream>
#include <imgui.h>
#include <imgui_impl_sdlrenderer2.h>
#include <imgui_impl_sdl2.h>

Window::Window(uint32_t width, uint32_t height, const std::string& title)
    : mWidth(width), mHeight(height)
{
    // TODO: Error handling?
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "[SDL] Failed to initialize SDL!" << std::endl;
        return;
    }

    // Create window
    mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!mWindow) {
        std::cout << "[SDL] Failed to create window!" << std::endl;
    }

    // Create renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mRenderer) {
        std::cout << "[SDL] Failed to create SDL renderer!" << std::endl;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImGui::StyleColorsClassic();

    ImGui_ImplSDL2_InitForSDLRenderer(mWindow, mRenderer);
    ImGui_ImplSDLRenderer2_Init(mRenderer);
    
    mOpen = true;
}

Window::~Window()
{
    if (mRenderer != nullptr) {
        SDL_DestroyRenderer(mRenderer);
    }
    if (mWindow != nullptr) {
        SDL_DestroyWindow(mWindow);
    }
    SDL_Quit();
}

void Window::PollEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                mOpen = false;
                break;
        }
    }
}

void Window::Begin()
{
    SDL_RenderClear(mRenderer);

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void Window::Present()
{
    ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::Render();
    SDL_RenderSetScale(mRenderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
    SDL_SetRenderDrawColor(mRenderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), mRenderer);
    
    SDL_UpdateWindowSurface(mWindow);
    SDL_RenderPresent(mRenderer);
}
