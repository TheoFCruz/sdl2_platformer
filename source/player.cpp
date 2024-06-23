#include "player.hpp"

#include <SDL2/SDL.h>

#include "consts.hpp"
#include "gameMath.hpp"
#include "physicsManager.hpp"

Player::Player(SDL_FRect pRect):
  Entity(pRect)
{

}

Player::~Player()
{

}

void Player::handleInput()
{
  // TODO: Implement better input handling with an InputManager class

  const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
  int dir = 0;
  if (keyboardState[SDL_SCANCODE_D]) dir++;
  if (keyboardState[SDL_SCANCODE_A]) dir--;

  mVelocity.x = dir * PLAYER_SPEED;
  
  if (keyboardState[SDL_SCANCODE_W] && mGrounded) mVelocity.y = -JUMP_SPEED;
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

}
