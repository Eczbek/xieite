#pragma once

#include "../trait/is_lref_referent.hpp"
#include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_clref = xieite::is_var_c<T> && xieite::is_lref_referent<T>;
}
