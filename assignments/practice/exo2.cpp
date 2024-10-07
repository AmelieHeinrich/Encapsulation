// exo2.cpp

#include <utility>

class Point
{
public:
    Point()
        : mX(0), mY(0)
    {
    }

    Point(int x, int y)
        : mX(x), mY(y)
    {
    }

    int DistanceVector(const Point& b) {
        // As vectors
        return mX * b.mX + mY * b.mY;
    }

    std::pair<int, int> DistancePoints(const Point& b) {
        // As points
        return std::make_pair<int, int>(b.mX - mX, b.mY - mY);
    }

    bool Compare(const Point& b) {
        return (mX == b.mX) && (mY == b.mY);
    }

    int GetX() { return mX; }
    int GetY() { return mY; }

    void SetX(int x) { mX = x; }
    void SetY(int y) { mY = y; }
private:
    int mX;
    int mY;
};
