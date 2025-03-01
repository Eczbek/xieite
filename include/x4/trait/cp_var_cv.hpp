#pragma once

#include "../trait/cpcvreft.hpp"
#include "../trait/cpvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcv = x4::cpvar<T, x4::cpcvreft<T, U>>;
}
