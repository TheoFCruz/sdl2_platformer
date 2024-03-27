#include "player.hpp"

#include <SDL2/SDL.h>

#include "consts.hpp"

Player::Player(SDL_FRect pRect):
  Entity(pRect)
{

}

Player::~Player()
{

}

void Player::handleInput(SDL_Event& pInput)
{
  if (pInput.type == SDL_KEYDOWN && !pInput.key.repeat)
  {
    switch(pInput.key.keysym.sym)
    {
      case SDLK_a:
        mVelocity.x -= PLAYER_SPEED;
        break;
      case SDLK_d:
        mVelocity.x += PLAYER_SPEED;
        break;
      case SDLK_w:
        if (mGrounded)
        {
          mVelocity.y -= JUMP_SPEED;
          mGrounded = false;
        }
    }
  }
  else if (pInput.type == SDL_KEYUP && !pInput.key.repeat)
  {
    switch(pInput.key.keysym.sym)
    {
      case SDLK_a:
        mVelocity.x += PLAYER_SPEED;
        break;
      case SDLK_d:
        mVelocity.x -= PLAYER_SPEED;
        break;
    }
  }
}

void Player::update(double deltaTime)
{
  mRect.x += mVelocity.x * deltaTime;
  mRect.y += mVelocity.y * deltaTime; 
}

void Player::render(SDL_Renderer* pRenderer)
{
  SDL_SetRenderDrawColor(pRenderer, 0xff, 0x00, 0x00, 0xFF);
  SDL_RenderFillRectF(pRenderer, &mRect);
}

void Player::onCollision(Tile& pTile)
{
  if (pTile.getPosition().y > this->getPosition().y) mGrounded = true;
}
