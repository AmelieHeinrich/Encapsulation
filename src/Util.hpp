// Util.hpp

#pragma once

#include <cstdint>

template<typename T>
struct Vector2
{
    T x;
    T y;

    Vector2() {
        x = 0;
        y = 0;
    }

    Vector2(T scalar) {
        x = scalar;
        y = scalar;
    }

    Vector2(T X, T Y) {
        x = X;
        y = Y;   
    }
};

struct ColorU8
{
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
    uint8_t Alpha;

    ColorU8() {
        Red = 255;
        Green = 255;
        Blue = 255;
        Alpha = 255;
    }

    ColorU8(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        Red = r;
        Green = g;
        Blue = b;
        Alpha = a;
    }
};

using Vector2f = Vector2<float>;
using Vector2u = Vector2<uint32_t>;
using Vector2i = Vector2<int>;

namespace util
{
    int RandomInt(int min, int max);
    float RandomRange(float min, float max);
}
