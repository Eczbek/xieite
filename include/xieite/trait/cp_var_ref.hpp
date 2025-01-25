#pragma once

#include "../trait/cp_ref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_ref = xieite::cp_var<T, xieite::cp_ref_referent<T, U>>;
}
