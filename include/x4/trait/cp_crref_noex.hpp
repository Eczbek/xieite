#pragma once

#include "../trait/cpcrrefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcrrefnoex = x4::cpcrrefreft<T, x4::cpnoex<T, U>>;
}
