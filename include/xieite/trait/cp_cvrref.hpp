#pragma once

#include "../trait/cp_cv.hpp"
#include "../trait/cp_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvrref = xieite::cp_cv<T, xieite::cp_rref<T, U>>;
}
