#pragma once

#include "../trait/cpvarcvlref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvlrefnoex = x4::cpvarcvlref<T, x4::cpnoex<T, U>>;
}
