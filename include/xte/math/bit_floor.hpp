#ifndef DETAIL_XTE_HEADER_MATH_BIT_FLOOR
#	define DETAIL_XTE_HEADER_MATH_BIT_FLOOR
#
#	include "../math/leading_zeros.hpp"
#	include "../math/lshift.hpp"
#	include "../math/width.hpp"
#	include "../trait/is_int.hpp"
#	include <type_traits>

namespace xte {
	inline constexpr auto bit_floor = []<xte::is_int T>[[nodiscard]](T x) static noexcept -> T {
		return xte::lshift(static_cast<T>(1), xte::width<T> - xte::leading_zeros(x) - 1);
	};
}

#endif
