#ifndef PHYSICS_MANAGER
#define PHYSICS_MANAGER

class Game;

class PhysicsManager
{
public:
  PhysicsManager();
  ~PhysicsManager();

  void update();

private:
  void solveCollisions();

  Game& mGameReference;
};

#endif // !PHYSICS_MANAGER
