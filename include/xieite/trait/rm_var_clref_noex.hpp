#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_clref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_clref_noex = xieite::rm_var_clref<xieite::rm_noex<T>>;
}
