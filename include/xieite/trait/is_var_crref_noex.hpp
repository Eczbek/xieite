#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_crref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_crref_noex = xieite::is_var_crref<T> && xieite::is_noex<T>;
}
