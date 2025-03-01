#pragma once

#include "../trait/cpvarclref.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarclrefnoex = x4::cpvarclref<T, x4::cpnoex<T, U>>;
}
