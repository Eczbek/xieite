#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/isvarv.hpp"

namespace x4 {
	template<typename T>
	concept isvarvlref = x4::isvarv<T> && x4::islrefreft<T>;
}
