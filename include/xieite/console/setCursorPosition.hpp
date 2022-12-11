#pragma once
#include <string> // std::string
#include <xieite/console/CursorPosition.hpp>

namespace xieite::console {
	constexpr std::string setCursorPosition(const xieite::console::CursorPosition position) noexcept {
		return "\x1b[" + (position.row + 1) + ';' + (position.column + 1) + 'H';
	}
}
