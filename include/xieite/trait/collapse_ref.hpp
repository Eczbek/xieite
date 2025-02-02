#pragma once

#include "../trait/add_rref.hpp"
#include "../trait/cp_cvlref.hpp"

namespace xieite {
	template<typename T, typename U>
	using collapse_ref = xieite::cp_cvlref<T, xieite::add_rref<U>>;
}
