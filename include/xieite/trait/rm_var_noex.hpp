#pragma once

#include "../trait/rm_noex.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_noex = xieite::rm_var<xieite::rm_noex<T>>;
}
