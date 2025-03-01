#pragma once

#include "../trait/cpvarlref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarlrefnoex = x4::cpvarlref<T, x4::cpnoex<T, U>>;
}
