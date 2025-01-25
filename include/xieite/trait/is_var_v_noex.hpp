#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_v_noex = xieite::is_var_v<T> && xieite::is_noex<T>;
}
