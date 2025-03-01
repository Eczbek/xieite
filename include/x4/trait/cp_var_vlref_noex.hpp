#pragma once

#include "../trait/cpvarvlref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvlrefnoex = x4::cpvarvlref<T, x4::cpnoex<T, U>>;
}
