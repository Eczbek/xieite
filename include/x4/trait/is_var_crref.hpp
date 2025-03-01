#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/isvarc.hpp"

namespace x4 {
	template<typename T>
	concept isvarcrref = x4::isvarc<T> && x4::isrrefreft<T>;
}
