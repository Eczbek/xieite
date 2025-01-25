#pragma once

#include "../trait/add_ref_referent.hpp"
#include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cvref = xieite::add_var_cv<xieite::add_ref_referent<T, U>>;
}
