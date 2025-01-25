#pragma once

#include "../trait/cp_cvref_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvref = xieite::cp_var<T, xieite::cp_cvref_referent<T, U>>;
}
