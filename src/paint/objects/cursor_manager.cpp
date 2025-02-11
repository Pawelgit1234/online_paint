#include "cursor_manager.hpp"


void CursorManager::addCursors(const std::vector<Cursor>& cursors)
{
    for (const Cursor& cursor : cursors)
        addCursor(cursor);
}

void CursorManager::addCursor(const Cursor& cursor)
{
    deleteCursor(cursor.getName());
    cursors_.emplace_back(cursor);
}

void CursorManager::deleteCursor(char name)
{
    const auto it = std::find_if(cursors_.begin(), cursors_.end(), 
        [name](const Cursor& c)
        {
            return name == c.getName();
        });

    if (it != cursors_.end())
        cursors_.erase(it);
}

void CursorManager::clear()
{
    cursors_.clear();
}

std::vector<Cursor> CursorManager::getCursors() const
{
    return cursors_;
}