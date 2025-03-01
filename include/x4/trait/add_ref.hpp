#pragma once

#include "../trait/cplref.hpp"
#include "../trait/cprref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addref = x4::cplref<T, x4::cprref<T, U>>;
}
