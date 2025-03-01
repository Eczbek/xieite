#pragma once

#include "../trait/cpnoex.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarnoex = x4::cpvar<T, x4::cpnoex<T, U>>;
}
