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

void Player::update(double deltaTime)
{
  mPosition.x += mVelocity.x * deltaTime;
  mPosition.y += mVelocity.y * deltaTime; 
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
