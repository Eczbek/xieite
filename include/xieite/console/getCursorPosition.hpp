#pragma once
#include <cstdio> // std::scanf
#include <iostream> // std::cout
#include <xieite/console/CursorPosition.hpp>
#include <xieite/console/RawLock.hpp>

namespace xieite::console {
	[[nodiscard]]
	inline xieite::console::CursorPosition getCursorPosition() noexcept {
		xieite::console::RawLock rawLock;
		std::cout << "\x1b[6n";
		xieite::console::CursorPosition position;
		std::scanf("\x1b[%d;%dR", &position.row, &position.column);
		return xieite::console::CursorPosition(position.row - 1, position.column - 1);
	}
}
