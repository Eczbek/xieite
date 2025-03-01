#pragma once

#include "../trait/isrefreft.hpp"
#include "../trait/isvarv.hpp"

namespace x4 {
	template<typename T>
	concept isvarvref = x4::isvarv<T> && x4::isrefreft<T>;
}
