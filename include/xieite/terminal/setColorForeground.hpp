#ifndef XIEITE_HEADER_TERMINAL_SETCOLORFOREGROUND
#	define XIEITE_HEADER_TERMINAL_SETCOLORFOREGROUND

#	include <string>
#	include <xieite/graphics/Color.hpp>
#	include <xieite/math/baseTo.hpp>

namespace xieite::terminal {
	constexpr std::string setColorForeground(const xieite::graphics::Color& color) noexcept {
		return "\u001b[38;2;" + xieite::math::baseTo(color.red, 10) + ';' + xieite::math::baseTo(color.green, 10) + ';' + xieite::math::baseTo(color.blue, 10) + 'm';
	}

	constexpr std::string setColorForeground() noexcept {
		return "\u001b[38m";
	}
}

#endif
