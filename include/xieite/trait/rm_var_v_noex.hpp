#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_v.hpp"

namespace xieite {
	template<typename T>
	using rm_var_v_noex = xieite::rm_var_v<xieite::rm_noex<T>>;
}
