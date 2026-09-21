#ifndef DETAIL_XTE_HEADER_MATH_CONSTANTS
#	define DETAIL_XTE_HEADER_MATH_CONSTANTS
#
#	include "../arithmetic.hpp"
#	include "../array.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include <meta>

namespace xte {
	template<xte::is_arithmetic arithmetic_type>
	constexpr auto factorial = std::define_static_array(([] {
		xte::array<arithmetic_type> result = { 1 };
		while (auto next = xte::mul_checked(result.size(), result.back())) {
			result.append(*next);
		}
		return result;
	})());

	template<xte::is_arithmetic T>
	constexpr auto fibonacci = std::define_static_array(([] {
		xte::array<T> result = { 0, 1 };
		while (auto next = xte::add_checked(result.back(), result.back(1))) {
			result.append(*next);
		}
		return result;
	})());
}

#endif
