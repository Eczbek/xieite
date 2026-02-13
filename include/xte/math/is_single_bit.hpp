#ifndef DETAIL_XTE_HEADER_MATH_IS_SINGLE_BIT
#	define DETAIL_XTE_HEADER_MATH_IS_SINGLE_BIT
#
#	include "../math/as_unsigned.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	inline constexpr auto is_single_bit = [][[nodiscard]](xte::is_int auto x) static noexcept {
		return x && !(xte::as_unsigned(x) & ~-xte::as_unsigned(x));
	};
}

#endif
