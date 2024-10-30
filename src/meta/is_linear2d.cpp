export module xieite:is_linear2d;

import std;
import :is_arith;
import :is_same_as_any;

export namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<typename T, typename U = double>
	concept is_linear2d =
		xieite::is_same_as_any<
			std::remove_cv_t<T>,
			xieite::line2d<U>,
			xieite::ray2d<U>,
			xieite::segm2d<U>
		>;
}
