#pragma once

#include "../trait/is_ref_referent.hpp"
#include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cref = xieite::is_var_c<T> && xieite::is_ref_referent<T>;
}
