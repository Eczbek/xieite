
#include <gcufl/console/setStyle.hpp>
#include <iostream>

void gcufl::console::setStyle(const int style) noexcept {
	std::cout << "\x1b[" << style << 'm';
}

void gcufl::console::setStyle(const int effect, const int foreground) noexcept {
	std::cout << "\x1b[" << effect << ';' << foreground << 'm';
}

void gcufl::console::setStyle(const int effect, const int foreground, const int background) noexcept {
	std::cout << "\x1b[" << effect << ';' << foreground << ';' << background << 'm';
}
