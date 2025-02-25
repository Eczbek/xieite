#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_vlref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vlref_noex = xieite::rm_var_vlref<xieite::rm_noex<T>>;
}
