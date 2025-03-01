#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/isvreft.hpp"

namespace x4 {
	template<typename T>
	concept isvlrefreft = x4::isvreft<T> && x4::islrefreft<T>;
}
