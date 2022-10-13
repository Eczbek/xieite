
#include <gcufl/console/eraseScreen.hpp>
#include <iostream>

void gcufl::console::eraseScreen(const int erasor) noexcept {
	std::cout << "\x1b[" << erasor << 'J';
}
