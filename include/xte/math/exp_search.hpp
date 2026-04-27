#ifndef DETAIL_XTE_HEADER_MATH_EXP_SEARCH
#	define DETAIL_XTE_HEADER_MATH_EXP_SEARCH
#
#	include "../math/approx_equal.hpp"
#	include "../math/avg.hpp"
#	include "../math/diff.hpp"
#	include "../math/minmax.hpp"
#	include "../math/mul_checked.hpp"
#	include "../meta/end.hpp"
#	include "../preproc/feature.hpp"
#	include "../trait/is_callable_lref.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_noex_callable.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_unsigned.hpp"
#	include <type_traits>

namespace xte {
	template<xte::is_number T, xte::is_number U, xte::end...,
		typename common_type = std::common_type_t<T, U>>
	[[nodiscard]] constexpr T exp_search(xte::is_callable_lref<bool(common_type)> auto&& predicate, T limit0, U limit1)
	noexcept(xte::is_noex_callable<decltype(predicate)&, bool(common_type)>) {
		auto [min, max] = xte::minmax(static_cast<common_type>(limit0), static_cast<common_type>(limit1));
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

	template<xte::is_number T>
	[[nodiscard]] constexpr T exp_search(xte::is_callable_lref<bool(T)> auto&& predicate)
	noexcept(xte::is_noex_callable<decltype(predicate)&, bool(T)>) {
		T mid = 0;
		if constexpr (!xte::is_unsigned<T>) {
			if (!static_cast<bool>(predicate(static_cast<T>(0)))) {
				T min = -1;
				while (!static_cast<bool>(predicate(min))) {
					mid = min;
					if (auto next = xte::mul_checked(min, static_cast<T>(2))) {
						min = *next;
						continue;
					}
					return xte::exp_search(predicate, mid, std::numeric_limits<T>::lowest());
				}
				return xte::exp_search(predicate, mid, min);
			}
		}
		T max = 1;
		while (predicate(max)) {
			mid = max;
			if (auto next = xte::mul_checked(max, static_cast<T>(2))) {
				max = *next;
				continue;
			}
			return xte::exp_search(predicate, mid, std::numeric_limits<T>::max());
		}
		return xte::exp_search(predicate, mid, max);
	}
}

#endif
