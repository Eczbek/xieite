#ifndef DETAIL_XTE_HEADER_UTIL_AS_NOT_V
#	define DETAIL_XTE_HEADER_UTIL_AS_NOT_V
#
#	include "../trait/remove_v.hpp"

namespace xte {
	inline constexpr auto as_not_v = []<typename T>[[nodiscard]](T&& x) static noexcept -> auto&& {
		return const_cast<xte::remove_v<T&&>>(x);
	};
}

#endif
