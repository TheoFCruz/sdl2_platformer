#ifndef TILE
#define TILE

#include "gameMath.hpp"

class Tile
{
public:
  Tile(); 
  ~Tile(); 

  Vector2f getPos() { return mPosition; }
  Vector2f getScale() { return mScale; }

private:
  Vector2f mPosition;
  Vector2f mScale;
};

#endif // !TILE
