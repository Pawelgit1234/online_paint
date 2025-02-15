#include "render.hpp"

std::string render(const std::vector<Cursor>& cursors, const std::vector<Dot>& dots,
                   const FpsCounter& fpsCounter)
{
    std::string canvas;
    canvas.reserve(CANVAS_PIXEL_COUNT);

    for (int y = 0; y < CANVAS_HEIGHT; ++y)
    {
        for (int x = 0; x < CANVAS_WIDTH; ++x)
        {
            const auto dot_it = std::find_if(dots.begin(), dots.end(),
                [x, y](const Dot& dot)
                {
                    return dot.x == x && dot.y == y;
                });

            const auto cursor_it = std::find_if(cursors.begin(), cursors.end(),
                [x, y](const Cursor& cursor)
                {
                    return cursor.getX() == x && cursor.getY() == y;
                });

            if (x == 0 || y == 0 || x == CANVAS_WIDTH - 1 || y == CANVAS_HEIGHT - 1)
                canvas += paintBackgroundChar(' ', WALL_COLOR);
            else if (cursor_it != cursors.end())
                canvas += paintBothChar(cursor_it->getName(), CURSOR_SYMBOL_COLOR, CURSOR_BACKGROUND_COLOR);
            else if (dot_it != dots.end())
                canvas += paintBackgroundChar(' ', dot_it->color);
            else
                canvas += ' ';
        }
        canvas += '\n';
    }

    // extra information
    canvas += paintBothChar('1', Color::WHITE, Color::BLACK) +
              paintBothChar('2', Color::BLACK, Color::RED) +
              paintBothChar('3', Color::BLACK, Color::GREEN) +
              paintBothChar('4', Color::BLACK, Color::YELLOW) +
              paintBothChar('5', Color::BLACK, Color::BLUE) +
              paintBothChar('6', Color::BLACK, Color::MAGENTA) +
              paintBothChar('7', Color::BLACK, Color::CYAN) +
              paintBothChar('8', Color::BLACK, Color::WHITE) +
              " 9 - remove, q - quit, " +
              std::to_string(dots.size()) + "d " + // dots count
              std::to_string(fpsCounter.getFps()) + "fps\n"; // fps

    return canvas;
}