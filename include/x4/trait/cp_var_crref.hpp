#pragma once

#include "../trait/cpcrrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcrref = x4::cpvar<T, x4::cpcrrefreft<T, U>>;
}
