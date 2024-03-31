#include "physicsManager.hpp"

#include <algorithm>

#include "consts.hpp"
#include "game.hpp"

PhysicsManager::PhysicsManager(Game& pGame):
  mGameReference(pGame)
{

}

PhysicsManager::~PhysicsManager() 
{

}

void PhysicsManager::update(double deltaTime)
{
  // Applying gravity
  this->applyGravity(deltaTime);
  this->solveCollisions();
}

void PhysicsManager::solveCollisions()
{
  // Entity-Tile collision
  for (const auto& entity : mGameReference.getEntities())
  {
    for (const auto& tile : mGameReference.getTiles())
    {
      Collision collision;
      SDL_FRect rectA = tile->getRect();
      SDL_FRect rectB = entity->getRect();

      if (rectOnRectCollision(rectA, rectB, &collision))
      {
        Vector2f resultPosition = entity->getPosition();
        resultPosition.x += collision.normal.x * collision.depth.x;
        resultPosition.y += collision.normal.y * collision.depth.y;

        Vector2f resultVelocity = entity->getVelocity();
        float dotProd = resultVelocity.dotProd(collision.normal);

        resultVelocity.x += std::abs(dotProd) * collision.normal.x;
        resultVelocity.y += std::abs(dotProd) * collision.normal.y;

        entity->setPosition(resultPosition);
        entity->setVelocity(resultVelocity);

        entity->onCollision(*tile);
      }
    }
  }
}

void PhysicsManager::applyGravity(double deltaTime)
{
  for (const auto& entity : mGameReference.getEntities())
  {
    Vector2f resultVel = entity->getVelocity();
    resultVel.y = resultVel.y + GRAVITY * deltaTime;
    entity->setVelocity(resultVel);
  }
}

bool PhysicsManager::rectOnRectCollision(SDL_FRect& rectA, SDL_FRect& rectB, Collision* collision)
{
  if (rectA.x + rectA.w < rectB.x) return false;
  if (rectA.x > rectB.x + rectB.w) return false;

  if (rectA.y + rectA.h < rectB.y) return false;
  if (rectA.y > rectB.y + rectB.h) return false;

  float depthX = std::min(rectA.x + rectA.w - rectB.x,
                          rectB.x + rectB.w - rectA.x);
  float depthY = std::min(rectA.y + rectA.h - rectB.y,
                          rectB.y + rectB.h - rectA.y);

  if (depthX < depthY)
  {
    collision->depth.x = depthX;
    collision->depth.y = 0;

    collision->normal.x = (rectB.x - rectA.x)/std::abs(rectB.x - rectA.x);
    collision->normal.y = 0;
  }
  else
  {
    collision->depth.x = 0;
    collision->depth.y = depthY;

    collision->normal.x = 0;
    collision->normal.y = (rectB.y - rectA.y)/std::abs(rectB.y - rectA.y);
  }

  return true;
}
