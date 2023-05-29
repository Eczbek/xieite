#ifndef XIEITE_HEADER_TERMINAL_SETCURSORALTERNATIVE
#	define XIEITE_HEADER_TERMINAL_SETCURSORALTERNATIVE

#	include <string_view>
#	include <xieite/math/baseTo.hpp>

namespace xieite::terminal {
	constexpr std::string_view setCursorAlternative(const bool value) noexcept {
		return value ? "\u001b[s" : "\u001b[u";
	}
}

#endif
