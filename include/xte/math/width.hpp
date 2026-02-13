#ifndef DETAIL_XTE_HEADER_MATH_WIDTH
#	define DETAIL_XTE_HEADER_MATH_WIDTH
#
#	include "../trait/is_int.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<xte::is_int Int>
	constexpr xte::uz width = ([] {
		xte::uz width = 8;
		for (auto x = static_cast<Int>(128); (x = static_cast<Int>(x << 1)); ++width);
		return width;
	})();
}

#endif
