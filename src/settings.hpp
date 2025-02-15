#pragma once

#include <cstdint>
#include <chrono>

#include "paint/color.hpp"

inline constexpr int CANVAS_WIDTH = 41;
inline constexpr int CANVAS_HEIGHT = 8;
inline constexpr int CANVAS_PIXEL_COUNT = CANVAS_WIDTH * CANVAS_HEIGHT;

inline constexpr uint8_t CURSOR_SPAWN_X = 1;
inline constexpr uint8_t CURSOR_SPAWN_Y = 1;

inline constexpr Color CURSOR_BACKGROUND_COLOR = Color::WHITE;
inline constexpr Color CURSOR_SYMBOL_COLOR = Color::BLACK;
inline constexpr Color WALL_COLOR = Color::YELLOW;

inline constexpr int TARGET_FPS = 30;

inline constexpr std::chrono::milliseconds FRAME_DURATION = std::chrono::milliseconds(1000) / TARGET_FPS;
inline constexpr std::chrono::seconds ACTIVITY_TIME = std::chrono::seconds(1);

inline constexpr size_t MAX_BUFFER_LENGTH = 2048; // bytes
inline constexpr size_t CLIENT_TIMEOUT = 120; // seconds

inline constexpr size_t CURSOR_SIZE = sizeof(uint8_t) * 2 + sizeof(char);
inline constexpr size_t DOT_SIZE = sizeof(uint8_t) * 2 + sizeof(Color);
inline constexpr uint8_t QUIT_SIGNAL = 0xFF;
