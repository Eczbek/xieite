#pragma once

#include "../trait/is_lref.hpp"
#include "../trait/is_rref.hpp"

namespace xieite {
	template<typename T>
	concept is_ref = xieite::is_lref<T> || xieite::is_rref<T>;
}
