
#include <gcufl/io/cursor/move.hpp>
#include <iostream>

void gcufl::io::cursor::move(const char direction, const int distance) noexcept {
	std::cout << "\u001b[" << distance << direction;
}
