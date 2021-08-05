#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "World.hpp"
#include "Player.hpp"
#include "Config.hpp"
#include "Ball.hpp"

World::World(std::map<const char*, SDL_Texture*>* pTextures)
    :mpTextures(pTextures)
{
    mLeftPlayer = Player(mpTextures->at("white-pixel"), {0, 0, 1, 1}, Vector2f(0, (Config::screenHeight / 2) - 35), Vector2f(5, 70));

    mRightPlayer = Player(mpTextures->at("white-pixel"), {0, 0, 1, 1}, Vector2f(Config::screenWidth - 5, (Config::screenHeight / 2) - 35), Vector2f(5, 70));

    mBall = Ball(mpTextures->at("ball"));
}

Player& World::rGetLeftPlayer()
{
    return mLeftPlayer;
}

Player& World::rGetRightPlayer()
{
    return mRightPlayer;
}

Ball& World::rGetBall()
{
    return mBall;
}

