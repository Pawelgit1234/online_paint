#pragma once

#include <chrono>
#include <cstdint>
#include <thread>

#include "../settings.hpp"

class FpsCounter
{
    public:
        FpsCounter();

        void update();
        uint16_t getFps() const;

    private:
        std::chrono::high_resolution_clock::time_point lastTime_;
        uint16_t frameCount_;
        uint16_t fps_;
};