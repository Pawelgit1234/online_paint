#include <iostream>
#include <vector>

#include "../paint/cursor.hpp"
#include "../paint/dot.hpp"
#include "../paint/color.hpp"
#include "../paint/render.hpp"
#include "../settings.hpp"

int main(int argc, char* argv[])
{
    std::vector<Dot> dots;
    std::vector<Cursor> cursors;

    Dot dot(10, 5, Color::BLUE);
    Cursor cursor(CURSOR_SPAWN_X, CURSOR_SPAWN_Y, 'f');

    dots.emplace_back(dot);
    cursors.emplace_back(cursor);

    std::cout << render(dots, cursors);
    return 0;
}