
#include <gcufl/console/eraseScreen.hpp>
#include <iostream>

void gcufl::console::eraseScreen(const int erasor) noexcept {
	std::cout << "\u001b[" << erasor << 'J';
}
