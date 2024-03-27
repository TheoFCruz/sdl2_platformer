#ifndef PLAYER
#define PLAYER

#include <SDL2/SDL.h>

#include "entity.hpp"

class Player: public Entity
{
public:
  Player(SDL_FRect pRect);
  ~Player();

  virtual void handleInput(SDL_Event& pInput) override;
  virtual void update(double deltaTime) override;
  virtual void render(SDL_Renderer* pRenderer) override;
  virtual void onCollision(Tile& pTile) override;

private:
  bool mGrounded;
};

#endif // !PLAYER
