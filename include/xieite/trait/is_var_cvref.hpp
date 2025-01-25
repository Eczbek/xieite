#pragma once

#include "../trait/is_ref_referent.hpp"
#include "../trait/is_var_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvref = xieite::is_var_cv<T> && xieite::is_ref_referent<T>;
}
