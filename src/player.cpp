#include "Player.hpp"
#include "Config.hpp"

Player::Player() = default;

Player::Player(SDL_Texture* pTexture, SDL_Rect currentFrame, Vector2f position, Vector2f dimensions)
    : Entity(pTexture, currentFrame, position, dimensions), mVelocity(0.0f)
{}

void Player::up()
{
    mVelocity = -5.f;
}

void Player::down()
{
    mVelocity = 5.f;
}

void Player::stop()
{
    mVelocity = 0;
}

void Player::update()
{
    if (!(mPosition.mY + mVelocity > Config::screenHeight - mDimensions.mY) && mPosition.mY + mVelocity >= 0)
    {
        mPosition.mY += mVelocity;
    }
}
