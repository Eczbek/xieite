#pragma once

#include "../trait/cp_lref.hpp"
#include "../trait/cp_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_ref = xieite::cp_lref<T, xieite::cp_rref<T, U>>;
}
