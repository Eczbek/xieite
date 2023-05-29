#ifndef XIEITE_HEADER_TERMINAL_SETCOLORPOSITION
#	define XIEITE_HEADER_TERMINAL_SETCOLORPOSITION

#	include <string>
#	include <xieite/terminal/Position.hpp>
#	include <xieite/math/baseTo.hpp>

namespace xieite::terminal {
	constexpr std::string setCursorPosition(const xieite::terminal::Position position) noexcept {
		return "\u001b[" + xieite::math::baseTo(position.row + 1, 10) + ';' + xieite::math::baseTo(position.column + 1, 10) + 'H';
	}
}

#endif
