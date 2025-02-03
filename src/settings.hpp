#pragma once

#include <cstdint>
#include <chrono>

#include "paint/color.hpp"

extern const int CANVAS_WIDTH;
extern const int CANVAS_HEIGHT;
extern const int CANVAS_PIXEL_COUNT;

extern const uint8_t CURSOR_SPAWN_X;
extern const uint8_t CURSOR_SPAWN_Y;

extern const Color CURSOR_BACKGROUND_COLOR;
extern const Color CURSOR_SYMBOL_COLOR;
extern const Color WALL_COLOR;

extern const uint16_t TARGET_FPS;

extern const std::chrono::milliseconds FRAME_DURATION;