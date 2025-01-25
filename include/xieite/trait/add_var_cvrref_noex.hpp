#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_cvrref.hpp"

namespace xieite {
	template<typename T>
	using add_var_cvrref_noex = xieite::add_var_cvrref<xieite::add_noex<T>>;
}
