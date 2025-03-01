#pragma once

#include "../trait/cpvar.hpp"
#include "../trait/cpvrrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarvrref = x4::cpvar<T, x4::cpvrrefreft<T, U>>;
}
