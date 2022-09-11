
#include <gcufl/io/eraseLine.hpp>
#include <iostream>


void gcufl::io::eraseLine(const int erasor, const char prefix) noexcept {
	std::cout << prefix << '[' << erasor << 'K';
}
