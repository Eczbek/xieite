#pragma once

#include "../trait/cpc.hpp"
#include "../trait/cprref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcrref = x4::cpc<T, x4::cprref<T, U>>;
}
