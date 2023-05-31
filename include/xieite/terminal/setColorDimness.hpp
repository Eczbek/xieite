#ifndef XIEITE_HEADER_TERMINAL_SETCOLORDIM
#	define XIEITE_HEADER_TERMINAL_SETCOLORDIM

#	warning "'xieite::terminal::setColorDimness' is deprecated"

#	include <string_view>

namespace xieite::terminal {
	[[deprecated]]
	constexpr std::string_view setColorDimness(const bool value) noexcept {
		return value ? "\u001b[2m" : "\u001b[22m";
	}
}

#endif
