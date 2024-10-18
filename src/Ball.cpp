// Ball.cpp

#include <cmath>

#include "Ball.hpp"
#include "Util.hpp"

Ball::Ball(Vector2i position, int radius)
    : mPosition(position), mRadius(radius)
{
    mVelocity = Vector2i(util::RandomInt(1, 4), util::RandomInt(1, 4));
    mColor = ColorU8();
}

Ball::~Ball()
{

}

// https://discourse.libsdl.org/t/query-how-do-you-draw-a-circle-in-sdl2-sdl2/33379
void Ball::Render(SDL_Renderer* renderer)
{
    int dx = 0, dy = mRadius - 1;
    while (dy >= dx) {
        SDL_SetRenderDrawColor(renderer, mColor.Red, mColor.Green, mColor.Blue,mColor.Alpha);
        
        SDL_RenderDrawPoint(renderer, mPosition.x + dx, mPosition.y + dy);
	SDL_RenderDrawPoint(renderer, mPosition.x - dx, mPosition.y + dy);
	SDL_RenderDrawPoint(renderer, mPosition.x + dx, mPosition.y - dy);
	SDL_RenderDrawPoint(renderer, mPosition.x - dx, mPosition.y - dy);
	SDL_RenderDrawPoint(renderer, mPosition.x + dy, mPosition.y + dx);
	SDL_RenderDrawPoint(renderer, mPosition.x - dy, mPosition.y + dx);
	SDL_RenderDrawPoint(renderer, mPosition.x + dy, mPosition.y - dx);
	SDL_RenderDrawPoint(renderer, mPosition.x - dy, mPosition.y - dx);
        
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    
        dx++;
	dy = sqrt(mRadius * mRadius - dx * dx);
    }
}

void Ball::Update(Vector2i bounds)
{
    mPosition.x += mVelocity.x;
    mPosition.y += mVelocity.y;

    if (mPosition.x >= bounds.x - mRadius - 2) mVelocity.x = -mVelocity.x;
    if (mPosition.x <= mRadius + 1) mVelocity.x = -mVelocity.x;
    if (mPosition.y >= bounds.y - mRadius - 2) mVelocity.y = -mVelocity.y;
    if (mPosition.y <= mRadius + 1) mVelocity.y = -mVelocity.y;
}

bool Ball::HandleCollision(const Ball& b)
{
    int totalRadiusSquared = mRadius + b.mRadius;
    totalRadiusSquared *= totalRadiusSquared;
	
    int deltaX = b.mPosition.x - mPosition.x;
    int deltaY = b.mPosition.y - mPosition.y;

    int distanceSquared = deltaX * deltaX + deltaY * deltaY;

    if (distanceSquared <= totalRadiusSquared) {
	mVelocity.x = -mVelocity.x;
	mVelocity.y = -mVelocity.y;
		
	// @todo(ame): fix weird inter-collision bug when balls are pushed into one another
	// mPosition.x += (b.mRadius / 2) * mVelocity.x;
	return true;
    }
    return false;
}
