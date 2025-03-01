#pragma once

#include "../trait/cpvarcv.hpp"
#include "../trait/cpnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvarcvnoex = x4::cpvarcv<T, x4::cpnoex<T, U>>;
}
