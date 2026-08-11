#ifndef DETAIL_XTE_HEADER_UTIL_AS_CONST_XVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_CONST_XVALUE
#
#	include "../util/as_const.hpp"
#	include "../util/as_xvalue.hpp"

namespace xte {
	inline constexpr auto as_const_xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return xte::as_xvalue(xte::as_const(x));
	};
}

#endif
