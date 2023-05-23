#ifndef XIEITE_HEADER_TERMINAL_SETCOLORDIM
#	define XIEITE_HEADER_TERMINAL_SETCOLORDIM

#	include <string_view>

namespace xieite::terminal {
	constexpr std::string_view setColorDim(const bool value) noexcept {
		return value ? "\u001b[2m" : "\u001b[22m";
	}
}

#endif
