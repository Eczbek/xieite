#pragma once

#include "../trait/cpvarv.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvnoex = x4::cpvarv<T, x4::cpnoex<T, U>>;
}
