#ifndef XIEITE_HEADER_TERMINAL_RESETSTYLE
#	define XIEITE_HEADER_TERMINAL_RESETSTYLE

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view resetStyles() noexcept {
		return "\u001b[0m";
	}
}

#endif
