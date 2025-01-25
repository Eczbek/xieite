#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_vrref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vrref_noex = xieite::is_var_vrref<T> && xieite::is_noex<T>;
}
