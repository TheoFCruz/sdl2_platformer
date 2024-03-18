#ifndef ENTITY
#define ENTITY

#include <SDL2/SDL.h>

#include "gameMath.hpp"

class Game;

class Entity
{ 
public:
  Entity(Vector2f pPosition): mPosition(pPosition) {} 
  virtual ~Entity() = default;

  virtual void update(double deltaTime) = 0;
  virtual void render(SDL_Renderer* pRenderer) = 0;
  virtual void handleInput(SDL_Event& input) = 0;

protected:
  Vector2f mPosition;
  Vector2f mVelocity;
};

#endif // !ENTITY
