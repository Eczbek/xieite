#pragma once

#include "../trait/isrefreft.hpp"
#include "../trait/isvarc.hpp"

namespace x4 {
	template<typename T>
	concept isvarcref = x4::isvarc<T> && x4::isrefreft<T>;
}
