#pragma once

#include "../trait/is_clref.hpp"
#include "../trait/is_crref.hpp"

namespace xieite {
	template<typename T>
	concept is_cref = xieite::is_clref<T> || xieite::is_crref<T>;
}
