#pragma once

#include <vector>
#include <algorithm>
#include <cstdint>

#include "dot.hpp"

class DotManager
{
    public:
        void addDots(const std::vector<Dot>& dots);
        void addDot(const Dot& dot);
        void deleteDot(uint8_t x, uint8_t y); // delete a dot with same coordinates
        void clear();

        std::vector<Dot> getDots() const;

    private:
        std::vector<Dot> dots_;
};