#ifndef XIEITE_HEADER_TERMINAL_SETTEXTUNDERLINE
#	define XIEITE_HEADER_TERMINAL_SETTEXTUNDERLINE

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextUnderline(const bool value) noexcept {
		return value ? "\u001b[4m" : "\u001b[24m";
	}
}

#endif
