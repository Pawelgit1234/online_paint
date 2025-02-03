#pragma once

#include <string>
#include <algorithm>
#include <vector>

#include "../settings.hpp"
#include "objects/dot.hpp"
#include "objects/cursor.hpp"
#include "../utils/fps_counter.hpp"

std::string render(const std::vector<Dot>& dots, const std::vector<Cursor>& cursors,
                   const FpsCounter& fpsCounter);