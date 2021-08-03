#include <cstdio>

#include "Math.hpp"

Vector2f::Vector2f()
    :mX(0.0f), mY(0.0f)
{}

Vector2f::Vector2f(float x, float y)
    :mX(x), mY(y)
{}

void Vector2f::getPos() const
{
    printf("%f, %f\n", mX, mY);
}
