#pragma once

#include "../trait/add_rref_referent.hpp"
#include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_rref = xieite::add_var<xieite::add_rref_referent<T>>;
}
