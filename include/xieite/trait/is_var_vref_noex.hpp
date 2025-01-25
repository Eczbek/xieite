#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_vref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vref_noex = xieite::is_var_vref<T> && xieite::is_noex<T>;
}
