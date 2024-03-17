#ifndef MATH
#define MATH

#include <cmath>

template <class T>
class Vector2
{
public:
  Vector2(): x(0), y(0) {}
  Vector2(T x, T y): x(x), y(y) {}
  
  static Vector2<T> normalize(const Vector2<T>& vec)
  {
    Vector2<T> returnVec;
    T vecNorm = std::sqrt(vec.x * vec.x + vec.y * vec.y);

    if (vecNorm == 0) return vec;
    
    returnVec.x = vec.x / vecNorm;
    returnVec.y = vec.y / vecNorm;

    return returnVec;
  }

  T x;
  T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

#endif // !MATH
