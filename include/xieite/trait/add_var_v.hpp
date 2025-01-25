#pragma once

#include "../trait/add_v_referent.hpp"
#include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_v = xieite::add_var<xieite::add_v_referent<T>>;
}
