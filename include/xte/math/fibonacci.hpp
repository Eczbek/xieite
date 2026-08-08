#ifndef DETAIL_XTE_HEADER_MATH_FIBONACCI
#	define DETAIL_XTE_HEADER_MATH_FIBONACCI
#
#	include "../data/array.hpp"
#	include "../math/add_checked.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include <meta>

namespace xte {
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
