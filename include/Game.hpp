#pragma once
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "World.hpp"

class Game
{
public:
    Game(RenderWindow* pWindow, std::map<const char*, SDL_Texture*>* pTextures);
    void logic();
    void loop();
    ~Game();

private:
    RenderWindow* mpWindow;
    std::map<const char*, SDL_Texture*>* mpTextures;
    SDL_Event mEvent;
    World* mpWorld;
    bool mQuit;
};
