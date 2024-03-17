#ifndef ENTITY
#define ENTITY

class Game;

class Entity
{ 
public:
  Entity(Game& pGame): mGameReference(pGame) {} 
  virtual ~Entity() = default;

  virtual void update(double deltaTime) = 0;
  virtual void render() = 0;

protected:
  Game& mGameReference;
};

#endif // !ENTITY
