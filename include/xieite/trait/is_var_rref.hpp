#pragma once

#include "../trait/is_rref_referent.hpp"
#include "../trait/is_var.hpp"

namespace xieite {
	template<typename T>
	concept is_var_rref = xieite::is_var<T> && xieite::is_rref_referent<T>;
}
