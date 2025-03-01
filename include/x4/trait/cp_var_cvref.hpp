#pragma once

#include "../trait/cpcvrefreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvref = x4::cpvar<T, x4::cpcvrefreft<T, U>>;
}
