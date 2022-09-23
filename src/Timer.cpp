
#include <chrono>
#include <gcufl/Timer.hpp>


gcufl::Timer::Timer() noexcept
: start(std::chrono::high_resolution_clock::now()) {}

void gcufl::Timer::reset() noexcept {
	start = std::chrono::high_resolution_clock::now();
}
