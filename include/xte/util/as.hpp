#ifndef DETAIL_XTE_HEADER_UTIL_AS
#	define DETAIL_XTE_HEADER_UTIL_AS
#
#	include "../meta/value_at.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_const.hpp"
#	include "../trait/is_lvalue_ref.hpp"
#	include "../trait/is_volatile.hpp"
#	include "../util/as_const.hpp"
#	include "../util/as_lvalue.hpp"
#	include "../util/as_not_const.hpp"
#	include "../util/as_not_volatile.hpp"
#	include "../util/as_volatile.hpp"
#	include "../util/as_xvalue.hpp"

namespace xte {
	template<typename T>
	constexpr auto as = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return xte::value_at<xte::is_const<T>, xte::as_not_const, xte::as_const>(
			xte::value_at<xte::is_volatile<T>, xte::as_not_volatile, xte::as_volatile>(
				xte::value_at<xte::is_lvalue_ref<T>, xte::as_xvalue, xte::as_lvalue>(
					XTE_FWD(x)
				)
			)
		);
	};
}

#endif
