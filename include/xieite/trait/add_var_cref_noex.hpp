#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_cref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cref_noex = xieite::add_var_cref<T, xieite::add_noex<U>>;
}
