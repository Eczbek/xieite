#ifndef DETAIL_XIEITE_HEADER_MATH_ISDIGIT
#	define DETAIL_XIEITE_HEADER_MATH_ISDIGIT
#
#	include "../trait/is_char.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool isdigit(xieite::is_char auto c) noexcept {
		return (c >= '0') && (c <= '9');
	}
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/lex.charset#9.sentence-5
