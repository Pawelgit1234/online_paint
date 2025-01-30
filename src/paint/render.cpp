#include "render.hpp"

std::string render(const std::vector<Dot>& dots, const std::vector<Cursor>& cursors)
{
    std::string canvas;
    canvas.reserve(CANVAS_PIXEL_COUNT);

    for (int y = 0; y < CANVAS_HEIGHT + 1; ++y)
    {
        for (int x = 0; x < CANVAS_WIDTH + 1; ++x)
        {
            if (x == 0 || y == 0 || x == CANVAS_WIDTH || y == CANVAS_HEIGHT)
                canvas += BORDER;
            else
                canvas += EMPTY;
        }
        canvas += '\n';
    }

    return canvas;
}