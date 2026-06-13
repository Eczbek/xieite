#ifndef DETAIL_XTE_HEADER_UTIL_XVALUE
#	define DETAIL_XTE_HEADER_UTIL_XVALUE
#
#	include "../trait/drop_ref.hpp"

namespace xte {
	inline constexpr auto xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return static_cast<xte::drop_ref<decltype(x)>&&>(x);
	};
}

#endif
