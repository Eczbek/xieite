#ifndef XIEITE_HEADER_TERMINAL_SETCOLORPOSITION
#	define XIEITE_HEADER_TERMINAL_SETCOLORPOSITION

#	include <string>
#	include <xieite/terminal/Position.hpp>
#	include <xieite/math/baseTo.hpp>

namespace xieite::terminal {
	constexpr std::string setCursorPosition(const xieite::terminal::Position position) noexcept {
		return "\u001b[" + xieite::math::baseTo(10, position.row + 1) + ';' + xieite::math::baseTo(10, position.column + 1) + 'H';
	}
}

#endif
