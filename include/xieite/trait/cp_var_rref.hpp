#pragma once

#include "../trait/cp_rref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_rref = xieite::cp_var<T, xieite::cp_rref_referent<T, U>>;
}
