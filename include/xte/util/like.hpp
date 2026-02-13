#ifndef DETAIL_XTE_HEADER_UTIL_LIKE
#	define DETAIL_XTE_HEADER_UTIL_LIKE
#
#	include "../meta/value_at.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_c.hpp"
#	include "../trait/is_lref.hpp"
#	include "../trait/is_v.hpp"
#	include "../util/as_c.hpp"
#	include "../util/as_not_c.hpp"
#	include "../util/as_not_v.hpp"
#	include "../util/as_v.hpp"
#	include "../util/lvalue.hpp"
#	include "../util/xvalue.hpp"

namespace xte {
	template<typename T>
	constexpr auto like = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return xte::value_at<xte::is_c<T>, xte::as_not_c, xte::as_c>(
			xte::value_at<xte::is_v<T>, xte::as_not_v, xte::as_v>(
				xte::value_at<xte::is_lref<T>, xte::xvalue, xte::lvalue>(
					XTE_FWD(x)
				)
			)
		);
	};
}

#endif
