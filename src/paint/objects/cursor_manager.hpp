#pragma once

#include <vector>
#include <algorithm>

#include "cursor.hpp"

class CursorManager
{
    public:
        void addCursor(const Cursor& cursor);

        std::vector<Cursor> getCursors() const;

    private:
        std::vector<Cursor> cursors_;
};