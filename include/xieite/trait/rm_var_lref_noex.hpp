#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_lref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_lref_noex = xieite::rm_var_lref<xieite::rm_noex<T>>;
}
