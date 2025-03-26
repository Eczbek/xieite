#ifndef DETAIL_XIEITE_HEADER_MATH_MINMAX_MAGN
#	define DETAIL_XIEITE_HEADER_MATH_MINMAX_MAGN
#
#	include <concepts>
#	include "../math/closest.hpp"
#	include "../math/farthest.hpp"
#	include "../math/interval.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr xieite::interval<T> minmax_magn(T first, Ts... rest) noexcept {
		auto result = xieite::interval<T>(first, first);
		(..., (result =
			xieite::interval<T>(
				xieite::closest(static_cast<T>(0), result.start, static_cast<T>(rest)),
				xieite::farthest(static_cast<T>(0), result.end, static_cast<T>(rest))
			)
		));
		return result;
	}
}

#endif
