#pragma once

#include "../trait/set_cv.hpp"
#include "../trait/set_rref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvrref = xieite::set_cv<qual, xieite::set_rref<qual, T>>;
}
