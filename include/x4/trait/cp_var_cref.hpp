#pragma once

#include "../trait/cpcrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcref = x4::cpvar<T, x4::cpcrefreft<T, U>>;
}
