#pragma once

#include "../trait/cp_var_cv.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cv_noex = xieite::cp_var_cv<T, xieite::cp_noex<T, U>>;
}
