#pragma once

#include "../trait/cp_cvrref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvrref = xieite::cp_var<T, xieite::cp_cvrref_referent<T, U>>;
}
