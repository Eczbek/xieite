#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_c.hpp"

namespace xieite {
	template<typename T>
	using add_var_c_noex = xieite::add_var_c<xieite::add_noex<T>>;
}
