#include "color.hpp"

std::string paintChar(char c, Color color)
{
    std::string ansi_code;

    switch (color)
    {
    case Color::BLACK:         ansi_code = "\033[40m"; break;
    case Color::RED:           ansi_code = "\033[41m"; break;
    case Color::GREEN:         ansi_code = "\033[42m"; break;
    case Color::YELLOW:        ansi_code = "\033[43m"; break;
    case Color::BLUE:          ansi_code = "\033[44m"; break;
    case Color::MAGENTA:       ansi_code = "\033[45m"; break;
    case Color::CYAN:          ansi_code = "\033[46m"; break;
    case Color::WHITE:         ansi_code = "\033[47m"; break;
    }

    return ansi_code + c + "\033[0m";
}