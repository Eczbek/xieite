#pragma once

#include "../trait/cpvarrref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarrrefnoex = x4::cpvarrref<T, x4::cpnoex<T, U>>;
}
