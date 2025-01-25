#pragma once

#include "../trait/cp_var_lref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_lref_noex = xieite::cp_var_lref<T, xieite::cp_noex<T, U>>;
}
