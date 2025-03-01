#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/isvarc.hpp"

namespace x4 {
	template<typename T>
	concept isvarclref = x4::isvarc<T> && x4::islrefreft<T>;
}
