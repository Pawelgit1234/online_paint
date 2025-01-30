#pragma once

#include <cstdint>

struct Cursor
{
    Cursor(uint8_t x, uint8_t y, char n) : x(x), y(y), name(n) {}

    uint8_t x;
    uint8_t y;
    char name;
};
