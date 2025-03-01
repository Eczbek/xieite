#pragma once

#include "../trait/cprefreft.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cprefnoex = x4::cprefreft<T, x4::cpnoex<T, U>>;
}
