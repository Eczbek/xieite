#ifndef DETAIL_XTE_HEADER_UTIL_AS_CONST_LVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_CONST_LVALUE
#
#	include "../util/as_const.hpp"
#	include "../util/as_lvalue.hpp"

namespace xte {
	inline constexpr auto as_const_lvalue = [][[nodiscard]](auto&& x) static noexcept -> auto& {
		return xte::as_lvalue(xte::as_const(x));
	};
}

#endif
