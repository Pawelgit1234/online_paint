#pragma once

#include <string>
#include <algorithm>
#include <vector>

#include "../settings.hpp"
#include "dot.hpp"
#include "cursor.hpp"

std::string render(const std::vector<Dot>& dots, const std::vector<Cursor>& cursors);