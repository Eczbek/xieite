#ifndef DETAIL_XIEITE_HEADER_MATH_SUB_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_SUB_OVERFLOW
#
#	include <concepts>
#	include <limits>
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool sub_overflow(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && (xieite::neg(rest) ? ((std::numeric_limits<T>::max() + rest) < first) : ((std::numeric_limits<T>::min() + rest) > first))) {
					return true;
				}
				first -= static_cast<T>(rest);
				return false;
			})());
	}
}

#endif
