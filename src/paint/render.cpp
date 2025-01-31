#include "render.hpp"

std::string render(const std::vector<Dot>& dots, const std::vector<Cursor>& cursors)
{
    std::string canvas;
    canvas.reserve(CANVAS_PIXEL_COUNT);

    for (int y = 0; y < CANVAS_HEIGHT; ++y)
    {
        for (int x = 0; x < CANVAS_WIDTH; ++x)
        {
            const auto dot_it = std::find_if(dots.begin(), dots.end(), [x, y](const Dot& dot){
                return dot.x == x && dot.y == y;
            });

            const auto cursor_it = std::find_if(cursors.begin(), cursors.end(), [x, y](const Cursor& cursor){
                return cursor.x == x && cursor.y == y;
            });

            if (x == 0 || y == 0 || x == CANVAS_WIDTH - 1 || y == CANVAS_HEIGHT - 1)
                canvas += BORDER;
            else if (cursor_it != cursors.end())
                canvas += paintChar(cursor_it->name, CURSOR_COLOR);
            else if (dot_it != dots.end())
                canvas += paintChar(DOT, dot_it->color);
            else
                canvas += EMPTY;
        }
        canvas += '\n';
    }

    return canvas;
}