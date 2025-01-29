#include "render.hpp"

std::string render(std::vector<Dot> dots, std::vector<Cursor> cursors)
{
    std::string canvas;
    canvas.reserve(CANVAS_PIXEL_COUNT);

    for (int x = 0; x < CANVAS_HEIGHT; x++)
    {
        for (int y = 0; y < CANVAS_WIDTH; y++)
        {
            if (x == 0 || x == CANVAS_WIDTH || y == 0 || y == CANVAS_HEIGHT)
                canvas += BORDER;
        }
    }
}