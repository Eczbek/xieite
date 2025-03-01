#pragma once

#include "../trait/cpclrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarclref = x4::cpvar<T, x4::cpclrefreft<T, U>>;
}
