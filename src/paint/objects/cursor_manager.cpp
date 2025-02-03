#include "cursor_manager.hpp"


void CursorManager::addCursor(const Cursor& cursor)
{
    const auto it = std::find_if(cursors_.begin(), cursors_.end(), 
        [cursor](const Cursor& c)
        {
            return cursor.getName() == c.getName();
        });
    
    if (it == cursors_.end())
    {
        cursors_.emplace_back(cursor);
    }
    else
    {
        cursors_.erase(it);
        cursors_.emplace_back(cursor);
    }
}

std::vector<Cursor> CursorManager::getCursors() const
{
    return cursors_;
}