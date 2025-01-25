#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_cvrref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvrref_noex = xieite::rm_var_cvrref<xieite::rm_noex<T>>;
}
