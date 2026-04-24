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
		if (max <= static_cast<xte::uptrdiff>(-1)) {
			return static_cast<xte::uz>(static_cast<xte::uptrdiff>(last - (first + iptrdiff_max + 1)) ^ (static_cast<xte::uptrdiff>(iptrdiff_max) + 1));
		}
		return ((first + max / 2) < last)
			? (xte::ptr_diff(first + max / 2 + 1, last, max - max / 2 - 1) + max / 2 + 1)
			: xte::ptr_diff(first, last, max / 2);
	}
}

#endif
