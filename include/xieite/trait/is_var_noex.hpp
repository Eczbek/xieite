#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var.hpp"

namespace xieite {
	template<typename T>
	concept is_var_noex = xieite::is_var<T> && xieite::is_noex<T>;
}
