#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_cvref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cvref_noex = xieite::add_var_cvref<T, xieite::add_noex<U>>;
}
