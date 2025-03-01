#pragma once

#include "../trait/cpcvrrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvrref = x4::cpvar<T, x4::cpcvrrefreft<T, U>>;
}
