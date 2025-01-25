#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_crref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_crref_noex = xieite::rm_var_crref<xieite::rm_noex<T>>;
}
