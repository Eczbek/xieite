#pragma once

#include "../trait/is_cv.hpp"
#include "../trait/is_rref.hpp"

namespace xieite {
	template<typename T>
	concept is_cvrref = xieite::is_cv<T> && xieite::is_rref<T>;
}
