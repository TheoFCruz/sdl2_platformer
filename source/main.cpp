#include <SDL2/SDL.h>

#include "game.hpp"

int main(int argc, char** argv)
{
  Game game;
  if (!game.init()) return -1; 

  Uint64 currentCounter = SDL_GetPerformanceCounter();
  Uint64 lastCounter = 0;
  double deltaTime = 0;
  
  SDL_Event event;
  bool running = true;
  while (running)
  {
    // Calculates delta_time in milliseconds
    lastCounter = currentCounter;
    currentCounter = SDL_GetPerformanceCounter();
    deltaTime = ((double)(currentCounter - lastCounter))/((double)(SDL_GetPerformanceFrequency()));

    // Event loop
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT) running = false;
    }

    //Game update and draw
    game.update(deltaTime);
    game.render();
  }

  game.quit();
}

