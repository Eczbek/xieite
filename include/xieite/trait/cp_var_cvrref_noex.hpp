#pragma once

#include "../trait/cp_var_cvrref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvrref_noex = xieite::cp_var_cvrref<T, xieite::cp_noex<T, U>>;
}
