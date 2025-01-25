#pragma once

#include "../trait/cp_var_cvlref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvlref_noex = xieite::cp_var_cvlref<T, xieite::cp_noex<T, U>>;
}
