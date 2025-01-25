#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_vlref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vlref_noex = xieite::is_var_vlref<T> && xieite::is_noex<T>;
}
