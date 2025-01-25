#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_rref.hpp"

namespace xieite {
	template<typename T>
	using add_var_rref_noex = xieite::add_var_rref<xieite::add_noex<T>>;
}
