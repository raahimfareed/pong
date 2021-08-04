#include "Game.hpp"

Game::Game(RenderWindow* pWindow, std::map<const char*, SDL_Texture*>* pTextures)
    :mpWindow(pWindow), mpTextures(pTextures), mQuit(false)
{}

void Game::logic()
{
    //
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
