#include "cursor.hpp"

void Cursor::moveUp()
{
    if (y_ > 1)
        --y_;
}

void Cursor::moveDown()
{
    if (y_ < CANVAS_HEIGHT - 2)
        ++y_;
}

void Cursor::moveLeft()
{
    if (x_ > 1)
        --x_;
}

void Cursor::moveRight()
{
    if (x_ < CANVAS_WIDTH - 2)
        ++x_;
}

Dot Cursor::createDot(Color c) const
{
    return Dot(x_, y_, c);
}

uint8_t Cursor::getX() const 
{
    return x_;
}

uint8_t Cursor::getY() const 
{
    return y_;
}

char Cursor::getName() const
{
    return name_;
}