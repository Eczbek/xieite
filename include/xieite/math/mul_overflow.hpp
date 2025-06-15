#ifndef DETAIL_XIEITE_HEADER_MATH_MUL_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_MUL_OVERFLOW
#
#	include <concepts>
#	include <limits>
#	include "../fn/unroll.hpp"
#	include "../math/abs.hpp"
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr bool mul_overflow(Arith first, Ariths... rest) noexcept {
		return sizeof...(Ariths)
			&& first
			&& xieite::unroll<sizeof...(Ariths)>([&first, rest...]<std::size_t... i> -> bool {
				return (... || ([&first, rest] -> bool {
					if (rest && ((xieite::abs((xieite::neg(first) != xieite::neg(rest)) ? std::numeric_limits<Arith>::min() : std::numeric_limits<Arith>::max()) / xieite::abs(first)) < xieite::abs(rest))) {
						return true;
					}
					if constexpr (i < (sizeof...(Ariths) - 1)) {
						first *= static_cast<Arith>(rest);
					}
					return false;
				})());
			});
	}
}

#endif
