#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow();
    RenderWindow(const char* title, int w, int h, SDL_Color bgColor = {0, 0, 0, 255});

    SDL_Texture* pLoadTexture(const char* path);

    void create(const char* title, int w, int h);
    void clear();
    void render(SDL_Texture* pTexture);
    void render(Entity& rEntity);
    void display();
    void cleanUp();

    void setBgColor(SDL_Color bgColor);
    void setBgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    SDL_Window*& rpGetWindow();
    SDL_Renderer*& rpGetRenderer();
    SDL_Color getBgColor();

private:
    SDL_Window* mpWindow;
    SDL_Renderer* mpRenderer;
    SDL_Color mBackgroundColor;
};
