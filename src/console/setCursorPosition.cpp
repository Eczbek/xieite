#include <iostream> // std::cout
#include <xieite/console/setCursorPosition.hpp>
#include <xieite/console/CursorPosition.hpp>

void xieite::console::setCursorPosition(const xieite::console::CursorPosition position) noexcept {
	std::cout << "\x1b[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}
