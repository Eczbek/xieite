
#include <gcufl/io/eraseScreen.hpp>
#include <iostream>


void gcufl::io::eraseScreen(const int erasor) noexcept {
	std::cout << "\u001b[" << erasor << 'J';
}
