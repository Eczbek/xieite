#pragma once

#include "../trait/add_c_referent.hpp"
#include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_c = xieite::add_var<xieite::add_c_referent<T>>;
}
