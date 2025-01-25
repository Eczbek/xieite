#pragma once

#include "../trait/rm_cv.hpp"
#include "../trait/rm_lref.hpp"

namespace xieite {
	template<typename T>
	using rm_cvlref = xieite::rm_cv<xieite::rm_lref<T>>;
}
