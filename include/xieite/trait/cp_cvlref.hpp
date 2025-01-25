#pragma once

#include "../trait/cp_cv.hpp"
#include "../trait/cp_lref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvlref = xieite::cp_cv<T, xieite::cp_lref<T, U>>;
}
