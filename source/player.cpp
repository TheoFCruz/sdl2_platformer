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

void Player::handleInput(SDL_Event& input)
{
  if (input.type == SDL_KEYDOWN && !input.key.repeat)
  {
    switch(input.key.keysym.sym)
    {
      case SDLK_a:
        mVelocity.x -= PLAYER_SPEED;
        break;
      case SDLK_d:
        mVelocity.x += PLAYER_SPEED;
        break;
    }
  }
  else if (input.type == SDL_KEYUP && !input.key.repeat)
  {
    switch(input.key.keysym.sym)
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
