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
	struct segment2d;

	template<typename T, typename Arith = double>
	concept is_linear2d =
		xieite::is_same_any<
			std::remove_cv_t<T>,
			xieite::line2d<Arith>,
			xieite::ray2d<Arith>,
			xieite::segment2d<Arith>
		>;
}

#endif
