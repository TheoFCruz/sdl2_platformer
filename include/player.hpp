#ifndef PLAYER
#define PLAYER

#include "entity.hpp"
#include "gameMath.hpp"

class Player: public Entity
{
public:
  Player(Game& pGame);
  ~Player();

  virtual void update(double deltaTime) override;
  virtual void render() override;

private:
  Vector2f mPosition;
  Vector2f mVelocity;
};

#endif // !PLAYER
