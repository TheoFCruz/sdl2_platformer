#ifndef ENTITY
#define ENTITY

#include "math.hpp"

class Entity
{ 
public:
  Entity(); 
  virtual ~Entity();

private:
  Vector2f mPosition;
};

#endif // !ENTITY
