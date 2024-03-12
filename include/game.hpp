#ifndef GAME
#define GAME

#include <SDL2/SDL.h>

#include <vector>

#include "entity.hpp"

class Game
{
public:
  Game() {}
  ~Game() {}

  bool init();
  void quit();

  void update(double deltaTime);
  void render();

private:
  SDL_Window* mWindow;  
  SDL_Renderer* mRenderer;

  std::vector<Entity> mEntities;
};

#endif // !GAME
