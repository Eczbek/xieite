#pragma once

#include "../trait/cp_var_vref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vref_noex = xieite::cp_var_vref<T, xieite::cp_noex<T, U>>;
}
