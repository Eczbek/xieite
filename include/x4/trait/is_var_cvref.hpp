#pragma once

#include "../trait/isrefreft.hpp"
#include "../trait/isvarcv.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvref = x4::isvarcv<T> && x4::isrefreft<T>;
}
