#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var_cvlref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvlref_noex = xieite::rm_var_cvlref<xieite::rm_noex<T>>;
}
