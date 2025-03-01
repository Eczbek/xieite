#pragma once

#include "../trait/cpvreft.hpp"
#include "../trait/cprefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvrefreft = x4::cpvreft<T, x4::cprefreft<T, U>>;
}
