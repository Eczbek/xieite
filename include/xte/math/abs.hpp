#ifndef DETAIL_XTE_HEADER_MATH_ABS
#	define DETAIL_XTE_HEADER_MATH_ABS
#
#	include "../math/as_unsigned.hpp"
#	include "../math/neg.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	inline constexpr auto abs = [][[nodiscard]](xte::is_number auto x) static noexcept {
		return xte::neg(x) ? -xte::as_unsigned(x) : xte::as_unsigned(x);
	};
}

#endif
