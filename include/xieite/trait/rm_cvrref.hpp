#pragma once

#include "../trait/rm_cv.hpp"
#include "../trait/rm_rref.hpp"

namespace xieite {
	template<typename T>
	using rm_cvrref = xieite::rm_cv<xieite::rm_rref<T>>;
}
