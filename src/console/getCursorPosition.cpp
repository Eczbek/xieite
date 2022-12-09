#include <cstdio> // std::scanf
#include <iostream> // std::cout
#include <xieite/console/getCursorPosition.hpp>
#include <xieite/console/CursorPosition.hpp>
#include <xieite/console/RawLock.hpp>

xieite::console::CursorPosition xieite::console::getCursorPosition() noexcept {
	xieite::console::RawLock RawLock;
	std::cout << "\x1b[6n";
	xieite::console::CursorPosition position;
	std::scanf("\x1b[%d;%dR", &position.row, &position.column);
	return xieite::console::CursorPosition(position.row - 1, position.column - 1);
}
