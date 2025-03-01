#pragma once

#include <type_traits>
#include "../trait/isarith.hpp"
#include "../trait/issame_any.hpp"

namespace x4 {
	template<x4::isarith>
	struct line2d;

	template<x4::isarith>
	struct ray2d;

	template<x4::isarith>
	struct segm2d;

	template<typename T, typename U = double>
	concept islinear2d =
		x4::issame_any<
			std::remove_cv_t<T>,
			x4::line2d<U>,
			x4::ray2d<U>,
			x4::segm2d<U>
		>;
}
