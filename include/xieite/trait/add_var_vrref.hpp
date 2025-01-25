#pragma once

#include "../trait/add_rref_referent.hpp"
#include "../trait/add_var_v.hpp"

namespace xieite {
	template<typename T>
	using add_var_vrref = xieite::add_var_v<xieite::add_rref_referent<T>>;
}
