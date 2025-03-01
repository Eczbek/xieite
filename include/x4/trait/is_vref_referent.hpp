#pragma once

#include "../trait/isrefreft.hpp"
#include "../trait/isvreft.hpp"

namespace x4 {
	template<typename T>
	concept isvrefreft = x4::isvreft<T> && x4::isrefreft<T>;
}
