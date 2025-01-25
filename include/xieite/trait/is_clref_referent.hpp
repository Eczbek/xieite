#pragma once

#include "../trait/is_c_referent.hpp"
#include "../trait/is_lref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_clref_referent = xieite::is_c_referent<T> && xieite::is_lref_referent<T>;
}
