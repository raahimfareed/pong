#include <cstdio>
#include <map>
#include <ctime>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Entity.hpp"
#include "Game.hpp"
#include "Config.hpp"

Game* gpGame;
RenderWindow gWindow;
std::map<const char*, SDL_Texture*> gTextures;
std::map<const char*, TTF_Font*> gFonts;

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
    srand((unsigned)time(0));

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        printf("[Error]: Failed to Initialize SDL.\n[SDL Error]: %s\n", SDL_GetError());
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        printf("[Error]: Failed to Initialize IMG.\n[IMG Error]: %s\n", IMG_GetError());
    }

    if (TTF_Init() == -1)
    {
        printf("[Error]: Failed to Initialize TTF.\n[TTF Error]: %s\n", TTF_GetError());
    }

    gWindow.create("TEH GAYM", Config::screenWidth, Config::screenHeight);

    gTextures["white-pixel"] = gWindow.pLoadTexture("./assets/white-pixel.png");
    gTextures["ball"] = gWindow.pLoadTexture("./assets/ball.png");

    gFonts["VT323-8"] = TTF_OpenFont("./assets/ttf/VT323-Regular.ttf", 8);
    gFonts["VT323-16"] = TTF_OpenFont("./assets/ttf/VT323-Regular.ttf", 16);
    gFonts["VT323-32"] = TTF_OpenFont("./assets/ttf/VT323-Regular.ttf", 32);

    gpGame = new Game(&gWindow, &gTextures, &gFonts);
}

void cleanUp()
{
    gWindow.cleanUp();
    delete gpGame;
    SDL_Quit();
}
