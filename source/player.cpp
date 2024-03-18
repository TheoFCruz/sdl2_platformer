#include "player.hpp"

#include <SDL2/SDL.h>

#include "consts.hpp"

Player::Player(Vector2f pPosition):
  Entity(pPosition)
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
  mPosition.x += mVelocity.x * deltaTime;
  mPosition.y += mVelocity.y * deltaTime; 
}

void Player::render(SDL_Renderer* pRenderer)
{
  SDL_FRect rect;
  
  rect.x = mPosition.x;
  rect.y = mPosition.y;
  rect.w = SQUARE_SIDE;
  rect.h = SQUARE_SIDE;

  SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderFillRectF(pRenderer, &rect);
}
