#ifndef DETAIL_XTE_HEADER_LIMIT_WIDTH
#	define DETAIL_XTE_HEADER_LIMIT_WIDTH
#
#	include "../core/types.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	template<xte::is_int Int>
	constexpr xte::uz width = ([] {
		xte::uz width = 8;
		for (Int x = static_cast<Int>(128); (x = static_cast<Int>(x << 1)); ++width);
		return width;
	})();
}

#endif
