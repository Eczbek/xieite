#pragma once

#include "../trait/cp_var_cref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cref_noex = xieite::cp_var_cref<T, xieite::cp_noex<T, U>>;
}
