#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_cvref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvref_noex = xieite::rm_var_cvref<xieite::rm_noex<T>>;
}
