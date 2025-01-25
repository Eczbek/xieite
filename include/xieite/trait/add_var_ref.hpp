#pragma once

#include "../trait/add_ref_referent.hpp"
#include "../trait/add_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_ref = xieite::add_var<xieite::add_ref_referent<T, U>>;
}
