#pragma once
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"
#include "World.hpp"

class Game
{
public:
    Game(RenderWindow* pWindow, std::map<const char*, SDL_Texture*>* pTextures, std::map<const char*, TTF_Font*>* pFonts);
    void logic();
    void loop();
    ~Game();

private:
    RenderWindow* mpWindow;
    std::map<const char*, SDL_Texture*>* mpTextures;
    std::map<const char*, TTF_Font*>* mpFonts;
    SDL_Event mEvent;
    World* mpWorld;
    bool mQuit;
    bool mMenu;
};
