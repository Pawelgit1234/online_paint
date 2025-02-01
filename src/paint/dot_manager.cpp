#include "dot_manager.hpp"

void DotManager::addDot(const Dot& dot)
{
    const auto it = std::find_if(dots_.begin(), dots_.end(), 
        [dot](const Dot& d)
        {
            return dot.x == d.x && dot.y == d.y;
        });
    
    if (it == dots_.end())
    {
        dots_.emplace_back(dot);
    }
    else
    {
        dots_.erase(it);
        dots_.emplace_back(dot);
    }
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