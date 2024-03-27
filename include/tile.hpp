#ifndef TILE
#define TILE

#include <SDL2/SDL.h>

class Tile
{
public:
  Tile(SDL_FRect pRect); 
  ~Tile();

  const SDL_FRect& getRect() { return mRect; }

  void render(SDL_Renderer* pRenderer);

private:
  SDL_FRect mRect;
};

#endif // !TILE
