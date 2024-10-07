// App.cpp

#include "App.hpp"

App::App()
{
    mWindow = std::make_unique<Window>(WIDTH, HEIGHT, "Encapsulation | Amelie Heinrich");

    for (int i = 0; i < BALL_COUNT; i++) {
        AddRandomBall();
    }
}

void App::Run()
{
    while (mWindow->IsOpen()) {
        uint32_t start_time = SDL_GetTicks();

        mWindow->PollEvent();
        mWindow->Begin();

        RenderBalls();
        RenderOverlay();
        RenderBallEditor();

        mWindow->Present();

        float frame_time = SDL_GetTicks() - start_time;
        mFPS = (frame_time > 0) ? 1000.0f / frame_time : 0.0f;
    }
}

void App::RenderBalls()
{
    for (int i = 0; i < mBalls.size(); i++) {
        for (int j = 0; j < mBalls.size(); j++) {
            if (i != j) {
                mBalls[i].HandleCollision(mBalls[j]);
                mBalls[j].HandleCollision(mBalls[i]);
            }
        }

        mBalls[i].Update(Vector2i(WIDTH, HEIGHT));
        mBalls[i].Render(mWindow->GetRenderer());
    }
}

void App::RenderOverlay()
{
    static bool p_open = true;

    ImGuiIO& io = ImGui::GetIO();
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
    const float PAD = 10.0f;
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 work_pos = viewport->WorkPos;
    ImVec2 work_size = viewport->WorkSize;
    ImVec2 window_pos, window_pos_pivot;
    window_pos.x = (work_pos.x + PAD);
    window_pos.y = (work_pos.y + PAD);
    window_pos_pivot.x = 0.0f;
    window_pos_pivot.y = 0.0f;
    ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
    window_flags |= ImGuiWindowFlags_NoMove;

    ImGui::SetNextWindowBgAlpha(0.70f);
    ImGui::Begin("Example: Simple overlay", &p_open, window_flags);
    ImGui::Text("Encapsulation Project by Amélie Heinrich");
    ImGui::Text("FPS: %d", mFPS);
    ImGui::Text("Ball Editor: F1");
    ImGui::End();
}

void App::RenderBallEditor()
{
    if (mBallEditor) {
        ImGui::Begin("Ball Editor");
        ImGui::Text("Ball Count: %d", mBalls.size());
        if (ImGui::Button("Add Ball")) {
            AddRandomBall();
        }
        
        ImGui::Separator();

        for (int i = 0; i < mBalls.size(); i++) {
            Ball& ball = mBalls[i];
            std::string nodeName = "Ball " + std::to_string(i);
            if (ImGui::TreeNodeEx(nodeName.c_str())) {
                float color[3] = { ball.GetColor().Red / 255.0f, ball.GetColor().Green / 255.0f, ball.GetColor().Blue / 255.0f };
                ImGui::ColorPicker3("Ball Color", color);
                ball.SetColor(ColorU8(color[0] * 255, color[1] * 255, color[2] * 255, 255));
                int r = ball.GetRadius();
                ImGui::SliderInt("Radius", &r, 5, 20);
                ball.SetRadius(r);
                ImGui::TreePop();
            }
        }

        ImGui::End();
    }

    if (ImGui::IsKeyPressed(ImGuiKey_F1)) {
        mBallEditor = !mBallEditor;
    }
}

void App::AddRandomBall()
{
    int r = util::RandomInt(5, 10);
    int x = util::RandomInt(0 + r, WIDTH - r);
    int y = util::RandomInt(0 + r, HEIGHT - r);

    int red = util::RandomInt(100, 255);
    int green = util::RandomInt(100, 255);
    int blue = util::RandomInt(100, 255);

    Ball ball(Vector2i(x, y), r);
    ball.SetColor(ColorU8(red, green, blue, 255));

    mBalls.push_back(ball);
}
