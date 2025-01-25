#pragma once

#include "../trait/cp_cref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cref = xieite::cp_var<T, xieite::cp_cref_referent<T, U>>;
}
