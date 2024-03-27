#ifndef TILE
#define TILE

#include <SDL2/SDL.h>

#include "gameMath.hpp"

class Tile
{
public:
  Tile(SDL_FRect pRect); 
  ~Tile();

  SDL_FRect getRect() { return mRect; }
  Vector2f getPosition() { return Vector2f(mRect.x, mRect.y); }

  void setPosition(Vector2f pos) { mRect.x = pos.x; mRect.y = pos.y; }
  void setScale(Vector2f scale) { mRect.w = scale.x; mRect.h = scale.y; }

  void render(SDL_Renderer* pRenderer);

private:
  SDL_FRect mRect;
};

#endif // !TILE
