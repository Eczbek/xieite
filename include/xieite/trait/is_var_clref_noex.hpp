#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_clref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_clref_noex = xieite::is_var_clref<T> && xieite::is_noex<T>;
}
