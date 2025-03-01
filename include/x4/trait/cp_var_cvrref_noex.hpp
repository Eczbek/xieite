#pragma once

#include "../trait/cpvarcvrref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvrrefnoex = x4::cpvarcvrref<T, x4::cpnoex<T, U>>;
}
