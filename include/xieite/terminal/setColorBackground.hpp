#ifndef XIEITE_HEADER_TERMINAL_SETCOLORBACKGROUND
#	define XIEITE_HEADER_TERMINAL_SETCOLORBACKGROUND

#	include <string>
#	include <xieite/graphics/Color.hpp>
#	include <xieite/math/toBase.hpp>

namespace xieite::terminal {
	constexpr std::string setColorBackground(const xieite::graphics::Color& color) noexcept {
		return "\u001b[48;2;" + xieite::math::toBase(color.red, 10) + ';' + xieite::math::toBase(color.green, 10) + ';' + xieite::math::toBase(color.blue, 10) + 'm';
	}

	constexpr std::string setColorBackground() noexcept {
		return "\u001b[48m";
	}
}

#endif
