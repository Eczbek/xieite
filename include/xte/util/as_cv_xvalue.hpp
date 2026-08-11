#ifndef DETAIL_XTE_HEADER_UTIL_AS_CV_XVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_CV_XVALUE
#
#	include "../util/as_cv.hpp"
#	include "../util/as_xvalue.hpp"

namespace xte {
	inline constexpr auto as_cv_xvalue = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return xte::as_xvalue(xte::as_cv(x));
	};
}

#endif
