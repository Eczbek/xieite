#ifndef DETAIL_XTE_HEADER_DATA_PTR_DIFF
#	define DETAIL_XTE_HEADER_DATA_PTR_DIFF
#
#	include "../trait/is_ptr.hpp"
#	include "../util/numbers.hpp"
#	include <limits>

namespace xte {
	[[nodiscard]] constexpr xte::uz ptr_diff(xte::is_ptr auto first, decltype(first) last, xte::uz max) noexcept {
		static constexpr auto iptrdiff_max = std::numeric_limits<xte::iptrdiff>::max();
		if (max <= iptrdiff_max) {
			return static_cast<xte::uz>(last - first);
		}
		if ((max == static_cast<xte::uptrdiff>(-1)) && ((first + max) == last)) {
			return max;
		}
		if (max < static_cast<xte::uptrdiff>(-1)) {
			return static_cast<xte::uz>(iptrdiff_max) + static_cast<xte::uz>(last - (first + iptrdiff_max));
		}
		return ((first + max / 2) < last)
			? (xte::ptr_diff(first + max / 2, last, max / 2) + max / 2)
			: xte::ptr_diff(first, last, max / 2 + 1);
	}
}

#endif
