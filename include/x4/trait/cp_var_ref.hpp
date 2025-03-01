#pragma once

#include "../trait/cprefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarref = x4::cpvar<T, x4::cprefreft<T, U>>;
}
