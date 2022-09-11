
#include <gcufl/io/eraseScreen.hpp>
#include <iostream>


void gcufl::io::eraseScreen(const int erasor, const char prefix) noexcept {
	std::cout << prefix << '[' << erasor << 'J';
}
