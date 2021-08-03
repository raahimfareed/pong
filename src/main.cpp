#include <cstdio>

#include <SDL2/SDL.h>

#include "RenderWindow.hpp"

RenderWindow gWindow;

bool init();

bool gQuit = !init();

int main(int argc, char* args[])
{
    SDL_Event event;

    SDL_Texture* pGhost = gWindow.pLoadTexture("./assets/ghost.png");

    while (!gQuit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    gQuit = true;
                    break;
            }
        }

        gWindow.clear();
        gWindow.render(pGhost);
        gWindow.display();
    }

    gWindow.cleanUp();
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

    return true;
}
