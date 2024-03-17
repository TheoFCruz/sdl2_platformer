#ifndef MATH
#define MATH

template <class T>
class Vector2
{
public:
  Vector2(): x(0), y(0) {}
  Vector2(T x, T y): x(x), y(y) {}
  
  T x;
  T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

#endif // !MATH
