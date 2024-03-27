#ifndef ENTITY
#define ENTITY

#include <SDL2/SDL.h>

#include "gameMath.hpp"
#include "tile.hpp"

class Entity
{ 
public:
  Entity(SDL_FRect pRect): mRect(pRect) {} 
  virtual ~Entity() = default;

  virtual void update(double deltaTime) = 0;
  virtual void render(SDL_Renderer* pRenderer) = 0;
  virtual void handleInput(SDL_Event& pInput) = 0;
  virtual void onCollision(Tile& pTile) = 0;

  SDL_FRect getRect() { return mRect; }
  Vector2f getPosition() { return Vector2f(mRect.x, mRect.y); }
  Vector2f getVelocity() { return mVelocity; }

  void setRect(SDL_FRect pRect) { mRect = pRect; }
  void setPosition(Vector2f pPos) { mRect.x = pPos.x; mRect.y = pPos.y; }
  void setVelocity(Vector2f pVel) { mVelocity = pVel; }

protected:
  SDL_FRect mRect;
  Vector2f mVelocity;
};

#endif // !ENTITY
