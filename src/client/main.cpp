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
    Cursor cursor(CURSOR_SPAWN_X, CURSOR_SPAWN_Y, 'f');

    std::cout << render({}, {});
    return 0;
}