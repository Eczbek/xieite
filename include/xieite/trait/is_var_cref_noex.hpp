#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_cref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cref_noex = xieite::is_var_cref<T> && xieite::is_noex<T>;
}
