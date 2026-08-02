#ifndef DETAIL_XTE_HEADER_MATH_POW
#	define DETAIL_XTE_HEADER_MATH_POW
#
#	include "../math/abs.hpp"
#	include "../math/mul.hpp"
#	include "../meta/end.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../util/make.hpp"
#	include <cmath>
#	include <type_traits>
#	include <utility>

namespace xte {
	template<xte::is_arithmetic base_type, xte::is_arithmetic exp_type, xte::end...,
		typename common_type = std::common_type_t<base_type, exp_type>>
	[[nodiscard]] constexpr common_type pow(base_type base, exp_type exp) noexcept {
		if constexpr (xte::is_float<common_type>) {
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
					power = xte::mul(power, base);
					--exp;
				}
				base = xte::mul(base, base);
				exp >>= 1;
			}
			return power * static_cast<common_type>(base);
		}
	}
}

#endif
