#ifndef DETAIL_XTE_HEADER_UTIL_AS_XVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_XVALUE
#
#	include "../trait/drop_ref.hpp"

namespace xte {
	inline constexpr auto as_xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return static_cast<xte::drop_ref<decltype(x)>&&>(x);
	};
}

#endif
