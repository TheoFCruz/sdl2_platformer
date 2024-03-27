#include "tile.hpp"

Tile::Tile(SDL_FRect pRect):
  mRect(pRect)
{
  
}

Tile::~Tile()
{

}

void Tile::render(SDL_Renderer* pRenderer)
{
  SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderFillRectF(pRenderer, &mRect);
}
