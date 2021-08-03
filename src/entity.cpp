#include "Entity.hpp"
#include "Math.hpp"

Entity::Entity()
    : mpTexture(nullptr), mCurrentFrame({0, 0, 0, 0}), mPosition(Vector2f()), mDimensions(Vector2f())
{}

Entity::Entity(SDL_Texture* pTexture, SDL_Rect currentFrame, Vector2f position, Vector2f dimensions)
    :mpTexture(pTexture), mCurrentFrame(currentFrame), mPosition(position), mDimensions(dimensions)
{}

Vector2f& Entity::rGetPosition()
{
    return mPosition;
}

Vector2f& Entity::rGetDimensions()
{
    return mDimensions;
}

SDL_Rect Entity::getCurrentFrame() const
{
    return mCurrentFrame;
}

SDL_Texture* Entity::pGetTexture() const
{
    return mpTexture;
}
