#ifndef ENTITY
#define ENTITY

#include <SDL2/SDL.h>

#include "gameMath.hpp"

class Entity
{ 
public:
  Entity(SDL_FRect pRect): mRect(pRect) {} 
  virtual ~Entity() = default;

  virtual void update(double deltaTime) = 0;
  virtual void render(SDL_Renderer* pRenderer) = 0;
  virtual void handleInput(SDL_Event& input) = 0;

  SDL_FRect getRect() { return mRect; }
  Vector2f getVel() { return mVelocity; }

  void setRect(SDL_FRect pRect) { mRect = pRect; }
  void setVel(Vector2f pVel) { mVelocity = pVel; }

protected:
  SDL_FRect mRect;
  Vector2f mVelocity;
};

#endif // !ENTITY
