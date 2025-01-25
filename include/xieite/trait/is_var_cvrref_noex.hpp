#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_cvrref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvrref_noex = xieite::is_var_cvrref<T> && xieite::is_noex<T>;
}
