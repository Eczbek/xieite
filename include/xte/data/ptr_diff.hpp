#ifndef DETAIL_XTE_HEADER_DATA_PTR_DIFF
#	define DETAIL_XTE_HEADER_DATA_PTR_DIFF
#
#	include "../math/highest.hpp"
#	include "../util/numbers.hpp"

namespace xte {
	[[nodiscard]] constexpr xte::uz ptr_diff(auto* first, decltype(first) last, xte::uz max) noexcept {
		if (max <= xte::highest<xte::iptrdiff>) {
			return static_cast<xte::uz>(last - first);
		}
		if (max <= static_cast<xte::uptrdiff>(-1)) {
			return static_cast<xte::uz>(static_cast<xte::uptrdiff>(last - (first + xte::highest<xte::iptrdiff> + 1)) ^ (static_cast<xte::uptrdiff>(xte::highest<xte::iptrdiff>) + 1));
		}
		return ((first + max / 2) < last)
			? (xte::ptr_diff(first + max / 2 + 1, last, max - max / 2 - 1) + max / 2 + 1)
			: xte::ptr_diff(first, last, max / 2);
	}
}

#endif
