#ifndef XIEITE_HEADER_TERMINAL_SETTEXTSTRIKETHROUGH
#	define XIEITE_HEADER_TERMINAL_SETTEXTSTRIKETHROUGH

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setTextStriked(const bool value) noexcept {
		return value ? "\u001b[9m" : "\u001b[29m";
	}
}

#endif
