#pragma once

#include "../trait/cp_noex.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_noex = xieite::cp_var<T, xieite::cp_noex<T, U>>;
}
