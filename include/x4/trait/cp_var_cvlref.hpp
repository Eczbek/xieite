#pragma once

#include "../trait/cpcvlrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvlref = x4::cpvar<T, x4::cpcvlrefreft<T, U>>;
}
