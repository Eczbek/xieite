#pragma once

#include "../trait/add_lref_referent.hpp"
#include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T>
	using add_var_cvlref = xieite::add_var_cv<xieite::add_lref_referent<T>>;
}
