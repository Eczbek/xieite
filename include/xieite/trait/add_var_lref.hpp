#pragma once

#include "../trait/add_lref_referent.hpp"
#include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_lref = xieite::add_var<xieite::add_lref_referent<T>>;
}
