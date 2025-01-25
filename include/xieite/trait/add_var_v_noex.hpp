#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_v.hpp"

namespace xieite {
	template<typename T>
	using add_var_v_noex = xieite::add_var_v<xieite::add_noex<T>>;
}
