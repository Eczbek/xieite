#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_c.hpp"

namespace xieite {
	template<typename T>
	using rm_var_c_noex = xieite::rm_var_c<xieite::rm_noex<T>>;
}
