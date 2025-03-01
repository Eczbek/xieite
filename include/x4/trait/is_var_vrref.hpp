#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/isvarv.hpp"

namespace x4 {
	template<typename T>
	concept isvarvrref = x4::isvarv<T> && x4::isrrefreft<T>;
}
