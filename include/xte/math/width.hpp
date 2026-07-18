#ifndef DETAIL_XTE_HEADER_MATH_WIDTH
#	define DETAIL_XTE_HEADER_MATH_WIDTH
#
#	include "../trait/is_int.hpp"
#	include "../util/number_types.hpp"

namespace xte {
	template<xte::is_int T>
	constexpr xte::uz width = ([] {
		xte::uz width = 8;
		for (auto x = static_cast<T>(128); (x = static_cast<T>(x << 1)); ++width);
		return width;
	})();
}

#endif
