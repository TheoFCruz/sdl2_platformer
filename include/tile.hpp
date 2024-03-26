#ifndef TILE
#define TILE

#include <SDL2/SDL.h>

#include "gameMath.hpp"

class Tile
{
public:
  Tile(Vector2f pos, Vector2f scale): mPosition(pos), mScale(scale) {} 
  ~Tile() {} 

  Vector2f getPos() { return mPosition; }
  Vector2f getScale() { return mScale; }

  void render(SDL_Renderer* pRenderer);

private:
  Vector2f mPosition;
  Vector2f mScale;
};

#endif // !TILE
