#pragma once

#include <vector>
#include <algorithm>

#include "cursor.hpp"

class CursorManager
{
    public:
        void addCursors(const std::vector<Cursor>& cursors);
        void addCursor(const Cursor& cursor);
        void deleteCursor(char name);

        std::vector<Cursor> getCursors() const;

    private:
        std::vector<Cursor> cursors_;
};