#pragma once
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Player.hpp"

class World
{
public:
    World(std::map<const char*, SDL_Texture*>* pTextures);

    Player& rGetLeftPlayer();
    Player& rGetRightPlayer();

private:
    std::map<const char*, SDL_Texture*>* mpTextures;
    Player mLeftPlayer;
    Player mRightPlayer;
};
