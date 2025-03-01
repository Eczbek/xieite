#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/isvarcv.hpp"

namespace x4 {
	template<typename T>
	concept isvarcvrref = x4::isvarcv<T> && x4::isrrefreft<T>;
}
