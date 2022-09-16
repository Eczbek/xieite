
#include <gcufl/io/eraseLine.hpp>
#include <iostream>


void gcufl::io::eraseLine(const int erasor) noexcept {
	std::cout << "\u001b[" << erasor << 'K';
}
