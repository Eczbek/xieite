
#include <gcufl/console/setStyle.hpp>
#include <iostream>

void gcufl::console::setStyle(const int style) noexcept {
	std::cout << "\u001b[" << style << 'm';
}

void gcufl::console::setStyle(const int effect, const int foreground) noexcept {
	std::cout << "\u001b[" << effect << ';' << foreground << 'm';
}

void gcufl::console::setStyle(const int effect, const int foreground, const int background) noexcept {
	std::cout << "\u001b[" << effect << ';' << foreground << ';' << background << 'm';
}
