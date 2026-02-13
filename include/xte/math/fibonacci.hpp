#ifndef DETAIL_XTE_HEADER_MATH_FIBONACCI
#	define DETAIL_XTE_HEADER_MATH_FIBONACCI
#
#	include "../data/array.hpp"
#	include "../func/gen.hpp"
#	include "../math/add_checked.hpp"
#	include "../trait/is_number.hpp"
#	include <meta>

namespace xte {
	template<xte::is_number T>
	constexpr auto fibonacci = std::define_static_array(([] {
		xte::array<T> result = { 0, 1 };
		return result += xte::gen([&] { return xte::add_checked(result.back(), result.back(1)); });
	})());
}

#endif
