#pragma once

#include "../trait/cp_crref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_crref = xieite::cp_var<T, xieite::cp_crref_referent<T, U>>;
}
