#include <cstdio>
#include <map>

#include <SDL2/SDL.h>

#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Entity.hpp"
#include "Game.hpp"

Game* gpGame;
RenderWindow gWindow;
std::map<const char*, SDL_Texture*> gTextures;

bool init();

bool gQuit = !init();

int main(int argc, char* args[])
{

    gpGame->loop();

    gWindow.cleanUp();
    delete gpGame;
    SDL_Quit();
    return 0;
}

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        printf("[Error]: Failed to Initialize SDL.\n[SDL Error]: %s\n", SDL_GetError());
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        printf("[Error]: Failed to Initialize IMG.\n[IMG Error]: %s\n", IMG_GetError());
        return false;
    }

    gWindow.create("TEH GAYM", 480, 272);

    gTextures["ghost"] = gWindow.pLoadTexture("./assets/ghost.png");

    gpGame = new Game(&gWindow, &gTextures);

    return true;
}
