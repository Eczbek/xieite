#ifndef DETAIL_XTE_HEADER_DATA_PTR_DIFF
#	define DETAIL_XTE_HEADER_DATA_PTR_DIFF
#
#	include "../math/highest.hpp"
#	include "../util/numbers.hpp"

namespace xte {
	[[nodiscard]] constexpr xte::uz ptr_diff(auto* begin, decltype(begin) end, xte::uz size) noexcept {
		if (size <= static_cast<xte::uz>(xte::highest<xte::iptrdiff>)) {
			return static_cast<xte::uz>(end - begin);
		}
		if (size <= static_cast<xte::uptrdiff>(-1)) {
			return static_cast<xte::uz>(static_cast<xte::uptrdiff>(end - (begin + xte::highest<xte::iptrdiff> + 1)) ^ (static_cast<xte::uptrdiff>(xte::highest<xte::iptrdiff>) + 1));
		}
		return ((begin + size / 2) < end)
			? (xte::ptr_diff(begin + size / 2 + 1, end, size - size / 2 - 1) + size / 2 + 1)
			: xte::ptr_diff(begin, end, size / 2);
	}
}

#endif
