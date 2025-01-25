#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_lref.hpp"

namespace xieite {
	template<typename T>
	using add_var_lref_noex = xieite::add_var_lref<xieite::add_noex<T>>;
}
