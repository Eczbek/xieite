#pragma once

#include "../trait/cpvarcref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcrefnoex = x4::cpvarcref<T, x4::cpnoex<T, U>>;
}
