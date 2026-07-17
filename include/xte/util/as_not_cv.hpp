#ifndef DETAIL_XTE_HEADER_UTIL_AS_NOT_CV
#	define DETAIL_XTE_HEADER_UTIL_AS_NOT_CV
#
#	include "../trait/drop_cv.hpp"

namespace xte {
	inline constexpr auto as_not_cv = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return const_cast<xte::drop_cv<decltype(x)&&>>(x);
	};
}

#endif
