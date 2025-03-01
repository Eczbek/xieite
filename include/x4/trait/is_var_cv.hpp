#pragma once

#include "../trait/isvreft.hpp"
#include "../trait/isvarc.hpp"

namespace x4 {
	template<typename T>
	concept isvarcv = x4::isvarc<T> && x4::isvreft<T>;
}
