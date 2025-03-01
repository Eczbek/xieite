#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/isvarcv.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvlref = x4::isvarcv<T> && x4::islrefreft<T>;
}
