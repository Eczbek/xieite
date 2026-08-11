#ifndef DETAIL_XTE_HEADER_UTIL_AS_CV_LVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_CV_LVALUE
#
#	include "../util/as_cv.hpp"
#	include "../util/as_lvalue.hpp"

namespace xte {
	inline constexpr auto as_cv_lvalue = [][[nodiscard]](auto&& x) static noexcept -> auto& {
		return xte::as_lvalue(xte::as_cv(x));
	};
}

#endif
