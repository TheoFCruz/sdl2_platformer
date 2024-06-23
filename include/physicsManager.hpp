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
  void solveCollisions();
  void applyGravity(double deltaTime);
  void applyGrounded();

  bool rectOnRectCollision(SDL_FRect* rectA, SDL_FRect* rectB, Collision* collision);
  bool raycast(Vector2f start, Vector2f end);

  Game& mGameReference;
};

#endif // !PHYSICS_MANAGER
