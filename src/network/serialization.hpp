#pragma once

#include <vector>

#include "../paint/objects/cursor.hpp"
#include "../paint/objects/dot.hpp"

void serializeCursor(const Cursor& cursor, uint8_t* buffer);
void serializeDot(const Dot& dot, uint8_t* buffer);
void serialize(const std::vector<Cursor>& cursors, const std::vector<Dot>& dots, uint8_t* buffer);

void deserializeCursor(const uint8_t* buffer, Cursor& cursor);
void deserializeDot(const uint8_t* buffer, Dot& dot);
void deserialize(const uint8_t* buffer, std::vector<Cursor>& cursors, std::vector<Dot>& dots);