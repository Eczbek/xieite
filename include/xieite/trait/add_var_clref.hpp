#pragma once

#include "../trait/add_lref_referent.hpp"
#include "../trait/add_var_c.hpp"

namespace xieite {
	template<typename T>
	using add_var_clref = xieite::add_var_c<xieite::add_lref_referent<T>>;
}
