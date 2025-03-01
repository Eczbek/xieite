#pragma once

#include "../trait/cpcv.hpp"
#include "../trait/cprref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvrref = x4::cpcv<T, x4::cprref<T, U>>;
}
