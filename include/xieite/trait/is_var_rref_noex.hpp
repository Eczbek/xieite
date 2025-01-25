#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_rref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_rref_noex = xieite::is_var_rref<T> && xieite::is_noex<T>;
}
