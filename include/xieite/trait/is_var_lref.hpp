#pragma once

#include "../trait/is_lref_referent.hpp"
#include "../trait/is_var.hpp"

namespace xieite {
	template<typename T>
	concept is_var_lref = xieite::is_var<T> && xieite::is_lref_referent<T>;
}
