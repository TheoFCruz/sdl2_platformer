#include "game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>

#include "consts.hpp"
#include "player.hpp"

Game::Game():
  mPhysics(*this)
{

}

Game::~Game()
{

}

bool Game::init()
{
  // Initializes SDL, SDL_image and SDL_ttf
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    std::cout << "Unable to init SDL. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  Uint32 imgFlags = IMG_INIT_PNG;
  if ((IMG_Init(imgFlags) | imgFlags) != imgFlags)
  {
    std::cout << "Unable to init SDL_image. Error: " << IMG_GetError() << std::endl;
    return false;
  }

  if (TTF_Init() != 0)
  {
    std::cout << "Unable to init SDL_ttf. Error: " << TTF_GetError() << std::endl;
    return false;
  }

  //Creates the window
  mWindow = SDL_CreateWindow("platformer",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_RESIZABLE);
  if (mWindow == NULL)
  {
    std::cout << "Unable to create window. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // Creates the renderer
  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
  if (mRenderer == NULL)
  {
    std::cout << "Unable to create renderer. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // Makes renderer adapt to resizing
  SDL_RenderSetLogicalSize(mRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  return true;
}

void Game::quit()
{
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

void Game::createEntities()
{
  mEntities.push_back(std::make_unique<Player>(SDL_FRect{50.f, 50.f, SQUARE_SIDE, SQUARE_SIDE}));

  mTiles.push_back(std::make_unique<Tile>(SDL_FRect{150.f, 500.f, 500.f, 50.f}));
  mTiles.push_back(std::make_unique<Tile>(SDL_FRect{350.f, 360.f, 200.f, 50.f}));
}

void Game::handleInput()
{
  for (auto& entity : mEntities) entity->handleInput();
}

void Game::update(double deltaTime)
{
  for (auto& entity : mEntities) entity->update(deltaTime); 

  mPhysics.update(deltaTime); 
}

void Game::render()
{
  SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(mRenderer);

  for (auto& entity : mEntities) entity->render(mRenderer); 
  for (auto& tile : mTiles) tile->render(mRenderer); 

  SDL_RenderPresent(mRenderer);
}
