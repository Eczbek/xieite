#ifndef DETAIL_XTE_HEADER_MATH_FACTORIAL
#	define DETAIL_XTE_HEADER_MATH_FACTORIAL
#
#	include "../data/array.hpp"
#	include "../func/gen.hpp"
#	include "../math/mul_checked.hpp"
#	include "../trait/is_number.hpp"
#	include <meta>

namespace xte {
	template<xte::is_number T>
	constexpr auto factorial = std::define_static_array(([] {
		xte::array<T> result = { 1 };
		return result += xte::gen([&] { return xte::mul_checked(result.size(), result.back()); });
	})());
}

#endif
