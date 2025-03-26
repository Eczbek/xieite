#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_LINEAR2D
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_LINEAR2D
#
#	include <type_traits>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_same_any.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<typename T, typename U = double>
	concept is_linear2d =
		xieite::is_same_any<
			std::remove_cv_t<T>,
			xieite::line2d<U>,
			xieite::ray2d<U>,
			xieite::segm2d<U>
		>;
}

#endif
