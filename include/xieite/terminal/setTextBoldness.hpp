#ifndef XIEITE_HEADER_TERMINAL_SETTEXTBOLD
#	define XIEITE_HEADER_TERMINAL_SETTEXTBOLD

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextBoldness(const bool value) noexcept {
		return value ? "\u001b[1m" : "\u001b[21m";
	}
}

#endif
