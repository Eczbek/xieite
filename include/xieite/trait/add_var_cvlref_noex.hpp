#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_cvlref.hpp"

namespace xieite {
	template<typename T>
	using add_var_cvlref_noex = xieite::add_var_cvlref<xieite::add_noex<T>>;
}
