#include "serialization.hpp"

static void serializeCursor(const Cursor& cursor, uint8_t* buffer)
{
    buffer[0] = cursor.getX();
    buffer[1] = cursor.getY();
    buffer[2] = cursor.getName();
}

static void serializeDot(const Dot& dot, uint8_t* buffer)
{
    buffer[0] = dot.x;
    buffer[1] = dot.y;
    buffer[2] = static_cast<uint8_t>(dot.color);
}

size_t serialize(const std::vector<Cursor>& cursors, const std::vector<Dot>& dots, uint8_t* buffer)
{
    size_t offset = 0;
    buffer[offset++] = static_cast<uint8_t>(cursors.size());
    buffer[offset++] = static_cast<uint8_t>(dots.size());

    for (const auto& cursor : cursors)
    {
        serializeCursor(cursor, buffer + offset);
        offset += CURSOR_SIZE;
    }

    for (const auto& dot : dots)
    {
        serializeDot(dot, buffer + offset);
        offset += DOT_SIZE;
    }

    return offset;
}

static void deserializeCursor(const uint8_t* buffer, Cursor& cursor)
{
    cursor = Cursor(buffer[0], buffer[1], buffer[2]);
}

static void deserializeDot(const uint8_t* buffer, Dot& dot)
{
    dot = Dot(buffer[0], buffer[1], static_cast<Color>(buffer[2]));
}

size_t deserialize(const uint8_t* buffer, std::vector<Cursor>& cursors, std::vector<Dot>& dots)
{
    size_t offset = 0;
    size_t cursorCount = buffer[offset++];
    size_t dotCount = buffer[offset++];
    
    cursors.clear();
    dots.clear();
    
    for (size_t i = 0; i < cursorCount; ++i)
    {
        Cursor cursor(0, 0, ' ');
        deserializeCursor(buffer + offset, cursor);
        cursors.push_back(cursor);
        offset += CURSOR_SIZE;
    }
    
    for (size_t i = 0; i < dotCount; ++i)
    {
        Dot dot(0, 0, Color::WHITE);
        deserializeDot(buffer + offset, dot);
        dots.push_back(dot);
        offset += DOT_SIZE;
    }

    return offset;
}