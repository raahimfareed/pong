#pragma once

#include "Entity.hpp"

class Player: public Entity
{
public:
    Player();
    Player(SDL_Texture* pTexture, SDL_Rect currentFrame, Vector2f position = Vector2f(), Vector2f dimensions = Vector2f(16, 16));

    void up();
    void down();
    void stop();
    void update();

private:
    float mVelocity;
};
