#ifndef PHYSICS_MANAGER
#define PHYSICS_MANAGER

#include <SDL2/SDL.h>
#include "gameMath.hpp"

class Game;

struct Collision
{
  Vector2f normal;
  Vector2f depth;
};

class PhysicsManager
{
public:
  PhysicsManager(Game& pGame);
  ~PhysicsManager();

  void update(double deltaTime);

private:
  void applyGravity(double deltaTime);
  void solveCollisions();

  bool rectOnRectCollision(SDL_FRect& rectA, SDL_FRect& rectB, Collision* collision);

  Game& mGameReference;
};

#endif // !PHYSICS_MANAGER
