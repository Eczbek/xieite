
#include <gcufl/io/setStyle.hpp>
#include <iostream>


void gcufl::io::setStyle(const int style, const char prefix) noexcept {
	std::cout << prefix << '[' << style << 'm';
}

void gcufl::io::setStyle(const int effect, const int foreground, const char prefix) noexcept {
	std::cout << prefix << '[' << effect << ';' << foreground << 'm';
}

void gcufl::io::setStyle(const int effect, const int foreground, const int background, const char prefix) noexcept {
	std::cout << prefix << '[' << effect << ';' << foreground << ';' << background << 'm';
}
