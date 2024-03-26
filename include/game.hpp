#ifndef GAME
#define GAME

#include <SDL2/SDL.h>

#include <vector>
#include <memory>

#include "entity.hpp"
#include "tile.hpp"
#include "physicsManager.hpp"

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

  std::vector<std::unique_ptr<Entity>>& getEntities() { return mEntities; }
  std::vector<std::unique_ptr<Tile>>& getTiles() { return mTiles; }

private:
  SDL_Window* mWindow;  
  SDL_Renderer* mRenderer;

  PhysicsManager mPhysics;

  std::vector<std::unique_ptr<Entity>> mEntities;
  std::vector<std::unique_ptr<Tile>> mTiles;
};

#endif // !GAME
