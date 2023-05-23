#ifndef XIEITE_HEADER_TERMINAL_CLEARSCREEN
#	define XIEITE_HEADER_TERMINAL_CLEARSCREEN

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view clearScreen() noexcept {
		return "\u001b[2J";
	}
}

#endif
