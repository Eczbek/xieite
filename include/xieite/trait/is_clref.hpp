#pragma once

#include "../trait/is_c.hpp"
#include "../trait/is_lref.hpp"

namespace xieite {
	template<typename T>
	concept is_clref = xieite::is_c<T> && xieite::is_lref<T>;
}
