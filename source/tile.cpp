#include "tile.hpp"

void Tile::render(SDL_Renderer* pRenderer)
{
  SDL_FRect rect;
  
  rect.x = mPosition.x;
  rect.y = mPosition.y;
  rect.w = mScale.x;
  rect.h = mScale.y;

  SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderFillRectF(pRenderer, &rect);
}
