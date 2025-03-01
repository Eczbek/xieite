#pragma once

#include "../trait/isnoex.hpp"
#include "../trait/isvarcv.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvnoex = x4::isvarcv<T> && x4::isnoex<T>;
}
