#ifndef DETAIL_XTE_HEADER_MATH_IS_NAN
#	define DETAIL_XTE_HEADER_MATH_IS_NAN
#
#	include "../trait/is_number.hpp"

namespace xte {
	inline constexpr auto is_nan = [][[nodiscard]](xte::is_number auto x) static noexcept {
		return x != x;
	};
}

#endif
