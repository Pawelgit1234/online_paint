#include "dot.hpp"

struct Dot
{
    Dot(uint8_t x, uint8_t y, Color c) : x(x), y(y), color(c) {}

    uint8_t x;
    uint8_t y;
    Color color;
};