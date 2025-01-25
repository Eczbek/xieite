#pragma once

#include "../trait/is_v_referent.hpp"
#include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cv = xieite::is_var_c<T> && xieite::is_v_referent<T>;
}
