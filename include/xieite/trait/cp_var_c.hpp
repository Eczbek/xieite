#pragma once

#include "../trait/cp_c_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_c = xieite::cp_var<T, xieite::cp_c_referent<T, U>>;
}
