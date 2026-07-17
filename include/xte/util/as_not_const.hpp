#ifndef DETAIL_XTE_HEADER_UTIL_AS_NOT_CONST
#	define DETAIL_XTE_HEADER_UTIL_AS_NOT_CONST
#
#	include "../trait/drop_const.hpp"

namespace xte {
	inline constexpr auto as_not_const = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return const_cast<xte::drop_const<decltype(x)&&>>(x);
	};
}

#endif
