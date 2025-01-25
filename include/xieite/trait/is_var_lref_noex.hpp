#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_lref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_lref_noex = xieite::is_var_lref<T> && xieite::is_noex<T>;
}
