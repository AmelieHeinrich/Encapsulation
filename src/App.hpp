// App.hpp

#pragma once

#include <vector>
#include <memory>
#include <imgui.h>

#include "Window.hpp"
#include "Ball.hpp"

constexpr int BALL_COUNT = 100;
constexpr int MAX_BALLS = 512;
constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

class App
{
public:
    App();
    ~App() = default;

    void Run();
private:
    void RenderBalls();
    void RenderOverlay();
    void RenderBallEditor();
    void AddRandomBall();

    std::unique_ptr<Window> mWindow;
    std::vector<Ball> mBalls;
    bool mBallEditor = false;
    int mFPS = 0;
};
