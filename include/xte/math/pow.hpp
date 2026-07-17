#ifndef DETAIL_XTE_HEADER_MATH_POW
#	define DETAIL_XTE_HEADER_MATH_POW
#
#	include "../math/abs.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../util/make.hpp"
#	include <cmath>
#	include <type_traits>
#	include <utility>

namespace xte {
	[[nodiscard]] constexpr auto pow(xte::is_arithmetic auto base, xte::is_arithmetic auto exp) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(base), decltype(exp)>; xte::is_float<common_type>) {
			return std::pow(xte::make<common_type>(base), xte::make<common_type>(exp));
		} else {
			if ((base == 1) || (exp == 1)) {
				return static_cast<common_type>(base);
			}
			if (base == -1) {
				return static_cast<common_type>((exp & 1) ? base : -base);
			}
			if (exp < 0) {
				if (!base) {
					std::unreachable();
				}
				return static_cast<common_type>(0);
			}
			if (!exp) {
				return static_cast<common_type>(1);
			}
			common_type power = 1;
			while (base && (exp > 1)) {
				if (exp & 1) {
					power *= base;
					--exp;
				}
				base *= base;
				exp >>= 1;
			}
			return power * base;
		}
	}
}

#endif
