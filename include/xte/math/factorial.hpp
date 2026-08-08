#ifndef DETAIL_XTE_HEADER_MATH_FACTORIAL
#	define DETAIL_XTE_HEADER_MATH_FACTORIAL
#
#	include "../data/array.hpp"
#	include "../math/mul_checked.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include <meta>

namespace xte {
	template<xte::is_arithmetic T>
	constexpr auto factorial = std::define_static_array(([] {
		xte::array<T> result = { 1 };
		while (auto next = xte::mul_checked(result.size(), result.back())) {
			result.append(*next);
		}
		return result;
	})());
}

#endif
