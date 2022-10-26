
#include <chrono>
#include <xieite/Timer.hpp>

xieite::Timer::Timer() noexcept
: start(std::chrono::high_resolution_clock::now()) {}

void xieite::Timer::reset() noexcept {
	start = std::chrono::high_resolution_clock::now();
}
