#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "RenderWindow.hpp"
#include "Input.hpp"

Game::Game(RenderWindow* pWindow, std::map<const char*, SDL_Texture*>* pTextures)
    :mpWindow(pWindow), mpTextures(pTextures), mQuit(false)
{}

void Game::logic()
{
    if (Input::isPressed(SDLK_q))
    {
        mQuit = true;
    }
}

void Game::loop()
{
    while (!mQuit)
    {
        while (SDL_PollEvent(&mEvent))
        {
            switch (mEvent.type)
            {
                case SDL_QUIT:
                    mQuit = true;
                    break;
                case SDL_KEYDOWN:
                    Input::handleKeyPress(mEvent);
                    break;
                case SDL_KEYUP:
                    Input::handleKeyRelease(mEvent);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    Input::handleMouseClick(mEvent);
                    break;
                case SDL_MOUSEBUTTONUP:
                    Input::handleMouseRelease(mEvent);
                    break;
            }
        }

        logic();

        mpWindow->clear();
        mpWindow->render(mpTextures->at("ghost"));
        mpWindow->display();
    }
}

Game::~Game()
{
    printf("Released game from heap\n");
}
