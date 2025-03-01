#pragma once

#include "../trait/cpvarvref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvrefnoex = x4::cpvarvref<T, x4::cpnoex<T, U>>;
}
