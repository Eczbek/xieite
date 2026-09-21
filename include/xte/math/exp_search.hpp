#ifndef DETAIL_XTE_HEADER_MATH_EXP_SEARCH
#	define DETAIL_XTE_HEADER_MATH_EXP_SEARCH
#
#	include "../approx_equal.hpp"
#	include "../arithmetic.hpp"
#	include "../detect/feature.hpp"
#	include "../limits.hpp"
#	include "../make.hpp"
#	include "../math/avg.hpp"
#	include "../math/clamp.hpp"
#	include "../math/diff.hpp"
#	include "../meta/end.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_callable_lvalue.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_unsigned_int.hpp"
#	include <type_traits>

namespace xte {
	template<xte::is_arithmetic arithmetic_type0, xte::is_arithmetic arithmetic_type1, xte::end...,
		typename common_type = std::common_type_t<arithmetic_type0, arithmetic_type1>>
	[[nodiscard]] constexpr common_type exp_search(xte::is_callable_lvalue<bool(common_type)> auto&& predicate, arithmetic_type0 limit0, arithmetic_type1 limit1)
	noexcept(xte::is_callable_lvalue<decltype(predicate), bool(common_type) noexcept>) {
		auto [min, max] = xte::minmax(xte::make<common_type>(limit0), xte::make<common_type>(limit1));
		while (true) {
			common_type mid = xte::avg(min, max);
			if constexpr (xte::is_int<common_type>) {
				if (xte::diff(max, min) < 2) {
					return max;
				}
			} else if (xte::approx_equal(mid, max)) {
				return mid;
			}
			(predicate(mid) ? min : max) = mid;
		}
	}

	template<xte::is_arithmetic arithmetic_type>
	[[nodiscard]] constexpr arithmetic_type exp_search(xte::is_callable_lvalue<bool(arithmetic_type)> auto&& predicate)
	noexcept(xte::is_callable_lvalue<decltype(predicate), bool(arithmetic_type) noexcept>) {
		if constexpr (xte::is_int<arithmetic_type>) {
			return xte::exp_search(predicate, xte::lowest<arithmetic_type>, xte::highest<arithmetic_type>);
		} else {
			arithmetic_type mid = 0;
			if (!static_cast<bool>(predicate(static_cast<arithmetic_type>(0)))) {
				arithmetic_type min = -1;
				while (!static_cast<bool>(predicate(min))) {
					mid = min;
					if (auto next = xte::mul_checked(min, static_cast<arithmetic_type>(2))) {
						min = *next;
						continue;
					}
					return xte::exp_search(predicate, mid, xte::lowest<arithmetic_type>);
				}
				return xte::exp_search(predicate, mid, min);
			}
			arithmetic_type max = 1;
			while (predicate(max)) {
				mid = max;
				if (auto next = xte::mul_checked(max, static_cast<arithmetic_type>(2))) {
					max = *next;
					continue;
				}
				return xte::exp_search(predicate, mid, xte::highest<arithmetic_type>);
			}
			return xte::exp_search(predicate, mid, max);
		}
	}
}

#endif
