#include "player.hpp"

#include <SDL2/SDL.h>

#include "game.hpp"
#include "consts.hpp"

Player::Player(Game& pGame):
  Entity(pGame),
  mPosition(0, 0),
  mVelocity(0, 0)
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
      case SDLK_w:
        mVelocity.y -= 1;
        break;
      case SDLK_a:
        mVelocity.x -= 1;
        break;
      case SDLK_s:
        mVelocity.y += 1;
        break;
      case SDLK_d:
        mVelocity.x += 1;
        break;
    }
  }
  else if (input.type == SDL_KEYUP && !input.key.repeat)
  {
    switch(input.key.keysym.sym)
    {
      case SDLK_w:
        mVelocity.y += 1;
        break;
      case SDLK_a:
        mVelocity.x += 1;
        break;
      case SDLK_s:
        mVelocity.y -= 1;
        break;
      case SDLK_d:
        mVelocity.x -= 1;
        break;
    }
  }
}

void Player::update(double deltaTime)
{
  Vector2f normalVelocity = Vector2f::normalize(mVelocity);
  mPosition.x += PLAYER_SPEED * normalVelocity.x * deltaTime;
  mPosition.y += PLAYER_SPEED * normalVelocity.y * deltaTime; 
}

void Player::render()
{
  SDL_Renderer* renderer = mGameReference.getRenderer();
  SDL_FRect rect;
  
  rect.x = mPosition.x;
  rect.y = mPosition.y;
  rect.w = SQUARE_SIDE;
  rect.h = SQUARE_SIDE;

  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderFillRectF(renderer, &rect);
}
