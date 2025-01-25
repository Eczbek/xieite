#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_cvlref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvlref_noex = xieite::is_var_cvlref<T> && xieite::is_noex<T>;
}
