#pragma once

#include "../trait/is_rref_referent.hpp"
#include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_crref = xieite::is_var_c<T> && xieite::is_rref_referent<T>;
}
