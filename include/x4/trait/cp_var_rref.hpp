#pragma once

#include "../trait/cprrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarrref = x4::cpvar<T, x4::cprrefreft<T, U>>;
}
