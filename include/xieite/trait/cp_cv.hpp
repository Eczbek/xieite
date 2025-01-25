#pragma once

#include "../trait/cp_c.hpp"
#include "../trait/cp_v.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cv = xieite::cp_c<T, xieite::cp_v<T, U>>;
}
