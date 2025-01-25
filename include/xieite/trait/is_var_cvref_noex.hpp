#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvref_noex = xieite::is_var_cvref<T> && xieite::is_noex<T>;
}
