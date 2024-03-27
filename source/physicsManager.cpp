#include "physicsManager.hpp"

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
  for (const auto& entity : mGameReference.getEntities())
  {
    Vector2f oldVel = entity->getVel();
    Vector2f newVel;

    newVel.x = oldVel.x;
    newVel.y = oldVel.y + GRAVITY * deltaTime;

    entity->setVel(newVel);
  }

  this->solveCollisions();
}

void PhysicsManager::solveCollisions()
{

}