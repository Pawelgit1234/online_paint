#pragma once

#include <string>
#include <algorithm>
#include <vector>

#include "../settings.hpp"
#include "objects/dot.hpp"
#include "objects/cursor.hpp"
#include "../utils/fps_counter.hpp"

#ifdef _WIN32
    #include <windows.h>
    void setupWindowsTerminal();
    void fastDrawingWindows(const std::string& frame);
#endif

std::string render(const std::vector<Cursor>& cursors, const std::vector<Dot>& dots,
                   const FpsCounter& fpsCounter);