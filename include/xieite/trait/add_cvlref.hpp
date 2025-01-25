#pragma once

#include "../trait/add_cv.hpp"
#include "../trait/add_lref.hpp"

namespace xieite {
	template<typename T>
	using add_cvlref = xieite::add_cv<xieite::add_lref<T>>;
}
