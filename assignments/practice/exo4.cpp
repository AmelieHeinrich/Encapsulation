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

    float Area() {
        return M_PI * std::pow(mRadius, 2);
    }

    int GetRadius() { return mRadius; }
    void SetRadius(int radius) { mRadius = radius; }
private:
    int mRadius;
};
