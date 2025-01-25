#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_vrref.hpp"

namespace xieite {
	template<typename T>
	using add_var_vrref_noex = xieite::add_var_vrref<xieite::add_noex<T>>;
}
