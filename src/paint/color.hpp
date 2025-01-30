#pragma once

#include <string>

enum class Color
{
    BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
};

std::string paintChar(char c, Color color);