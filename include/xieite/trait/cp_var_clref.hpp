#pragma once

#include "../trait/cp_clref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_clref = xieite::cp_var<T, xieite::cp_clref_referent<T, U>>;
}
