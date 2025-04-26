#ifndef DETAIL_XIEITE_HEADER_MATH_EXP_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_EXP_OVERFLOW
#
#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr bool exp_overflow(Arith first, Ariths... rest) noexcept {
		return sizeof...(Ariths)
			&& first
			&& (first != 1)
			&& (std::unsigned_integral<Arith> || (first != static_cast<Arith>(-1)))
			&& (... || ([&first, rest] -> bool {
				// Store power in some deduced fractional type
				const auto pow = std::pow(first, rest);
				if ((pow > std::numeric_limits<Arith>::max()) || (!std::unsigned_integral<Arith> && (pow < std::numeric_limits<Arith>::min()))) {
					return true;
				}
				first = static_cast<Arith>(pow);
				return false;
			})());
	}
}

#endif
