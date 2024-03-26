#ifndef PHYSICS_MANAGER
#define PHYSICS_MANAGER

class Game;

class PhysicsManager
{
public:
  PhysicsManager(Game& pGame);
  ~PhysicsManager();

  void update(double deltaTime);

private:
  void solveCollisions();

  Game& mGameReference;
};

#endif // !PHYSICS_MANAGER
