#ifndef DETAIL_XTE_HEADER_UTIL_AS_VOLATILE_LVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_VOLATILE_LVALUE
#
#	include "../util/as_lvalue.hpp"
#	include "../util/as_volatile.hpp"

namespace xte {
	inline constexpr auto as_volatile_lvalue = [][[nodiscard]](auto&& x) static noexcept -> auto& {
		return xte::as_lvalue(xte::as_volatile(x));
	};
}

#endif
