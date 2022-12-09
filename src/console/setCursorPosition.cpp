#include <iostream> // std::cout
#include <xieite/console/setCursorPosition.hpp> // xieite::console::setCursorPosition
#include <xieite/console/CursorPosition.hpp> // xieite::console::CursorPosition

void xieite::console::setCursorPosition(const xieite::console::CursorPosition position) noexcept {
	std::cout << "\x1b[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}
