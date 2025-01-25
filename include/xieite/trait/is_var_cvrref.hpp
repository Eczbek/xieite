#pragma once

#include "../trait/is_rref_referent.hpp"
#include "../trait/is_var_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvrref = xieite::is_var_cv<T> && xieite::is_rref_referent<T>;
}
