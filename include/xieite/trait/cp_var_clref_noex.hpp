#pragma once

#include "../trait/cp_var_clref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_clref_noex = xieite::cp_var_clref<T, xieite::cp_noex<T, U>>;
}
