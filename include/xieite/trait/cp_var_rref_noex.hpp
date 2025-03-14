#pragma once

#include "../trait/cp_var_rref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_rref_noex = xieite::cp_var_rref<T, xieite::cp_noex<T, U>>;
}
