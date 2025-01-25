#pragma once

#include "../trait/set_cv.hpp"
#include "../trait/set_lref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvlref = xieite::set_cv<qual, xieite::set_lref<qual, T>>;
}
