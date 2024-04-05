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
  // if (pInput.type == SDL_KEYDOWN && !pInput.key.repeat)
  // {
  //   switch(pInput.key.keysym.sym)
  //   {
  //     case SDLK_a:
  //       mVelocity.x -= PLAYER_SPEED;
  //       break;
  //     case SDLK_d:
  //       mVelocity.x += PLAYER_SPEED;
  //       break;
  //     case SDLK_w:
  //       if (mGrounded)
  //       {
  //         mVelocity.y = -JUMP_SPEED;
  //         mGrounded = false;
  //       }
  //   }
  // }
  // else if (pInput.type == SDL_KEYUP && !pInput.key.repeat)
  // {
  //   switch(pInput.key.keysym.sym)
  //   {
  //     case SDLK_a:
  //       mVelocity.x += PLAYER_SPEED;
  //       break;
  //     case SDLK_d:
  //       mVelocity.x -= PLAYER_SPEED;
  //       break;
  //   }
  // }
  
  // TODO: Implement better input handling with an InputManager class
  
  const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
  int dir = 0;
  if (keyboardState[SDL_SCANCODE_D]) dir++;
  if (keyboardState[SDL_SCANCODE_A]) dir--;

  mVelocity.x = dir * PLAYER_SPEED;
  
  bool jumpCondition = (
    pInput.type == SDL_KEYDOWN &&
    pInput.key.keysym.sym == SDLK_w &&
    !pInput.key.repeat &&
    mGrounded
  );

  if (jumpCondition) mVelocity.y = -JUMP_SPEED;
}

void Player::update(double deltaTime)
{
  mGrounded = false;

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
