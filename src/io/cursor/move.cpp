
#include <gcufl/io/cursor/move.hpp>
#include <iostream>

void gcufl::io::cursor::move(const char direction, const int distance, const char prefix) noexcept {
	std::cout << prefix << '[' << distance << direction;
}
