#pragma once

#include "../trait/set_v_noex.hpp"
#include "../trait/is_v_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_v_noex = xieite::set_v_noex<xieite::is_v_noex<T>, U>;
}
