#ifndef XIEITE_HEADER_TERMINAL_SETTEXTBLINK
#	define XIEITE_HEADER_TERMINAL_SETTEXTBLINK

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextBlink(const bool value) noexcept {
		return value ? "\u001b[5m" : "\u001b[25m";
	}
}

#endif
