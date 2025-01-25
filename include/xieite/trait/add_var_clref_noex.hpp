#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_clref.hpp"

namespace xieite {
	template<typename T>
	using add_var_clref_noex = xieite::add_var_clref<xieite::add_noex<T>>;
}
