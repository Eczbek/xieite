#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/isrrefreft.hpp"

namespace x4 {
	template<typename T>
	concept isrefreft = x4::islrefreft<T> || x4::isrrefreft<T>;
}
