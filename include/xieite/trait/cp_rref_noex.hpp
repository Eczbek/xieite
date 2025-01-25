#pragma once

#include "../trait/set_rref_noex.hpp"
#include "../trait/is_rref_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_rref_noex = xieite::set_rref_noex<xieite::is_rref_noex<T>, U>;
}
