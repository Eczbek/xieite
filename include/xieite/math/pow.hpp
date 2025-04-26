#ifndef DETAIL_XIEITE_HEADER_MATH_POW
#	define DETAIL_XIEITE_HEADER_MATH_POW
#
#	include <cmath>
#	include <concepts>
#	include <stdexcept>
#	include "../math/neg.hpp"
#	include "../math/split_bool.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith pow(Arith base, Arith exp) {
		if constexpr (std::floating_point<Arith>) {
			return std::pow(base, exp);
		} else {
			if ((base == 1) || (exp == 1)) {
				return base;
			}
			if (!std::unsigned_integral<Arith> && (base == static_cast<Arith>(-1))) {
				return base * xieite::split_bool(exp & 1);
			}
			if (!base || !exp) {
				if (xieite::neg(exp)) {
					throw std::out_of_range("must not take power of zero to negative exp");
				}
				return !exp;
			}
			Arith result = 1;
			while (exp) {
				if (exp & 1) {
					result *= base;
				}
				exp >>= 1;
				base *= base;
			}
			return result;
		}
	}
}

#endif
