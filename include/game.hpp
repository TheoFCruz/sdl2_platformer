#ifndef GAME
#define GAME

#include <SDL2/SDL.h>

#include <vector>
#include <memory>

#include "entity.hpp"

class Game
{
public:
  Game() {}
  ~Game() {}

  bool init();
  void quit();

  void createEntities();

  void handleInput(SDL_Event& input);
  void update(double deltaTime);
  void render();

  SDL_Renderer* getRenderer() { return mRenderer; }

private:
  SDL_Window* mWindow;  
  SDL_Renderer* mRenderer;

  std::vector<std::unique_ptr<Entity>> mEntities;
};

#endif // !GAME
