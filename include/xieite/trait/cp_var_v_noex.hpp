#pragma once

#include "../trait/cp_var_v.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_v_noex = xieite::cp_var_v<T, xieite::cp_noex<T, U>>;
}
