// exo4.cpp

#define _USE_MATH_DEFINES
#include <cmath>

class Circle
{
public:
    Circle()
        : mRadius(1)
    {
    }

    Circle(int radius)
        : mRadius(radius)
    {
    }

    float Perimeter() {
        return 2 * M_PI * mRadius;
    }

    int GetRadius() { return mRadius; }
    void SetRadius(int radius) { mRadius = radius; }
private:
    int mRadius;
};
