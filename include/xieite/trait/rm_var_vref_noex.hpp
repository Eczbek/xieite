#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_vref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vref_noex = xieite::rm_var_vref<xieite::rm_noex<T>>;
}
