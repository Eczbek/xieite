#ifndef DETAIL_XTE_HEADER_UTIL_AS_XVALUE_IF_NOEX
#	define DETAIL_XTE_HEADER_UTIL_AS_XVALUE_IF_NOEX
#
#	include "../util/as_xvalue.hpp"

namespace xte {
	inline constexpr auto as_xvalue_if_noex =
		[][[nodiscard]](auto&& x) noexcept -> auto&&
		requires(requires { { auto(xte::as_xvalue(x)) } noexcept; }
			|| requires { auto(x); })
		{
			if constexpr (requires { { auto(xte::as_xvalue(x)) } noexcept; }) {
				return xte::as_xvalue(x);
			} else {
				return x;
			}
		};
}

#endif
