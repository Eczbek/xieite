#pragma once

#include "../trait/is_rref_referent.hpp"
#include "../trait/is_v_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vrref_referent = xieite::is_v_referent<T> && xieite::is_rref_referent<T>;
}
