#ifndef DETAIL_XTE_HEADER_MATH_MIN_MAX
#	define DETAIL_XTE_HEADER_MATH_MIN_MAX
#
#	include "../math/less.hpp"
#	include "../meta/define_struct.hpp"
#	include "../meta/end.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../util/make.hpp"
#	include <type_traits>

namespace xte {
	template<typename T, typename U, xte::end...,
		typename common_type = std::common_type_t<T, U>,
		typename result_type = xte::define_struct<{ ^^common_type, "min" }, { ^^common_type, "max" }>>
	[[nodiscard]] constexpr auto min_max(T&& x, U&& y) XTE_RETURNS(
		xte::less(x, y)
			? result_type { xte::make<common_type>(XTE_FWD(x)), xte::make<common_type>(XTE_FWD(y)) }
			: result_type { xte::make<common_type>(XTE_FWD(y)), xte::make<common_type>(XTE_FWD(x)) }
	)
}

#endif
