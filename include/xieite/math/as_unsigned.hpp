#ifndef DETAIL_XIEITE_HEADER_MATH_AS_UNSIGNED
#	define DETAIL_XIEITE_HEADER_MATH_AS_UNSIGNED
#
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	inline constexpr auto as_unsigned = []<xieite::is_arith Arith>(Arith x) static noexcept {
		return static_cast<xieite::try_unsigned<Arith>>(x);
	};
}

#endif
