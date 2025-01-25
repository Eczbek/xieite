#pragma once

#include "../trait/cp_cvlref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvlref = xieite::cp_var<T, xieite::cp_cvlref_referent<T, U>>;
}
