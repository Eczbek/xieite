#pragma once

#include "../trait/cplrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarlref = x4::cpvar<T, x4::cplrefreft<T, U>>;
}
