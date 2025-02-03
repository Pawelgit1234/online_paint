#include "settings.hpp"

const int CANVAS_WIDTH = 40;
const int CANVAS_HEIGHT = 8;
const int CANVAS_PIXEL_COUNT = CANVAS_WIDTH * CANVAS_HEIGHT;

const uint8_t CURSOR_SPAWN_X = 1;
const uint8_t CURSOR_SPAWN_Y = 1;

const Color CURSOR_BACKGROUND_COLOR = Color::WHITE;
const Color CURSOR_SYMBOL_COLOR = Color::BLACK;
const Color WALL_COLOR = Color::YELLOW;

const uint16_t TARGET_FPS = 120;

const std::chrono::milliseconds FRAME_DURATION = std::chrono::milliseconds(1000) / TARGET_FPS;