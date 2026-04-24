#ifndef DETAIL_XTE_HEADER_MATH_MINMAX
#	define DETAIL_XTE_HEADER_MATH_MINMAX
#
#	include "../math/less.hpp"
#	include "../meta/end.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include <type_traits>

namespace DETAIL_XTE {
	template<typename T>
	struct minmax {
		T min;
		T max;
	};
}

namespace xte {
	template<typename T, typename U, xte::end...,
		typename common_type = std::common_type_t<T, U>>
	[[nodiscard]] constexpr auto minmax(T&& x, U&& y) XTE_ARROW(
		xte::less(x, y)
			? DETAIL_XTE::minmax<common_type> { static_cast<common_type>(XTE_FWD(x)), static_cast<common_type>(XTE_FWD(y)) }
			: DETAIL_XTE::minmax<common_type> { static_cast<common_type>(XTE_FWD(y)), static_cast<common_type>(XTE_FWD(x)) }
	)
}

#endif
