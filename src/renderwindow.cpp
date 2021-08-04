#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow()
    :mpWindow(nullptr), mpRenderer(nullptr), mBackgroundColor({0, 0, 0, 255})
{}

RenderWindow::RenderWindow(const char* title, int w, int h, SDL_Color bgColor)
    :mpWindow(nullptr), mpRenderer(nullptr), mBackgroundColor(bgColor)
{
    mpWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if (mpWindow == nullptr)
    {
        printf("[Error]: Failed to initialize window.\n[SDL Error]: %s\n", SDL_GetError());
    }

    mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mpRenderer == nullptr)
    {
        printf("[Error]: Failed to initialize renderer.\n[SDL Error]: %s\n", SDL_GetError());
    }
}

SDL_Texture* RenderWindow::pLoadTexture(const char* path)
{
    SDL_Texture* pTexture = nullptr;

    pTexture = IMG_LoadTexture(mpRenderer, path);

    if (pTexture == nullptr)
    {
        printf("[Error]: Failed to load the texture.\n[SDL Error]: %s\n", SDL_GetError());
    }

    return pTexture;

}

void RenderWindow::create(const char* title, int w, int h)
{
    mpWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if (mpWindow == nullptr)
    {
        printf("[Error]: Failed to initialize window.\n[SDL Error]: %s\n", SDL_GetError());
    }

    mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mpRenderer == nullptr)
    {
        printf("[Error]: Failed to initialize renderer.\n[SDL Error]: %s\n", SDL_GetError());
    }
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(mpRenderer, mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a);
    SDL_RenderClear(mpRenderer);
}

void RenderWindow::render(SDL_Texture* pTexture)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 16;
    src.h = 16;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 16;
    dst.h = 16;

    SDL_RenderCopy(mpRenderer, pTexture, &src, &dst);
}

void RenderWindow::render(Entity& rEntity)
{
    SDL_Rect src;
    src.x = rEntity.getCurrentFrame().x;
    src.y = rEntity.getCurrentFrame().y;
    src.w = rEntity.getCurrentFrame().w;
    src.h = rEntity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = rEntity.rGetPosition().mX;
    dst.y = rEntity.rGetPosition().mY;
    dst.w = rEntity.rGetDimensions().mX;
    dst.h = rEntity.rGetDimensions().mY;

    SDL_RenderCopy(mpRenderer, rEntity.pGetTexture(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(mpRenderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(mpWindow);
}

void RenderWindow::setBgColor(SDL_Color bgColor)
{
    mBackgroundColor = bgColor;
}

void RenderWindow::setBgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    mBackgroundColor = {r, g, b, a};
}
