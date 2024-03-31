#ifndef MATH
#define MATH

#include <cmath>

template <class T>
class Vector2
{
public:
  Vector2(): x(0), y(0) {}
  Vector2(T x, T y): x(x), y(y) {}
  
  void normalize()
  {
    T vecNorm = std::sqrt(x*x + y*y);
    x = x/vecNorm;
    y = y/vecNorm;
  }

  T dotProd(Vector2<T> prodVec) 
  {
    return this->x * prodVec.x + this->y * prodVec.y;
  }

  T x;
  T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;


#endif // !MATH
