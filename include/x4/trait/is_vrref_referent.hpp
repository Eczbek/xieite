#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/isvreft.hpp"

namespace x4 {
	template<typename T>
	concept isvrrefreft = x4::isvreft<T> && x4::isrrefreft<T>;
}
