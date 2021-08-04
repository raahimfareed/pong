#include "Player.hpp"

Player::Player() = default;

Player::Player(SDL_Texture* pTexture, SDL_Rect currentFrame, Vector2f position, Vector2f dimensions)
    : Entity(pTexture, currentFrame, position, dimensions)
{}
