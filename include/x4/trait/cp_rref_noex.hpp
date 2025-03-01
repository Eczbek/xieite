#pragma once

#include "../trait/setrrefnoex.hpp"
#include "../trait/isrrefnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cprrefnoex = x4::setrrefnoex<x4::isrrefnoex<T>, U>;
}
