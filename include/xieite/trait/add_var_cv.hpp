#pragma once

#include "../trait/add_cv_referent.hpp"
#include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_cv = xieite::add_var<xieite::add_cv_referent<T>>;
}
