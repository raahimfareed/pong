#include <cmath>

#include "Ball.hpp"
#include "Config.hpp"
#include "Player.hpp"

Ball::Ball() = default;

Ball::Ball(SDL_Texture* pTexture)
    : mVelocity(1.f, 1.f), mOnScreen(true), mDirectionLeft(true), mDirectionUp(true)
{
    mpTexture = pTexture;
    mCurrentFrame = {0, 0, 8, 8};
    mPosition = Vector2f((Config::screenWidth / 2) - 4, (Config::screenHeight / 2) - 4);
    mDimensions = Vector2f(8, 8);
}

void Ball::reInit()
{
    mOnScreen = true;
    mPosition = Vector2f((Config::screenWidth / 2) - 4, (Config::screenHeight / 2) - 4);
}

void Ball::setVel(Vector2f vel)
{
    mVelocity = vel;
}

void Ball::update(Player* p1, Player* p2)
{
    if (mPosition.mX < -mDimensions.mX || mPosition.mX > Config::screenWidth || mPosition.mY < -mDimensions.mY || mPosition.mY > Config::screenHeight)
    {
        mOnScreen = false;
        return;
    }

    if (mPosition.mX - p1->rGetPosition().mX <= p1->rGetDimensions().mX + 1.0f &&
        mPosition.mY - p1->rGetPosition().mY <= p1->rGetDimensions().mY &&
        mPosition.mY - p1->rGetPosition().mY >= -7.f
        )
    {
        if (mDirectionLeft)
        {
            mDirectionLeft = false;
            mVelocity.mX += (rand() % 10) / 10.0f;
            mVelocity.mY = (rand() % 10) / 10.0f;
        }
    }

    if (p2->rGetPosition().mX - (mPosition.mX + (mDimensions.mX / 2.0f)) <= p2->rGetDimensions().mX &&
        mPosition.mY - p2->rGetPosition().mY <= p2->rGetDimensions().mY &&
        mPosition.mY - p2->rGetPosition().mY >= -7.f
        )
    {
        if (!mDirectionLeft)
        {
            mDirectionLeft = true;
            mVelocity.mX += (rand() % 10) / 10.0f;
            mVelocity.mY = (rand() % 10) / 10.0f;
        }
    }

    if (mPosition.mY + mVelocity.mY <= 0)
    {
        mDirectionUp = false;
        mVelocity.mY = (rand() % 10) / 10.0f;
    }

    if (mPosition.mY + mVelocity.mY >= Config::screenHeight - mDimensions.mY)
    {
        mDirectionUp = true;
        mVelocity.mY = (rand() % 10) / 10.0f;
    }

    mPosition.mX += std::pow(-1, mDirectionLeft) * mVelocity.mX; 
    mPosition.mY += std::pow(-1, mDirectionUp) * mVelocity.mY; 

}

bool Ball::isOnScreen() const
{
    return mOnScreen;
}

void Ball::setOnScreen(bool onScreen)
{
    mOnScreen = onScreen;
}
