#pragma once

#include "../trait/cp_c.hpp"
#include "../trait/cp_lref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_clref = xieite::cp_c<T, xieite::cp_lref<T, U>>;
}
