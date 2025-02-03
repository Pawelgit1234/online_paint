#pragma once

#include <cstdint>

#include "../../settings.hpp"
#include "dot.hpp"

class Cursor
{
    public:
        Cursor(uint8_t x, uint8_t y, char n) : x_(x), y_(y), name_(n) {}

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        
        Dot createDot(Color c) const;

        uint8_t getX() const;
        uint8_t getY() const;
        char getName() const;

    private:
        uint8_t x_;
        uint8_t y_;
        char name_;
};
