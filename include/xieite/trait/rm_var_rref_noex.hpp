#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_rref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_rref_noex = xieite::rm_var_rref<xieite::rm_noex<T>>;
}
