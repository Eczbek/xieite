#ifndef DETAIL_XTE_HEADER_MATH_NEG
#	define DETAIL_XTE_HEADER_MATH_NEG
#
#	include "../trait/is_number.hpp"

namespace xte {
	inline constexpr auto neg = [][[nodiscard]](xte::is_number auto x) static noexcept -> bool {
		return x < 0;
	};
}

#endif
