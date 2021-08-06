#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Player.hpp"

class Ball: public Entity
{
public:
    Ball();
    Ball(SDL_Texture* pTexture);

    void reInit();

    void setVel(Vector2f vel);

    void update(Player* p1, Player* p2);

    bool isOnScreen() const;
    void setOnScreen(bool onScreen);
private:
    Vector2f mVelocity;
    bool mDirectionLeft;
    bool mDirectionUp;
    bool mOnScreen;
};
