#pragma once

#include "../trait/set_c.hpp"
#include "../trait/is_c.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_c = xieite::set_c<xieite::is_c<T>, U>;
}
