#pragma once

#include "../trait/cp_var_vlref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vlref_noex = xieite::cp_var_vlref<T, xieite::cp_noex<T, U>>;
}
