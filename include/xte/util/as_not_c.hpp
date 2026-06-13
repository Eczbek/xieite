#ifndef DETAIL_XTE_HEADER_UTIL_AS_NOT_C
#	define DETAIL_XTE_HEADER_UTIL_AS_NOT_C
#
#	include "../trait/drop_c.hpp"

namespace xte {
	inline constexpr auto as_not_c = []<typename T>[[nodiscard]](T&& x) static noexcept -> auto&& {
		return const_cast<xte::drop_c<T&&>>(x);
	};
}

#endif
