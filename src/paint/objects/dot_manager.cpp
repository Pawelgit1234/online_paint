#include "dot_manager.hpp"

void DotManager::addDots(const std::vector<Dot>& dots)
{
    for (const Dot& dot : dots)
        addDot(dot);
}

void DotManager::addDot(const Dot& dot)
{
    deleteDot(dot.x, dot.y);
    dots_.emplace_back(dot);
}

void DotManager::deleteDot(uint8_t x, uint8_t y)
{
    const auto it = std::find_if(dots_.begin(), dots_.end(),
        [x, y](const Dot& dot)
        {
            return dot.x == x && dot.y == y;
        });
    
    if (it != dots_.end())
        dots_.erase(it);
}

std::vector<Dot> DotManager::getDots() const
{
    return dots_;
}