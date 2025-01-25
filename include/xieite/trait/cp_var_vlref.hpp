#pragma once

#include "../trait/cp_var.hpp"
#include "../trait/cp_vlref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vlref = xieite::cp_var<T, xieite::cp_vlref_referent<T, U>>;
}
