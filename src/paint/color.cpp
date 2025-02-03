#include "color.hpp"

std::string paintBackgroundChar(char c, Color color)
{
    return "\033[1;" + std::to_string(40 + static_cast<int>(color)) + 'm' + c + "\033[0m";
}

std::string paintSymbolChar(char c, Color color)
{
    return "\033[" + std::to_string(30 + static_cast<int>(color)) + 'm' + c + "\033[0m";
}

std::string paintBothChar(char c, Color symbolColor, Color bgColor)
{
    return "\033[1;" + std::to_string(30 + static_cast<int>(symbolColor)) + "m" + 
           "\033[" + std::to_string(40 + static_cast<int>(bgColor)) + "m" + 
           c + "\033[0m";
}