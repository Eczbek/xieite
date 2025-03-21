#pragma once

#include "../trait/is_c_referent.hpp"
#include "../trait/is_var.hpp"

namespace xieite {
	template<typename T>
	concept is_var_c = xieite::is_var<T> && xieite::is_c_referent<T>;
}
