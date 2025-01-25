#pragma once

#include "../trait/set_c_noex.hpp"
#include "../trait/is_c_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_c_noex = xieite::set_c_noex<xieite::is_c_noex<T>, U>;
}
