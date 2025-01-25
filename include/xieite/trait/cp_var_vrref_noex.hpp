#pragma once

#include "../trait/cp_var_vrref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vrref_noex = xieite::cp_var_vrref<T, xieite::cp_noex<T, U>>;
}
