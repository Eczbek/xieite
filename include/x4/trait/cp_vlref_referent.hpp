#pragma once

#include "../trait/cpvreft.hpp"
#include "../trait/cplrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvlrefreft = x4::cpvreft<T, x4::cplrefreft<T, U>>;
}
