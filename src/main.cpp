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

void init();
void cleanUp();

int main(int argc, char* args[])
{
    init();

    gpGame->loop();

    cleanUp();
    return 0;
}

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        printf("[Error]: Failed to Initialize SDL.\n[SDL Error]: %s\n", SDL_GetError());
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        printf("[Error]: Failed to Initialize IMG.\n[IMG Error]: %s\n", IMG_GetError());
    }

    gWindow.create("TEH GAYM", 480, 272);

    gTextures["ghost"] = gWindow.pLoadTexture("./assets/ghost.png");

    gpGame = new Game(&gWindow, &gTextures);
}

void cleanUp()
{
    gWindow.cleanUp();
    delete gpGame;
    SDL_Quit();
}
