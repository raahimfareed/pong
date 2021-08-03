#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
    Entity();
    Entity(SDL_Texture* pTexture, SDL_Rect currentFrame, Vector2f position = Vector2f(), Vector2f dimensions = Vector2f(16, 16));

    Vector2f& rGetPosition();
    Vector2f& rGetDimensions();
    SDL_Rect getCurrentFrame() const;

protected:
    SDL_Texture* mpTexture;
    SDL_Rect mCurrentFrame;
    Vector2f mPosition;
    Vector2f mDimensions;
};
