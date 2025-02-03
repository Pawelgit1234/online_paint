#include "fps_counter.hpp"

FpsCounter::FpsCounter() : frameCount_(0), fps_(0)
{
    lastTime_ = std::chrono::high_resolution_clock::now();
}

void FpsCounter::update()
{
    frameCount_++;
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastTime_).count();

    if (elapsed >= 1) 
    {
        fps_ = frameCount_;
        frameCount_ = 0;
        lastTime_ = now;
    }

    static auto lastFrameTime = std::chrono::high_resolution_clock::now();
    auto frameTime = std::chrono::high_resolution_clock::now() - lastFrameTime;

    if (frameTime < FRAME_DURATION)
        std::this_thread::sleep_for(FRAME_DURATION - frameTime);

    lastFrameTime = std::chrono::high_resolution_clock::now();
}

uint16_t FpsCounter::getFps() const 
{
    return fps_;
}
