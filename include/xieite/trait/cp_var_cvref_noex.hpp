#pragma once

#include "../trait/cp_var_cvref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvref_noex = xieite::cp_var_cvref<T, xieite::cp_noex<T, U>>;
}
