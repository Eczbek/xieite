#ifndef DETAIL_XIEITE_HEADER_MATH_ISDIGIT
#	define DETAIL_XIEITE_HEADER_MATH_ISDIGIT
#
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<xieite::is_ch Ch = char>
	[[nodiscard]] constexpr bool isdigit(Ch c) noexcept {
		return (c >= '0') && (c <= '9');
	}
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/lex.charset#5.sentence-5
