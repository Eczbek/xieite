#pragma once

#include "../trait/is_rref.hpp"
#include "../trait/set_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_rref = xieite::set_rref<xieite::is_rref<T>, U>;
}
