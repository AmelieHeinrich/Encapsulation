// Ball.hpp

#pragma once

#include <SDL.h>

#include "Util.hpp"

class Ball
{
public:
    Ball(Vector2i position, int radius);
    ~Ball();

    void Render(SDL_Renderer* renderer);
    void Update(Vector2i bounds);
    bool HandleCollision(const Ball& b);

    int GetRadius() { return mRadius; }
    void SetRadius(int radius) { mRadius = radius; } 

    void SetColor(ColorU8 color) { mColor = color; }
    ColorU8 GetColor() { return mColor; }
private:
    int mRadius = 0.0f;
    ColorU8 mColor;
    
    Vector2i mPosition;
    Vector2i mVelocity;
};
