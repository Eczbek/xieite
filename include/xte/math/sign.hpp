#ifndef DETAIL_XTE_HEADER_MATH_SIGN
#	define DETAIL_XTE_HEADER_MATH_SIGN
#
#	include "../math/is_neg.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	inline constexpr auto sign = [][[nodiscard]](xte::is_number auto... values) static noexcept {
		return static_cast<std::common_type_t<decltype(values)...>>((1 * ... * (!xte::is_neg(values) * 2 - 1)));
	};
}

#endif
