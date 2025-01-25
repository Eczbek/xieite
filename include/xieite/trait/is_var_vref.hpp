#pragma once

#include "../trait/is_ref_referent.hpp"
#include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vref = xieite::is_var_v<T> && xieite::is_ref_referent<T>;
}
