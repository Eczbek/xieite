#pragma once

#include "../trait/add_rref_referent.hpp"
#include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T>
	using add_var_cvrref = xieite::add_var_cv<xieite::add_rref_referent<T>>;
}
