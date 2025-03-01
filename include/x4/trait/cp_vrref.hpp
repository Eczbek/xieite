#pragma once

#include "../trait/cpv.hpp"
#include "../trait/cprref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvrref = x4::cpv<T, x4::cprref<T, U>>;
}
