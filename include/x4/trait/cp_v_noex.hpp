#pragma once

#include "../trait/setvnoex.hpp"
#include "../trait/isvnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvnoex = x4::setvnoex<x4::isvnoex<T>, U>;
}
