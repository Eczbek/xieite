#ifndef DETAIL_XTE_HEADER_MATH_POW
#	define DETAIL_XTE_HEADER_MATH_POW
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/abs.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/mul_checked.hpp"
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
	[[nodiscard]] constexpr xte::opt<common_type> pow_checked(base_type base, exp_type exp) noexcept {
		if constexpr (xte::is_float<common_type>) {
			return (xte::is_finite(base) && xte::is_finite(exp)) ? xte::opt(std::pow(xte::make<common_type>(base), xte::make<common_type>(exp))) : xte::null;
		} else {
			if ((base == 1) || (exp == 1)) {
				return xte::opt<common_type>(base);
			}
			if (base == -1) {
				return xte::opt<common_type>((exp & 1) ? base : -base);
			}
			if (exp < 0) {
				if (!base) {
					return xte::null;
				}
				return xte::opt<common_type>(0);
			}
			if (!exp) {
				return xte::opt<common_type>(1);
			}
			common_type power = 1;
			while (power && base && (exp > 1)) {
				if (exp & 1) {
					if (auto prod = xte::mul_checked(power, base)) {
						power = *prod;
					} else {
						return xte::null;
					}
					--exp;
				}
				if (auto prod = xte::mul_checked(base, base)) {
					base = *prod;
				} else {
					return xte::null;
				}
				exp >>= 1;
			}
			return xte::opt(power * static_cast<common_type>(base));
		}
	}
}

#endif
