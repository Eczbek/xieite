#ifndef DETAIL_XIEITE_HEADER_MATH_POW_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_POW_OVERFLOW
#
#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../fn/unroll.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto pow_overflow(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		if constexpr (using Type = decltype(first); std::floating_point<Type>) {
			return false;
		} else {
			return sizeof...(rest)
				&& first
				&& (first != 1)
				&& (std::unsigned_integral<Type> || (first != static_cast<Type>(-1)))
				&& xieite::unroll<sizeof...(rest)>([&first, rest...]<std::size_t... i> -> bool {
					return (... || ([&first](auto next) -> bool {
						// Store power in some deduced fractional type
						const auto pow = std::pow(first, next);
						if ((pow > std::numeric_limits<Type>::max()) || (!std::unsigned_integral<Type> && (pow < std::numeric_limits<Type>::min()))) {
							return true;
						}
						if constexpr (i < (sizeof...(rest) - 1)) {
							first = static_cast<Type>(pow);
						}
						return false;
					})(rest));
				});
		}
	}
}

#endif
