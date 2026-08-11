#ifndef DETAIL_XTE_HEADER_UTIL_AS_VOLATILE_XVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_VOLATILE_XVALUE
#
#	include "../util/as_volatile.hpp"
#	include "../util/as_xvalue.hpp"

namespace xte {
	inline constexpr auto as_volatile_xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return xte::as_xvalue(xte::as_volatile(x));
	};
}

#endif
