#pragma once

#include <string>

enum class Color
{
    BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
    REMOVE, // workaround
};

std::string paintBackgroundChar(char c, Color color);
std::string paintSymbolChar(char c, Color color);
std::string paintBothChar(char c, Color symbolColor, Color bgColor);