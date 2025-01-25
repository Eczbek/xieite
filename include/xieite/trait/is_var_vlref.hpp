#pragma once

#include "../trait/is_lref_referent.hpp"
#include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vlref = xieite::is_var_v<T> && xieite::is_lref_referent<T>;
}
