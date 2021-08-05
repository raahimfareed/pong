#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "RenderWindow.hpp"
#include "Input.hpp"
#include "World.hpp"

Game::Game(RenderWindow* pWindow, std::map<const char*, SDL_Texture*>* pTextures, std::map<const char*, TTF_Font*>* pFonts)
    :mpWindow(pWindow), mpTextures(pTextures), mpFonts(pFonts), mpWorld(nullptr), mQuit(false), mMenu(true)
{
    mpWorld = new World(mpTextures);
}

void Game::logic()
{
    if (Input::isPressed(SDLK_q))
    {
        mQuit = true;
    }

    if (Input::isPressed(SDLK_UP) || Input::isPressed(SDLK_DOWN))
    {
        if (Input::isPressed(SDLK_UP))
            mpWorld->rGetRightPlayer().up();

        if (Input::isPressed(SDLK_DOWN))
            mpWorld->rGetRightPlayer().down();
    }
    else
    {
        mpWorld->rGetRightPlayer().stop();
    }

    if (Input::isPressed(SDLK_w) || Input::isPressed(SDLK_s))
    {
        if (Input::isPressed(SDLK_w))
            mpWorld->rGetLeftPlayer().up();

        if (Input::isPressed(SDLK_s))
            mpWorld->rGetLeftPlayer().down();
    }
    else
    {
        mpWorld->rGetLeftPlayer().stop();
    }

    if (Input::isPressed(SDLK_RETURN) && mMenu)
    {
        mMenu = false;
    }

    mpWorld->rGetLeftPlayer().update();
    mpWorld->rGetRightPlayer().update();
    if (!mMenu)
    {
        mpWorld->rGetBall().update(&(mpWorld->rGetLeftPlayer()), &(mpWorld->rGetRightPlayer()));
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
        mpWindow->render(*mpWorld);
        if (mMenu)
        {
            mpWindow->renderCenter(Vector2f(0, -32.0f), "Press Return To Start", mpFonts->operator[]("VT323-32"), {255, 255, 255, 255});
        }
        mpWindow->display();
    }
}

Game::~Game()
{
    delete mpWorld;
    printf("Released game from heap\n");
}
