#ifndef DETAIL_XTE_HEADER_UTIL_AS_NOT_VOLATILE
#	define DETAIL_XTE_HEADER_UTIL_AS_NOT_VOLATILE
#
#	include "../trait/drop_volatile.hpp"

namespace xte {
	inline constexpr auto as_not_volatile = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return const_cast<xte::drop_volatile<decltype(x)&&>>(x);
	};
}

#endif
