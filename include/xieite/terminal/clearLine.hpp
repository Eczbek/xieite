#ifndef XIEITE_HEADER_TERMINAL_CLEARLINE
#	define XIEITE_HEADER_TERMINAL_CLEARLINE

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view clearLine() noexcept {
		return "\u001b[2K";
	}
}

#endif
